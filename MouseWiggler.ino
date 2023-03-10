/*
Pressing a button turns on onboard LED (pin 13) and starts servo motor running a back and forthe cycle.
Pressing the button again turns off the LED and stops the servo.
*/

/* power management values */
int powerState = 'off';

/* servo values */
#include <Servo.h>
Servo myservo;  // designates name for servo object
int pos = 0;        // set starting position
int direction = 'up';

/* button values */
#define BUTTON_PIN 7
int buttonState = LOW;

/* led values */
#define LED_PIN 13


void setup() {
  myservo.attach(9);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);      // check if button is pressed and switch power

    if (buttonState == HIGH && powerState == 'off') {
      powerState = 'on';
      else if (buttonState == HIGH && powerState == 'on') {
        powerState = 'off';
      }
    }
    if (powerState = 'on')  {         // if ON turn on LED and step Servo
      digitalWrite(LED_PIN, HIGH);
      runServo();
    } 
}

runServo() {        // alternate direction servo goes but flopping pos change up and down
  if (direction == 'up' && pos ,= 45) {
    pos++;
    myservo.write(pos);
  }
  else if (pos == 45) {
    direction = 'down';
    myservo.write(pos);
  }
  else if (direction == 'down' && pos >= 0) {
    myservo.write(pos);
  }
  else if (pos == 0)  {
    direction = 'up';
    myservo.write(pos);
  }
}




  /* 
  int buttonState != digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN, ledState);

      for (pos = 0; pos <= 45; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos =45; pos >= 0; pos -= 1) { 
        myservo.write(pos);              
        delay(15);                       
      }
    }
  }
}
*/
