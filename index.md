# Table of Contents

- General announcements
  - [Introduction](#introduction)
  - [Piazza Forum](#piazza-forum)
- Lab Activities
  - [Lab 1: Circuits and GPIO Control with Arduino](#lab-1-circuits-and-gpio-control-with-arduino)
  - [Lab 2: X-mas lights with Arduino](#lab-2-x-mas-lights-with-arduino)
  - [Lab 3: X-mas lights with Arduino, Part 2](#lab-2-x-mas-lights-with-arduino-part-ii)
  - [Lab 4: Assemble Your Kit](#lab-4-assemble-your-kit)
  - [Lab 5: Seriasl Communication and IF Statement](#lab-5-serial-communication-and-if-statements)
  - [Lab 6: Parsing Serial Data](#lab-6-parsing-serial-data)

# Piazza Forum

We've created an online space for you to ask questions and for help at any time! Sign up for the class Piazza page at [https://piazza.com](https://piazza.com) . Sign up for an account and search for the school MIAO and add the class with access code ARD160.

# Lab 6: Parsing Serial Data

Parsing will become an extremely important concept for all of your programming and electronic projects. Parsing is the idea that we will send some data from one place to another, then be able to read and break that data apart into meaningful items. Let’s make an example to make it clear:
We have this data:
```
	Acceleration due to gravity = 3.7 m/s^2
	Time spent falling = 33 seconds
```
We saw that in Lab 5 we could enter in the time spent falling and read it into a variable in the Arduino from the serial monitor. Now we need to read 2 numbers into two variables!!! We need to read the time into the time variable and read the acceleration due to gravity into another variable. <br>

This is very important when getting one device to send data to another device. Often you will have to send many different pieces of information. Parsing gives us a way to send many values at once then pull them apart. We will use this same protocol later when we combine the Raspberry PI with the Arduino to issue commands to the Arduino so take good notes. <br>

_**Note: Which planet do you think are we talking about here? How can you tell? Is it bigger or smaller than earth?**_ <br>

We will build upon our previous work from homework 4 where you built a program to determine the velocity and distance after falling so many seconds.
Recall the program from homework 4:

``` c
void setup() {

 //OPEN SERIAL COMMUNICATIONS
Serial.begin(9600);
}
void loop() {

  //DECLARE YOUR VARIABLES
  float time_spent_falling = 3; //seconds
  float acceleration_due_to_gravity = 9.8; //m/s^2
  float velocity; //m/s
  float distance; // m
  //CALCULATE VELOCITY
  velocity = acceleration_due_to_gravity * time_spent_falling;
  //CALCULATE DISTANCE
  distance = acceleration_due_to_gravity * time_spent_falling * time_spent_falling / 2;
  //PRINT OUT CALCULATED VALUES
  Serial.print("Velocity is: ");
  Serial.println(velocity);
  Serial.print("Distance is: ");
  Serial.println(distance);
  //DELAY FOR A LITTLE WHILE BEFORE PRINTING VALUES AGAIN
  delay(2000);
}
```

Now we want to modify this to be able to dynamically enter in both acceleration due to gravity and the time falling through the serial monitor. We will use the following template which will be the same template you will use from now on when receiving multiple values from the serial port to the Arduino.

```c
  bool DEBUG = true;  // change to true/false to turn printing on/off
  while (Serial.available()) {
    String line = Serial.readStringUntil('\r');
    if (DEBUG) Serial.println(line);
    //sample string acceleration_due_to_gravity?time_spent_falling?ding
    if (line.endsWith("ding"))    //YOUR ENTRY SHOULD END WITH ding
    {
      //THIS IS DEBUG OUTPUT...CHANGE 1 TO 0 TO STOP IT FROM PRINTING
      if (1)
      {
        Serial.println("*************RECEIVED DATA**************");
        Serial.println("parsing....");
      }
      //using strok_r() to parse the incoming TCP message
      //pointers to store temporary locations of parsed variables
      char linebuf[100];
      char *one, *two;
      line.toCharArray(linebuf, 100);
      one = strtok(linebuf, "?");
      acceleration_due_to_gravity = atof(one);           //MODIFY THIS LINE TO STORE THE FIRST ENTRY INTO A VARIABLE USE atoi(one) for integer and atof(one) for a float
      one = strtok(NULL, "?");                            //COPY AND PASTE THIS LINE AND THE FOLLOWING LINE FOR EVERY ADDITIONAL PARAMETER NEEDED
      time_spent_falling = atof(one);
      //THIS IS DEBUG OUTPUT...CHANGE 1 TO 0 TO STOP IT FROM PRINTING
      if (1) {
        Serial.println("Parsed String:  ");
        Serial.print("acceleration_due_to_gravity: \t");
        Serial.println(acceleration_due_to_gravity);
        Serial.print("  time_spent_falling: \t");
        Serial.println(time_spent_falling);
        Serial.println("*****************************************************");
      } // end DEBUG
    }
  } // end while client.available

```

## LAB ASSIGNMENT
Use the code above to modify your velocity and distance code to be able to take in both variables from the serial monitor program. (hint: if your acceleration due to gravity is 5.4 m/s^2 and time falling is 3 seconds your string should look like “5.4?3?ding” entered into the serial monitor.

## HOMEWORK ASSIGNMENT - Walk signal
Modify the circuit from Lab 2 to use only 2 LEDs. Choose 2 LEDs of different colors. Your job is to create the timing controller for a walk signal. It should have the following sequence.
LED 1 - on for a specified time (time1)  then turns off
LED 2 - starts flashing after LED 1 turns off and flashes with a specified interval (interval1) for a specified number of flashes (flash1)
LED 2 - stays on solid for a specified time (time2) then turns off
REPEAT FROM LED 1
Your program should use the serial interface and the code used for the lab exercise to take in values for (time1, interval1, flash1, and time2).
Consider using a “for” loop for flashing LED 2. See lab 2 for your reference to for loops. Remember to take good notes in your lab notebook to record progress or problems.



# Lab 5: Serial Communication and IF Statements

When working with any device, it is very important to consider how you will interact with it. Will it require human input? Will it need to communicate with another device. In this laboratory we will learn the basics of Serial communication which is the primary means that we will be communicating with our Arduinos for the rest of the activities.

First we need to cover some background about types. In many programming languages including the C programming language whenever you create and declare a variable, you need to specify the type of variable that you will be using.

|Type   |Description    | Code  |
|---|---|---|
| Integer  | A positive or negative whole number  | int <variable name>  |
| float  | A decimal representation of a number  | float <variable name>  |
| char  | Any character   | char <variable name>  |
| String  |A string of characters   |String “<variable name>”   |

In this lab we will continue from the homework assignment that you had completed from last night. Now we will add the portion for a human input. We will be using the serial monitor on the Arduino IDE program to input a string to your program and use the input for processing.

In your program, you used:

```c
float t = <number of seconds>;
```

We will be using the following two commands to enable you to receive data from the Serial Monitor. We will briefly cover If statements and you will use them for homework assignments.

We will use this command to receive Serial Communications from the serial monitor.

[https://www.arduino.cc/en/Serial/ReadString](https://www.arduino.cc/en/Serial/ReadString)

Input from the Serial monitor will come in as a string, we want to convert it to a float using this command

[https://www.arduino.cc/en/Tutorial/StringToFloatExample](https://www.arduino.cc/en/Tutorial/StringToFloatExample)

In our exercise we will now use the serial monitor to input time into your program and have it process and give you an output.


## HOMEWORK

For your homework read the instructions on IF statements:

[https://www.arduino.cc/reference/en/language/structure/control-structure/if/](https://www.arduino.cc/reference/en/language/structure/control-structure/if/)

Use an if statement to tell you YES as an output on your serial monitor. if your speed after falling is over 120 meters/second and NO if it is not.

## ADVANCED

We will give you several LEDs. Use the DigitalWrite function:

[https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)

Using the LEDS create a program that will take a time input in seconds and light up a specific number of LEDS depending on how fast you are travelling after falling. More LEDs if you are falling faster. Use the same LED circuit set up as in Lab 2.

# Lab 4: Homework

## Explore C program creation and compilation.

**Task:**

Given the time an object falls,in seconds, compute the velocity of the object when it hits the ground using: <br>
`velocity = g * time`

and the distance it fell using:  <br>
`distance = g * t * t / 2`

**Use the arduino to accomplish your task.**

You will just use a static float assignment to enter the time like this: <br>

`	float time = 2.3;`

Or whatever time is required


# Lab 4: Assemble Your Kit


## LABORATORY NOTEBOOK

A lab notebook is one of the most important tools you will have in your journey into programming and electronics. Keeping good notes will save you time and trouble. The lab notebook is where you will write down important information about your projects. Many times, you will have a problem that will need to be solved in electronics or programming which is very similar to one you had already solved before. If it has been a while since you solved the problem the last time, you might not remember exactly how you did it. This is where your lab notebook comes in handy.
As you write your lab notebook, keep this at the forefront of your mind when you take notes. Think about all of the effort you took to solve this problem that you are currently facing and how you wouldn’t have to go through all that effort again if you come across it next time. You will be tempted to cut corners thinking that you will remember and don’t need to write it all down but in time you will see when you are looking back through your notes what you need and what you don’t need.
The other use for a lab notebook is for others to look at and figure out what you did. A good lab notebook will be able to convey all of the information about a project in a way that others would be able to follow it and repeat what you did.


## PROJECT ASSIGNMENT

Each of you will be given a laboratory notebook. It will be your job to keep good notes in your notebook so that it can help you to complete your tasks. We are going with pencil and paper, but there are other tools like Microsoft OneNote that you can use which you can cut and paste screenshots, code, and other images into. Start with pen and paper. You can move to something digital later when you feel comfortable with the process. Oftentimes, even with a digital notebook, I still keep the handy pen and paper around.

Write your name on the notebook cover and put the date it was started
Reserve the first 3 pages for the table of contents...label the top of the page as table of contents
Number the pages in the upper right hand corner so you can quickly find where the information in your notebook is

## GENERAL FORMAT

Title at top of page
Description of the project objectives
Any problems that you encountered and how you fixed it
Results of the project
Instructions about how to use the products you created in your project
Create a table of contents entry in the front of your notebook

## MAIN TOOLS AND WORKFLOW MOTIVATION

In most of your upcoming assignments, we have chosen to use what we as a commercial laboratory have found most useful in creating real commercial projects. These tools combine areas of coding with electronics in order to create hardware solutions from robotics to distributed sensors and even big data.

What we have found is that there are two main hardware components which are essential to creating effective devices. These are the single board computer (SBC) and the microcontroller (MCU).  The SBC is an entire computer in a small board. It contains a whole operating system which makes it easy to connect to the internet and communicate with using various networking methods. It is also good at adding visualization and serving as a hub for your devices needs. It is not so good at controlling pins directly or real time controls because it requires a lot of overhead for the operating system processes. For this reason we use an MCU which is a bit harder to program but it is very good at fast operations which require real time actions.

The single board computer will be your Raspberry PI.

In this exercise we will learn how to install the operating system onto the raspberry pi. This will serve us later when we start using the device.
Use the documentation from the Raspberry PI organization to install Raspbian Jessie with desktop onto an SD card. This SD card will hold the operating system for the Raspberry PI.

https://www.raspberrypi.org/documentation/installation/installing-images/

INSTALLING OPERATING SYSTEM IMAGES
This resource explains how to install a Raspberry Pi operating system image on an SD card. You will need another computer with an SD card reader to install the image.
We recommend most users download NOOBS, which is designed to be very easy to use. However, more advanced users looking to install a particular image should use this guide.

**Download the image**

Official images for recommended operating systems are available to download from the Raspberry Pi website Downloads page.
Alternative distributions are available from third-party vendors.
If you're not using Etcher (see below), you'll need to unzip .zip downloads to get the image file (.img) to write to your SD card.
Note: the Raspbian with PIXEL image contained in the ZIP archive is over 4GB in size and uses the ZIP64 format. To uncompress the archive, a unzip tool that supports ZIP64 is required. The following zip tools support ZIP64:

- 7-Zip (Windows)
- The Unarchiver (Mac)
- Unzip (Linux)

**Writing an image to the SD card**

You will need to use an image writing tool to install the image you have downloaded on your SD card.
Etcher is a graphical SD card writing tool that works on Mac OS, Linux and Windows, and is the easiest option for most users. Etcher also supports writing images directly from the zip file, without any unzipping required. To write your image with Etcher:
Download Etcher and install it.
Connect an SD card reader with the SD card inside.
Open Etcher and select from your hard drive the Raspberry Pi .img or .zip file you wish to write to the SD card.
Select the SD card you wish to write your image to.
Review your selections and click 'Flash!' to begin writing data to the SD card.

After installing Jessie into the PI place the completed SD card into the device as shown.

Now the device is a complete linux computer. Attach a screen via HDMI and a keyboard and mouse and you are ready to start programming!!! Next we move onto the Arduino which will be the majority of the beginning lessons in programming.


## ASSEMBLE YOUR NANO

We will be following the tutorial on soldering your MCU together from the instructables page:
http://www.instructables.com/id/Solder-Arduino-Header-Pins-Easily/

While I have seen and tried many methods of soldering header pins, this is the most basic, yet best way to solder them. Feel free to adapt, modify, or add to this method in any way. :)

Materials required:
- Header pins
- Breadboard (Tip: Do not use this a bread cutting board. Don't ask.)
- Tinned soldering iron
- Solder
- Flux Pen (Optional, or use regular flux)
- Helping hands/magnifying glass (Optional)
- Patience (Not optional)

That's it, be prepared to have your mind blown in a very simplistic way.

### Step 1: Set Up and Flux

Carefully dump the contents of what you want to solder onto a soft surface. Picking out the header pin from the pile, place them into the breadboard apart the width of your PCB. For my Arduino nano it was 3 slots, plus the middle gap. The next step is to flux the pins and the board, while this is completely optional I would recommend it.

### Step 2: Solder

This is fairly self explanatory, but place the soldering iron on one side of the pin, and the solder on the other. once the pin has warmed up for a second or two, the solder will melt and wick around the pin and the board. If this is not happening there are several possible causes:
Tip not tinned properly
Tip is baked (A soldering iron should not be left on for long periods, a replacement is required)
The iron is not getting hot enough
Solder is not meant for electrical.

### Step 3: Soldering the Pins on Reverse

This step is a bit tricky, but once one or two pins are soldered it becomes much easier. Not it will be different for every board, but you have to make sure your board is flat and lined up with the pins. Arduino nano boards have mini usb on the top, so when soldering the back you have to make sure it does not interfere. To do so pull the pins slightly out from the breadboard until the gap is bridged. See the photos for better explanation.

### Step 4: Good Job!

Good job! You just soldered your first (Maybe) set of header pins. Will I have done this more than a few times, I am no where near a professional, in fact I am somewhat of an amateur. So If I can do it, so can you. It takes around 5 minutes, so go for it!


# Lab 3: X-mas lights with Arduino, Part II

In the previous lab, we looked at using multiple LEDs and explored the concept of `while` and `for` loops to make our coding life easier. We saw that the for-loop is really just a special case of the while loop that's great when we know how many times we want to run the loop.

Today, we will continue with control loops and will also look at using the [NeoPixel](https://www.adafruit.com/category/168) RGB LED strip. RGB LEDs are special LEDs because they can light in red, green, and blue at the same time. We can either only display one color, or a combination of two or three colors. By mixing the red, green, and blue color intensities, we can in fact create any color we want. We can represent the intensity of each color using a number between 0 and 255.

To try this out, go to [http://www.color-hex.com/color/](http://www.color-hex.com/color/), and type `rgb(71, 178, 67)` into the input box. Which color will this give you? Try generating 3-5 interesting colors and write down their `rgb()` values.

## Connecting the NeoPixel

The NeoPixel has three pins: `5V`, `GND`, and `SIGNAL`. You can connect them to your Arduino as shown below using any of the 13 digital pin on the Arduino for your `SIGNAL` pin. Because of the large number of LED's, it is better to connect `5V` and `GND` from an external `5V` supply, if available. Why do you think that is?

![Arduino to NeoPixel](images/lab3/uno-neopixels.png)


## Coding the NeoPixel

**Adding the NeoPixel Library**<br>
Before we can get started with the actual coding, we need to install a library that makes it easier to control the NeoPixel. An Arduino library is a set of functions, tools, that make your life easier.

To install the NeoPixel library, go to `Manage Libraries` and search for `NeoPixel`. You should see the Adafruit NeoPixel library as shown in the images below.

![NeoPixel Library 1](images/lab3/neo_add_library1.png)

![NeoPixel Library 2](images/lab3/neo_add_library2.png)

**Running the Example Code**<br>
To get started and see how to use the `NeoPixel library`, we are going to look at the `simple` example program, as shown in the two images below. You want to make sure to change the number highlighted in yellow to match the pin that you're connected to on the Arduino, and the number of LED's on your `NeoPixel`.

![simple code 1](images/lab3/simple_1.png)

![simple code 2](images/lab3/simple_2.png)

**How does the Example Code Work?**<br>

Looking at the `void loop()` program, how is the NeoPixel being controlled? Ask yourself the following,
1. How is each pin being addressed?
2. How do we set the color of each pin?

Here is the reference code:
```c
void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}
```

Ok, so the first thing to notice here is the for loop. Using the for loop and naming our counter variable `i`, we can easily address each LED `i` when running the loop. <br>
Next, we see that we can set the color of each pixel using the `pixels.setPixelColor()` command. This one takes two arguments: the led number `i` and the RGB color `pixels.Color(0,150,0)`. You can change the the three numbers to change the color. <br>
In order to update the LED, we say `pixels.show()`. What does the delay do here? Experiment with it by changing it and observing the behavior.

**Your Turn: Create your Own Christmas Lights**

Now that you know how to connect the NeoPixel, and how to set the color of each LED using for loops, what patterns can you come up with?

Here are some inspirations for you:

- [Exmaples](https://www.youtube.com/watch?v=POV-qvEx1ws)
- [Outdoor lights](https://www.youtube.com/watch?annotation_id=annotation_581560751&feature=iv&src_vid=IXbUM5VZqX8&v=YKY-t6-V_8E)
- [Ping Pong Balls](https://www.youtube.com/watch?v=XTa9Qhpohms)

# Lab 2: X-mas lights with Arduino

Today we will explore some fundamental programming concepts of loops and conditionals and apply them to LED lightings. Using the hardware setup shown below, how can you arrange and control them in your own way?

![LED schematic](images/lab2/lab2_12led_breadboard.png)

## Coding without loops

Imagine you want to control all 12 LEDs that you have wired up. Can you guess how much typing it would take to control each one using just basic coding that we used last time? Well, take a look at the code below, copy it to your Arduino IDE, and then try adding to it to make the LED's blink backwards from 12 to 1. What do you think, is there an easier way? How would you make this program better?

```c
int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int led_4 = 5;
int led_5 = 6;
int led_6 = 7;
int led_7 = 8;
int led_8 = 9;
int led_9 = 10;
int led_10 = 11;
int led_11 = 12;
int led_12 = 13;

void setup() {
  // set communication with the computer
  Serial.begin(9600);

  // set the pins as output pins
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);

  pinMode(led_9, OUTPUT);
  pinMode(led_10, OUTPUT);
  pinMode(led_11, OUTPUT);
  pinMode(led_12, OUTPUT);

}

void loop() {
  // blink all twelve at the same time
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  digitalWrite(led_9, HIGH);
  digitalWrite(led_10, HIGH);
  digitalWrite(led_11, HIGH);
  digitalWrite(led_12, HIGH);

  delay(100);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, LOW);

  delay(100);

  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  digitalWrite(led_9, HIGH);
  digitalWrite(led_10, HIGH);
  digitalWrite(led_11, HIGH);
  digitalWrite(led_12, HIGH);

  delay(100);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, LOW);


  // turn led's on/off in a row with 100 millisecond interval

  digitalWrite(led_1, HIGH);
  delay(100);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(100);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(100);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, HIGH);
  delay(100);
  digitalWrite(led_4, LOW);

  digitalWrite(led_5, HIGH);
  delay(100);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, HIGH);
  delay(100);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, HIGH);
  delay(100);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, HIGH);
  delay(100);
  digitalWrite(led_8, LOW);

  digitalWrite(led_9, HIGH);
  delay(100);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, HIGH);
  delay(100);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, HIGH);
  delay(100);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, HIGH);
  delay(100);
  digitalWrite(led_12, LOW);

  // wow  ... so much typing
  // can you make it go backwards from 12 to 1?


}
```

## Coding with loops

What do you think we mean by coding with loops? What kind of programming loops have you heard of so far?

### While Loop
The first loop that we will look at is the while lop. A while loop allows you to run a set of instructions while some condition is met. You can apply this type of logic to many situations in your personal life too. For example, `while you're learning programming, you have to be very patient and pay attention to every little comma, semicolon, and parentheses`, or as you know, `while driving, you are not allowed to text on a phone`.

In programming, we can apply the same idea. For example, while some pin variable is less than 14 (`while (pin < 14)`), turn pin on (`digitalWrite(pin, HIGH)`). Then we just need make sure to update our pin variable in the loop by 1 (`pin = pin + 1` or `pin += 1`). In the code below, you can see how the `void setup()` loop and the `void loop()` loop become so much easier to type.

**Make sure to change the code to also do the following:**
- Turn one led on and off at a time starting at pin 2 and going up to pin 14
- Turn one led on and off at a time starting with pin 13 and going down to 2
- Try and come up with some other examples on your own.

```c
int pin;

void setup() {
  // set communication with the computer
  Serial.begin(9600);

  // set the pins as output pins
  pin = 2;
  while (pin < 14) {
    pinMode(pin, OUTPUT);
    pin = pin + 1;

  }
}

void loop() {
  // blink all twelve at the same time

  // blink on
  pin = 2;
  while (pin < 14) {
    digitalWrite(pin, HIGH);
    pin = pin + 1;
  }

  // wait
  delay(100);

  // blink off
  pin = 2;
  while (pin < 14) {
    digitalWrite(pin, LOW);
    pin = pin + 1;
  }


  // turn led's on/off in a row with 100 millisecond interval
  // How can you make one led at a time turn on and off using a while loop?

  // wow  ... so much less typing

  // can you make it go backwards from 12 to 1?

  // what else can you come up with?
}
```

### For Loop

Awesome, now we know how to save time on typing so many lines of code and get things done faster. The next type of loop that we're going to look at is a for loop, which is really just a special case of the whle loop. Remember that in the while loop, we alway had to update our pin variable in each loop. With the for loop we don't need to do that because we can tell the computer in advance how many time you want to execute something.

In some cultures like spain, you eat 12 grapes in the last twelve seconds of the year. So you could say `For the next 12 seconds, starting with 1 and ending with 12, you need to eat one grape per second.`

A for loop looks basically like shown below, the block in the curly braces `{}` get's repeated and the content in the parentheses `()` after the word `for` defines how often to loop and what the counter variable should be called. The first part `pin=2` means that we start with pin being equal to 2. Then we define that our `pin` counter should be less than `14` by saying (`pin < 14`), and we say that the `pin` counter should increase by `1` for every iteration. If you wanted it to increase by two, you could say `pin+=2`.


```c
for (pin=2; pin < 14; pin++) {
  digitalWrite(pin, HIGH);
  delay(100);
  digtalWrite(pin, OFF);
}
```

Let's see how this helps with the code above.

```c
int pin;

void setup() {
  // set communication with the computer
  Serial.begin(9600);

  // set the pins as output pins
  for (pin=2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // blink all twelve at the same time

  // blink on
  for (pin=2; pin < 14; pin++) {
    digitalWrite(pin, HIGH);
  }

  // wait
  delay(100);

  // blink off
  for (pin=2; pin < 14; pin++) {
    digitalWrite(pin, LOW);
  }


  // turn led's on/off in a row with 100 millisecond interval
  for (pin=2; pin < 14; pin++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
  }

  // wow  ... so much less typing
  // can you make it go backwards from 12 to 1?

  // what else can you come up with?
}

```


# Lab 1: Circuits and GPIO Control with Arduino

In this lab, we will continue on learning the fundamentals of circuits, how to use a breadboard, and how to write an Arduino Program that can control GPIO (general purpose input output) and read analogue voltages. This can also be done using a Raspberry Pi, but we will focus on the Arduino for now as it will help us later on.

Before we get started, here are a list of good videos that relate to today's class:
- [What is an LED? - Collin's Lab](https://www.youtube.com/watch?v=P3PDLsJQcGI)
- [What is a breadboard? - Collin's Lab](https://www.youtube.com/watch?v=w0c3t0fJhXU)
- [How to Solder - Collin's Lab](https://www.youtube.com/watch?v=QKbJxytERvg)
- [Soldering Arduino Nano](https://www.youtube.com/watch?v=37mW1i_oEpA)
- [Blinking an LED with Arduino](https://www.youtube.com/watch?v=dnPPoetX0uw)
- [Another Arduino blinking tutorial](https://www.youtube.com/watch?v=GaaMQjpPOFQ)
- Analog inputs on Arduino --- _coming soon_

If you want to see how to do all this on a Raspberry Pi with Python, you may check out this video: [GPIO Control Raspberry Pi](https://m.youtube.com/watch?v=41IO4Qe5Jzw).


## Part 1: LED Circuit

Our first circuit is an LED circuit. We can connect in an LED in series with a resistor to our GPIO output pin on the Arduino, as shown below.

![LED schematic](images/lab1/led_schematic.png)
![LED wiring](images/lab1/led_wiring.png)


## Part 2: Potentiometer Circuit

In the second circuit, we will connect a potentiometer to an Arduino analog input pin of the Arduino, as shown below. _Note: You can add this circuit to your existing circuit._

![Pot schematic](images/lab1/pot_schematic.png)
![Pot wiring](images/lab1/pot_led_wiring.png)

## Part 3: Arduino Coding

Ok, now that we have the hardware in place, we can start coding.
Before diving into the details of coding, let's remind ourselves what we're trying to do here:
1. Control and LED with an automated computer program
2. Read the voltage of a voltage dividing potentiometer
3. Use a potentiometer to turn an LED on and off

Now that we know our goals, we can split this problem into three different parts and write own program for each problem.

The programming approach for each of these is exactly the same, as every Arduino program is structured the same way. You can think of Arduino programs like simple a simple board game. When playing a board game, you typically do the following:
1. Define the game you are playing and some of the game rules
2. You setup the game by identifying players and setting up the "board" of the game.
3. Once everyone knows who is playing in the game and what the rules are, you can play the game. Typically this involves doing same procedures in every round of the game until someone wins.

An Arduino program is the same, except that there is no winner. You
1. Define global names and variables, e.g. `int green_LED = 9;`;
2. You setup your program in `void setup()`. Here you say what each pin is doing and at what speed you want to talk to the computer `Serial.begin(9600);`
3. Lastly there is the `void loop()`. Here you can define the routines that you want your program to execute, e.g. `digital.Write(green_LED, HIGH);`

### Problem 1: LED control

Let's think about what we need here:

1. Global variables:
  - You need to name your LED pin as an `int`. In the following line, we will define a green_LED as pin 9. You can change this based on the color that you are using, or give it any other name that you want. _The only important thing is that the number that you put here, `9`, is the pin that you are connecting to on your Arduino._
  ```
  int green_LED = 9;
  ```

2. Setup:
  - In the setup, we want to make sure that our LED pin is defined as an output:
  ```
  pinMode(green_LED, OUTPUT);
  ```
  - We also want to set the language that we're communiting with between the computer and the Arduino:
  ```
  Serial.begin(9600);
  ```

3. Loop:
  - In the main loop, we basically just want to make the LED blink. For this, you need one command that allows you to turn the LED on and off, and one that allows you put a pause in your program.
  - To turn a digital output pin on and off, or HIGH and LOW, we use the `digitalWrite()` command. So if we want to turn the `green_LED` (pin 9) on, we say
  ```
  digitalWrite(green_LED, HIGH);
  ```
  And if we want to turn it off, we use
  ```
  digitalWrite(green_LED, LOW);
  ```
  - Now because our computer is so fast, if we write on and off immediately one after another, we are going to have a problem seeing the on/off action. (Try it out and see what happens!). So, to make it blink at 1 second interval, we can put a time belay between the on-off and the off-on. (Why do you need two delays?). In Arduino, we can use the ```delay()``` command to do this. Within in the function parameters `()`, we specify the delay that we want in milliseconds. So a 1-second delay would mean that you write
  ```
  delay(1000);
  ```

The entire code should look something like shown below. Do not just copy it, but write your own program. Change the pin number to `8`, name your led something else, and change the interval (the delays) that you're blinking at.

```c
int green_LED = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(green_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(green_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(green_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
```

### Problem 2: Potentiometer Sensing

So far so good, let's see how we can learn more about potentiometers by sensing their output using and Arduino. Again, let's think about what we need to here:

0. Goal:
  - Our goal is read the output from the potentiometer and display it on the computer using the Serial Monitor.

1. Global variables:
  - You need to define two things here, the analog input pin that your Arduino is connected to, and a variable that can store your readings.
  ```
  int pot = 0;          // potentiometer connected to pin A0
  int reading;          // initialize integer variable to store sensor output
  ```

2. Setup:
  - Since we want to display our readings on the `Serial Monitor`, we want to make sure to set the language (speed) that we're communiting with between the computer and the Arduino:
  ```
  Serial.begin(9600);
  ```
  - Analog inputs (pins A0 - A5) DO NOT NEED to be defined in the setup, because unlike GPIO pins, these can only do one thing: reading voltage signals and digitizing it into a number between 0-1023 representing 0-5V.

3. Loop:
  - Now remember, the main loop is like a round in a boardgame, the same code is being executed over and over and over (never ending) at a very, very high speed. In fact, it's being executed as fast as the Arduino can unless if you tell it wait a little bit here and there using the `delay()` method that we also used with the LEDs.
  - To read the input on the `A0` pin, we use the `analogRead()` function. Inside the `()`, you are going to put the pin/port that you want to read from. In this case, you stored your pin number in the `pot` variable. So `analogRead(pot)` is going to to give us a number between `0` and `1023`, which means that we need to store this somehow. That where we use the `reading` variable that defined at the very top too.
  ```
  reading = analogRead(pot);
  ```
  - Next we want to print this number to the Serial monitor, so we use the `Serial.print()` command. Can you guess what the difference is between `Serial.print` and `Serial.println`. Why do we put `"Reading: "` into quatation marks and `pot` not? If you're not sure, try it out and see what happens.
  ```
  Serial.print("Reading: ");
  Serial.println(pot);
  ```
  - Now because our computer is so fast, if we don't tell it to wait a little bit, the numbers are gonna change so quickly that it's going to be hard for us to track it. In Arduino, we can use the ```delay()``` command to do this. Within in the function parameters `()`, we specify the delay that we want in **milliseconds**. So a 1-second delay would mean that you write
  ```
  delay(1000);
  ```

  The entire code should look something like shown below. Do not just copy it, but write your own program. **Change the pin number to `1` (what does that mean for our circuit?), name your `reading` variable something else (like `pot_reading`, `pot_recording`, etc.), and change the interval (the delay) that you're reading at.**

  ```c
  int pot = 0;
  int reading;

  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
  }

  void loop() {
    // put your main code here, to run repeatedly:
    reading = analogRead(pot);
    Serial.print("Reading: ");
    Serial.println(pot);

    delay(1000);
  }
  ```
### Problem 3: Can we combine Potentiomers and LEDs?

**How would you combine the LED program and the potentiometer program into a single program? What would you want it to do?**
To give you a possible example, have you every turn a knob that makes a light fade in and out? How do think that works?

**Hint:** <br>
In Arduino, instead of just turning pins on and off using `digitalWrite(pin, HIGH)` and `digitalWrite(pin, LOW)`, we can actually output anything in between the two. You can do this using the `analogWrite(pin, value)` function, where `pin` is the pin that you're using to connect to the LED, and `value` is a number between `0` and `255`. The higher the number, the closer the output will be to 5V, which is the maximum. So, if you want your LED to light at half the brightness, you could say
```c
analogWrite(led_pin, 127);
```
Now how can we use this for our project? Discuss with your partner how you want to use the LEDs and Potentiometers togeher.


# Introduction

Aloha! Here you will find some helpful links and resources for our weekly lab acitivities.
