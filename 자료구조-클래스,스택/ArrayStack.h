#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#pragma once

class ArrayStack {
	int data[MAX_STACK_SIZE]; // 스택 요소를 저장할 배열
	int top;                  // 요소의 개수를 나타낼 int형 변수
public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(int e) {
		if (isFull()) printf("스택 포화 에러");
		data[++top] = e;
	}
	int pop() {
		if (isEmpty()) printf("스택 공백 에러");
		return data[top--];
	}
	int peek() {
		if (isEmpty())printf("스택 공백 에러");
		return data[top];
	}
	void display() {
		printf("[스택 항목 수 = %2d]", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};

