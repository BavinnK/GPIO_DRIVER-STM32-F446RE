#include "RingBuffer.h"

bool RingBuffer_Write(RingBuffer_t *rb, uint8_t data){
	if(RingBuffer_IsFull(rb)){
		rb->head = (rb->head + 1) & (RING_BUF_SIZE - 1);
		return true;
	}
	else return false;
}
bool RingBuffer_Read(RingBuffer_t *rb, uint8_t *data){
	if(RingBuffer_IsEmpty(rb)){
		rb->tail = (rb->tail + 1) & (RING_BUF_SIZE - 1);
		return true;
	}
	else return false;
}




bool RingBuffer_IsEmpty(RingBuffer_t *rb){
	if(rb->head==rb->tail) return true;
	else 				   return false;

}
bool RingBuffer_IsFull(RingBuffer_t *rb){
	if(rb->head+1==rb->tail) return true;
	else   					 return false;
}
