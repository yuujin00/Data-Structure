// 다시보기
#pragma once
#include <iostream>
#include "Node2.h"

class DblLinkedList
{
	Node2 org;    // 헤드노드
public:
	DblLinkedList():org(0) {}
	~DblLinkedList() { clear(); }

	// 요소 제거
	void clear() { while (!isEmpty()) delete remove(0); }
	// 헤드 포인터 반환
	Node2* getHead() { return org.getNext(); }
	// 공백상태
	bool isEmpty() { return getHead() == NULL; }

	// pos번째 node 반환
	Node2* getEntry(int pos) {
		Node2* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}

	// pos위치에 node 삽입
	void insert(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos위치에 node 삭제
	Node2* remove(int pos) {
		Node2* prev = getEntry(pos);
		return prev->remove();
	}

	//node Data 탐색
	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}

	//pos번째 node 교체
	void replace(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}

	// 리스트 항목 개수 반환
	int size() {
		int count = 0;
		for (Node2* p = getHead();p != NULL;p = p->getNext())
			count++;
		return count;
	}

	// 리스트 출력
	void display() {
		printf("[전체 항목 수= %2d] : ", size());
		for (Node2* p = getHead();p != NULL; p = p->getNext())
			p->display();
		printf("\n");
	}
};
