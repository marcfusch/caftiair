# CaftiAIR
Automate your coffee experience with a NodeMCU ESP8266

## Before proceeding
Make sure you have a working ESP8266 and a working arduino IDE. You can download this one here:
https://www.arduino.cc/en/software

## Prerequisites
Once you have the Arduino IDE installed, you'll also need to install the ESP8266 library. You will find this one in the board manager.

## Doing the hardware modding
You can see some examples of my mod to my " L'Or Espresso Barista " here https://marcfusch.com/projets/caftiair.html where I used basic BC547Bs transistors I had lying around.

## Clone the repo
```
$ git clone https://github.com/marcfusch/caftiair
```

## Modify the code and flash it!
Open the ```  CaftiAIRv1.ino ``` project file. Modify the following lines:
```
const char* ssid = "CaftiAIR";       
const char* password = "YOUR_PASSWORD"; 
```
As well as 
```
const char pinpower = D1;
const char pinsmall = D3;
const char pinmedium = D2;
const char pinlarge = D4;
```
To your needs and your specific pin layout.

Once done, you can flash the code to the NodeMCU. 

## Connecting to the newly created access point and making coffee.
If you have power, you can connect to the CaftiAIR's Wifi network and go to http://192.168.4.1/ where you will be greeted with the interface.

## Notes
This project is still under development and was planned to be released with a working RFID scanner where only authentified users were allowed to make coffee. Due to the hardware required that failed on me, I was no longer able to continue working on the project waiting for replacement parts.
