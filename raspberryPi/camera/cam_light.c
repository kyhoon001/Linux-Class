#include <wiringPi.h>
#include <stdio.h>


#define CDS 7
#define LED 1

int cdsControl()
{
	int i;

	pinMode(CDS,INPUT);
	pinMode(LED,OUTPUT);

	for(int i = 0; i < 10000000; i++) {
		if(digitalRead(CDS) == LOW) {
			printf("Lights...: %f\n", analogRead(CDS));
			digitalWrite(LED,HIGH);
			delay(200);
			digitalWrite(LED,LOW);
			delay(200);
		}
		else {
			printf("No light...\n");
			delay(200);
		}
	};

	return 0;
}



int main(int argc, char** argv) {
	wiringPiSetup();
	cdsControl();
	return 0;
}
