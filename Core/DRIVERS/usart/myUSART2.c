#include <MyUsart2.h>

void send_str(char * ptr,uint32_t length) {
	DMA1_Stream6->CR&=~(1);//disable stream when everything is ready we enable then when buffer is empty we enable again
	while (!(USART2->SR & (1 << 7)));
	DMA1_Stream6->M0AR=(uint32_t)ptr;
	DMA1_Stream6->NDTR=length-1;//we will remove the null terminator tahts why we do -1

	USART2->CR3|=(1<<7);//ENABLE  DMA enable transmitter bit7
	DMA1_Stream6->CR|=(1<<0);//enable stream
}

//when we use this small lib for usart the cpu has to wait for a while in the send string func in the while loop line
//ive decided to add DMA for sending the data so the cpu doesnt wait for the buffer to get empty and send the data
void USART2_init(void) {
    // 1. Enable clocks
    RCC->AHB1ENR |= (1<<21)|(1 << 0);   // GPIOA, DMA1
    RCC->APB1ENR |= (1 << 17);  // USART2

    //DMA CONFIG
    DMA1_Stream6->CR=0;//clear it
    DMA1_Stream6->CR|=(0b100<<25)|(1<<16)|(0b0000<<11)|(1<<10)|(0b01<<6);
    DMA1_Stream6->CR&=~(1);//disable stream
    /*
     * bit25: we configure stream6 to channel 4 which USARTTX is hard wired to
     * bit16: the priority level is optional for which stream wins the AHB1 bus but i set it to med
     * bit14,13: since the uart sends a byte at time we set it to a byte then set MSIZE bits to 00 which is a byte of data
     * bit12,11: again since the uart sends a byte at time we set it to a bytethen set PSIZE bits to 00
     * bit10: we set to 1 so we want th epointer to increment when each data is tranffered and it depends on the MSIZE, when incrementing
     * bit7,6: set it to preph to mem which is 01
     * bit0: we disable the stream fornow until every config is complete then turn it on in send str func
     * */


    DMA1_Stream6->PAR=0;
    DMA1_Stream6->PAR=(uint32_t)&USART2->DR;
    DMA1_Stream6->M1AR=0;

    // 2. Configure PA2 (TX) as Alternate Function
    GPIOA->MODER &= ~(3 << (2*2)); // clear mode bits
    GPIOA->MODER |=  (2 << (2*2)); // AF mode
    GPIOA->OTYPER &= ~(1 << 2);    // push-pull
    GPIOA->OSPEEDR |= (3 << (2*2)); // high speed
    GPIOA->PUPDR &= ~(3 << (2*2));  // no pull-up/down

    // 3. Set AF7 for PA2
    GPIOA->AFR[0] &= ~(0xF << 8);   // clear
    GPIOA->AFR[0] |=  (7 << 8);     // AF7 = USART2

    // 4. Baud rate 9600 @ APB1=45MHz
    USART2->BRR = (292 << 4) | 15;

    // 5. Enable USART, TX only
    USART2->CR1 = (1 << 13) | (1 << 3); // UE | TE
}

