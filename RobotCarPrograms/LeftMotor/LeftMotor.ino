//Declaring variables for the pin numbers of each motor, to keep things neat.
int left_forward = 6;
int left_reverse = 9;

//variable for the speed of the motor, an integer from 0-255
int motor_speed = 255;

void setup() {
  /*
   * The pinMode function parameters are ("pin number" , "Type of pin, INPUT or OUTPUT")
   * The function serves to set the mode of the pin so it can output or take in a signal
   */
  pinMode(left_forward, OUTPUT);
  pinMode(left_reverse, OUTPUT);
}

void loop() {
    /*
   * Writes an analog signal to a pin, parameters are ("The pin number" , "The value of the signal")
   */

   //code to power left motor forward.
   analogWrite(left_forward, motor_speed);

   //code to power left motor backwards
   //analogWrite(left_reverse, motor_speed);
}
