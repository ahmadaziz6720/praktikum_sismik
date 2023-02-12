#include <mega328.h>
#include <delay.h>
int i;
void main(void) {
	//Set mode PIN D menjadi OUTPUT
	DDRD=0xff;
	while (1) {
	    for (i = 0; i < 8; i++) {
			PORTD = (1 << i);
			delay_ms(1000);
	    }
	}
}