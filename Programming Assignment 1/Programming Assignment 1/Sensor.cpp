			/*******************************************************************
			*   Source Code Sensor.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "Sensor.h"
#include <random>
#include <vector>
#include "Display.h"
#include <iostream>
#include "Message.h"
using namespace std;

//Default constructor, initializes all variables
Sensor::Sensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
    this->id = id;
    this->minValue = minValue;
    this->maxValue = maxValue;
    this ->time = time;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(this->minValue, this->maxValue);
    this->value.push_back(  distribution(generator) );
    this->units = units;
    this->material = material;
    this->name = name;
}

//Blank constructor used in testing.
Sensor::Sensor() {
    this->id = 0;
    this->minValue = 0.0;
    this->maxValue = 0.0;
    this->time = 1;
    this->units = "None";
}

//Debug to print the attributes.
void Sensor::print() {
    cout << id << "\n";
    cout << minValue << "\n";
    cout << maxValue << "\n";
    cout << time << "\n";
    cout << value.back() << "\n";
    cout << units << "\n";
    cout << material << "\n";
    cout << name << "\n";
}

//Refresh the value reading.
double Sensor::refresh() {
	this->value.clear();

    this->value.push_back(  (this->maxValue - this->minValue) * ( (double)rand() / (double)RAND_MAX ) + this->minValue  );
//	cout << "Value size is: " << this->value.size();
    return this->value.back();

}


//Getters and setters below for next few functions.
std::vector<double> Sensor::getSensorData() {
    return this->value;
}

string Sensor::getSensorUnits() {
    return this->units;
}

int Sensor::getID() {
    return this->id;
}

int Sensor::getLatestData() {
	return this->value.back();
}

bool Sensor::setDisplay(Display d) {
	this->output.push_back(d);
	return true;
}


//Creates a message object and returns it to SensorMount to route appropriately.
Message Sensor::sendData() {
	const char* datatosend; 
	string test = "Sensor Name: " + this->name + " Sensor Type: " + this->material + " Reading: " + std::to_string( this->value.back()) + " " + this->units;
	this->value.clear();
	datatosend = test.c_str();
	char *cstr = new char[test.length() + 1];
	strcpy(cstr, test.c_str());
	return Message(this->output, cstr);
}

//Debug function to print which display is over the sensor.
void Sensor::printDisplay() {
	for(int x = 0; x < this->output.size(); x++) {
		cout << output[x].getName() << "\n";
	}
}