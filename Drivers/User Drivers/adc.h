/*
 * adc.h
 *
 *  Created on: Dec 9, 2021
 *      Author: ercan
 */

#ifndef USER_DRIVERS_ADC_H_
#define USER_DRIVERS_ADC_H_

void pin_init();
void adc_init();
uint16_t read_adc();
void led_on();
void led_off();

#endif /* USER_DRIVERS_ADC_H_ */
