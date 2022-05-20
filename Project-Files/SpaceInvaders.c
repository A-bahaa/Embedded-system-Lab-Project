#include "gpio.c"
#include "race.c"

void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count);
void print_(int score);
int main(void){
	
	  PortF_Init();
    EdgeCounter_Init();           // initialize GPIO Port F interrupt
    TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
    Random_Init(1);
		ADC_Init();
    Nokia5110_Init();
		vertical_pos1 = CARH, vertical_pos2 =  CARH - 24 ;
		horizontal_pos = 32;
		r1 = 1;
		r2 = 3;
		score = 0; 
	
	
  while(1){
		
			if((ADC0_RIS_R & (1 << 3)) == (1 << 3)){ // if third bit is set
			ADC0_ISC_R  |= (1<<3);  // third bit = 1
			addData = ADC0_SSFIFO3_R;
		}
		horizontal_pos = (addData * (80-CARSW))/4095;
		
		
		
		
		if(vertical_pos1 > 48) score ++,r1 = rand ()%31, vertical_pos1 = 0;  // for new random number and restart
		if(vertical_pos2 > 48) score ++,r2 = rand ()%31, vertical_pos2 = 0;  // for new random number and restart
			Enemies(horizontal_pos,vertical_pos1,vertical_pos2,r1,r2);
		
			vertical_pos1 += ((score/10) + 1); 
		  vertical_pos2 += ((score/10) + 1); 
			Delay100ms(1);
		
		
		if(vertical_pos1 > 37){
		
			if ((horizontal_pos >= 60 && horizontal_pos <68 && r1 & (1<<0)) || (horizontal_pos >= 44 && horizontal_pos <52 && r1 & (1<<1)) ||(horizontal_pos >= 28 && horizontal_pos <36 && r1 & (1<<2)) || (horizontal_pos >= 12 && horizontal_pos <20 && r1 & (1<<3)) || (horizontal_pos >= 0 && horizontal_pos <8 && r1 & (1<<4))){
				
					//Delay100ms(10);
					print_(score);
					break;
		}
	}
		else if(vertical_pos2 > 37){
			
		if ((horizontal_pos >= 60 && horizontal_pos <68 && r2 & (1<<0)) || (horizontal_pos >= 44 && horizontal_pos <52 && r2 & (1<<1)) ||(horizontal_pos >= 28 && horizontal_pos <36 && r2 & (1<<2)) || (horizontal_pos >= 12 && horizontal_pos <20 && r2 & (1<<3)) || (horizontal_pos >= 0 && horizontal_pos <8 && r2 & (1<<4))){
					//Delay100ms(10);
					print_(score);
					break;
			}	
		}
		

	}
}

void print_(int score){
					Nokia5110_Clear();
					Nokia5110_SetCursor(2, 1);
					Nokia5110_OutString("GAME OVER");
					Nokia5110_SetCursor(3, 2);
					Nokia5110_OutString("score: ");
					Nokia5110_SetCursor(1, 3);
					Nokia5110_OutUDec(score);
					Nokia5110_SetCursor(3, 4);
					Nokia5110_OutString("level: ");
					Nokia5110_SetCursor(1, 5);
					Nokia5110_OutUDec(score/10);
					Delay100ms(20);
}



/*void GPIOPortF_Handler(void){
	
	if ( GPIO_PORTF_RIS_R & (1 <<4) ){   /// right
		GPIO_PORTF_ICR_R = 0x10;          
		if(horizontal_pos< 4 * CARW ) h += CARW;
}	
	else if(GPIO_PORTF_RIS_R & (1 <<0)){     /// left
		GPIO_PORTF_ICR_R = 0x01;
		if(horizontal_pos > 0) h -= CARW;
	}
	
	GPIO_PORTF_DATA_R = count_;
} 

void Delay100ms(unsigned long count){
	unsigned long volatile time;
  while(count>0){
    time = 227240;
    while(time){
	  	time--;
    }
    count--;
  }
}*/

