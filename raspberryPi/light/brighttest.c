#include <stdio.h>
#include <wiringPi.h>

#define LED2 1



int main(int argc, char ** argv)
{
	wiringPiSetup();
	pinMode(LED2,PWM_OUTPUT);
	digitalWrite(LED2,LOW);
	int b = 0;

	while(1) {
		for(b = 0; b < 1024; ++b) {
			pwmWrite(LED2,b);
			delay(50);
		}
		for(b = 1023; b >= 0; --b) {
			pwmWrite(LED2,b);
			delay(50);
		}
	}




	return 0;



}
