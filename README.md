# Universal Interface Multi-Tool (UI-MT)

A compact ESP32-based handheld terminal and electronics multi-tool with touch input, keyboard input, local storage, wireless scanning, external I²C module support, UART debugging, GPIO probing, AD9833-based waveform generation, and basic ESP32 PWM output.

---

## Overview

Universal Interface Multi-Tool, or UI-MT, is a portable ESP32-based handheld device designed to act as a compact field terminal, data logger, reference viewer, wireless scanner, and basic electronics utility tool.

The goal is not to build a smartphone replacement. The goal is to build a dedicated embedded handheld device that is useful for electronics projects, field notes, sensor testing, debugging, logging, and lightweight technical workflows.

UI-MT is designed around a practical and finishable hardware platform:

- ESP32 main controller
- SPI TFT display with touch
- M5Stack CardKB V1.1 Mini QWERTY keyboard
- SD card storage
- RTC module
- buzzer feedback
- external I²C expansion port
- UART/GPIO/PWM utility functions
- AD9833 waveform generator module
- battery-powered operation

The project focuses on building a stable base system first, then expanding into modular tools that are useful for real hardware work.

---

## Design Inspiration

This project is heavily inspired by handheld devices from the 2000s and the pre-smartphone era.

Those devices were often minimalist, focused, and genuinely useful. They were not trying to be everything at once. They provided direct interfaces, practical tools, and a form factor that encouraged real-world use instead of constant distraction.

That idea is central to UI-MT.

Rather than designing this project as a mini smartphone, UI-MT is intended to feel like a dedicated handheld instrument: simple, purposeful, tactile, and reliable. The interface should be clean and effective. Navigation should be understandable. Features should exist because they are useful, not because they are flashy.

The inspiration from older handheld systems influences both the hardware and software direction of the project:

- compact self-contained device
- touch interface for direct interaction
- physical keyboard for fast text entry
- local-first storage and logging
- offline usefulness
- technical reference access
- practical field/lab tools
- simple audible and visual feedback
- modular expansion through known hardware interfaces

UI-MT is meant to carry forward that older handheld design philosophy into a modern DIY embedded platform.

---

## Re-Locked Scope

The camera feature has been completely removed from the current UI-MT project scope.

UI-MT is now re-locked as an ESP32-based handheld terminal and electronics multi-tool focused on:

- local storage
- notes and logs
- offline reference access
- Wi-Fi/BLE observation
- external I²C sensor modules
- UART debugging
- GPIO probing
- AD9833 waveform generation
- simple ESP32 PWM/square-wave output

---

## Official Objective List

The current project scope includes the following objectives:

1. **System Dashboard / Handheld Control Panel**

   A central home screen for launching tools, checking system state, viewing the clock, monitoring storage, and navigating the device.

2. **File Manager / Logger / Data Recorder**

   A local file system interface for browsing SD card contents, saving logs, organizing notes, storing sensor readings, and managing project data.

3. **Journal / Notes / Text Workspace**

   A text-based workspace for writing notes, project logs, field observations, and timestamped entries using the CardKB keyboard.

4. **Wi-Fi Scanner / Network Viewer**

   A passive Wi-Fi scanning tool for displaying nearby networks, signal strength, channel information, security type, and scan timestamps.

5. **BLE Scanner / Beacon Viewer**

   A passive BLE discovery tool for viewing nearby BLE devices, identifiers, RSSI values, and scan logs.

6. **Portable Text Console / Command Terminal**

   A local command interface for launching tools, checking system status, running internal commands, and interacting with device features through typed commands.

7. **Config Editor / Profile Manager**

   A configuration system for managing device settings, UI preferences, module settings, saved profiles, and calibration values.

8. **Offline Reference Tool**

   A local reference viewer for storing and reading technical notes, pinouts, checklists, wiring references, and documentation from the SD card.

9. **External I²C Modular Sensor Port / I²C Bus Scanner / Diagnostics**

   An external I²C expansion system that allows selected sensor modules to be connected, scanned, identified, read, and logged.

