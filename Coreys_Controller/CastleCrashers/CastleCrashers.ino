
int xMap, joyX, joyY, joyZ, joyZrotate;

void setup() {
  /*
   * Setup Input IO's
   * All inputs should be set as inputs using pinMode(IO Number, INPUT)
  */
  Serial.begin(9600);
  // Button Inputs (Digital)
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT); 
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
 

  // Axis Inputs (Analog)
  pinMode(A4, INPUT);//F6
  pinMode(A5, INPUT);//F7
  pinMode(A0, INPUT);//F0
  pinMode(A1, INPUT);//F1

}

void loop() {
  /*yvalue = analogRead(A3)-100;
  xvalue = analogRead(A2)-120;
  if (yvalue<0) {
    yvalue=0;
  }
  if(xvalue<0){
    xvalue=0;
  }*/

  joyX = analogRead(A1);
  joyY = analogRead(A0);
  joyZ = analogRead(A5);
  joyZrotate = analogRead(A4);

  xMap = map(joyX, 0,1023, 1023, 0);

  
  // Read Axis inputs (Analog) and pass to Joystick lib
  Joystick.X(xMap);
  Joystick.Y(analogRead(A0));
  Joystick.Z(analogRead(A5));
  Joystick.Zrotate(analogRead(A4));
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A0));
  // Read Button inputs (Digital) and pass to Joystick lib
  Joystick.button(4, !digitalRead(0));
  Joystick.button(8, !digitalRead(1));
  Joystick.button(12, !digitalRead(2));
  Joystick.button(6, !digitalRead(3));
  Joystick.button(1, !digitalRead(4));
  Joystick.button(2, !digitalRead(5));
  Joystick.button(3, !digitalRead(6));
  Joystick.button(7, !digitalRead(11));
  Joystick.button(13, !digitalRead(12));
  Joystick.button(5, !digitalRead(14));
  Joystick.button(11, !digitalRead(15));
  Joystick.button(10, !digitalRead(18));
  Joystick.button(9, !digitalRead(19));
  Joystick.button(14, !digitalRead(22));
  Joystick.button(15, !digitalRead(23));

  //Google: Arduino X -input xbox input 

  // Set Frequency of Button checking, time = 1/F (milliseconds)
  delay(50);
}
