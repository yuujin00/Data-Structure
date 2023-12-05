#pragma once
#include <iostream>
#include "Node.h"

class LinkedList
{
	Node org;   // 헤드 노드
public:
	LinkedList() : org(0){}
	~LinkedList() { clear(); }

	// 요소 제거
	void clear() { while (!isEmpty())delete remove(0); }
	// 헤드 포인터 반환
	Node* getHead() { return org.getLink(); }
	// 공백상태
	bool isEmpty() { return getHead() == NULL; }

	// pos번째 항목 반환
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	// pos위치에 node 삽입
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos위치에 node 삭제
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	//pos번째 node 교체
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//node Data 탐색
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}

	// 리스트 항목 개수 반환
	int size() {
		int count = 0;
		for (Node* p = getHead();p != NULL;p = p->getLink())
			count++;
		return count;
	}

	// 리스트 출력
	void display() {
		printf("[전체 항목 수= %2d] : ", size());
		for (Node* p = getHead();p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};
