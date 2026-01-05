Bare-metal USART2 transmit driver for STM32F4 using DMA1 Stream 6.

	-Uses USART2 TX (PA2, AF7)
	-DMA is used so CPU does not block while sending data
	-Designed for sending strings only (TX)
	-No interrupts used (simple + lightweight)

How it works:

	1.USART2_init() configures GPIO, USART2, and DMA
	2.send_str() sends a string using DMA (non-blocking after setup)

Notes:

	-Baud rate is fixed to 9600 (fixed for now, will change it)
	-Null terminator is not transmitted
	-RX is not implemented (yet)