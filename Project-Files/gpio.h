#ifndef GPIO_H
#define	GPIO_H

#include "..//tm4c123gh6pm.h"
#include "Random.h"
#include <stdlib.h>
#include <time.h>
#include "inter.h"
//#include "Nokia5110.h"	
int TimerCount, Semaphore;
int delay;
int m;
volatile int addData;
/* section: functions declarations */
void EdgeCounter_Init(void);
void PortF_Init(void);
void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count);
void ADC_Init(void);
void ADC0Seq3_Handler(void){
 
} 

#endif

