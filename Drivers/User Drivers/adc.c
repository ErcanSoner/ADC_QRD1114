/*
 * adc.c
 *
 *  Created on: Dec 9, 2021
 *      Author: ercan
 */


#include "stm32f0xx_hal.h"
#include "stdio.h"

void pin_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIOA->MODER |= (1<<0); //analog mode
	GPIOA->MODER |= (1<<1);
	GPIOA->OSPEEDR |= (1<<0); //HIGH SPEED
	GPIOA->OSPEEDR |= (1<<0);

	//LED AYARLARI

	GPIOA->MODER |= (1 << 10);
	GPIOA->MODER &= ~(1 << 11);

	GPIOA->OTYPER &= ~(1 << 5);

	GPIOA->OSPEEDR &= ~(1 << 10);
	GPIOA->OSPEEDR &= ~(1 << 11);
}

void adc_init(){
	__HAL_RCC_ADC1_CLK_ENABLE();

	ADC1->CHSELR |= (1<<0); //KANAL SECIMI

	ADC1->CFGR1 |=(1<<13); //CONTINUOUS MODE

	ADC1->SMPR |= (1 << 2);  //55.5 ADC Clock Cycles
	ADC1->SMPR &= ~(1 << 1);
	ADC1->SMPR |= (1 << 0);

	ADC1->CR |= (1<<0); //ENABLE

	ADC1->CFGR1 |= (1<<4);  //8 bits
	ADC1->CFGR1 &=~(1<<3);
}

uint16_t read_adc(){
	uint16_t value;
	ADC1->CR |= (1<<2); //yazilimsal olarak ADC'yi baslatir

	while(!(ADC1->ISR & (1<<2)));
	value=ADC1->DR;
	return value;
}

void led_on(){
	GPIOA->ODR |= (1<<5);
}

void led_off(){
	GPIOA->ODR &=~ (1<<5);
}
