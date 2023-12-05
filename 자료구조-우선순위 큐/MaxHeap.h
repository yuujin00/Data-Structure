#include "HeapNode.h"
#pragma once
#define MAX_ELEMENT 200

class MaxHeap {
	HeapNode node[MAX_ELEMENT];  // 요소의 배열
	int size;                    // 힙의 현재 요소의 개수
public:
	MaxHeap():size(0){}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }   // 부모 노드
	HeapNode& getLeft(int i) { return node[i * 2]; }     // 왼쪽 자식 노드
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }// 오른쪽 자식 노드

	// 삽입 함수 : 힙에 키값 key를 갖는 새로운 요소를 삽입
	void insert(int key){
		if (isFull())return;  // 힙이 가득 찬 경우
		int i = ++size;       // 증가된 힙 크기 위치에서 시작

		// 트리를 거슬러 부모노드와 비교하는 과정
		while (i != 1 && key > getParent(i).getKey()) {  // root아니고 부모보다 크면
			node[i] = getParent(i);                      // 부모 끌어내리고
			i /= 2;                                      // 한 레벨 위로 상승
		}
		node[i].setKey(key);                             // 최종 위치 : 데이터 복사
	}

	// 삭제 함수 : root 삭제 후, 힙 성질 만족 시킴
	HeapNode remove() {	
		if (isEmpty()) return 0;
		HeapNode item = node[1];        // 루트노드(삭제 요소)
		HeapNode last = node[size--];   // 힙의 마지막 노드
		int parent = 1;                 // 마지막 노드의 위치를 루트로 생각
		int child = 2;                  // 루트의 왼쪽 자식 위치
		while (child <= size) {         // 힙 트리를 벗어나지 않는 동안
			// 왼쪽이 오른쪽보다 작으면 루트의 오른쪽 자식으로 바꿈. 아니면 왼쪽 자식
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) child++;
			// 마지막 노드가 자식보다 크거나 같으면 빠져나옴.
			if (last.getKey() >= node[child].getKey()) break;

			// 한 단계 아래로 이동
			node[parent] = node[child]; 
			parent = child;             
			child *= 2;
		}
		node[parent] = last;            // 마지막 노드를 최종 위치에 저장
		return item;                    // 루트 노드 반환
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
		MaxHeap h;
		for (int i = 0; i < n; i++) h.insert(a[i]);    // 정렬할 n개의 요소 삽입
		
		// 최대 힙에서는 삭제시 가장 큰 값이 반환되므로
		// 오름차순으로 정렬하기 위한 삭제한 항목을 배열의 끝부터 앞까지 채워감.
		for (int i = n - 1; i >= 0; i--) a[i] = h.remove().getKey();
	}
};