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
	Student() {}
	~Student() {}
	Student(int i,const char* n, const char* d) { 
		id = i;
		strcpy_s(name, n);
		strcpy_s(dept, n);
	}
	void display() {
		printf("�й�:%-15d ����:%-10s �а�:%-20d\n", id, name, dept);
	}
};


class StudentStack {
	int top;  
	Student data[MAX_STACK_SIZE];
public:
	StudentStack() { top = -1; }
	~StudentStack() { }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(Student e) {
		if (isFull()) printf("���� ��ȭ ����");
		data[++top] = e;
	}
	Student pop() {
		if (isEmpty()) printf("���� ���� ����");
		return data[top--];
	}
	Student peek() {
		if (isEmpty())printf("���� ���� ����");
		return data[top];
	}
	void display() {
		printf("[��ü �л� �� = %2d]", top + 1);
		for (int i = 0; i <= top; i++)
			data[i].display();
		printf("\n");
	}
};
