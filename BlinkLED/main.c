 #include<stdint.h>
#include<stdbool.h>
#include"tm4c123gh6pm.h"
int main(void)
{
 int i=0;
 SYSCTL_RCGCGPIO_R |= (1<<5); /* enable clock to GPIOF */
 GPIO_PORTF_LOCK_R = 0x4C4F434B; /* unlock commit register */
 GPIO_PORTF_CR_R = 0x01; /* make PORTF0 configurable */
 GPIO_PORTF_DIR_R = 0x0E; /* set PORTF2 pin as output (LED) pin */
 GPIO_PORTF_DEN_R = 0x1F; /* set PORTF pin 2 as digital pins */
 GPIO_PORTF_PUR_R = 0x11; /* enable pull up for pin 4 and 0 */
 while(1)
 {
 for(i=0; i<1600; i++)
 {
 if( i<800)
 GPIO_PORTF_DATA_R = 0x2;
 else
 GPIO_PORTF_DATA_R = 0x0;
 }
 }
}
