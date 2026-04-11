# Universal Interface Multi-Tool (UI-MT)

![Status](https://img.shields.io/badge/status-scoped%20and%20planning-blue)
![Platform](https://img.shields.io/badge/platform-ESP32-green)
![UI](https://img.shields.io/badge/UI-TFT%20Touch-orange)
![Storage](https://img.shields.io/badge/storage-SD%20Card-lightgrey)
![Clock](https://img.shields.io/badge/time-RTC-yellow)
![Power](https://img.shields.io/badge/power-battery%20powered-red)

A portable **ESP32-based handheld interface terminal** with touchscreen UI, local storage, timekeeping, wireless scanning, journaling, file management, and a basic local web portal.

---

## Table of Contents

- [Overview](#overview)
- [Locked Scope](#locked-scope)
  - [Included Objectives](#included-objectives)
  - [Excluded From Current Scope](#excluded-from-current-scope)
- [Hardware](#hardware)
  - [Locked Hardware Set](#locked-hardware-set)
  - [Hardware Roles](#hardware-roles)
- [Target Device Definition](#target-device-definition)
- [Core Features](#core-features)
- [Design Priorities](#design-priorities)
- [Software Architecture Goals](#software-architecture-goals)
- [Storage Model](#storage-model)
- [Timekeeping and Logging](#timekeeping-and-logging)
- [Wireless Scope](#wireless-scope)
- [Power and Field Use](#power-and-field-use)
- [Development Roadmap](#development-roadmap)
- [Current Status](#current-status)
- [Non-Goals](#non-goals)
- [Vision](#vision)
- [License](#license)

---

## Overview

Universal Interface Multi-Tool (UI-MT) is a compact, battery-powered embedded handheld built around the ESP32.

This project is scoped around a practical and finishable first version: a responsive touchscreen device that can:

- boot reliably
- navigate a polished UI
- store and manage files
- keep accurate time
- record notes and sketches
- scan nearby Wi-Fi and BLE activity
- expose a local text console
- display offline references
- host a basic local web interface

The goal of this phase is to build a dependable **base platform first**. More advanced instrumentation and expansion features may be considered later, but they are **not part of the current locked scope**.

---

## Design Inspiration

This project is heavily inspired by handheld devices from the 2000s and the pre-smartphone era.

What stands out to me about those devices is that they were often minimalist, focused, and genuinely useful. They were not trying to be everything at once. They provided direct interfaces, practical tools, and a form factor that encouraged real-world use instead of constant distraction.

That idea is central to UI-MT.

Rather than designing this project as a mini smartphone, I want it to feel more like a dedicated handheld instrument: simple, purposeful, tactile, and reliable. The interface should be clean and effective. Navigation should be understandable. Features should exist because they are useful, not because they are flashy.

The inspiration from older handheld systems influences both the hardware and software direction of the project:

- a compact self-contained device
- a focused UI with clear tool access
- offline-first usefulness
- touch and button interaction
- lightweight feedback through visuals and sound
- practical features such as logging, journaling, scanning, and file access

UI-MT is meant to carry forward that older design philosophy into a modern DIY embedded platform.

## Locked Scope

### Included Objectives

The current project scope includes the following nine objectives:

1. **System dashboard / handheld control panel**  
   A touchscreen-based home screen and navigation shell for launching tools, viewing system state, and adjusting device behavior.

2. **File manager / logger / data recorder**  
   Browse files on SD storage, create and save logs, organize user data, and record device events.

3. **Drawing pad / journal / touch notebook**  
   Support touch-based drawing, quick notes, and timestamped journaling using the touchscreen and stylus.

4. **Wi-Fi scanner / network viewer**  
   Scan nearby Wi-Fi networks and display information such as SSID, RSSI, security type, and scan time.

5. **BLE scanner / beacon viewer**  
   Discover nearby Bluetooth Low Energy devices and display identifiers, RSSI, and related scan data.

6. **Portable text console / command terminal**  
   Provide a local text-based command interface for device tools, diagnostics, and power-user functions.

7. **Config editor / profile manager**  
   Store and edit device settings, UI preferences, calibration data, and user profiles.

8. **Offline reference tool**  
   View locally stored notes, reference material, checklists, and technical lookup content from SD storage.

9. **Mini web device / local portal**  
   Host a simple local web interface for status viewing, basic file access, and limited device interaction over Wi-Fi.

### Excluded From Current Scope

The following are intentionally excluded from the present version:

- ESP-NOW peer features
- RF transmission modules
- IR transmission modules
- waveform generation
- protocol injection tools
- logic analyzer features
- external bus tools such as UART/I2C/SPI probing hardware
- advanced scripting engines
- broad multi-protocol expansion hardware

These may be considered in future phases, but they are **not part of V1**.

---

## Hardware

### Locked Hardware Set

The hardware for the current version is locked to:

- **ESP32**
- **SPI TFT display**
- **Touch panel with stylus**
- **SD card module**
- **RTC module**
- **Buzzer**
- **Power circuit**
- **2 physical buttons**

### Hardware Roles

#### ESP32
Main controller responsible for UI logic, storage access, wireless scanning, configuration management, local services, and overall coordination.

#### TFT Display
Primary visual output for menus, tools, status views, file browsing, scan results, and journaling functions.

#### Touch Panel + Stylus
Primary interactive input for navigation, selection, drawing, and text entry through on-screen controls.

#### SD Card Module
Mass storage for user files, logs, journal entries, references, and exported data.

#### RTC Module
Provides accurate real-time clock data for timestamps, logs, journaling, and time display when offline.

#### Buzzer
Supplies audible feedback for UI actions, alerts, warnings, and confirmations.

#### Power Circuit
Handles battery-powered operation, charging, voltage regulation, and basic power-state monitoring.

#### Two Physical Buttons
Provide reliable hardware input for navigation, recovery, shortcuts, and boot-time modes.

---

## Target Device Definition

UI-MT is currently defined as:

> A battery-powered ESP32 handheld interface terminal with touchscreen UI, SD storage, RTC timekeeping, buzzer feedback, two physical buttons, Wi-Fi and BLE scanning, journaling and file tools, offline references, and a basic local web portal.

This definition replaces earlier broader concepts that attempted to combine too many tool functions into a first release.

---

## Core Features

### 1. Dashboard and Navigation
The system includes a main dashboard that acts as the central launcher and status panel for the device.

Planned capabilities:

- boot screen and startup status
- main menu / home screen
- tool launcher
- battery and clock display
- storage and connectivity indicators
- settings access
- shortcut navigation using touch and buttons

### 2. File Management and Logging
The device acts as a portable file and log terminal.

Planned capabilities:

- browse folders and files on SD card
- create and manage log files
- save scan records
- open and view supported text-based content
- organize user-created notes and references
- record system events and diagnostics

### 3. Journal and Drawing Pad
The notebook feature supports quick field notes and simple sketching.

Planned capabilities:

- touch drawing with stylus
- text-based journal entries
- timestamped entries using RTC
- save note files to SD card
- basic page management
- simple write or sketch workflow

### 4. Wi-Fi Scanner
Passive wireless observation is one of the key built-in utility features.

Planned capabilities:

- scan nearby Wi-Fi networks
- display SSID
- display signal strength
- show basic network metadata
- save scan results to SD card
- review historical scan logs

### 5. BLE Scanner
The BLE scanner provides nearby device discovery and logging.

Planned capabilities:

- scan nearby BLE devices
- display device identifiers when available
- show RSSI
- show scan time
- store scan results
- review previously saved observations

### 6. Local Console
The text console provides a lightweight interface for diagnostics and internal tools.

Planned capabilities:

- enter commands locally through UI controls
- run basic system commands
- inspect device state
- launch tests or utilities
- view command output
- support developer-oriented workflows

### 7. Configuration and Profiles
The project includes a structured configuration system.

Planned capabilities:

- save user preferences
- edit display and UI settings
- store calibration values
- manage profiles or presets
- retain settings across reboot
- import or export config files when appropriate

### 8. Offline Reference Viewer
The device should remain useful without network access.

Planned capabilities:

- browse locally stored reference notes
- display simple technical checklists
- open project documentation copies or field notes
- organize references on SD card
- support personal knowledge storage for offline use

### 9. Local Web Portal
The device includes a minimal web interface accessible over Wi-Fi.

Planned capabilities:

- show a basic status page
- expose selected device information
- allow limited file access
- allow simple upload/download workflows
- provide lightweight remote interaction from a browser on the same network

The web portal is intentionally scoped to remain basic and is **not intended to replace the on-device UI**.

---

## Design Priorities

The project follows these priorities in order:

1. **Reliability**
2. **Usability**
3. **Clear modular architecture**
4. **Storage and data integrity**
5. **Responsive UI**
6. **Low-friction field use**
7. **Feature growth only after stable integration**

This project favors a smaller polished system over a larger unstable one.

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
    sdcard.cpp
    sdcard.h
    rtc.cpp
    rtc.h
    buzzer.cpp
    buzzer.h
    buttons.cpp
    buttons.h
    power.cpp
    power.h

  services/
    logger.cpp
    logger.h
    file_service.cpp
    file_service.h
    journal_service.cpp
    journal_service.h
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
    web_service.cpp
    web_service.h

  ui/
    screens/
      boot_screen.cpp
      home_screen.cpp
      files_screen.cpp
      journal_screen.cpp
      wifi_screen.cpp
      ble_screen.cpp
      console_screen.cpp
      config_screen.cpp
      references_screen.cpp
      diagnostics_screen.cpp
````

### Architecture Principles

* keep hardware drivers isolated from UI logic
* keep UI code separate from services
* avoid monolithic application code
* define ownership of peripherals clearly
* keep storage and configuration paths predictable
* make future extension possible without destabilizing the base platform

---

## Storage Model

The project uses persistent storage in two categories.

### SD Card

Used for:

* user files
* notes and sketches
* logs
* scan records
* offline reference documents
* exported configurations

### Internal Persistent Storage

Used for:

* device settings
* calibration values
* preferences
* lightweight saved state

This split keeps user data portable while preserving device-specific settings internally.

---

## Timekeeping and Logging

The RTC is part of the locked hardware because time-aware data is fundamental to the project.

Planned uses:

* timestamp journal entries
* timestamp scan logs
* display current time on dashboard
* maintain useful records when no network time is available

Timekeeping is treated as a core system service, not an optional accessory.

---

## Wireless Scope

Wireless capability in the current version is passive and administrative in nature.

### Included

* Wi-Fi scanning
* BLE scanning
* local web access

### Excluded

* active attack tooling
* signal injection features
* generalized RF experimentation
* unrelated protocol expansion

This phase is focused on **observation, management, and local interaction** rather than aggressive RF tooling.

---

## Power and Field Use

The power circuit is part of the core platform, not a later add-on.

Design expectations:

* battery-powered operation
* charging support
* regulated supply for stable operation
* power-aware software behavior
* portable handheld form factor

Power stability is critical because the device combines display activity, storage access, and wireless functions.

---

## Development Roadmap

### Phase 1 — Hardware Bring-Up

Initial hardware validation and low-level integration.

**Targets**

* [ ] ESP32 boots reliably
* [ ] display works
* [ ] touch input works
* [ ] SD card is readable and writable
* [ ] RTC reads valid time
* [ ] buzzer works
* [ ] buttons work
* [ ] power circuit is stable

### Phase 2 — Core UI Shell

Build the main user-facing structure.

**Targets**

* [ ] boot screen
* [ ] home screen
* [ ] navigation system
* [ ] settings screen
* [ ] diagnostics screen
* [ ] status indicators

### Phase 3 — Storage and Note Tools

Focus on local usefulness and persistence.

**Targets**

* [ ] file browser
* [ ] logger
* [ ] journal / drawing pad
* [ ] offline reference viewer
* [ ] config save/load

### Phase 4 — Wireless Observation

Add passive wireless features.

**Targets**

* [ ] Wi-Fi scanner
* [ ] BLE scanner
* [ ] scan result logging
* [ ] review of saved scan data

### Phase 5 — Power-User Interfaces

Add advanced service layers after the core is stable.

**Targets**

* [ ] local console
* [ ] mini web portal
* [ ] remote file/status access

---

## Current Status

> **Project State:** Scoped-definition and platform planning

### Status Summary

* [x] project scope reduced and locked for focus
* [x] hardware narrowed to a practical handheld baseline
* [x] objectives 1 through 9 accepted as current scope
* [ ] hardware bring-up started
* [ ] firmware base structure created
* [ ] UI shell implemented
* [ ] file/journal tools implemented
* [ ] wireless tools implemented
* [ ] local portal implemented

At this stage, the priority is **not feature expansion**. The priority is successful bring-up and staged implementation of the locked scope.

---

## Non-Goals

To protect focus, the following are not goals for this version:

* becoming a general-purpose RF tool
* replacing a full laptop-based development workflow
* supporting every embedded bus or protocol
* implementing advanced external instrumentation features
* maximizing feature count at the cost of reliability

This version is about producing a compact, useful, stable handheld interface terminal.

---

## Vision

UI-MT is intended to become a dependable embedded handheld platform that combines interface, storage, observation, journaling, and local access into one portable device.

The current version is deliberately restrained so it can be built well. The long-term value of the project depends on the first phase being reliable, understandable, and extensible.

---

## License

See [`LICENSE`](LICENSE) for license information.

```

Paste that in as your new `README.md`.

Next best step is to add a `PROJECT_ROADMAP.md` and `HARDWARE.md` so the README stays clean while the implementation details grow.
```
