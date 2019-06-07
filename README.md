<p align="center">
  <a href="" rel="noopener">
 <img src="https://github.com/kylelobo/Hydroponics/blob/master/images/nft.jpg" alt="NFT"></a>
</p>

<h3 align="center">Automated Hydroponics using Arduino Mega</h3>

<div align="center">
  
  [![Status](https://img.shields.io/badge/status-active-success.svg)]()
  [![GitHub Issues](https://img.shields.io/github/issues/kylelobo/Hydroponics.svg)](https://github.com/kylelobo/Hydroponics/issues)
  [![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/Hydroponics.svg)](https://github.com/kylelobo/Hydroponics/pulls)
  [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)
  
  [![Tweet](https://img.shields.io/twitter/url/https/shields.io.svg?style=social)](https://twitter.com/intent/tweet?text=Automated%20Hydroponics%20using%20Arduino%20Mega&url=https://github.com/kylelobo/Hydroponics)

</div>

--- 

<p align="center"> 🌱 Hydroponics is a subset of hydroculture, the method of growing plants without soil, using mineral nutrient solutions in a water solvent. </p>


## 📝 Index
- [Working](#working)
- [Description](#description)
- [Problem Definition](#problem_definition)
- [Screenshots](#screenshots)
- [Sensors Used](#sensors_used)
- [Software Requirements](#software_requirements)
- [Arduino Libraries Used](#arduino_libraries_used)
- [Running the code](#running_the_code)
- [Conclusion](#conclusion)
- [References](#references)


## 🎈 Description <a name="description"></a>
- Hydroponics is a subset of hydroculture, the method of growing plants without soil, using mineral nutrient solutions in a water solvent. Terrestrial plants may be grown with only their roots exposed to the mineral solution, or the roots may be supported by an inert medium, such as perlite or gravel.The nutrients in hydroponics can come from an array of different sources; these can include but are not limited to byproduct from fish waste, duck manure, or commercial fertilisers. <sup>[[1]](#1)</sup>

- Growing with hydroponics comes with many advantages, the biggest of which is a greatly increased rate of growth in your plants. With a proper setup, your plants will mature up to 25% faster and produce up to 30% more than the same plants grown in soil. <sup>[[2]](#2)</sup>

- Plants in a hydroponic system grow more quickly because they have food and water available to them all the time. They produce bigger crops because they can devote their energy to producing their crop rather than producing large roots such as would be needed in soil to seek out water and nutrients. Hydroponically-grown plants have smaller root systems because the roots do not need to go out looking for nutrients and water.

- All of this is possible through careful control of the nutrient solution and pH levels. A hydroponic system will also use 70-90% less water than soil based plants because the system is enclosed, which results in less evaporation. Hydroponics is better for the environment because it reduces waste and pollution from soil runoff. <sup>[[2]](#2)</sup>


## 📍 Problem Definition <a name="problem_definition"></a>
- Traditional agriculture isn’t possible in places with arid climates such as Arizona, Israel.

- Similarly, hydroponics is useful in dense urban areas, where land is at a premium. In Tokyo, hydroponics is used in lieu of traditional soil-based plant growth.

- Hydroponics is also useful in places which have land shortage problems, such as Singapore. With so little space available for planting, hydroponic systems take around 20 percent of the land usually required for crop growth. This allows the citizens to enjoy year-round local produce without the expense and delay of importation.

- Finally, areas that don't receive consistent sunlight or warm weather can benefit from hydroponics. Places like Alaska and Russia, where growing seasons are shorter, can use hydroponic greenhouses, where light and temperature can be controlled to produce higher crop yields. <sup>[[3]](#3)</sup>

- Hydroponics allows farmers to adapt to any situation, whether it’s Antarctica’s frozen tundra, Saudi Arabia’s windswept and barren deserts, southern Arizona’s Sonoran Desert, or even a space station.


## ⚙️ Working <a name="working"></a>
- The entire system mainly consists of a grow box, a reservoir and a water reservoir.

- The DC water pumps are attached to the nutrient solution, reservoir, water reservoir and the pH up down solutions. The water level sensor, temperature sensor, EC sensor, pH sensor are installed in the reservoir.

- When the EC sensor detects low-salt levels it indicates nutrient deficiencies. Therefore, in such situations, the DC water pump pumps the nutrient solution to the reservoir. The presence of high salt levels / low water levels indicates that fresh water needs to be pumped to the reservoir.

- Overlooking pH control can be perilous for plants, particularly those that rely on water supplies with high alkalinity. The pH of the nutrient solution is a major factor in determining the uptake rate of many essential nutrient ions. Run pH too high and the dreaded nutrient lockout looms. The pH sensor detects the pH level of the water and prompts the pH up / pH down pump to balance out the pH levels in the reservoir.

- The grow box has a drainage system which allows continous flow of nutrient solution runs over the plants roots.

- This type of system works very well because the roots of a plant absorb more oxygen from the air than from the nutrient solution itself. Since only the tips of the roots come in contact with the nutrient solution, the plant is able to get more oxygen which fascilitates a faster rate of growth.

- All this can be monitored on the website for this project.

- The below video shows a brief working of this project: (💡 **PS -** Due to financial constraints, we have not used the EC sensor & pH up / down solutions) <br>

<div align="center">
  
  [![Video Demonstration](http://img.youtube.com/vi/mIO8MYL-RWc/0.jpg)](http://www.youtube.com/watch?v=mIO8MYL-RWc "Video Demonstration")

</div>


## 🎞️ Screenshots <a name="screenshots"></a>
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
![Sensor Data (Tabular)](https://i.imgur.com/Pe3MPlg.jpg)
![Sensor Data (Graphical)](https://i.imgur.com/Q6NAUEZ.jpg)


## 🔩 Sensors Used <a name="sensors_used"></a>
1. **Arduino Mega 2560** - The hardware will most likely fit perfectly in the UNO, the problem will be the program size that may not fit in the UNOs 32kB. Plus, such a project might be increased and a mega board will allow that more easily.

2. **Water-Level Sensor** - A water-level sensor is a device used in the detection of the water level.

3. **pH Sensor** - Optimal pH levels are critical to healthy plants and high yields in both soil and hydroponics gardening. Maintaining those optimal levels, especially in soil-less growing systems, calls for frequent, accurate pH testing. Ideal pH levels maximize a plant’s nutrient uptake. Those nutrients, in turn, increase a plant’s vigor and productivity.

4. **EC Sensor** - To maximize the benefits of growing hydroponically, it’s important to know how to fine-tune your nutrient regimen to ensure your plants are getting everything they need, in the right doses. To do that, you need to learn how to measure EC, or electrical conductivity, which tells you the amounts of fertilizer salts in your water, and use those readings to feed your plants the right mix of elements for optimal growth and yields.

5. **Water Temperature Sensor** - The pH value of the solution changes with the temperature i.e. an increase in any solutions’ temperature will cause a decrease in it’s viscosity and an increase in the mobility of it’s ions in solution. An increase in temperature may also lead to an increase in the number of ions in solution due to the dissociation of molecules. As pH is a measure of the hydrogen ion concentration, a change in the temperature of the solution will be reflected by a subsequent
change in pH. <sup>[[4]](#4)</sup>

6. **Soil Moisture Sensor** - This soil moisture sensor can be used to detect the moisture of soil or judge if there is water around the sensor, let's you know if the plants in the mesh pot require water or not.

7. **DHT22 Temperature/Humidity Sensor** - The DHT22 is a humidity and temperature sensor with a single wire digital interface. The sensor is calibrated so you can get right to measuring relative humidity and temperature.

8. **ESP8266** - ESP8266 is a WiFi module which helps us track all the sensor data on the website.

9. **DC Water Pump** - A DC Water Pump is used to pump water from the water reservoir to the substrate.

10. **5V Relay** - A relay is an electromagnetic switch operated by a relatively small electric current that can turn on or off a much larger electric current. It is going to be used to control the DC Water Pump


## 💻 Software Requirements <a name="software_requirements"></a>
- Arduino IDE
- A Linux Environment
- Git Version Control
- Editor
- ThingSpeak


## 🖥️ Arduino Libraries Used <a name="arduino_libraries_used"></a>
- DHT Sensor Library
- ThingSpeak
- WiFi101
- Adafruit_IO_Arduino


## 🔧 Running the code <a name="running_the_code"></a>
1. Install [Apache](https://www.digitalocean.com/community/tutorials/how-to-install-linux-apache-mysql-php-lamp-stack-on-ubuntu-16-04#step-1-install-apache-and-allow-in-firewall)
2. Install [MySQL](https://www.digitalocean.com/community/tutorials/how-to-install-linux-apache-mysql-php-lamp-stack-on-ubuntu-16-04#step-2-install-mysql)
3. Install [PHP](https://www.digitalocean.com/community/tutorials/how-to-install-linux-apache-mysql-php-lamp-stack-on-ubuntu-16-04#step-3-install-php)
4. Clone or Download the repository
```
$ git clone https://github.com/Hydroponics/Reddit-Bot.git
```
5. Move the Hydroponics folder to ```/var/www/```
```
$ sudo mv Hydroponics/ /var/www
```
6. In your browser, open [localhost](http://localhost/)


## 🔍 Conclusion <a name="conclusion"></a>
The aim of this project is to:
- Reduction of water wastage caused by traditional agriculture systems
- Providing a scaled down solution for urban gardening
- Growing healthier plants at a faster rate due to a controlled growing environment
- Simplifying the process of Hydroponics using IOT and Internet Programming


## 🗒️ References <a name="references"></a>
[1]<a name="1"></a> [Hydroponics](https://en.wikipedia.org/wiki/Hydroponics) - _Wikipedia_ <br>
[2]<a name="2"></a> [Hydroponic Systems 101](http://www.fullbloomhydroponics.net/hydroponic-systems-101/) - _Fullbloom Hydroponics_ <br>
[3]<a name="3"></a> [How Hydroponics Works](https://home.howstuffworks.com/lawn-garden/professional-landscaping/hydroponics2.htm) - _Bambi Turner_ <br>
[4]<a name="4"></a> [pH Meters in Hydroponics](https://manicbotanix.com/ph-meters/) - _Med-Tek_ <br>
[5]<a name="5"></a> [Urban Hydroponic Oasis](https://devpost.com/software/urban-hydroponic-oasis) - _Paul Langdon_


## ✍️ Authors <a name = "authors"></a>
- [@kylelobo](https://github.com/kylelobo)
- [@sephiroth7712](https://github.com/sephiroth7712)
- [@rudij7](https://github.com/rudij7)
- [@chaitanyadukkipaty](https://github.com/chaitanyadukkipaty)
