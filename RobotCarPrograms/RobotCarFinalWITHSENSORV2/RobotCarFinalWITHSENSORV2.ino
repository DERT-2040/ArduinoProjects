// ping sensor
#include <StandardCplusplus.h>
#include <vector>
const int pingPin = 2;
int dist_in_cm = 100; // pick a high number to start
int power_turn_level = 255; /* power on turns */

// adjust these till the robot goes streight to compensate for motor differences
int power_forward_right = 255; 
int power_forward_left = 255; 
int test_delay = 500;

// motor pins.  N;ote that only pins 2,5,6,9 and 10 can be used for pwm
int right_forward = 3;
int right_reverse = 5;
int left_forward = 6;
int left_reverse = 9;

int echo = 10;
int trig = 2;

std::vector<double> rollingAverage;


// try this time to make a right turn just above 90 degrees
int delay_time_ninty_turn = 100;
// if we are under this distance, make a turn.  For higher power, make this larger
int cm_for_turn = 35;
int delay_time_forward = 100;

void setup() {
  
  Serial.begin(9600);
  pinMode(pingPin, INPUT);
  
  pinMode(right_forward, OUTPUT);
  pinMode(right_reverse, OUTPUT); 
  pinMode(left_forward, OUTPUT); 
  pinMode(left_reverse, OUTPUT);
  pinMode(echo , INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
    
  // get the distance from the ping sensor in CM  
  // if there is something in front, turn right
  
  dist_in_cm = get_distance_cm();
  if (dist_in_cm < cm_for_turn) {
      turn_right();
    } else {
      move_forward();
    }


  
  Serial.print("distance cm=");
  Serial.print(dist_in_cm);
  
}

void turn_right() {
  Serial.println("turning right");
  analogWrite(right_forward, LOW);
  analogWrite(right_reverse, power_turn_level);
  analogWrite(left_forward, power_turn_level);
  analogWrite(left_reverse, LOW);
  delay(delay_time_ninty_turn);
}

void move_forward() {
  Serial.println("moving forward");
  analogWrite(right_forward, power_forward_right);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, power_forward_left);
  analogWrite(left_reverse, LOW);
  delay(delay_time_forward);
}


int get_distance_cm()
{
  long duration = 0;
  long cm=0;
  int average = 0;
  /*
  for(int i = 0; i < 4; i++)
  {
    duration = 0;
    digitalWrite(trig, LOW);
    digitalWrite(trig, HIGH);
    //delayMicroseconds(1);
    duration = pulseIn(echo, HIGH);
    cm += microsecondsToCentimeters(duration);
  }
  cm = cm/4;
  */
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);
  rollingAverage.push_back(cm);
  if(rollingAverage.size() > 2)
  {
    rollingAverage.erase(rollingAverage.begin()); 
  }
  for(int i = 0; i < rollingAverage.size(); i++)
  {
    average += rollingAverage[i];  
  }
  average = average/rollingAverage.size();
  Serial.print("average = ");
  Serial.println(average);
  return average;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

