#include "CircularDeque.h"

void main() {
	CircularDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2)deq.addFront(i);  // Ȧ���� �տ��� ����
		else deq.addRear(i);        // ¦���� �ڿ��� ����
	}
	deq.display();
	deq.deleteFront(); // �տ��� ����
	deq.deletRear();   // �ڿ��� ����
	deq.deleteFront();
	deq.display();
}