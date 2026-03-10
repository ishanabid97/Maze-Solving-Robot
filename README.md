# Maze Solving Robot

This project is an autonomous maze solving robot built using an Arduino Uno. The robot navigates a line maze using the Left-Hand Rule algorithm. A 5-channel BFD1000 line sensor detects the maze path, while an L298N motor driver controls two DC motors to move the robot through the maze.

## Components Used

- Arduino Uno
- BFD1000 5-Channel Line Sensor
- L298N Motor Driver
- 2 × DC Motors
- Robot Chassis
- 2 × Wheels
- 1 × Caster Wheel
- Battery Pack / Power Supply
- Jumper Wires

## Algorithm

The robot follows the **Left-Hand Rule** for maze solving.  
This algorithm prioritizes movement in the following order:

1. Turn Left
2. Move Forward
3. Turn Right
4. Turn Back (if no path is available)

Using this method, the robot can systematically navigate and solve line mazes.

## How It Works

The BFD1000 5-channel line sensor continuously reads the maze lines and sends signals to the Arduino Uno. The Arduino processes these signals and determines the robot's movement based on the Left-Hand Rule algorithm. The L298N motor driver receives control signals from the Arduino and drives the two DC motors to move the robot.
