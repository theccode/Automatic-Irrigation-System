# Automatic-Irrigation-System

## Introduction

Agriculture has a central socioeconomic position in Africa. In Ghana, for instance, this sector accounts for about 60 percent of the work force, about 40 percent of the gross domestic product, and about 40 percent of foreign currencies acquired through exports of agricultural produce.
The World Bank estimates that by 2030, agriculture could develop into a USD 1 trillion market in Sub-Saharan Africa, up from USD313million in 2010.
Although agriculture is a key part of the country's economy, the structure of the sector is vulnerable because it relies on rain-fed agriculture during a roughly six-month rainy season. Droughts and other types of unseasonable weather pose risks for farmers. Under these conditions, irrigation development offers the promise of greater food security and the rural- area development by ensuring yearlong agricultural production.
Achieving Africa’s agricultural growth potential will require a significant increase in historically low levels of productivity. This is an area where irrigation can play a critical role. Modern, efficient irrigation systems such as ours can substantially increase crop yields, resulting in improved livelihoods, reduced risk associated with drought, efficient use of limited water resources, and greater food production
Despite considerable potential for development and the emphasis placed on irrigation development in many plans, less than two percent of the total cultivatable area in Ghana is irrigated.

## TARGET GROUP
- Peasant farmers
- Commercial farmers  
- Hobby farmers

## WHAT WE SEEK TO ADDRESS
## Why Automated Irrigation System?
###### Crop yields
Our irrigation system can extensively increase crop yields and improve livelihoods.
- Risks associated with droughts
The irrigation system can reduce drought associated risks due to climatic changes.
- Limited water resources
   
## Food production
The use of our system will enables farms to yield a greater food production.
- Drip Irrigation Technique
Our system is best suited for drip irrigation technique which has the ability to save water by allowing water to sip slowly to the roots of the plant.

## EXISTING INNOVATIONS
![existing_system](https://user-images.githubusercontent.com/7442471/187659264-d36f3f3a-f90e-4009-b6bd-baa89844b329.png)

The existing innovations used by farmers to apply irrigation lack a number of features critical to the implementation of an effective irrigation system. These include:
¬	the ability to monitor soil moisture levels.
¬	the ability to automate the watering process.
¬	the ability to sense ambient temperature around crops/plants.
¬	the ability to verify the status of water supply.

## TOOLS/RESOURCES/EQUIPMENTS FOR PROJECT DEVELOPMENT
**Arduino UNO** is the brain of this system and all the sensors and display devices are controlled by it. 
A **Moisture sensor** is used to read the Moisture content of the soil. 
An **LCD** is provided to monitor the Soil Status 
The **Soil Moisture Sensor** values depends on the resistance of the soil. The **LM393** Driver is a dual differential comparator which compares the sensor voltage with fixed 5V supply voltage.
The value of this sensor varies from 0- 1023. 0 being most wet condition and 1023 being very dry condition.
The **LM35** is a precision integrated-circuit temperature sensor, whose output voltage is linearly proportional to the Celsius temperature. The LM35 is operates at -55˚ to +120˚C.
The **Water Level Switch** contains a Reed-Magnetic Switch surrounded by a floating magnet. When water is available it conducts. 
The **NPT Ball Valve** controls the water flow.
The Arduino reads the status of the soil using Soil Moisture Sensor. If the soil is dry it performs the following Operations: 
1.  Checks for the availability of water using water level sensor.
2.  If the water is available, the NPT Ball Valve is turned ON and is automatically turned OFF when sufficient amount of water is supplied.
The NPT Ball Valve is driven by a relay driver circuit.
3.  If the Water is Unavailable, you will be notified with a sound.
The status of soil (Dry, Moist, Soggy), the temperature and the status of Pump is displayed on the LCD Screen.
Hardware:

## SETUP 

![WP_20191128_001](https://user-images.githubusercontent.com/7442471/187662832-35ecd7e8-a4b2-4407-b01a-d2e492ee5d5b.jpg)

![WP_20191128_002](https://user-images.githubusercontent.com/7442471/187662897-adcecace-b1de-4133-9e05-7dedfaac5f76.jpg)


![WP_20191128_003](https://user-images.githubusercontent.com/7442471/187662928-8e90ed29-27c2-4d5c-899a-d50175dc04a8.jpg)

![WP_20191128_007](https://user-images.githubusercontent.com/7442471/187663011-eaaba6cb-c493-4042-8184-31d7567b3b78.jpg)

![WP_20191128_009](https://user-images.githubusercontent.com/7442471/187663067-78d60205-5dce-498e-86ca-97f3d95ecb43.jpg)


![IMG-20191128-WA0001](https://user-images.githubusercontent.com/7442471/187663343-41b17eaf-a364-45c4-a9cf-09f3a5d3fd14.jpg)


## DEMOSTRATION

![IMG-20191227-WA0001](https://user-images.githubusercontent.com/7442471/187663371-167d33b0-f74a-49ce-8010-8590fe5b8471.jpg)


## PARTS USED
### Arduino Uno

![Arduino Uno](https://user-images.githubusercontent.com/7442471/187660938-9ee193f2-4946-4311-9c58-3f673ed528fa.png)

### I2C 20x4 LCD
![I2C 20x4 LCD](https://user-images.githubusercontent.com/7442471/187661031-1b66eb30-0410-48ab-9782-b3fda1d06fac.png)

### I2C RTC DS3231

![I2C RTC DS3231](https://user-images.githubusercontent.com/7442471/187661099-88e46032-4c10-4ee7-b764-e7ec55d2a9ba.png)

### 5v1CH Relay
![5v1CH Relay](https://user-images.githubusercontent.com/7442471/187661155-66dc0837-8bef-425e-95c9-64201b552399.png)

### LM-393 Soil Moisture Sensor

![LM-393 Soil Moisture Sensor](https://user-images.githubusercontent.com/7442471/187661258-30f4a046-9fde-46b0-901b-60d10dbe603c.png)

### LM-393 Water Sensor
![LM-393 Water Sensor](https://user-images.githubusercontent.com/7442471/187661354-028b38d5-5fde-48e4-a0e6-5cd596f96bd4.png)

### 12vDC ¾” Stainless Steel NPT Ball Valve (3-wire)
![12vDC ¾” Stainless Steel NPT Ball Valve (3-wire)](https://user-images.githubusercontent.com/7442471/187661424-213e1c95-bac4-4e6f-ba9c-48aba7cf278c.png)


## Reference
http://mofa.gov.gh/site/wp-content/uploads/2011/07/GHANA-IRRIGATION-DEVELOPMENT-POLICY1.pdfhttp://www.fao.org/3/a-i4158e.pdf
https://www.arduino.cc/en/Reference/LiquidCrystalSetCursor
http://www.instructables.com/id/Connect-A-16x2-LCD-Display-To-An-Arduino/
http://www.instructables.com/id/Soil-Moisture-Sensor/
http://www.instructables.com/id/Arduino-Temperature-Sensor-Interfacing-LM35-THE-EA/
https://www.arduino.cc/en/Reference/digitalRead
http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/
http://www.electroschematics.com/6519/simple-soil-moisture-sensor-arduino-project/

## TEAM MEMBERS
1.	Josephine Akonobea Bekoe 
2.	Mohammed Dodoo
3.	Eric Addae Kumah 

