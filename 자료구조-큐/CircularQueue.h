#pragma once
#include <iostream>
#define MAX_QUEUE_SIZE 100

class CircularQueue {
protected:
	int front;                 // ù��° ��� ���� ��ġ
	int rear;                  // ������ ��� ��ġ
	int data[MAX_QUEUE_SIZE];  // ����� �迭
public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() {}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	// ť�� ����
	void enqueue(int val) {
		if (isFull()) printf("ť ��ȭ ����\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	// ť���� ���� ��ȯ
	int dequeue() {
		if (isEmpty())printf("ť ���� ����\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	// ť���� �����ʰ� ��ȯ
	int peek() {
		if (isEmpty())printf("ť �������\n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	// ť ������� ���
	void display() {
		printf("ť ����: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i < maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};