# Smart Industrial Safety Monitoring System

## Project Overview
The Smart Industrial Safety Monitoring System is an embedded system designed to monitor industrial safety conditions in real time. It uses an ARM7 LPC2129 microcontroller with temperature, motion, and flame sensors to detect potentially unsafe conditions.

The system displays temperature and safety status on a 16×2 LCD, transmits monitoring data through UART serial communication, and uses LED indicators to identify different safety conditions.

## Objectives
- Monitor industrial temperature using the LM35 sensor.
- Detect movement using a PIR sensor.
- Detect fire using a flame sensor.
- Display sensor readings and safety status on an LCD.
- Transmit sensor information through UART.
- Indicate safety conditions using LEDs.

## Hardware Requirements
- ARM7 LPC2129 microcontroller
- LM35 temperature sensor
- PIR motion sensor
- Flame sensor
- 16×2 LCD
- Green, yellow, and red LEDs
- Connecting wires and power supply
- Buzzer (optional)

## Software Requirements
- Keil µVision 5
- Proteus Design Suite
- Embedded C
- LPC2129 device support files

## Technologies Used
- Embedded C programming
- ARM7 microcontroller
- GPIO
- ADC
- UART serial communication
- Sensor interfacing
- Proteus simulation

## Working Principle
1. Initialize the microcontroller peripherals and sensors.
2. Read the temperature through the ADC.
3. Read PIR and flame sensor signals through GPIO.
4. Convert the ADC reading into temperature in degrees Celsius.
5. Compare the readings with predefined safety thresholds.
6. Display the readings and status on the LCD.
7. Transmit monitoring information through UART at 9600 baud.
8. Activate the appropriate LED and alarm indication according to the detected condition.

## Temperature Thresholds
- Below 30°C: NORMAL
- 30°C to below 40°C: SAFE
- 40°C and above: NOT SAFE
- Flame detected: Fire alert
- PIR triggered: Motion detected

*Note: These thresholds and sensor logic must match the final implementation in your source code.*

## Project Modules
- GPIO initialization and LED control
- UART initialization and serial display
- ADC initialization and sensor reading
- Temperature conversion
- PIR sensor reading
- Flame sensor reading
- LCD display and status indication
- Main monitoring and decision logic

## Simulation
The circuit can be designed and tested using Proteus. The simulation should verify sensor inputs, temperature conversion, LCD output, UART transmission, and LED indications.

## Expected Results
The system identifies temperature changes, movement, and flame detection. It displays the relevant status on the LCD and transmits monitoring information through UART. LED indicators provide a visual warning when unsafe conditions are detected.

## Conclusion
This project demonstrates the use of ARM7 LPC2129 and Embedded C to develop a basic industrial safety monitoring system. By integrating sensors, ADC, GPIO, UART, LCD, and LED indicators, it provides a foundation for real-time industrial hazard monitoring.

## Project Domain
Embedded Systems | Industrial Safety 
