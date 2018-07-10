			/*******************************************************************
			*   Source Code Simulation.cpp
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

void Simulation::InitializeSimulation() {
	//Call the file parser
	char* filename = "./SensorData1.xml";
    EnviroSimDataParser fparser = EnviroSimDataParser(filename);

	//Create a bunch of temporary pointers
    char* type = new char;
    char* material = new char;
    int* ID = new int;
    char* units = new char;
    double* minVal = new double;
    double* maxVal = new double;
    bool read = true;
	
    char* displaytype = new char;
    int* displayid = new int;
    int* displayidcount = new int;
	this->SensorList = SensorMount();

	//Read the file, pass the sensors to Sensor List
    read = fparser.getSensorData(type, material, ID, units, minVal, maxVal);
    SensorList.addSensor( Sensor(5, *ID, *minVal, *maxVal, type, material, units) );
    while(read) {
        read = fparser.getSensorData(type, material, ID, units, minVal, maxVal);
        SensorList.addSensor( Sensor(5, *ID, *minVal, *maxVal, type, material, units) );
    }

	//Pass the Displays to the Sensor Mount
    while(fparser.getDisplayData(displaytype, displayid, displayidcount)) {
		SensorList.addDisplay(Display(displayid, *displayidcount, displaytype));
        for(int i = 0; i < *displayidcount; i++) {
        }
    }
	//Attach them all
	this->SensorList.attachDisplays();
}

void Simulation::RunSimulation() {

	while(true) {
		//Clear screen so its pretty, display the data, make new data, sleep for 5 seconds
		system("cls");

		SensorList.DisplayData();
		SensorList.GenerateData();
		Sleep(5000);
	}
}

Simulation::Simulation() {

}