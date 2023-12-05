#include "HeapNode.h"
#pragma once
#define MAX_ELEMENT 200

class MinHeap {
	HeapNode node[MAX_ELEMENT];
	int size;
public:
	MinHeap() :size(0) { }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key < getParent(i).getKey()) {  // root 아니고 부모보다 작으면
			node[i] = getParent(i);                      // 부모를 끌어내리고
			i /= 2;                                      // 한 레벨 위로 상승
		}
		node[i].setKey(key);                             // 최종 위치 : 데이터 복사
	}

	HeapNode remove() {
		if (isEmpty()) return 0;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey()) child++;
			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }    // 우선순위가 높은 노드를 삭제하지 않고 반환.

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

	// 힙(우선순위 큐)이용한 정렬
	void heapSort(int a[], int n) {
		MinHeap h;
		for (int i = 0; i < n; i++) h.insert(a[i]);    // 정렬할 n개의 요소 삽입

		// 최대 힙에서는 삭제시 가장 큰 값이 반환되므로
		// 오름차순으로 정렬하기 위한 삭제한 항목을 배열의 끝부터 앞까지 채워감.
		for (int i = 0; i > n-1; i++) a[i] = h.remove().getKey();
	}
};