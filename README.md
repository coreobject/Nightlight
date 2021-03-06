# Nightlight

## Description

Create an interactive night light. At minimum it will turn on in the dark and off in the light. A touch sensor will allow the user to turn the lights on or off manually. Use an Arduino with 6 LEDs, a photoresistor, and a capacitive sensor. Consider the night light as a complete object. What will be its environment? Who will use it? How will it be used? What does it look like and why?

Design Criteria:
 + Appearance
 + Construction
 + Interactivity / usability

[Emerging Objects | Flickr - Photo Sharing!] (https://www.flickr.com/photos/sparkle_labs/albums/72157633249013685)

- [CapSense Library Reference](http://playground.arduino.cc//Main/CapacitiveSensor?from=Main.CapSense "Arduino Playground - CapacitiveSensor")
**Form:**
3”x3”x3” cube laser cut acrylic

**Input:**

+ Capacitive touch sensor [Arduino Playground - InterfacingWithHardware] (http://playground.arduino.cc/Main/InterfacingWithHardware#capsens)
+ Light Sensor

##Output:** 1-6 LEDs

##Parts List:**

1. 10kΩ
2. 1MΩ
3. Resistors for LEDs. ~100Ω - 220Ω
4. Mini Breadboard
5. Arduino UNO
6. LEDs
7. Photoresistor
8. Length of wire (22 gauge) for capacitive touch sensor
9. Acrylic to create enclosure
8. Acrylic cement and applicator

![minibreadboard](minibreadboard.jpg)
![image] (acryliccement.jpg)

```
//
//        +-----------+
//  +-----> LIGHT OFF <---------------------------+
//  |     +-----+-----+                           |
//  |           |                                 |
//  |           |                                 |
//  |     +-----V-----+        +----------+       |
//  |     |   IS IT   |        |  TOUCH   |       |
//  |     |           |---NO--->          |--NO--->
//  |     |   DARK?   |        |  SENSOR  |       |
//  |     +-----+-----+        +-----+----+       |
//  |           |                    |            |
//  |           |                   YES           |
//  |          YES                   |            |
//  |           |                    |            |
//  |           <--------------------+            |
//  |     +-----V-----+                           |
//  |     | LIGHTS ON <--------------+            |
//  |     +-----+-----+              |            |
//  |           |                    |            |
//  |           |                   NO            |
//  |           |                    |            |
//  |     +-----V-----+        +-----+----+       |
//  |     |   IS IT   |        |  TOUCH   |       |
//  +-----|           |--YES--->          |--YES--+
//        |   DARK?   |        |  SENSOR  |
//        +-----------+        +----------+
//
```
//    Final Circuit
//                                      +--------+
//                                      | TOUCH  |
//                                      | SENSOR |
//                                      |      | |
//                                      +------+ |
//                 ARDUINO                       |
//              +-----------+                    |
//              |        GND|-----------------+  |
//              |           |                 |  |
//              |         13|-[R220]--[LED>]--O  |
//              |         12|                 |  |
//              |        ~11|-[R220]--[LED>]--O  |
//              |        ~10|-[R220]--[LED>]--O  |
//  +--[PHOTO]--|5V       ~9|-[R220]--[LED>]--O  |
//  |           |GND       8|                 |  |
//  O---[R10K]--|GND       7|                 |  |
//  |           |         ~6|-[R220]--[LED>]--O  |
//  +-----------|A0       ~5|-[R220]--[LED>]--O  |
//              |A1        4|----[R1M]--------+--O
//              |A2       ~3|-[R220]--[LED>]--+  |
//              |A3        2|--------------------+
//              |A4        1|
//              +-----------+
//
