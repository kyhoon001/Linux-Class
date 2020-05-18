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

	printf("start..\n");
	while(1) {
		pressed = digitalRead(KEY); 
		ex = digitalRead(STOP);	
		if(pressed == HIGH) {
			printf("Key pressed!!\n");
			for(int i = 0; i < 3; i++) {
				digitalWrite(LED,HIGH);
				delay(500);
				digitalWrite(LED,LOW);
				delay(500);
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









