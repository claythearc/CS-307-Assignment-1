			/*******************************************************************
			*   Source Code Message.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "Message.h"
#include <iostream>

//Constructor for our message object
Message::Message(std::vector<Display> outputs, char* message){
	this->outputs = outputs;
	this->message = message;
}

//Makes sure it actually holds messages
void Message::DebugPrint() {
	std::cout << this->message << "\n";
}
//Returns the list of displays it should reach
std::vector<Display> Message::getOutputs() {
	return this->outputs;
}

//Return the message
std::string Message::GetMessage() {
	return this->message;
}