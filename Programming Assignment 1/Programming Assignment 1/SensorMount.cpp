			/*******************************************************************
			*   Source Code Sensor Mount.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "SensorMount.h"
#include "Sensor.h"
#include <vector>
#include <iostream>
#include "Message.h"
#include <string>

using namespace std;

//Empty Constructor and Destructor, no initializing needed.
SensorMount::SensorMount() {

}

SensorMount::~SensorMount() {

}

//Gets the size.
int SensorMount::getSize() {
    return this->size;
}

//Prints the list of sensors and their attributes.
void SensorMount::printSensors() {

    for (int i = 0; i < SensorList.size(); i++) {
		cout << "Sensor #: " << i << "\n";
        SensorList[i].print();
    }
}

//Adds a sensor onto the vector.
bool SensorMount::addSensor(Sensor s) {
    this->SensorList.push_back(s);
    return true;
}

//Tells Sensors its time to refresh data.
void SensorMount::GenerateData() {
    for (int i =0 ; i < this->SensorList.size(); i++) {
        this->SensorList[i].refresh();
    }
}

//Tells a specific sensor to refresh data.
int SensorMount::GenerateData(int id) {
    for(int i = 0; i < this->SensorList.size(); i++){
        if(SensorList[i].getID() == id){
            SensorList[i].refresh();
			return SensorList[i].getLatestData();
        }
    }
}

//Adds a display onto the list
void SensorMount::addDisplay(Display d) {
    this->DisplayList.push_back(d);
}

//Loops over all of the Sensors and Displays and makes sure the Sensors know which one should be recieving data.
void SensorMount::attachDisplays() {
    for(int i = 0; i < DisplayList.size(); i++) {
        for(int x = 0; x < DisplayList[i].getSize(); x++) {
            for(int y = 0; y < SensorList.size(); y++) {
                if( SensorList[y].getID() == DisplayList[i].getIDList(x)) {
                    SensorList[y].setDisplay(DisplayList[i]);
					//cout << "Attached Sensor to Display";
                }
            }
        }
    }
}



//Debug to print the display data.
void SensorMount::printDisplays() {
	for(int i = 0; i < SensorList.size(); i++) {
		//cout << "\n Sensor #: " << std::to_string(i); 
		SensorList[i].printDisplay();
	}
}

//FUnction I kept changing to show various information about each part
void SensorMount::debugMessage(){
	for(int i = 0; i < SensorList.size(); i++) {
		cout << "Sensor " << i << "\n";
		SensorList[i].sendData().DebugPrint();
	}
}

//Prints the IDs of each sensor

void SensorMount::printID() {
	for(int i = 0; i < SensorList.size(); i++) {
		cout << "Sensor ID: " << i << " " << SensorList[i].getID();
	}
}

//Tested writing messages
void SensorMount::DisplayDebug(){
	for(int i = 0; i < DisplayList.size(); i++) {
//		cout << "Display ID: " << i << " " << DisplayList[i].getName() << "\n";
		DisplayList[i].StoreMessages("Testing");
		DisplayList[i].WriteMessages();
	}
}

///Actually displays the data to the sensors
//I create a message object in Sensor
//Retrieve it here
//Loop through find the displays
//Ship it out to them to display
//Once all the sensors have been collected, it writes the data.

void SensorMount::DisplayData() {
	for(int i = 0; i < SensorList.size(); i++) {
		Message Received = SensorList[i].sendData();
		vector<Display> recievedIds = Received.getOutputs();
		for(int x = 0; x < recievedIds.size(); x++) {
			//cout << "Message Object recieved with IDs: ";
			for(int z = 0; z < DisplayList.size(); z++) {
				if (DisplayList[z].getName() == recievedIds[x].getName()) {
					DisplayList[z].StoreMessages(Received.GetMessage());
					//cout << "attached message to display \n";
				}
			}
		}
	}

	for(int i = 0; i < DisplayList.size(); i++) {
		DisplayList[i].WriteMessages();
	}
}