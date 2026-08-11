#  High-Precision Real-Time Clock (RTC)

##  Description
A highly accurate, microcontroller-based digital clock system. Unlike basic clocks that rely on inaccurate software delay loops, this project utilizes the ATmega32's internal hardware timers (Timer0 and Timer2) to achieve precise, interrupt-driven timekeeping. It features a user-friendly interface for setting time and scheduling audible alarms.

##  Component Usage & Technical Implementation

###  ATmega32 Internal Timers (Timer0 & Timer2)
*   **Usage:** The core timekeeping engine.
*   **Role:** Instead of using blocking `_delay_ms()` functions which cause time drift, the firmware configures Timer0 and Timer2 in CTC (Clear Timer on Compare Match) or Normal mode with interrupts. One timer generates a precise 1-second "tick" for the clock logic, while the other handles high-frequency tasks like refreshing the seven-segment displays or polling buttons, ensuring the clock never loses accuracy.

###  Seven-Segment Displays
*   **Usage:** Visual time and alarm output.
*   **Role:** Displays Hours, Minutes, and Seconds in real-time. The firmware likely uses **dynamic multiplexing** (rapidly switching between digits) to drive multiple displays using fewer microcontroller pins, creating a seamless, flicker-free visual experience.

###  Push Buttons
*   **Usage:** Human-Machine Interface (HMI) for configuration.
*   **Role:** Allows the user to pause the clock and increment/decrement the Hours, Minutes, and Seconds to set the correct time. The firmware includes software debouncing to ensure a single physical press registers as exactly one logical click.

###  Buzzer
*   **Usage:** Audible alarm system.
*   **Role:** Activates when the current system time matches the user-defined alarm time. It provides a clear audio cue to alert the user.

##  Key Software Features & Logic

###  Interrupt-Driven Timekeeping
*   **The Problem:** Using standard delay loops (`_delay_ms(1000)`) for a clock is highly inaccurate. Any extra code execution (like updating a display) adds milliseconds of delay, causing the clock to drift and lose time over hours.
*   **The Solution:** By using hardware timers (Timer0/Timer2) with interrupts, the timekeeping runs in the background independently of the main `while(1)` loop. The microcontroller handles display updates and button presses in the main loop, while the timer interrupt strictly handles the 1-second time increment, guaranteeing perfect accuracy.

###  Alarm State Machine
*   **The Feature:** A fully functional alarm system.
*   **The Implementation:** The firmware continuously compares the current RTC time against a stored "Alarm Time" variable. When a match occurs, it triggers the buzzer. The system also includes logic to acknowledge or snooze the alarm using the push buttons.

###  Dynamic Display Multiplexing
*   **The Feature:** Driving multiple seven-segment displays efficiently.
*   **The Implementation:** To save I/O pins and power, the microcontroller rapidly cycles through the digits (Hours, Minutes, Seconds), turning them on and off faster than the human eye can perceive. This requires precise timing, perfectly handled by the secondary hardware timer.

##  Real-World Applications
*   **Consumer Electronics:** Digital displays in microwaves, ovens, and washing machines.
*   **Public Infrastructure:** Digital wall clocks in schools, train stations, and airports.
*   **Industrial Automation:** Precise process timing and shift-change alerts in factories.
*   **Smart Home Devices:** Scheduled appliance control and wake-up systems.
*   **Medical Equipment:** Timers for infusions, sterilizations, and patient monitoring.

##  Project Structure
*   `/Src` - Contains all the main C source code files (main logic, timer configuration, seven-segment driver, button handling).
*   `/Inc` - Contains all the C header files for modular code organization.
*   `/Proteus` - Contains the Proteus simulation design files and schematics.

## 🔧 How to Run the Simulation
1. Open the `.DBK` or `.PWI` file located in the `Proteus` folder using Proteus Design Suite.
2. Compile the Embedded C code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the microcontroller component in Proteus.
4. Run the simulation. Observe the seven-segment displays counting up in real-time. Use the push buttons to set a specific time, set an alarm, and watch the buzzer trigger when the times match.