10. **UART Serial Terminal**

    A basic serial monitor/debug terminal for communicating with external UART devices, sending typed commands, reading incoming data, and saving serial logs.

11. **GPIO / Logic Probe Basic Tool**

    A simple GPIO probing tool for reading digital HIGH/LOW states, detecting state changes, checking simple pulses, and observing basic logic behavior.

12. **AD9833 Signal Generator / PWM Tool**

    A basic signal output tool using an AD9833 module for sine, triangle, and square-wave generation, plus ESP32 PWM output for simple logic-level square-wave testing.

---

## Excluded From Current Scope

The following are intentionally excluded from the current version:

- camera capture
- ESP32-CAM module integration
- image storage
- QR/barcode scanning
- active Wi-Fi attack tools
- BLE attack tools
- RF jamming
- RF spoofing
- sub-GHz transmission
- IR transmission
- advanced logic analyzer features
- high-speed oscilloscope functions
- high-precision lab-grade signal generation
- high-power signal output
- SDR functionality
- full scripting engine
- smartphone-style app ecosystem
- cloud-dependent features
- local web portal as a core objective

Some of these may be explored in future phases if they are safe, legal, and aligned with the project direction, but they are not part of the current locked scope.

---

## Hardware

### Locked Hardware Set

The hardware for the current version is defined as:

- ESP32 main development board
- SPI TFT display with touch
- touch pen / stylus
- M5Stack CardKB V1.1 Mini 50-Key QWERTY keyboard
- SD card module connected to the main ESP32
- RTC module
- buzzer
- power circuit / battery system
- external I²C expansion port for modular sensors
- exposed UART interface for serial terminal mode
- exposed GPIO input pins for probing
- exposed ESP32 PWM output pin for simple square-wave testing
- AD9833 waveform generator module for dedicated signal generation

The previous 2-button input system has been removed from the official hardware direction. Keyboard input through the CardKB replaces the need for dedicated navigation buttons.

The ESP32-CAM module has also been removed from the official hardware direction.

---

## Hardware Roles

### ESP32 Main Controller

The main ESP32 is responsible for:

- UI control
- TFT display output
- touch handling
- CardKB input handling
- SD card file management
- RTC timestamping
- Wi-Fi scanning
- BLE scanning
- command console
- configuration management
- I²C module selection and scanning
- UART terminal operation
- GPIO probing
- ESP32 PWM output
- AD9833 control over SPI

The main ESP32 is the central controller of the UI-MT system.

---

### SPI TFT Display + Touch Panel

The TFT display is the primary visual interface.

It is used for:

- dashboard
- menus
- tool screens
- file browsing
- scan results
- text console
- references
- sensor readings
- UART terminal output
- GPIO/PWM/signal generator tool screens

The touch panel provides direct menu navigation, selection, and interaction with on-screen controls.

---

### M5Stack CardKB V1.1 Mini Keyboard

The CardKB acts as the main text input device.

It is used for:

- writing notes
- entering console commands
- naming files
- searching files/references
- typing UART commands
- navigating menus with key shortcuts
- editing configuration values
- entering signal generator frequency and waveform settings

This changes UI-MT from a simple touchscreen gadget into a small handheld terminal.

---

### SD Card Module

The SD card module provides local removable storage.

It is used for:

- notes
- logs
- Wi-Fi scan records
- BLE scan records
- sensor readings
- UART logs
- GPIO logs
- PWM presets
- AD9833 signal presets
- configuration exports
- offline reference files

The SD card is the main user-accessible storage system.

---

### RTC Module

The RTC module provides offline timekeeping.

It is used for:

- dashboard clock
- timestamped notes
- timestamped scan logs
- timestamped sensor readings
- timestamped serial logs
- organized filenames

The RTC allows UI-MT to remain useful even without internet time synchronization.

---

### Buzzer

The buzzer provides simple audio feedback.

It is used for:

- button/key feedback
- alerts
- warnings
- scan completion
- low battery warning
- GPIO state-change alert
- system notifications

---

