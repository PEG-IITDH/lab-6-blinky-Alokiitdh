 #include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#define RED_LED (1<<1)
#define SW1 (1<<4)
int main(void)
{
 while(1)
 {
 SYSCTL_RCGC2_R |= 0x00000020;; /* enable clock to GPIOF */
 GPIO_PORTF_LOCK_R = 0x4C4F434B; /* unlock commit register */
 GPIO_PORTF_CR_R = 0x01; /* make PORTF0 configurable */
 GPIO_PORTF_DIR_R = RED_LED; /* set PF1 pin as output (LED) pin */
 GPIO_PORTF_DEN_R = (RED_LED|SW1); /* set PORTF pins 4,1 as digital pins */
 GPIO_PORTF_PUR_R = 0x11; /* enable pull up for pin 4 and 0 */

 int x= (GPIO_PORTF_DATA_R &= SW1);
 if (x == 0x00)
 {
 GPIO_PORTF_DATA_R = RED_LED;
 }
 else
 {
 GPIO_PORTF_DATA_R = ~RED_LED;
 }
 }
}
