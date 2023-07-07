# Sör mérő

This project implements a timer using an Arduino Nano, a vibration sensor, a button, and a 4x7 segments display. The timer starts when it detects vibration and stops when it detects vibration again. The button can be used to reset the timer. The display automatically scales based on the elapsed time, showing milliseconds, seconds and milliseconds, or minutes and seconds.

## Components

- Arduino Nano
- Vibration sensor
- Button
- 4x7 segments display

## Circuit Diagram

Include a circuit diagram here to show how the components are connected. You can use software like Fritzing or draw the diagram by hand and scan/upload it.

## Installation

1. Clone or download this repository to your local machine.
2. Connect the components as per the circuit diagram.
3. Connect your Arduino Nano to your computer.
4. Open the Arduino IDE and upload the code (`main.ino`) to the Arduino Nano.
5. Monitor the serial port to view the timer output.

## Usage

1. Power on the Arduino Nano.
2. Ensure that the vibration sensor, button, and 4x7 segments display are properly connected.
3. When the vibration sensor detects vibration, the timer will start counting.
4. The 4x7 segments display will automatically scale based on the elapsed time.
   - If the elapsed time is below 10 seconds, it will display milliseconds.
   - If the elapsed time is below a minute, it will display seconds and milliseconds.
   - For elapsed times beyond a minute, it will display minutes and seconds.
5. To stop the timer, wait for the vibration sensor to detect vibration again.
6. Press the button to reset the timer.

## Customization

You can customize the behavior of the timer by modifying the code (`main.ino`). You can adjust pin assignments, change display brightness, or add additional functionality as per your requirements.

## Contributing

Contributions to this project are welcome! If you find any issues or have ideas for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
