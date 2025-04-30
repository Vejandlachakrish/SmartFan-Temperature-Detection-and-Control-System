# SmartFan: Temperature Detection and Control System 🌡️🌀

An embedded system project developed for our second-year Engineering Clinics that aims to **automatically regulate fan speed based on ambient temperature** using real-time data and sensor control.

## 🔧 Features

- **Real-time Temperature Detection** using LM35 or DHT11 sensor
- **PWM-Based Fan Speed Control** for energy-efficient cooling
- **Buzzer Alert** when temperature exceeds threshold
- **LCD Display** shows current temperature and fan speed
- **Automatic Operation** — no manual intervention needed
- **Low Power Consumption** and high responsiveness

## 🛠️ Components Used

| Component             | Quantity | Description                                                                          |
|----------------------|----------|--------------------------------------------------------------------------------------|
| Arduino UNO          | 1        | Microcontroller board to read sensors and control output devices                    |
| LM35 / DHT11 Sensor  | 1        | Detects real-time temperature (and humidity in DHT11)                               |
| 12V DC Fan           | 1        | Controlled using PWM via a MOSFET for variable speed cooling                        |
| IRFz44N MOSFET       | 1        | Acts as an electronic switch to control high-current fan                            |
| 16x2 LCD Display     | 1        | Displays temperature and fan speed in real time                                     |
| 12V Buzzer           | 1        | Audio alert system for high-temperature warning                                     |
| 10uF Capacitor       | 1        | Smooths voltage fluctuations and stabilizes the power supply                        |
| Resistors (1k, 4.7k, 10k) | As required | Signal conditioning and limiting current                                    |
| Jumper Wires         | -        | Connects components on the breadboard                                               |
| Breadboard           | 1        | Prototyping board for assembling the circuit without soldering                      |
| 9V Battery + Clip    | 1        | Portable power supply for the Arduino and components                                |

## 🧠 Working

1. **Temperature Monitoring**:
   - LM35 or DHT11 continuously senses the ambient temperature.
   - The sensor output is fed to the Arduino analog pin.

2. **Fan Speed Control**:
   - Arduino converts temperature into PWM output.
   - PWM signal drives the MOSFET to control the 12V DC fan speed.

3. **Alert System**:
   - If temperature exceeds a critical value (e.g., 40°C), the buzzer is activated.
   - LCD displays current temperature and fan speed (PWM value).

4. **Energy Efficiency**:
   - Fan only turns on when temperature is above a set minimum (e.g., 30°C).
   - PWM ensures speed scales with temperature, avoiding unnecessary full-speed running.

## 💻 Code File

The main Arduino sketch is in [main.ino](main.ino). Upload it to your Arduino UNO using the Arduino IDE.

## 📷 Circuit Diagram (Optional)

You can design a simple circuit layout using [Fritzing](https://fritzing.org/) or [Tinkercad Circuits](https://www.tinkercad.com/) to visually simulate the system and connections.

## 👨‍💻 Team Members

- **D. Ganesh Siddhartha** (22BCE8990)
- **B. Bhanu Harshith** (22BCE7363)
- **K. Ram Adarsh** (22BCE7603)
- **V. Chakrish** (22BCE8330)
- **T. Koteswara Raju** (22BCE8240)
- **Ch. Sriman** (22BCE7220)

## 📚 References

- [LM35 Datasheet – Texas Instruments](https://www.ti.com/lit/ds/symlink/lm35.pdf)
- [Arduino Temperature Controlled Fan Tutorial](https://www.tutorialspoint.com/arduino/arduino_temperature_controlled_fan.htm)
- [Components101 – LM35](https://components101.com/sensors/lm35-temperature-sensor)

## 🚀 Future Enhancements

- 📶 Add IoT capabilities using ESP8266 for remote monitoring
- 📊 Store temperature logs on SD card or cloud
- 📱 Mobile app to control fan speed and view real-time data
- 🔋 Power via solar panel or portable battery
- 🤖 Add AI to predict and learn cooling patterns for better automation

---

> 🧾 *Submitted under the guidance of Prof. Dr. T. Rama Thulasi for ECS3001 – Engineering Clinics II*
