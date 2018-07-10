			/*******************************************************************
			*   Source Code Sensor.h
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#ifndef SENSOR_H
#define SENSOR_H
#include <vector>
#include "Display.h"
#include "Message.h"
#include <string>

using namespace std;
class Sensor {
private:
    string units;
    vector<double> value;
    int time;
    int id;
    string name;
    string material;
    double minValue;
    double maxValue;
	vector<Display> output;
public:
    Sensor(int time, int id, double minValue, double maxValue, char* name, char* material, char* units);
    Sensor();
    vector<double> getSensorData();
    string getSensorUnits();
    double refresh();
    int getID();
    void print();
    bool setDisplay(Display d);
	int getLatestData();
	Message sendData();
	void printDisplay();
};

#endif