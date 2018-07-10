//
// Created by clay turner on 7/7/18.
//
#include "stdafx.h"
#include "Sensor.h"
#include <random>
#include <vector>
#include "Display.h"
#include <iostream>
#include "Message.h"
using namespace std;

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

Sensor::Sensor() {
    this->id = 0;
    this->minValue = 0.0;
    this->maxValue = 0.0;
    this->time = 1;
    this->units = "None";
}

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

double Sensor::refresh() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(this->minValue, this->maxValue);
    this->value.push_back(  distribution(generator) );
    return this->value.back();

}

std::vector<double> Sensor::getSensorData() {
    return this->value;
}

char* Sensor::getSensorUnits() {
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

Message Sensor::sendData() {
	char* datatosend = reinterpret_cast<char*>(&this->value) + ' ' + *this->units;
	return Message(this->output, datatosend);
}

void Sensor::printDisplay() {
	for(int x = 0; x < this->output.size(); x++) {
		cout << output[x].getName();
	}
}