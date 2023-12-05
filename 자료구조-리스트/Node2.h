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

	// ���� node ������ ��ȯ
	Node2* getPrev() { return prev; }
	// ���� node ������ ��ȯ
	Node2* getNext() { return next; }

	// ���� node ����
	void setPrev(Node2* p) { prev = p; }
	// ���� node ����
	void setNext(Node2* n) { next = n; }

	// node ���
	void display() { printf(" <%2d>", data); }

	//������ ���� �˻�
	bool hasData(int val) { return data == val; }

	// ������ NodeNedt 
	void insertNext(Node2* n) {
		n->prev = this;
		n->next = next;
		if (next != NULL) next->prev = n;
		next = n;
	}
	// ������ NodeNext
	Node2* remove() {
		if (prev != NULL)prev->next = next;
		if (next != NULL)next->prev = prev;
		return this;
	}
};
