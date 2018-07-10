//
// Created by clay turner on 7/7/18.
//

#ifndef SENSOR_H
#define SENSOR_H
#include <vector>
#include "Display.h"
#include "Message.h"

using namespace std;
class Sensor {
private:
    char* units;
    vector<double> value;
    int time;
    int id;
    char* name;
    char* material;
    double minValue;
    double maxValue;
	vector<Display> output;
public:
    Sensor(int time, int id, double minValue, double maxValue, char* name, char* material, char* units);
    Sensor();
    vector<double> getSensorData();
    char* getSensorUnits();
    double refresh();
    int getID();
    void print();
    bool setDisplay(Display d);
	int getLatestData();
	Message sendData();
	void printDisplay();
};

#endif