#include "HeapNode.h"
#pragma once
#define MAX_ELEMENT 200

class MaxHeap {
	HeapNode node[MAX_ELEMENT];  // ����� �迭
	int size;                    // ���� ���� ����� ����
public:
	MaxHeap():size(0){}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }   // �θ� ���
	HeapNode& getLeft(int i) { return node[i * 2]; }     // ���� �ڽ� ���
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }// ������ �ڽ� ���

	// ���� �Լ� : ���� Ű�� key�� ���� ���ο� ��Ҹ� ����
	void insert(int key){
		if (isFull())return;  // ���� ���� �� ���
		int i = ++size;       // ������ �� ũ�� ��ġ���� ����

		// Ʈ���� �Ž��� �θ���� ���ϴ� ����
		while (i != 1 && key > getParent(i).getKey()) {  // root�ƴϰ� �θ𺸴� ũ��
			node[i] = getParent(i);                      // �θ� �������
			i /= 2;                                      // �� ���� ���� ���
		}
		node[i].setKey(key);                             // ���� ��ġ : ������ ����
	}

	// ���� �Լ� : root ���� ��, �� ���� ���� ��Ŵ
	HeapNode remove() {	
		if (isEmpty()) return 0;
		HeapNode item = node[1];        // ��Ʈ���(���� ���)
		HeapNode last = node[size--];   // ���� ������ ���
		int parent = 1;                 // ������ ����� ��ġ�� ��Ʈ�� ����
		int child = 2;                  // ��Ʈ�� ���� �ڽ� ��ġ
		while (child <= size) {         // �� Ʈ���� ����� �ʴ� ����
			// ������ �����ʺ��� ������ ��Ʈ�� ������ �ڽ����� �ٲ�. �ƴϸ� ���� �ڽ�
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) child++;
			// ������ ��尡 �ڽĺ��� ũ�ų� ������ ��������.
			if (last.getKey() >= node[child].getKey()) break;

			// �� �ܰ� �Ʒ��� �̵�
			node[parent] = node[child]; 
			parent = child;             
			child *= 2;
		}
		node[parent] = last;            // ������ ��带 ���� ��ġ�� ����
		return item;                    // ��Ʈ ��� ��ȯ
	}
	
	HeapNode find() { return node[1]; }    // �켱������ ���� ��带 �������� �ʰ� ��ȯ.
	
	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n-------------------------------------------------");
	}
	
	// ��(�켱���� ť)�̿��� ����
	void heapSort(int a[], int n) {
		MaxHeap h;
		for (int i = 0; i < n; i++) h.insert(a[i]);    // ������ n���� ��� ����
		
		// �ִ� �������� ������ ���� ū ���� ��ȯ�ǹǷ�
		// ������������ �����ϱ� ���� ������ �׸��� �迭�� ������ �ձ��� ä����.
		for (int i = n - 1; i >= 0; i--) a[i] = h.remove().getKey();
	}
};