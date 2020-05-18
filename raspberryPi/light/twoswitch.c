#include <stdio.h>
#include <wiringPi.h>

#define LED 1
#define KEY 7
#define STOP 2


int main(int argc, char ** argv)
{
	wiringPiSetup();
	pinMode(LED,OUTPUT);
	pinMode(KEY,INPUT);

	int pressed;
	int ex;

	int l = 0;
	printf("start..\n");
	digitalWrite(LED,LOW);
	while(1) {
		pressed = digitalRead(KEY); 
		ex = digitalRead(STOP);
		if(pressed == HIGH) {
			printf("Key pressed!!\n");
			if(l == 0) {
				l = 1;
				digitalWrite(LED,l);
			}
			else {
				l = 0;
				digitalWrite(LED,l);
			}
		}

		delay(200);
		if(ex == HIGH) {
			printf("exit this program\n");
			break;
		}
	
	}
	return 0;
}