### External I²C Port

The external I²C port allows UI-MT to connect selected interchangeable sensor modules.

The port should expose:

- 3.3V
- GND
- SDA
- SCL

The goal is not to support every possible I²C device automatically. Instead, UI-MT will include a defined list of supported modules that can be selected from the interface.

---

### UART / GPIO / Signal Output Interface

UI-MT should expose a small external interface for electronics utility functions.

Possible pins/functions:

- UART TX
- UART RX
- GND
- GPIO probe input
- ESP32 PWM/square-wave output
- AD9833 waveform output
- optional 3.3V reference output

These pins should be clearly labeled and protected where appropriate.

---

### AD9833 Waveform Generator Module

The AD9833 module is the dedicated waveform-generation hardware for UI-MT.

It is used for:

- sine-wave output
- triangle-wave output
- square-wave output
- frequency-controlled test signals
- saved waveform presets
- simple electronics experiments and signal injection at safe low levels

The ESP32 controls the AD9833 through SPI. The AD9833 output should be treated as a low-power signal output, not a power driver.

Recommended AD9833 UI settings:

- waveform type: sine, triangle, square
- frequency value
- start/stop output
- preset save/load
- output warning screen

Important limitations:

- output amplitude depends on the AD9833 module design
- output is not meant to directly drive motors, speakers, relays, or high-current loads
- external amplification or buffering would be needed for stronger output
- this is not intended to replace a professional function generator

---

### Power Circuit

The power system is responsible for:

- battery-powered operation
- voltage regulation
- safe current delivery
- powering the main ESP32
- powering the TFT display
- powering the SD module
- powering the RTC
- powering the CardKB
- powering the AD9833 module
- powering external low-current sensor modules

The power system should be stable enough to support the display, storage, keyboard, sensors, AD9833 module, and utility interfaces without brownouts.

---

## Target Device Definition

UI-MT is currently defined as:

> A compact ESP32-based handheld terminal and electronics multi-tool with touch input, keyboard input, SD storage, RTC timekeeping, buzzer feedback, passive Wi-Fi/BLE scanning, external I²C sensor support, UART debugging, GPIO probing, AD9833 waveform generation, and simple ESP32 PWM output.

This definition replaces earlier broader concepts that attempted to include too many advanced or unnecessary features at once.

---

## Core Features

### 1. System Dashboard / Handheld Control Panel

The dashboard is the central launcher and status screen.

Planned capabilities:

- boot screen
- home screen
- tool launcher
- current time display
- SD card status
- Wi-Fi/BLE status
- battery/power indicator
- active module indicator
- recent activity summary
- quick access to main tools

---

### 2. File Manager / Logger / Data Recorder

The file manager turns UI-MT into a portable storage and logging terminal.

Planned capabilities:

- browse SD card folders
- open supported text files
- create new files
- save logs
- save scan results
- save sensor readings
- save serial terminal output
- save GPIO logs
- save signal generator presets
- organize files by tool type
- support predictable folder paths

Example folder structure:

```text
/ui-mt/
  notes/
  logs/
  wifi/
  ble/
  sensors/
  uart/
  gpio/
  signal/
  pwm/
  refs/
  config/
```

---

### 3. Journal / Notes / Text Workspace

The journal is a lightweight text workspace for field notes and project documentation.

Planned capabilities:

- create notes
- edit text files
- save timestamped entries
- write project logs
- create quick observations
- use CardKB for text entry
- optionally support simple sketch/touch notes later

Example use cases:

- wiring notes
- lab observations
- sensor test notes
- debug logs
- project ideas
- quick reminders

---

### 4. Wi-Fi Scanner / Network Viewer

The Wi-Fi scanner is a passive observation tool.

Planned capabilities:

- scan nearby Wi-Fi networks
- display SSID
- display RSSI
- display channel
- display encryption/security type
- display scan timestamp
- save scan results to SD
- review previous scan logs

This feature is for passive viewing and logging only.

---

### 5. BLE Scanner / Beacon Viewer

The BLE scanner is a passive nearby-device discovery tool.

