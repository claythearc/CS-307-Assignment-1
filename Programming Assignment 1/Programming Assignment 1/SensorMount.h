			/*******************************************************************
			*   Source Code SensorMount.h
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#ifndef UNTITLED_SENSOR_MOUNT_H
#define UNTITLED_SENSOR_MOUNT_H
#include <vector>
#include "Sensor.h"
#include "Display.h"

using namespace std;
class SensorMount {
private:
    vector<Sensor> SensorList;
    int size;
    vector<Display> DisplayList;
public:
    SensorMount();
    ~SensorMount();
    void GenerateData();
    int GenerateData(int id);
    bool addSensor(Sensor s);
    int getSize();
    void printSensors();
    void attachDisplays();
    void addDisplay(Display d);
	void printDisplays();
	void attachDisplay();
	void debugMessage();
	void printID();
	void DisplayDebug();
	void DisplayData();

};

#endif //UNTITLED_SENSOR_MOUNT_H
