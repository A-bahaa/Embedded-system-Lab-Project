#include "gpio.c"
#include "race.c"

void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count);

int main(void){
    PortF_Init();
    EdgeCounter_Init();           // initialize GPIO Port F interrupt
    TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
    Random_Init(1);
    Nokia5110_Init();
		v1 = CARH, v2 =  CARH - 24 ;
		h = 32;
		r1 = 1;
		r2 = 3;
		x = 0; 
	
  while(1){
		if(v1 > 48) x ++,r1 = rand ()%31, v1 = 0;  // for new random number and restart
		if(v2 > 48) x ++,r2 = rand ()%31, v2 = 0;  // for new random number and restart
			Enemies(h,v1,v2,r1,r2);
		
			v1 += ((x/10) + 2); 
		  v2 += ((x/10) + 2); 
			Delay100ms(1);
		
		
		if(v1 > 37){
		
			if ((h == 48 && r1 & (1<<1)) ||(h == 32 && r1 & (1<<2)) || (h == 16 && r1 & (1<<3)) || (h == 0 && r1 & (1<<4))|| (h == 64 && r1 & (1<<0))){
				
					//Delay100ms(10);
					Nokia5110_Clear();
					Nokia5110_SetCursor(2, 1);
					Nokia5110_OutString("GAME OVER");
					Nokia5110_SetCursor(3, 2);
					Nokia5110_OutString("score: ");
					Nokia5110_SetCursor(1, 3);
					Nokia5110_OutUDec(x);
					Nokia5110_SetCursor(3, 4);
					Nokia5110_OutString("level: ");
					Nokia5110_SetCursor(1, 5);
					Nokia5110_OutUDec(x/10);
					Delay100ms(20);
					break;
		}
	}
		else if(v2 > 37){
			
		if ((h == 48 && r2 & (1<<1)) ||(h == 32 && r2 & (1<<2)) || (h == 16 && r2 & (1<<3)) || (h == 0 && r2 & (1<<4))|| (h == 64 && r2 & (1<<0))){
					//Delay100ms(10);
					Nokia5110_Clear();
					Nokia5110_SetCursor(2, 1);
					Nokia5110_OutString("GAME OVER");
					Nokia5110_SetCursor(3, 2);
					Nokia5110_OutString("score: ");
					Nokia5110_SetCursor(1, 3);
					Nokia5110_OutUDec(x);
					Nokia5110_SetCursor(3, 4);
					Nokia5110_OutString("level: ");
					Nokia5110_SetCursor(1, 5);
					Nokia5110_OutUDec(x/10);
					Delay100ms(20);
					break;
			}	
		}
		

	}
}
