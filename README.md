# :tennis: Tennis Ball 
## An Arduino sketch to help with parking in the garage.

Are you concerned you might pull too far forward when pulling into the garage, potentially causing damage to your home or vehicle? Are you running short on tennis balls but have a spare Arduino laying around? Well if that's the case this repo might be for you! This Arduino device / sketch provides a digital alternative to the old tennis-ball-on-a-string-hanging-from-the-ceiling.

This Arduino sketch is a simple mashup of the default Ping and LED examples. The device consists of an Arduino, a sonar distance sensor, a push button and an array of LEDs/resistors. When everything has been wired up correctly, a push button is used to set the optimal distance from the device (mounted on your garage wall). This sets the point at which the red LED will light up. From there, a LED will unlight for every foot you back up. When you pull in to your garage you should get a nice visual representation of how close your car's front end is to the garage wall.

<img width="553" alt="Screenshot 2022-12-05 at 10 43 48 PM" src="https://user-images.githubusercontent.com/1673133/205819757-9370822d-a129-4b1d-8240-ff6f7d88db9f.png">

![IMG_0996](https://user-images.githubusercontent.com/1673133/205819879-0c4f82db-d7b3-45a9-8e67-8ee66189a2b1.jpg)

I'd love to clean this up with a 3D-printed case, but so far so good. It has been working like a charm for 6+ months and I'm yet to run into the wall!
