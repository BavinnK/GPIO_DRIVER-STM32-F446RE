#include "MYadc.h"
#include "stm32f446xx.h"


int example_adc_main(void) {
    // Configure channel 0
    adc_config_t config;
    config.channel = 0;
    config.sample_time = 0b111; // 480 cycles


    // Initialize ADC1
    adc_init(ADC1, &config);

    while(1) {
        uint16_t value = adc_read(ADC1, config.channel);

        // maybe print via UART or just read it
        // you don’t need to do anything, just loop
    }
}
