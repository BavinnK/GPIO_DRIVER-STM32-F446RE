#include "MyDMA.h"
static inline void DMA_config(DMA_TypeDef *dma){
	if(dma==DMA1){
		RCC->AHB1ENR|=(1<<21);
	}
	else if(dma==DMA2){
		RCC->AHB1ENR|=(1<<22);
	}
	else return;
}
void DMAx_init(DMA_TypeDef *DMAx,DMA_config_t* DMA_CONFIG){
	DMA_config(DMAx);
	DMA_CONFIG->DMA_STREAM->CR=0;//clear everything
	DMA_CONFIG->DMA_STREAM->CR|=(DMA_CONFIG->CHANNEL<<25)|
								(DMA_CONFIG->PRIORITY<<16)|
								(DMA_CONFIG->MEMORY_DATA_SIZE<<13)|
								(DMA_CONFIG->PERIPHERAL_DATA_SIZE<<11)|
								(1<<10)|//Memory address pointer incremented after each data transfer (increment is done according to MSIZE)
								(DMA_CONFIG->MODE<<8)|
								(DMA_CONFIG->DIRECTION<<6);
	DMA_CONFIG->DMA_STREAM->NDTR=DMA_CONFIG->LENGTH-1;//we dont wanna include null terminator
	DMA_CONFIG->DMA_STREAM->PAR=0;
	DMA_CONFIG->DMA_STREAM->PAR=(uint32_t)DMA_CONFIG->PERIPHERAL_ADDR;
	DMA_CONFIG->DMA_STREAM->M0AR=0;
	DMA_CONFIG->DMA_STREAM->M0AR=(uint32_t)DMA_CONFIG->MEMORY_ADDR;
	DMA_CONFIG->DMA_STREAM->M1AR=0;//SINCE we don't use double buffer mode we will ignore second address register

}
