//Declaring variables for the pin numbers of each motor output, to keep things neat.
int right_forward = 5;
int right_reverse = 3;

//variable for the speed of the motor, an integer from 0-255.
int motor_speed = 255;

void setup() {
  /*
   * The pinMode function parameters are ("pin number" , "Type of pin, INPUT or OUTPUT")
   * The function serves to set the mode of the pin so it can output or take in a signal
   */
  pinMode(right_forward, OUTPUT);
  pinMode(right_reverse , OUTPUT);

}

void loop() {
  /*
   * Writes an analog signal to a pin, parameters are ("The pin number" , "The value of the signal")
   */

  //code to power the right motor forward. 
  analogWrite(right_forward , motor_speed);

  //code to power the right motor reverse.
  //analogWrite(right_reverse, motor_speed);
  
}
