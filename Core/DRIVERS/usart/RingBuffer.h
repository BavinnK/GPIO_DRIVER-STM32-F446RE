#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f446xx.h"

#define RING_BUF_SIZE 256 //size of our buffer

typedef struct {
    uint8_t buffer[RING_BUF_SIZE];
    uint32_t head;
    uint32_t tail;
} RingBuffer_t;

void RingBuffer_Init(RingBuffer_t *rb);
bool RingBuffer_IsEmpty(RingBuffer_t *rb);
bool RingBuffer_IsFull(RingBuffer_t *rb);
bool RingBuffer_Write(RingBuffer_t *rb, uint8_t data);
bool RingBuffer_Read(RingBuffer_t *rb, uint8_t *data);

#endif