Planned capabilities:

- scan nearby BLE devices
- display device name when available
- display device address/identifier
- display RSSI
- display scan timestamp
- save scan logs to SD
- review previous BLE observations

This feature is for passive viewing and logging only.

---

### 6. Portable Text Console / Command Terminal

The console provides a typed local interface for power-user workflows.

Planned capabilities:

- enter commands using CardKB
- view command output
- run internal system commands
- launch tools
- check system status
- scan I²C bus
- trigger Wi-Fi scan
- trigger BLE scan
- inspect storage state
- inspect RTC status
- open UART terminal
- read GPIO state
- start/stop ESP32 PWM output
- configure AD9833 waveform output

Example commands:

```text
help
status
time
ls /logs
scan wifi
scan ble
i2c scan
uart open 115200
gpio read
pwm start 1000 50
sig sine 1000
sig triangle 500
sig square 2000
sig stop
```

---

### 7. Config Editor / Profile Manager

The configuration system stores device settings and user preferences.

Planned capabilities:

- edit settings
- save profiles
- store UI preferences
- store keyboard behavior
- store module settings
- store UART baud presets
- store ESP32 PWM presets
- store AD9833 signal presets
- store sensor calibration values
- export/import configuration files

Example config files:

```text
/config/system.json
/config/ui.json
/config/modules.json
/config/uart_profiles.json
/config/pwm_presets.json
/config/signal_presets.json
```

---

### 8. Offline Reference Tool

The reference tool allows UI-MT to remain useful without internet access.

Planned capabilities:

- view saved reference files
- view wiring notes
- view pinout references
- view supported module notes
- view command references
- view project documentation
- view troubleshooting checklists
- view AD9833 usage notes

Example reference categories:

```text
/refs/
  esp32_pinout.txt
  cardkb_notes.txt
  i2c_modules.txt
  uart_reference.txt
  gpio_reference.txt
  pwm_reference.txt
  ad9833_reference.txt
  wiring_notes.txt
```

---

### 9. External I²C Modular Sensor Port / I²C Bus Scanner / Diagnostics

The external I²C tool allows selected modules to be connected and read.

Planned capabilities:

- scan external I²C bus
- display detected addresses
- match addresses to known supported modules
- allow user to select a module from a predefined list
- read live module data
- save sensor readings to SD
- display module information
- display basic wiring reminders
- show simple troubleshooting messages

Example module selection menu:

```text
External I2C Modules
  BME280   - Temp / Humidity / Pressure
  BH1750   - Light Intensity
  SCD41    - CO2 / Temp / Humidity
  MLX90614 - IR Temperature
  INA219   - Voltage / Current
  MPU6050  - Accelerometer / Gyroscope
  ADS1115  - External ADC
  I2C Scan - Address Scanner
```

Example scan output:

```text
I2C Scan Result:
0x23 detected -> possible BH1750
0x76 detected -> possible BME280
0x68 detected -> possible MPU6050 or RTC
```

The module list should be curated instead of fully open-ended. This keeps the interface simple and makes development realistic.

---

### 10. UART Serial Terminal

The UART terminal allows UI-MT to act as a small serial monitor/debug tool.

Planned capabilities:

- select baud rate
- open UART session
- send typed commands using CardKB
- display received serial data
- save serial logs to SD
- support common baud presets
- show TX/RX status
- timestamp serial logs when enabled

Example baud presets:

```text
9600
19200
38400
57600
115200
230400
921600
```

Example storage:

```text
/uart/uart_2026-05-01_145500.txt
```

---

### 11. GPIO / Logic Probe Basic Tool

The GPIO probe tool provides basic digital signal checking.

Planned capabilities:

- read digital HIGH/LOW state
- detect state changes
- display pin state
- optional buzzer alert on change
- simple pulse detection
- slow frequency estimate where practical
- save state logs to SD

This is not intended to replace a real oscilloscope or logic analyzer. It is a simple field-checking tool for low-speed signals.

Example screen:

