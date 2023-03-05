## My commute to uni: Technical documentation

Link to blog (creative documentation): https://andreabus99.github.io/2021/03/08/generative-art.html

On this project, I used an ESP32 to display some kind of generative art. I decided to display a scrolling text of my commute to uni, showing as a long
sentence the 21 stations I stop by on my way to school. 

What do you need for this project:
<li> TTGO T-Display ESP32 </li>
<li> USB-C cable </li>
<li> Platform to power on ESP32s </li>

<br>

To do this project, you will need to first install Arduino into your laptop. Also, connect your ESP32 to your laptop using an USB-C cable.
Once in Arduino, you have to load in the ESP32 boards on Preferences. 
<br>
<img width="550" alt="Screen Shot 2023-03-05 at 6 07 52 PM" src="https://user-images.githubusercontent.com/80929001/222991367-ba05a563-964f-4bc4-9616-be9e4b88f4e5.png">

Then, under Tools, you have to select the appropriate board, in our case, it is the ESP32 TTGO T1, and next select the appropriate port.
<br>
<img width="550" alt="Screen Shot 2023-03-05 at 6 09 08 PM" src="https://user-images.githubusercontent.com/80929001/222991415-6beba523-2f0a-446c-9fce-8eb81f54ac15.png">


In Manage Libraries, search for “TFT_eSPI” and install the one by Bodmer. 
<br>
<img width="331" alt="Screen Shot 2023-03-05 at 6 08 48 PM" src="https://user-images.githubusercontent.com/80929001/222991400-c6bfcc5c-ff93-4392-9148-91fbdfbfbff5.png">


Finally, load an example under File → Examples. Then you have to press update, and the code will compile and display on your device. You can play around with the different example codes, and change and adjust them to your preference. 
<br>
<img width="550" alt="Screen Shot 2023-03-05 at 6 10 50 PM" src="https://user-images.githubusercontent.com/80929001/222991457-5857e879-c36e-49d5-acab-72776d2f791f.png">

Once you have your generative art ready and already flashed in your ESP32, you can connect it to the platform that will power it. 
<br>
<br>
Note: we were supposed to use a battery to power on our devices, however our batteries were not working as intended so this is why we ended up using a
platform for powering on the devices.
<br>
<br>
Here are some pictures of the final installation!

![IMG_2512](https://user-images.githubusercontent.com/80929001/222992252-d5f536fe-f73c-4bfb-8054-c88c1b431129.jpg)

![IMG_2752](https://user-images.githubusercontent.com/80929001/222992262-29905a46-69b8-4927-83ba-caf8e2e20125.jpg)

