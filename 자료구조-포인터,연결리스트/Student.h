#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define MAX_STRING  20
#define MAX_STACK_SIZE 100
#pragma once

class Student {
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
public:
	Student(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, n);
		strcpy_s(dept, d);
	}
	~Student() {}
	void set(int i, char* n, char* d) {
		id = i;
		strcpy_s(name, n);
		strcpy_s(dept, d);
	};
	void display() {
		printf("학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};
