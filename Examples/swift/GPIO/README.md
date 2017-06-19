# GPIO

This example shows how to use the GPIO ports in Estimote Location Beacon, to develop apps that wirelessly (over Bluetooth LE) interact with devices connected to beacons.

* [Hardware prerequisites](#hardware-prerequisites)
  + [Example Output setup](#example-output-setup)
  + [Example Input setup](#example-input-setup)
* [Software prerequisites](#software-prerequisites)
* [Something doesn't work, what do I do?](#something-doesnt-work-what-do-i-do)
* [Additional resources](#additional-resources)

## Hardware prerequisites

This project requires a few elements that you can easily find at your local hardware store:

  - 2 Estimote Location Beacons (one for Input and one for Output)
  - breadboard (to connect wires, button and resistor)
  - wires
  - LED (for visualizing the Output)
  - push button (for Input)
  - resistor

### Example Output setup

![](https://image.ibb.co/b49cXa/Output.png)

You need to remember that the longer leg ("+", "positive", "anode") of the LED goes to the port you've set to the 'Output' mode, and shorter one ("-", "negative", "cathode") to GND.

### Example Input setup

![](https://image.ibb.co/eO9uCa/Input.png)

In this case you connect one wire to GND and the other one to the port you've set to the 'Input' mode. You should also remember about adding a resistor in between the latter connection.

## Software prerequisites

Before running the example app, configure the GPIO ports with the Estimote App:

![](https://image.ibb.co/kqpuCa/Software_Prerequisites_Config.png)

## Something doesn't work, what do I do?

Check if it works in the Estimote app:

- for Output, switching from low to high should light up the LED;
- for Input, pushing the button should change the input state.

If it doesn't, double-check your connections and the components you used. If it does, the problem is most likely in the app's code.

You can always ask for help on [Estimote forums](https://forums.estimote.com), or browse our [Knowledge Base](https://community.estimote.com/hc/en-us) for answers to general questions.

## Additional resources

- [iOS SDK reference](http://estimote.github.io/iOS-SDK/)
- [Knowledge Base](https://community.estimote.com/hc/en-us)
- [What is GPIO?](https://community.estimote.com/hc/en-us/articles/217429867-What-is-GPIO)
- [How to set up GPIO in Location Beacons?](https://community.estimote.com/hc/en-us/articles/219001708-How-to-set-up-GPIO-in-Location-Beacons-)
