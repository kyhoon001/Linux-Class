import RPi.GPIO as GPIO
import time

LED,SW = 18,4
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED,GPIO.OUT)
GPIO.setup(SW, GPIO.IN,pull_up_down = GPIO.PUD_DOWN)

print("Press the button")

while True : 
    GPIO.output(LED,False)
    if GPIO.input(SW)==GPIO.HIGH:
        print("Button pressed!")
        GPIO.output(LED,True)
        time.sleep(1)
        print("Press the button (CTRL-C to exit)")
GPIO.cleanup()


