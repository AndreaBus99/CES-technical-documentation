## The Boombox: Technical documentation

Link to blog (creative documentation): https://andreabus99.github.io/2023/04/01/interactive-devices.html

On this project, I created a device that interacts with a laptop by sending data for both visualization and sonification. 

What do you need for this project:
<li> TTGO T-Display ESP32 </li>
<li> USB-C cable </li>
<li> Breadboard </li>
<li> Joystick </li>
<li> Button </li>
<li> 4 female to male wires </li>
<li> 2 male to male wires </li>

<br>
(The wires are up to you, but this is what I used).
<br>

<h3> Hardware set up </h3>
Let’s start with getting your ESP32 into your breadboard. Then we will have to connect the joystick to the ESP32. For this project, we are going to use the x-axis and the z-axis. Using your female-to-male wires, map the x-axis to pin #17 and the z-axis to pin #21 (from the joystick to the breadboard location of the ESP32). You do not need to specifically use these pin numbers, however, if you change them you will have to change line 1 of the Arduino code to match the numbers. Finally, also connect 5V and Ground from the joystick to the ESP32. 
<br>
Now, let’s connect the button. The button has to be in the middle of the breadboard. Connect one side of it to pin #25 of the ESP32 and the other to Ground. You should be all set up on the hardware part of this project. This is how it should look:
<br>
<br>
<img width="350" alt="Screen Shot 2023-04-03 at 6 21 51 PM" src="https://user-images.githubusercontent.com/80929001/229639945-bdfe49a6-0501-41b7-a0b7-cfabb666f0ed.png">


<h3> Software set up </h3>
From a software perspective, please download both the Arduino code and the Processing code (make sure also to download the song). Once you have the Arduino code opened, flash it into your ESP32. Make sure that the port is the correct one. Open the serial monitor to check that the output that you are getting is correct (i.e. try pressing the button and see if the last number changes from 1 to 0). If you run into any issues, try changing the pin numbers or sometimes the wires can be defective. 
<br>
Now, open the Processing file. Ensure that the song's file is in the same folder as the code. Once you are in Processing, go to Sketch → Import Libraries → Manage Libraries and then search for Minim and install it. You might have to close Processing and start it again. Finally, before running the file, make sure that the serial monitor window is closed in Arduino, then you are good to run the code! Change the pitch using the joystick, pause the song by holding the button, and repeat the song from the beginning by clicking the button of the joystick. You have successfully created a serial port connection between Arduino and Processing! Essentially, what it does is that it connects through the same serial port; the Arduino file sends analog and digital signals of the joystick and button to the Processing file to then map them to change the sonification.

<h3> How it works </h3>
To control the pitch of the song, manipulate the joystick moving it up and down. As you move the joystick upwards you will get a higher pitch output, as you move it down, you will get a lower pitch noise. If you want to repeat the song, simply press the joystick. If you want to pause, press and hold the button. The waveform at the moment created will be displayed in your screen. Have fun!

<h3> Technical difficulties </h3>
A hardware project will always have bumps along the way. One problem I had was that the y-axis pin for my joystick stopped working. I had planned that the y-axis would be able to fast-forward and backward in the song. However, something happened in the last few days before the assignment was due, and the y-axis pin was not getting any input. This is a lesson to be careful where you store your hardware. To solve this, I instead made use of the z-axis (the button of the joystick) and made it able to repeat the song once pressed. 
As for software difficulties, I had a hard time achieving control over the pitch. It seems that for the pitch instead of using AudioPlayer, you need to use AudioOutput from the minim library. So you are not actually controlling the input song, but the output. However, I finally found an example in the Minim library that went over this. 
<br>
<br>
<img width="1164" alt="Screen Shot 2023-04-03 at 6 40 23 PM" src="https://user-images.githubusercontent.com/80929001/229642275-f1209ef2-275e-4878-b8fe-e9334151fb16.png">
<img width="1146" alt="Screen Shot 2023-04-03 at 6 39 45 PM" src="https://user-images.githubusercontent.com/80929001/229642218-75b259bb-88a8-4c06-b7e2-7f01382b1f66.png">
