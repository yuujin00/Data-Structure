#include "CircularQueue.h"
#pragma once

class CircularDeque : public CircularQueue {
public:
	CircularDeque() {}
	~CircularDeque() {}
	void addRear(int val) { enqueue(val); }  // enqueue() 호출
	int deleteFront() { return dequeue(); }  // dequeue() 호출 
	int getFront() { return peek(); }        // peek() 호출
	// display 다시 정의
	void display() {
		printf("덱의 내용: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i < maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
	// 뒤에서 peek
	int getRear() {
		if (isEmpty()) printf("덱 공백 상태\n");
		else return data[rear];
	}
	// 앞에 삽입
	void addFront(int val) {
		if (isFull()) printf("덱 포화 상태\n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	// 뒤에서 삭제
	int deletRear() {
		if (isEmpty()) printf("덱 공백 상태\n");
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}
};
