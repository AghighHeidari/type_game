# Typist --- CLI Typing Game (C++)

A command-line typing game built in C++ that helps users improve typing
speed and accuracy through timed challenges and multi-level progression.

------------------------------------------------------------------------

## Overview

This project was developed as an academic course project.\
It implements a console-based typing trainer with:

-   Multiple levels of increasing difficulty
-   Speed and accuracy calculation
-   Persistent progress and statistics
-   Console color feedback for correct and incorrect input

------------------------------------------------------------------------

## Features

-   Main menu (Start Game / View Stats / Exit)
-   Multiple typing levels using text prompts
-   Real-time performance tracking
-   Accuracy and speed calculation
-   Statistics stored in text files
-   Color-coded console feedback (Windows)

------------------------------------------------------------------------

## Project Structure

-   `main.cpp` --- Core game logic, scoring, file handling, and level
    control
-   `clui.h` --- Console UI utilities (color handling)
-   `one.txt`, `two.txt`, `three.txt` --- Typing prompts for each level
-   `level.txt` --- Stores current player level
-   `statcorrect.txt`, `statwrong.txt`, `stataccuracy.txt` --- Saved
    statistics

------------------------------------------------------------------------

## Technologies Used

-   C++
-   CMake
-   Command Line Interface (CLI)

------------------------------------------------------------------------

## Build Instructions (Windows)

``` bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the executable from the repository root so the required text files
can be accessed.

------------------------------------------------------------------------

## Skills Demonstrated

-   C++ program structure and modular design
-   File input/output handling
-   Console-based UI implementation
-   Performance metric calculation (speed & accuracy)
-   Basic build system configuration using CMake

------------------------------------------------------------------------

This repository is shared as an academic learning project and is not
actively maintained.
