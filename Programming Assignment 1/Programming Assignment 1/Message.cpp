#include "stdafx.h"
#include "Message.h"
#include <iostream>

Message::Message(std::vector<Display> outputs, char* message){
	this->outputs = outputs;
	this->message = message;
}

void Message::DebugPrint() {
	std::cout << this->message << "\n";
}