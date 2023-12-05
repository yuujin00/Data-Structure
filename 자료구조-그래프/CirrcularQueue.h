#pragma once
#include <iostream>
#define MAX_QUEUE_SIZE 100

class CircularQueue {
protected:
	int front;                 // 첫번째 요소 앞의 위치
	int rear;                  // 마지막 요소 위치
	int data[MAX_QUEUE_SIZE];  // 요소의 배열
public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() {}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	// 큐에 삽입
	void enqueue(int val) {
		if (isFull()) printf("큐 포화 상태\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	// 큐에서 빼고 반환
	int dequeue() {
		if (isEmpty())printf("큐 공백 상태\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	// 큐에서 빼지않고 반환
	int peek() {
		if (isEmpty())printf("큐 공백상태\n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	// 큐 순서대로 출력
	void display() {
		printf("큐 내용: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i < maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};