int xyzPins[] = {13, 17, 21}; //x,y,z pins

void setup() {
  Serial.begin(9600);
  pinMode(xyzPins[0], INPUT_PULLUP); //x axis controls pitch.
  pinMode(xyzPins[1], INPUT_PULLUP); //y axis controls volume (not working)
  pinMode(xyzPins[2], INPUT_PULLUP); //z axis is a button to repeat song.
  pinMode(25, INPUT_PULLUP); //button to pause and play
}
void loop() {

  //For joystick
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  //We print the data separated by comas: x,z,b
  //In the Processing we will split these and assign them to variables in order to manipulate them
  Serial.print(xVal, DEC);
  Serial.print(",");
  // Serial.print(yVal, DEC);
  // Serial.print(",");
  Serial.print(zVal, DEC);
  Serial.print(",");

  // For button
  int buttonVal = digitalRead(25);
  Serial.print(buttonVal, DEC);
  // Print a new line so that it is easier to get the data
  Serial.print('\n');
  delay(100);
  
}

