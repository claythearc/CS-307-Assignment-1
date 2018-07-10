			/*******************************************************************
			*   Source Code Main.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#include <iostream>
#include "stdafx.h"
#include "EnviroSimDataParser.h"
#include "Sensor.h"
#include <vector>
#include "SensorMount.h"
#include "Display.h"
#include <stdlib.h>
#include <Windows.h>
#include "Simulation.h"


#define _CRT_SECURE_NO_WARNINGS // Shut up MS, about strcpy(), etc.	



int main() {
	Simulation Sim = Simulation(); //Creates the Simulation Object
	Sim.InitializeSimulation(); //Sets all Variables
	Sim.RunSimulation(); //Loops
    return 0;
}