//Declaring variables for the pin numbers of each motor, to keep things neat.
int right_forward = 0;
int right_reverse = 0;
int left_forward = 0;
int left_reverse = 0;

//variable for the speed of the motor, an integer from 0-255
int motor_speed = 0;

void setup() {
  /*
   * The pinMode function parameters are ("pin number" , "Type of pin, INPUT or OUTPUT")
   * The function serves to set the mode of the pin so it can output or take in a signal
   */
  pinMode(0, 0);
  pinMode(0, 0);
  pinMode(0, 0);
  pinMode(0, 0);  
}

void loop() {
  /*
   * Writes an analog signal to a pin, parameters are ("The pin number" , "The value of the signal")
   */
  analogWrite(0, 0);
  analogWrite(0, 0);;
}