```text
GPIO Probe
Pin: GPIO34
State: HIGH
Last Change: 14:22:08
Logging: ON
```

---

### 12. AD9833 Signal Generator / PWM Tool

The signal generator tool provides basic signal output for testing and experimentation.

This tool has two output modes:

1. **AD9833 waveform mode**
   - sine wave
   - triangle wave
   - square wave
   - frequency-controlled output
   - preset save/load

2. **ESP32 PWM mode**
   - logic-level square-wave/PWM output
   - selectable frequency
   - selectable duty cycle
   - start/stop output
   - preset save/load

Planned capabilities:

- select AD9833 or ESP32 PWM mode
- select waveform type in AD9833 mode
- set frequency
- set duty cycle for PWM mode
- start/stop output
- save presets
- display warning for voltage/current limits
- show output pin information

Example AD9833 settings:

```text
Signal Generator
Mode: AD9833
Waveform: Sine
Frequency: 1000 Hz
Output: Enabled
```

Example ESP32 PWM settings:

```text
PWM Output
Pin: GPIO25
Frequency: 1000 Hz
Duty Cycle: 50%
State: Running
```

This feature is for low-voltage signal testing only. It is not intended to drive high-current loads or replace professional signal-generation equipment.

---

## External I²C Module System

The external I²C system is designed around a curated list of supported modules.

Instead of trying to automatically support every I²C device, UI-MT will provide a selectable list of known modules. Each supported module can have its own screen, data formatting, logging format, and reference notes.

### Suggested Supported Modules

| Module | Purpose | Typical Data |
|---|---|---|
| BME280 | Environmental sensor | temperature, humidity, pressure |
| BH1750 | Light sensor | lux |
| SCD41 | CO2 sensor | CO2, temperature, humidity |
| MLX90614 | IR temperature sensor | object temp, ambient temp |
| INA219 | Power monitor | voltage, current, power |
| MPU6050 | Motion sensor | acceleration, gyroscope |
| ADS1115 | External ADC | analog voltage readings |

### I²C Tool Modes

Possible modes:

- Scan Bus
- Select Module
- Read Live Data
- Log Data
- View Module Info
- View Wiring Notes
- Save Reading

Example module info screen:

```text
BME280
Address: 0x76 / 0x77
Interface: I2C
Data: Temp, Humidity, Pressure
Power: 3.3V recommended
Pins: VIN, GND, SDA, SCL
```

---

## Signal Generator System

The signal generator system is built around the AD9833 module and the ESP32's built-in PWM capability.

### AD9833 Mode

The AD9833 module is used when UI-MT needs a dedicated waveform output.

Supported waveform targets:

- sine wave
- triangle wave
- square wave

Suggested controls:

- waveform type
- frequency
- output enable/disable
- preset save/load
- output warning screen

Suggested preset examples:

```text
/signal/presets.json
  1000Hz_sine
  500Hz_triangle
  2000Hz_square
```

### ESP32 PWM Mode

ESP32 PWM mode is used for simple digital square-wave or PWM output.

Suggested controls:

- output pin
- frequency
- duty cycle
- start/stop
- preset save/load

This mode is useful for simple logic-level tests, LED dimming experiments, buzzer experiments, and low-voltage embedded testing.

### Output Safety

Both AD9833 and ESP32 PWM outputs should be treated as low-power signals.

Do not connect the outputs directly to:

- motors
- relays
- speakers
- solenoids
- high-current loads
- high-voltage circuits
- unknown external systems

Use proper buffering, protection, or amplification if stronger output is needed.

---

## Storage Model

The project uses two types of persistent storage.

### SD Card Storage

Used for user-accessible files:

- notes
- logs
- scan results
- references
- UART logs
- GPIO logs
- sensor logs
- PWM presets
- AD9833 signal presets
- configuration exports

Recommended folder structure:

```text
/ui-mt/
  notes/
  logs/
  wifi/
  ble/
  sensors/
  uart/
  gpio/
  signal/
  pwm/
  refs/
  config/
```

### Internal Persistent Storage

Used for lightweight device-specific settings:

