# Universal Interface Multi-Tool (UI-MT)

![Status](https://img.shields.io/badge/status-planning%20%2F%20prototype-orange)
![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![UI](https://img.shields.io/badge/interface-TFT%20Touch%20%2B%20CardKB-purple)
![Storage](https://img.shields.io/badge/storage-microSD-green)
![Clock](https://img.shields.io/badge/timekeeping-RTC-lightgrey)
![License](https://img.shields.io/badge/license-MIT-brightgreen)

A compact ESP32-based handheld terminal and electronics multi-tool with touch input, keyboard input, local storage, camera capture, wireless scanning, external I²C module support, UART debugging, GPIO probing, and basic signal generation.

---

## Table of Contents

- [Overview](#overview)
- [Design Inspiration](#design-inspiration)
- [Locked Scope](#locked-scope)
  - [Official Objective List](#official-objective-list)
  - [Excluded From Current Scope](#excluded-from-current-scope)
- [Hardware](#hardware)
  - [Locked Hardware Set](#locked-hardware-set)
  - [Hardware Roles](#hardware-roles)
- [Target Device Definition](#target-device-definition)
- [Core Features](#core-features)
- [External I²C Module System](#external-i²c-module-system)
- [ESP32-CAM Camera Module Architecture](#esp32-cam-camera-module-architecture)
- [Storage Model](#storage-model)
- [Timekeeping and Logging](#timekeeping-and-logging)
- [Input and Interface Model](#input-and-interface-model)
- [Electrical Tooling Scope](#electrical-tooling-scope)
- [Software Architecture Goals](#software-architecture-goals)
- [Design Priorities](#design-priorities)
- [Development Roadmap](#development-roadmap)
- [Current Status](#current-status)
- [Non-Goals](#non-goals)
- [Vision](#vision)
- [License](#license)

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
- ESP32-CAM module for image capture
- external I²C expansion port
- UART/GPIO/PWM utility functions
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

## Locked Scope

### Official Objective List

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

9. **Camera Capture / Visual Logger**

   A visual logging system using an ESP32-CAM module as a dedicated camera accessory. The main ESP32 controls capture commands and stores images on the main SD card.

10. **External I²C Modular Sensor Port / I²C Bus Scanner / Diagnostics**

    An external I²C expansion system that allows selected sensor modules to be connected, scanned, identified, read, and logged.

11. **UART Serial Terminal**

    A basic serial monitor/debug terminal for communicating with external UART devices, sending typed commands, reading incoming data, and saving serial logs.

12. **GPIO / Logic Probe Basic Tool**

    A simple GPIO probing tool for reading digital HIGH/LOW states, detecting state changes, checking simple pulses, and observing basic logic behavior.

13. **Simple Signal Generator / PWM Tool**

    A basic output tool for generating square-wave/PWM signals with selectable frequency and duty cycle for simple testing and experimentation.

---

### Excluded From Current Scope

The following are intentionally excluded from the current version:

- active Wi-Fi attack tools
- BLE attack tools
- RF jamming
- RF spoofing
- sub-GHz transmission
- IR transmission
- advanced logic analyzer features
- high-speed oscilloscope functions
- advanced waveform generation
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
- ESP32-CAM module as a dedicated camera accessory
- external I²C expansion port for modular sensors
- exposed UART interface for serial terminal mode
- exposed GPIO input/output pins for probing and PWM output

The previous 2-button input system has been removed from the official hardware direction. Keyboard input through the CardKB replaces the need for dedicated navigation buttons.

---

### Hardware Roles

#### ESP32 Main Controller

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
- PWM/signal output
- coordinating the ESP32-CAM module

The main ESP32 is the central controller of the UI-MT system.

---

#### SPI TFT Display + Touch Panel

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
- camera status
- UART terminal output
- GPIO/PWM tool screens

The touch panel provides direct menu navigation, selection, and interaction with on-screen controls.

---

#### M5Stack CardKB V1.1 Mini Keyboard

The CardKB acts as the main text input device.

It is used for:

- writing notes
- entering console commands
- naming files
- searching files/references
- typing UART commands
- navigating menus with key shortcuts
- editing configuration values

This changes UI-MT from a simple touchscreen gadget into a small handheld terminal.

---

#### SD Card Module

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
- captured images
- configuration exports
- offline reference files

The SD card is the main user-accessible storage system.

---

#### RTC Module

The RTC module provides offline timekeeping.

It is used for:

- dashboard clock
- timestamped notes
- timestamped scan logs
- timestamped sensor readings
- timestamped camera captures
- timestamped serial logs
- organized filenames

The RTC allows UI-MT to remain useful even without internet time synchronization.

---

#### Buzzer

The buzzer provides simple audio feedback.

It is used for:

- button/key feedback
- alerts
- warnings
- capture confirmation
- scan completion
- low battery warning
- GPIO state-change alert
- system notifications

---

#### ESP32-CAM Module

The ESP32-CAM is treated as a secondary camera subsystem, not as the main controller.

It is used for:

- initializing the camera
- capturing JPEG images
- sending image data to the main ESP32
- reporting capture status

The main ESP32 remains responsible for UI, storage, naming, and file organization.

---

#### External I²C Port

The external I²C port allows UI-MT to connect selected interchangeable sensor modules.

The port should expose:

- 3.3V
- GND
- SDA
- SCL

The goal is not to support every possible I²C device automatically. Instead, UI-MT will include a defined list of supported modules that can be selected from the interface.

---

#### UART / GPIO / PWM Interface

UI-MT should expose a small external interface for electronics utility functions.

Possible pins/functions:

- UART TX
- UART RX
- GND
- GPIO probe input
- GPIO output
- PWM/square-wave output
- optional 3.3V reference output

These pins should be clearly labeled and protected where appropriate.

---

#### Power Circuit

The power system is responsible for:

- battery-powered operation
- voltage regulation
- safe current delivery
- powering the main ESP32
- powering the TFT display
- powering the SD module
- powering the RTC
- powering the CardKB
- powering the ESP32-CAM
- powering external low-current sensor modules

The ESP32-CAM should receive stable power because camera capture can cause current spikes.

---

## Target Device Definition

UI-MT is currently defined as:

> A compact ESP32-based handheld terminal and electronics multi-tool with touch input, keyboard input, SD storage, RTC timekeeping, buzzer feedback, camera capture, passive Wi-Fi/BLE scanning, external I²C sensor support, UART debugging, GPIO probing, and simple PWM signal generation.

This definition replaces earlier broader concepts that attempted to include too many advanced or unsafe features at once.

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
- save camera images
- organize files by tool type
- support predictable folder paths

Example folder structure:

```text
/ui-mt/
  notes/
  logs/
  photos/
  wifi/
  ble/
  sensors/
  uart/
  gpio/
  pwm/
  refs/
  config/
