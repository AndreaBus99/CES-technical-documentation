/**
 * Simple Read
 * 
 * Slightly Modified from the Serial Example provided through the Ardunio IDE
 *
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port

void setup() 
{
  String portName = Serial.list()[6];
  System.out.println(portName);
  myPort = new Serial(this, portName, 9600);
}

