			/*******************************************************************
			*   Source Code Display.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "Display.h"
#include <iostream>
#include <string>

using namespace std;

//Debug function to make sure each display was reachable.
void Display::WriteData(char *message) {
    cout << message;
}

//Constructor to store the ids it wants to read in a vector, the size of the vector, and the name of the meter.
Display::Display(int* ids, int size, char* name) {
    for (int i = 0; i < size; i++) {
		this->idlist.push_back(ids[i]);
	}
	this->size = size;
	this->name = name;
}

//Returns the ID of a specific index in a vector, was used for debugging
int Display::getIDList(int index) {
    return this->idlist[index];
}

//Returns size of vector.
int Display::getSize(){
    return this->size;
}

//Sets the size of the size variable
void Display::setSize(int size) {
    this->size = size;
}

//Gets the name string
string Display::getName(){
	return this->name;
}

//Debug function to print all the IDs it holds
void Display::printID() {
	for(int i = 0; i < idlist.size(); i++) {
		cout << "ID# : " << i << " " << idlist[i] << "\n";
	}
}

//Push a message onto the vector of messages it has
void Display::StoreMessages(string message) {
	this->messages.push_back(message);
}

//Once the program tells them to output, it outputs all the messages and then clears the vector
void Display::WriteMessages() {
	cout << "Display " << name << "\n";
	for(int i = 0; i < this->messages.size(); i++) {
		cout << this->messages[i] << "\n";
	}
	this->messages.clear();
}