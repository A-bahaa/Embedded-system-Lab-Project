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
		v1 = CARH, v2 = - CARH - 2 ;
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

