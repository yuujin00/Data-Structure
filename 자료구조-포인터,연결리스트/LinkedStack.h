#pragma once
#include "Node_stack.h"

class LinkedStack
{
	Node* top;
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (!isEmpty())delete pop();}
	bool isEmpty() { return top == NULL; }

	void push(Node* p) {
		if (isEmpty()) top = p;
		else {
			p->setLink(top);
			top = p;
		}
	}

	Node* pop() {
		Node* p = top;
		top = p->getLink();
		return p;
	}

	Node* peek() {
		Node* p = top;
		return p;
	}

	void display() {
		printf("[Linked Stack]\n");
		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};

