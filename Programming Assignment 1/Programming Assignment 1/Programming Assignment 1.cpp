#include <iostream>
#include "stdafx.h"
#include "EnviroSimDataParser.h"
#include "Sensor.h"
#include <vector>
#include "SensorMount.h"
#include "Display.h"
#include <stdlib.h>


#define _CRT_SECURE_NO_WARNINGS // Shut up MS, about strcpy(), etc.	

using namespace std;

int main() {
    char* filename = "./SensorData1.xml";
    EnviroSimDataParser fparser = EnviroSimDataParser(filename);
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


    SensorMount SensorList = SensorMount();
    cout << "Sensor Count " << fparser.getSensorCount() << "\n";
    read = fparser.getSensorData(type, material, ID, units, minVal, maxVal);
    cout << type << " " << material << " " << *ID << " " << units << " " << *minVal << " " << *maxVal << "\n";
    SensorList.addSensor( Sensor(5, *ID, *minVal, *maxVal, type, material, units) );
    while(read) {
        read = fparser.getSensorData(type, material, ID, units, minVal, maxVal);
        cout << type << " " << material << " " << *ID << " " << units << " " << *minVal << " " << *maxVal << "\n";
        SensorList.addSensor( Sensor(5, *ID, *minVal, *maxVal, type, material, units) );
    }

    cout << "Display Count: " << fparser.getDisplayCount() << "\n";
    while(fparser.getDisplayData(displaytype, displayid, displayidcount)) {
        cout << "Display type " << displaytype << " count " << *displayidcount;
		SensorList.addDisplay(Display(displayid, *displayidcount, displaytype));
        for(int i = 0; i < *displayidcount; i++) {
            cout << " display id " << displayid[i] << "\n";
        }
    }

	SensorList.debugMessage();

	char* test = new char;
	cin >> test;
	



//    SensorList.printSensors();


    return 0;
}