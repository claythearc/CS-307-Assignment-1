//
// Created by clay turner on 7/8/18.
//
#ifndef UNTITLED_DISPLAY_H
#define UNTITLED_DISPLAY_H

class Display {
private:
    int* idlist;
    int size;
	char *name;
public:
    Display(int* ids, int size, char* name);
    void WriteData(char* message);
    int getIDList(int index);
    void setSize(int size);
    int getSize();
	char* getName();
};

#endif //UNTITLED_DISPLAY_H
