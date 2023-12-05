#include "CircularQueue.h"
#pragma once

class CircularDeque : public CircularQueue {
public:
	CircularDeque() {}
	~CircularDeque() {}
	void addRear(int val) { enqueue(val); }  // enqueue() ȣ��
	int deleteFront() { return dequeue(); }  // dequeue() ȣ�� 
	int getFront() { return peek(); }        // peek() ȣ��
	// display �ٽ� ����
	void display() {
		printf("���� ����: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i < maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
	// �ڿ��� peek
	int getRear() {
		if (isEmpty()) printf("�� ���� ����\n");
		else return data[rear];
	}
	// �տ� ����
	void addFront(int val) {
		if (isFull()) printf("�� ��ȭ ����\n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	// �ڿ��� ����
	int deletRear() {
		if (isEmpty()) printf("�� ���� ����\n");
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
};
