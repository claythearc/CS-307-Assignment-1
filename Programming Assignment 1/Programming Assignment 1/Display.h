			/*******************************************************************
			*   Source Code Display.h
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#ifndef UNTITLED_DISPLAY_H
#define UNTITLED_DISPLAY_H

#include <vector>
#include <string>

using namespace std;

class Display {
private:
    std::vector<int> idlist;
    int size;
	string name;
	vector<string> messages;
public:
    Display(int* ids, int size, char* name);
    void WriteData(char* message);
    int getIDList(int index);
    void setSize(int size);
    int getSize();
	string getName();
	void printID();
	void StoreMessages(string message);
	void WriteMessages();
};

#endif //UNTITLED_DISPLAY_H