- selected preferences
- boot state
- calibration values
- internal flags
- current profile
- last-used tool
- UI state

This split keeps user data portable while preserving device-specific settings internally.

---

## Timekeeping and Logging

The RTC is part of the locked hardware because time-aware data is fundamental to the project.

Planned uses:

- dashboard clock
- timestamp journal entries
- timestamp Wi-Fi scans
- timestamp BLE scans
- timestamp sensor logs
- timestamp UART logs
- timestamp GPIO logs
- timestamp configuration changes
- create organized filenames

Example timestamped files:

```text
/notes/note_2026-05-01_141500.txt
/wifi/wifi_scan_2026-05-01_142000.csv
/uart/uart_2026-05-01_145500.txt
/gpio/gpio_2026-05-01_150000.txt
/signal/signal_preset_2026-05-01_151000.json
```

Timekeeping is treated as a core system service, not an optional accessory.

---

## Input and Interface Model

UI-MT uses a hybrid input model:

- touch screen for direct menu interaction
- CardKB keyboard for text entry and shortcuts
- stylus for touch precision
- console commands for fast technical workflows

The CardKB replaces the previous two-button navigation concept.

### Input Roles

| Input Method | Role |
|---|---|
| Touch | menus, selection, UI controls |
| Stylus | precise touch, optional drawing/sketching |
| CardKB | text entry, commands, filenames, shortcuts |
| Console | advanced navigation and tool control |

### Possible Keyboard Shortcuts

```text
Ctrl + N  -> New note
Ctrl + S  -> Save
Ctrl + W  -> Wi-Fi scan
Ctrl + B  -> BLE scan
Ctrl + I  -> I2C scan
Ctrl + U  -> UART terminal
Ctrl + G  -> GPIO probe
Ctrl + P  -> PWM tool
Ctrl + F  -> AD9833 signal generator
```

---

## Electrical Tooling Scope

UI-MT includes a small set of electronics utility tools.

### Included

- external I²C scanning
- selected I²C module reading
- UART serial terminal
- GPIO digital state reading
- basic pulse/state-change detection
- ESP32 PWM/square-wave output
- AD9833 sine/triangle/square-wave output

### Not Included

- oscilloscope replacement
- high-speed logic analyzer
- professional arbitrary waveform generator
- RF test equipment
- high-voltage measurement
- high-current output
- active wireless attack tooling

The electrical tools are intended for low-voltage embedded development and simple debugging tasks.

---

## Software Architecture Goals

The firmware should be modular and organized around clear responsibilities.

### Recommended Top-Level Structure

```text
src/
  main.cpp

  app/
    app.cpp
    app.h
    navigation.cpp
    navigation.h
    state_machine.cpp
    state_machine.h

  drivers/
    display.cpp
    display.h
    touch.cpp
    touch.h
    cardkb.cpp
    cardkb.h
    sdcard.cpp
    sdcard.h
    rtc.cpp
    rtc.h
    buzzer.cpp
    buzzer.h
    power.cpp
    power.h
    gpio_tool.cpp
    gpio_tool.h
    pwm_tool.cpp
    pwm_tool.h
    ad9833.cpp
    ad9833.h
    uart_tool.cpp
    uart_tool.h
    i2c_bus.cpp
    i2c_bus.h

  services/
    logger.cpp
    logger.h
    file_service.cpp
    file_service.h
    notes_service.cpp
    notes_service.h
    wifi_service.cpp
    wifi_service.h
    ble_service.cpp
    ble_service.h
    console_service.cpp
    console_service.h
    config_service.cpp
    config_service.h
    reference_service.cpp
    reference_service.h
    i2c_module_service.cpp
    i2c_module_service.h
    uart_service.cpp
    uart_service.h
    gpio_service.cpp
    gpio_service.h
    pwm_service.cpp
    pwm_service.h
    signal_generator_service.cpp
    signal_generator_service.h

  ui/
    screens/
      boot_screen.cpp
      home_screen.cpp
      files_screen.cpp
      notes_screen.cpp
      wifi_screen.cpp
      ble_screen.cpp
      console_screen.cpp
      config_screen.cpp
      references_screen.cpp
      i2c_screen.cpp
      uart_screen.cpp
      gpio_screen.cpp
      pwm_screen.cpp
      signal_generator_screen.cpp
```

