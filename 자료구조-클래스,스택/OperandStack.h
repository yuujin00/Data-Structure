#include <cstdio>
#include <cstdlib>
#define MAX_STACK_SIZE 100
#pragma once

class OperandStack {
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack() { top = -1; }
	~OperandStack(){}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(double e) {
		if (isFull()) printf("���� ��ȭ ����");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty()) printf("���� ���� ����");
		return data[top--];
	}
};