#ifndef UNTITLED_MESSAGE_H
#define UNTITLED_MESSAGE_H

#include <vector>
#include "Display.h"



class Message{
private:
	std::vector<Display> outputs;
	char* message;
public:
	Message(std::vector<Display> outputs, char* message);
	void DebugPrint();
};


#endif