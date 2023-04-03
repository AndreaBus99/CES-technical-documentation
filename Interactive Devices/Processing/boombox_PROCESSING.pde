
/**
 * Boombox
 *
 * Read data from the serial port to control the pitch of a song and
 * also be able to pause, play and repeat the song.
 * Library Minim needs to be installed before
 *
 */


import processing.serial.*;
import ddf.minim.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port
String inputString;

int joystickButton;
int button;
int valuePitch;

Minim minim;
Gain gain;
TickRate rateControl;
FilePlayer filePlayer;
AudioOutput out;

String fileName = "studySong.wav";

void setup() 
{
  size(3400, 1000);
  //Might have to change the number
  String portName = Serial.list()[6];
  System.out.println(portName);
  myPort = new Serial(this, portName, 9600);
  
  minim = new Minim(this);
  filePlayer = new FilePlayer( minim.loadFileStream(fileName) );
  filePlayer.loop();
  
  rateControl = new TickRate(1.f);
  out = minim.getLineOut();
  filePlayer.patch(rateControl).patch(out);
 
  filePlayer.play();
}

void draw() {

  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  }
  
  if (val!= null) {
      val = val.trim();
      int[] vals = int(split(val, ","));
      
      // Assign to variables
      valuePitch = vals[0];
      joystickButton = vals[1];
      button = vals[2];
      
      //To control the pitch with x-axis of joystick
      float rate = map(valuePitch, 0, 4095, 0.3f, 1.8f);
      System.out.println(rate);
      rateControl.value.setLastValue(rate);
      
      //To control pause/play with button
      if (button == 0) {              // If the serial value is 0,
        filePlayer.pause();
      } 
      //Release button, keep playing
      else {                       // If the serial value is not 0,
        filePlayer.play();
      }
      //Repeat from beginning if joystick button pressed
      if (joystickButton == 0) {
        filePlayer.rewind();
      }
 
  }
  
  //To display the waveform on laptop screen, code from one of the examples provided in the minim library
  
  // erase the window to black
  background( 3 );
  // draw using a white stroke
  stroke( 255 );
  // draw the waveforms
  for( int i = 0; i < out.bufferSize() - 1; i++ ) {
    // find the x position of each buffer value
    float x1  =  map( i, 0, out.bufferSize(), 0, width );
    float x2  =  map( i+1, 0, out.bufferSize(), 0, width );
    // draw a line from one buffer position to the next for both channels
    line( x1, 50  - out.left.get(i)*50,  x2, 50  - out.left.get(i+1)*50);
    line( x1, 150  - out.left.get(i)*50,  x2, 200 - out.left.get(i+1)*50);
    line( x1, 250 - out.right.get(i)*50, x2, 250 - out.right.get(i+1)*70);
    line( x1, 350 - out.right.get(i)*50, x2, 350 - out.right.get(i+1)*50);
    line( x1, 450 - out.right.get(i)*50, x2, 450 - out.right.get(i+1)*70);
    line( x1, 550 - out.right.get(i)*50, x2, 550 - out.right.get(i+1)*70);
    line( x1, 650 - out.right.get(i)*50, x2, 600 - out.right.get(i+1)*50);
    line( x1, 750 - out.right.get(i)*50, x2, 750 - out.right.get(i+1)*70);
    line( x1, 850 - out.right.get(i)*50, x2, 800 - out.right.get(i+1)*70);
    line( x1, 950 - out.right.get(i)*50, x2, 950 - out.right.get(i+1)*50);
  }
  

}
