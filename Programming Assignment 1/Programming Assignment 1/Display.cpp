//
// Created by clay turner on 7/8/18.
//
#include "stdafx.h"
#include "Display.h"
#include <iostream>
using namespace std;

void Display::WriteData(char *message) {
    cout << message;
}

Display::Display(int* ids, int size, char* name) {
    this->idlist = ids;
	this->size = size;
	this->name = name;
}

int Display::getIDList(int index) {
    return this->idlist[index];
}

int Display::getSize(){
    return this->size;
}

void Display::setSize(int size) {
    this->size = size;
}

char* Display::getName(){
	return this->name;
}