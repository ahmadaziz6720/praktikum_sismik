#include <mega328.h>
#include <delay.h>
void main(void) {
	int i = 0;
	//Set mode PIN D menjadi OUTPUT
	DDRD=0xff;
 
	//Set mode PIN B menjadi INPUT      
	DDRB=0x00;      
	PORTB = 0xff; // set sebagai pull up
 
 
	while (1) {
		if (!(PINB.1)) {
			delay_ms(1000);
			PORTD = ~(1 << i);
			i++;
			if (i > 7) {
				i = 0;
			}
		while (!(PINB.1)) {};
	   }
	}
}
