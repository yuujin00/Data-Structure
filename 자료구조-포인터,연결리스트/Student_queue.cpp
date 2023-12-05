#include <iostream>
#include "LinkedQueue.h"

int main() {
	LinkedQueue Que;
	Que.enqueue(new Node(20200724, "������", "���а�"));
	Que.enqueue(new Node(20200723, "���ϸ�", "���а�"));
	Que.enqueue(new Node(20200722, "������", "���а�"));
	Que.display();

	Node* node = Que.dequeue();
	printf("[Dequeue�׸�]\n");
	node->display();
	printf("\n");
	delete node;
	
	Node* node1 = Que.peek();
	printf("[peek�׸�]\n");
	node1->display();
	printf("\n");

	Que.display();

	return 0;
}
