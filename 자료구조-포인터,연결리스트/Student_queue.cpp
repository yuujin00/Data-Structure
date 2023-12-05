#include <iostream>
#include "LinkedQueue.h"

int main() {
	LinkedQueue Que;
	Que.enqueue(new Node(20200724, "권유진", "수학과"));
	Que.enqueue(new Node(20200723, "김하린", "수학과"));
	Que.enqueue(new Node(20200722, "곽현지", "수학과"));
	Que.display();

	Node* node = Que.dequeue();
	printf("[Dequeue항목]\n");
	node->display();
	printf("\n");
	delete node;
	
	Node* node1 = Que.peek();
	printf("[peek항목]\n");
	node1->display();
	printf("\n");

	Que.display();

	return 0;
}
