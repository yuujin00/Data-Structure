#pragma once
#include "BInaryNode.h"
const int MAX_SIZE = 100;

class CircularQueue {
private:
    int front;
    int rear;
    int size;
    BinaryNode* arr[MAX_SIZE];

public:
    CircularQueue() : front(-1), rear(-1), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(BinaryNode* node) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = node;
        size++;
    }

    BinaryNode* dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return nullptr;
        }

        front = (front + 1) % MAX_SIZE;
        BinaryNode* node = arr[front];
        size--;

        return node;
    }
};