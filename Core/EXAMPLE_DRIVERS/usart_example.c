#include "MyUsart2.h"

int example_usart_main(void) {

    USART2_init_DMA();

    char msg[] = "Hello from USART2 DMA!\r\n";

    while (1) {
        send_str(msg, sizeof(msg));
        for (volatile uint32_t i = 0; i < 1000000; i++); // crude delay
    }
}
