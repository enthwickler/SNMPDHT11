# SNMPDHT11
CREATED BY
VIVEK KHAKHAR(https://www.linkedin.com/in/vivek-khakhar/)
MEENALI GUPTA(https://www.linkedin.com/in/meenali-gupta-3a9594160/)


Interfacing DTH11 temp and humidity sensor to NodeMcu and getting sensor data through SNMP

Simple Network Management Protocol (SNMP) is an Internet Standard protocol for collecting and organizing information about managed devices on IP networks and for modifying that information to change device behavior. Devices that typically support SNMP include cable modems, routers, switches, servers, workstations, printers, and more.

The DHT11 is a commonly used Temperature and humidity sensor. The sensor comes with a dedicated NTC to measure temperature and an 8-bit microcontroller to output the values of temperature and humidity as serial data. The sensor is also factory calibrated and hence easy to interface with other microcontrollers.The sensor can measure temperature from 0°C to 50°C and humidity from 20% to 90% with an accuracy of ±1°C and ±1%. So if you are looking to measure in this range then this sensor might be the right choice for you.

SNMP protocol is achieved by making PC(MIB BROWSER) as a manager and NodeMcu as a agent.The data is colected from the end device (Dth11-temperature sensor) and we can observe the values (temp & humidity).



Required hardware:
NodeMcu(SNMP agent)
DTH11(end device)
Jumper wire


Required Software:
Arduino IDE(https://www.arduino.cc/en/software)
MIB browser(http://bytesofgigabytes.com/snmp-protocol/snmp-manager/)


Connections between NODEMCU AND DTH11:
  VCC(nodemcu)->CC(dth11)
  D3(GPIO0)(nodemcu)->SIGNAL(dth11)
  GND(nodemcu)->GND(dth11)


For configuring SNMP on NodeMcu follow the link below:
http://bytesofgigabytes.com/snmp-protocol/esp8266-snmp-agent/

Only three O.I.D's are configured:

for getting temperature :.1.3.6.1.4.1.5.0
for getting humidity :.1.3.6.1.4.1.5.2

for toggling the led(to verify the SNMP connection):.1.3.6.1.4.1.5.1
if you want to check the connection between SNMP manager and agent you can toggle the Led using SET command with value 1.
To change the condition to toggle the led change the macro ( CHECK_LED )




