# Table of Contents

- General announcements
  - [Introduction](#introduction)
- Lab Activities
  - [Lab 1: Circuits and GPIO Control with Arduino](#lab-1-circuits-and-gpio-control-with-arduino)
  - [Lab 2: X-mas lights with Arduino](#lab-2-x-mas-lights-with-arduino)


# Lab 2: X-mas lights with Arduino


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
