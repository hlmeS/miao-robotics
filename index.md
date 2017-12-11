# Table of Contents

- General announcements
  - [Introduction](#introduction)
- Lab Activities
  - [Lab 1: Circuits and GPIO Control with Arduino](#lab-1-circuits-and-gpio-control-with-arduino) --- Updated 9/20

# Introduction

Aloha! Here you will find some helpful links and resources for our weekly lab acitivities.

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
