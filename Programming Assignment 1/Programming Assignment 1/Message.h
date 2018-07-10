			/*******************************************************************
			*   Source Code Message.h
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#ifndef UNTITLED_MESSAGE_H
#define UNTITLED_MESSAGE_H

#include <vector>
#include "Display.h"
#include <string>


class Message{
private:
	std::vector<Display> outputs;
	string message;
public:
	Message(std::vector<Display> outputs, char* message);
	void DebugPrint();
	std::vector<Display> getOutputs();
	string GetMessage();
};


#endif