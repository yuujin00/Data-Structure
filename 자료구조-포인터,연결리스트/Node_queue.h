#pragma once
#include <iostream>
#include "Student.h"

class Node : public Student
//class Node
{
	Node* link;
	//int data;
public:
	//Node(int val = 0) : data(val), link(NULL){}
	Node(int id = 0, const char* name = "", const char* dept = "")
		: Student(id, name, dept) {
		link = NULL;
	}
	~Node(){}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	//void display() { printf(" <%2d>", data); }
};