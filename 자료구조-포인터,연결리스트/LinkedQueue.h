#pragma once
#include "Node_queue.h"

class LinkedQueue
{
	Node* front;
	Node* rear;
public:
	LinkedQueue() :front(NULL),rear(NULL) {}
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == NULL; }

	void enqueue(Node* p) {
		if (isEmpty())front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}

	Node* dequeue() {
		Node* p = front;
		front = p->getLink();
		return p;
	}

	Node* peek() {
		Node* p = front;
		return p;
	}

	void display() {
		//printf("[Å¥ ³»¿ë]");
		printf("[Linked Queue]\n");
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	};
};
