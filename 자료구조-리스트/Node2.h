#pragma once
#include <cstdio>

class Node2
{
	Node2* prev;
	Node2* next;
	int data;
public:
	Node2(int val=0):data(val),prev(NULL),next(NULL) {}
	~Node2(){}

	// 선행 node 포인터 반환
	Node2* getPrev() { return prev; }
	// 후행 node 포인터 반환
	Node2* getNext() { return next; }

	// 선행 node 설정
	void setPrev(Node2* p) { prev = p; }
	// 후행 node 설정
	void setNext(Node2* n) { next = n; }

	// node 출력
	void display() { printf(" <%2d>", data); }

	//데이터 존재 검사
	bool hasData(int val) { return data == val; }

	// 삽일할 NodeNedt 
	void insertNext(Node2* n) {
		n->prev = this;
		n->next = next;
		if (next != NULL) next->prev = n;
		next = n;
	}
	// 삭제할 NodeNext
	Node2* remove() {
		if (prev != NULL)prev->next = next;
		if (next != NULL)next->prev = prev;
		return this;
	}
};
