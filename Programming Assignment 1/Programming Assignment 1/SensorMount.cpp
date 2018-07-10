//
// Created by clay turner on 7/8/18.
//
#include "stdafx.h"
#include "SensorMount.h"
#include "Sensor.h"
#include <vector>
#include <iostream>
#include "Message.h"
#include <string>

using namespace std;

SensorMount::SensorMount() {

}

SensorMount::~SensorMount() {

}

int SensorMount::getSize() {
    return this->size;
}

void SensorMount::printSensors() {

    for (int i = 0; i < this->SensorList.size(); i++) {
        SensorList[i].print();
        cout << "New sensor \n";
    }
}

bool SensorMount::addSensor(Sensor s) {
    this->SensorList.push_back(s);
    return true;
}

void SensorMount::GenerateData() {
    for (int i =0 ; i < this->SensorList.size(); i++) {
        this->SensorList[i].refresh();
    }
}

int SensorMount::GenerateData(int id) {
    for(int i = 0; i < this->SensorList.size(); i++){
        if(SensorList[i].getID() == id){
            SensorList[i].refresh();
			return SensorList[i].getLatestData();
        }
    }
}

void SensorMount::addDisplay(Display d) {
    this->DisplayList.push_back(d);
}

void SensorMount::attachDisplays() {
    for(int i = 0; i < DisplayList.size(); i++) {
        for(int x = 0; x < DisplayList[i].getSize(); x++) {
            for(int y = 0; y < SensorList.size(); y++) {
                if( SensorList[y].getID() == DisplayList[i].getIDList(x)) {
                    SensorList[y].setDisplay(DisplayList[i]);
					cout << "Attached Sensor to Display";
                }
            }
        }
    }
}


void SensorMount::attachDisplay() {
	for(int DisplayLoop = 0; DisplayLoop < this->DisplayList.size(); DisplayLoop++) {
		for(int DisplayID = 0; DisplayID < this->DisplayList[DisplayLoop].getSize(); DisplayID++) {
			for(int SensorLoop = 0; SensorLoop < this->SensorList.size(); SensorLoop++) {
				if(SensorList[SensorLoop].getID() == DisplayList[DisplayLoop].getIDList(DisplayID)) {
					SensorList[SensorLoop].setDisplay(DisplayList[DisplayLoop]);
				}
			}
		}
	}
}

void SensorMount::printDisplays() {
	for(int i = 0; i < SensorList.size(); i++) {
		cout << "\n Sensor #: " << std::to_string(i); 
		SensorList[i].printDisplay();
	}
}

void SensorMount::debugMessage(){
	for(int i = 0; i < SensorList.size(); i++) {
		SensorList[i].sendData().DebugPrint();
	}
}