### Architecture Principles

- keep hardware drivers isolated from UI logic
- keep UI screens separate from backend services
- avoid monolithic application code
- define ownership of each peripheral clearly
- keep storage paths predictable
- use simple file formats where possible
- design tools as independent modules
- make future expansion possible without destabilizing the base system
- prioritize reliability over feature quantity

---

## Design Priorities

The project follows these priorities:

1. Reliability
2. Usability
3. Clear modular architecture
4. Offline-first usefulness
5. Storage and data integrity
6. Responsive UI
7. Keyboard-friendly workflows
8. Practical electronics utility
9. Safe low-voltage operation
10. Expandability after stable integration

This project favors a smaller polished system over a larger unstable one.

---

## Development Roadmap

### Phase 1 — Core Platform Bring-Up

- ESP32 board setup
- TFT display test
- touch test
- CardKB input test
- SD card test
- RTC test
- buzzer test
- power system test

### Phase 2 — Base UI

- boot screen
- dashboard
- menu navigation
- status bar
- clock display
- keyboard shortcuts
- basic settings screen

### Phase 3 — Storage and Notes

- SD folder structure
- file browser
- text file viewer
- note creation
- note saving
- timestamped entries
- reference file viewer

### Phase 4 — Wireless Tools

- Wi-Fi scanner
- Wi-Fi scan logging
- BLE scanner
- BLE scan logging
- saved scan viewer

### Phase 5 — Console and Configuration

- command console
- basic commands
- config files
- profile handling
- settings editor
- command shortcuts

### Phase 6 — External I²C Tools

- external I²C scanner
- supported module selector
- module info pages
- live sensor readings
- sensor logging
- wiring reference notes

### Phase 7 — Electronics Utility Tools

- UART serial terminal
- GPIO probe mode
- state-change detection
- ESP32 PWM output
- AD9833 waveform output
- signal generator presets
- logging where useful

### Phase 8 — Refinement

- improve UI layout
- improve error handling
- improve file organization
- add user feedback sounds
- improve documentation
- add photos/screenshots
- create wiring diagrams
- prepare final enclosure concept

---

## Current Status

Current project status:

- concept redefined
- objective list re-locked
- camera feature removed from scope
- ESP32-CAM removed from hardware plan
- 2-button input removed
- CardKB keyboard added as the primary text input device
- external I²C modular sensor port added
- UART/GPIO/PWM utility tools added
- AD9833 waveform generator added
- local web portal removed from current objective list

The next major step is hardware bring-up and testing each core module individually before combining them into the full UI-MT system.

---

## Non-Goals

UI-MT is not intended to be:

- a smartphone replacement
- a general-purpose Linux handheld
- a full cyberdeck computer
- a hacking device
- a wireless attack platform
- a high-speed lab instrument
- a professional oscilloscope
- a professional logic analyzer
- a professional signal generator
- a camera system
- a cloud-dependent device

The purpose is to build a compact, understandable, useful embedded handheld terminal for electronics, logging, references, and modular field tools.

---

## Vision

UI-MT is a personal embedded systems project built around the idea of useful, focused technology.

The project combines:

- handheld computing
- embedded systems
- local storage
- real hardware interfaces
- field notes
- wireless observation
- modular sensors
- serial debugging
- GPIO probing
- ESP32 PWM output
- AD9833 waveform generation
- offline references

The long-term goal is to create a small, practical, self-contained device that feels like a real engineering companion: something that can sit on a workbench, go into a backpack, help with hardware debugging, store notes, read sensors, generate basic test signals, and provide offline references.

UI-MT should feel like a modern DIY version of an older dedicated handheld tool: focused, tactile, useful, and built with purpose.

---

## License

This project is licensed under the MIT License.
