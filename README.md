# Action Sudoku Game README
## Overview
This project involves the development of a game, focusing on object-oriented programming, graphical user interfaces, and game mechanics. The game is developed in C++ using the wxWidgets framework for the graphical interface.

## Key Features
Dynamic Gameplay: The game features different levels with varying challenges and objectives.<br />
Interactivity: Includes mouse and keyboard event handling for interactive gameplay.<br />
Graphical Interface: Utilizes wxGraphicsContext for drawing the game elements and managing graphical states.<br />
Game Mechanics: Incorporates elements like scoring, levels, and character actions (eating, regurgitating, etc.).<br />
Visitor Pattern: Implements visitor design patterns for different game items like containers, numbers, and potions.<br />
## Components
Game Class:<br />
Manages game states, updates, and rendering.<br />
Handles user interactions and events.<br />
Item Classes (Sparty, Number, XRay, etc.):<br />
Define various game elements and their behaviors.<br />
Board Class:<br />
Represents the game board and manages item placements and interactions.<br />
FPS Display:<br />
Displays the frame rate of the game.<br />
Declaration Classes:<br />
Facilitate the creation of game items from XML configurations.<br />
## Gameplay
The player interacts with the game using the mouse and keyboard.<br />
Specific keys are designated for different actions like eating, headbutting, and number regurgitation.<br />
The game progresses through various levels, each with unique challenges.<br />
## Technical Details
Language: C++<br />
Graphics Framework: wxWidgets<br />
Pattern Used: Visitor pattern for item interactions.<br />
XML Configuration: Levels and items are configured using XML files.<br />
## Building and Running
Prerequisites:<br />
C++ compiler (supporting C++17 or later)<br />
wxWidgets library<br />
Compilation:<br /><br />
Use a compatible C++ IDE or makefile to compile the source code.<br />
## Execution:
Run the compiled executable to start the game.<br />

