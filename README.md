# Automated Hydroponics using Arduino Mega
Hydroponics is a subset of hydroculture, the method of growing plants without soil, using mineral nutrient solutions in a water solvent.

## Index
+ [Working](#working)
+ [Description](#description)
+ [Problem Definition](#problem_definition)
+ [Explanation](#explanation)
+ [Screenshots](#screenshots)
+ [Sensors Used](#sensors_used)
+ [Software Requirements](#software_requirements)
+ [Arduino Libraries Used](#arduino_libraries_used)
+ [Conclusion](#conclusion)
+ [References](#references)

## Working <a name="working"></a>
[![Video Demonstration](http://img.youtube.com/vi/mIO8MYL-RWc/0.jpg)](http://www.youtube.com/watch?v=mIO8MYL-RWc "Video Demonstration")

## Description<a name="description"></a>
Hydroponics is a subset of hydroculture, the method of growing plants without soil, using mineral nutrient solutions in a water solvent. Terrestrial plants may be grown with only their roots exposed to the mineral solution, or the roots may be supported by an inert medium, such as perlite or gravel.The nutrients in hydroponics can come from an array of different sources; these can include but are not limited to byproduct from fish waste, duck manure, or commercial fertilisers. <sup>[[1]](#1)</sup>
<br>

Growing with hydroponics comes with many advantages, the biggest of which is a greatly increased rate of growth in your plants. With a proper setup, your plants will mature up to 25% faster and produce up to 30% more than the same plants grown in soil. <sup>[[2]](#2)</sup>
<br>

Plants in a hydroponic system grow more quickly because they have food and water available to them all the time. They produce bigger crops because they can devote their energy to producing their crop rather than producing large roots such as would be needed in soil to seek out water and nutrients. Hydroponically-grown plants have smaller root systems because the roots do not need to go out looking for nutrients and water.
<br>

All of this is possible through careful control of the nutrient solution and pH levels. A hydroponic system will also use 70-90% less water than soil based plants because the system is enclosed, which results in less evaporation. Hydroponics is better for the environment because it reduces waste and pollution from soil runoff. <sup>[[2]](#2)</sup>
<br>

## Problem Definition<a name="problem_definition"></a>
Traditional agriculture isn’t possible in places with arid climates such as Arizona, Israel.
<br>

Similarly, hydroponics is useful in dense urban areas, where land is at a premium. In Tokyo, hydroponics is used in lieu of traditional soil-based plant growth.
<br>

Hydroponics is also useful in places which have land shortage problems, such as Singapore. With so little space available for planting, hydroponic systems take around 20 percent of the land usually required for crop growth. This allows the citizens to enjoy year-round local produce without the expense and delay of importation.
<br>

Finally, areas that don't receive consistent sunlight or warm weather can benefit from hydroponics. Places like Alaska and Russia, where growing seasons are shorter, can use hydroponic greenhouses, where light and temperature can be controlled to produce higher crop yields. <sup>[[3]](#3)</sup>
<br>

Hydroponics allows farmers to adapt to any situation, whether it’s Antarctica’s frozen tundra, Saudi Arabia’s windswept and barren deserts, southern Arizona’s Sonoran Desert, or even a space station.
<br>


## Explanation<a name="explanation"></a>
The entire system mainly consists of a grow box, a reservoir and a water reservoir.
<br>

The DC water pumps are attached to the nutrient solution, reservoir, water reservoir and the pH up down solutions. The water level sensor, temperature sensor, EC sensor, pH sensor are installed in the reservoir.
<br>

When the EC sensor detects low-salt levels it indicates nutrient deficiencies. Therefore, in such situations, the DC water pump pumps the nutrient solution to the reservoir. The presence of high salt levels/low water levels indicates that fresh water needs to be pumped to the reservoir.
<br>

Overlooking pH control can be perilous for plants, particularly those that rely on water supplies with high alkalinity. The pH of the nutrient solution is a major factor in determining the uptake rate of many essential nutrient ions. Run pH too high and the dreaded nutrient lockout looms. The pH sensor detects the pH level of the water and prompts the pH up/ pH down pump to balance out the pH levels in the reservoir.
<br>

The grow box has a drainage system which allows continous flow of nutrient solution runs over the plants roots.

This type of system works very well because the roots of a plant absorb more oxygen from the air than from the nutrient solution itself. Since only the tips of the roots come in contact with the nutrient solution, the plant is able to get more oxygen which fascilitates a faster rate of growth.
<br>

All this can be monitored on the website for this project.
<br>

This project intends to automate the process of Hydroponics using IOT to make the discharge of water and maintenance of the substrate a wireless one using a mobile application and/or a website.

## Screenshots
![Home Page](https://imgur.com/UK5jDZZ.jpg)
![Intro 1](https://imgur.com/fPFmyoV.jpg)
![Intro 2](https://imgur.com/ZWgLvBh.jpg)
![Intro 3](https://imgur.com/11USWBp.jpg)
![Work 1](https://imgur.com/PHxcO7v.jpg)
![Work 2](https://imgur.com/PuKdpfC.jpg)
![About 1](https://imgur.com/l2F1xYg.jpg)
![About 2](https://imgur.com/pmIM7Nl.jpg)
![Log in](https://imgur.com/foOHpH1.jpg)
![Sign up](https://imgur.com/HEoo0pT.jpg)

## Sensors Used<a name="sensors_used"></a>
***Arduino Mega 2560***- The hardware will most likely fit perfectly in the UNO, the problem will be the program size that may not fit in the UNOs 32kB. Plus, such a project might be increased and a mega board will allow that more easily.

***Water-Level Sensor***- A water-level sensor is a device used in the detection of the water level.
<br>

***pH Sensor***- Optimal pH levels are critical to healthy plants and high yields in both soil and hydroponics gardening. Maintaining those optimal levels, especially in soil-less growing systems, calls for frequent, accurate pH testing. Ideal pH levels maximize a plant’s nutrient uptake. Those nutrients, in turn, increase a plant’s vigor and productivity.
<br>

***EC Sensor***- To maximize the benefits of growing hydroponically, it’s important to know how to fine-tune your nutrient regimen to ensure your plants are getting everything they need, in the right doses. To do that, you need to learn how to measure EC, or electrical conductivity, which tells you the amounts of fertilizer salts in your water, and use those readings to feed your plants the right mix of elements for optimal growth and yields.
<br>

***Water Temperature Sensor***- The pH value of the solution changes with the temperature i.e. an increase in any solutions’ temperature will cause a decrease in it’s viscosity and an increase in the mobility of it’s ions in solution. An increase in temperature may also lead to an increase in the number of ions in solution due to the dissociation of molecules. As pH is a measure of the hydrogen ion concentration, a change in the temperature of the solution will be reflected by a subsequent
change in pH. <sup>[[4]](#4)</sup>
<br>

***Soil Moisture Sensor***- This soil moisture sensor can be used to detect the moisture of soil or judge if there is water around the sensor, let's you know if the plants in the mesh pot require water or not.
<br>

***DHT22 Temperature/Humidity Sensor***- The DHT22 is a humidity and temperature sensor with a single wire digital interface. The sensor is calibrated so you can get right to measuring relative humidity and temperature.
<br>

***ESP8266***- ESP8266 is a WiFi module which helps us track all the sensor data on the website.
<br>

***DC Water Pump***- A DC Water Pump is used to pump water from the water reservoir to the substrate.
<br>

***5V Relay***- A relay is an electromagnetic switch operated by a relatively small electric current that can turn on or off a much larger electric current. It is going to be used to control the DC Water Pump
<br>

## Software Requirements<a name="software_requirements"></a>
+ Arduino IDE
+ A Linux Environment
+ Git Version Control
+ Editor
+ ThingSpeak

## Arduino Libraries Used<a name="arduino_libraries_used"></a>
+ DHT Sensor Library
+ ThingSpeak
+ WiFi101
+ Adafruit_IO_Arduino

## Conclusion<a name="conclusion"></a>
The aim of this project is to:
+ Reduction of water wastage caused by traditional agriculture systems
+ Providing a scaled down solution for urban gardening
+ Growing healthier plants at a faster rate due to a controlled growing environment
+ Simplifying the process of Hydroponics using IOT and Internet Programming

## References<a name="references"></a>
[1]<a name="1"></a> https://en.wikipedia.org/wiki/Hydroponics <br>
[2]<a name="2"></a> http://www.fullbloomhydroponics.net/hydroponic-systems-101/ <br>
[3]<a name="3"></a> https://home.howstuffworks.com/lawn-garden/professional-landscaping/hydroponics2.htm <br>
[4]<a name="4"></a> https://manicbotanix.com/ph-meters/ <br>
[5]<a name="5"></a> https://devpost.com/software/urban-hydroponic-oasis <br>

### This project is developed by [Kyle Lobo](https://github.com/kylelobo), [Roshan James](https://github.com/sephiroth7712) and [Rutash Joshipura](https://github.com/rudij7)
