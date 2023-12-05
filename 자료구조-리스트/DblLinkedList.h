// �ٽú���
#pragma once
#include <iostream>
#include "Node2.h"

class DblLinkedList
{
	Node2 org;    // �����
public:
	DblLinkedList():org(0) {}
	~DblLinkedList() { clear(); }

	// ��� ����
	void clear() { while (!isEmpty()) delete remove(0); }
	// ��� ������ ��ȯ
	Node2* getHead() { return org.getNext(); }
	// �������
	bool isEmpty() { return getHead() == NULL; }

	// pos��° node ��ȯ
	Node2* getEntry(int pos) {
		Node2* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}

	// pos��ġ�� node ����
	void insert(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos��ġ�� node ����
	Node2* remove(int pos) {
		Node2* prev = getEntry(pos);
		return prev->remove();
	}

	//node Data Ž��
	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}

	//pos��° node ��ü
	void replace(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}

	// ����Ʈ �׸� ���� ��ȯ
	int size() {
		int count = 0;
		for (Node2* p = getHead();p != NULL;p = p->getNext())
			count++;
		return count;
	}

	// ����Ʈ ���
	void display() {
		printf("[��ü �׸� ��= %2d] : ", size());
		for (Node2* p = getHead();p != NULL; p = p->getNext())
			p->display();
		printf("\n");
	}
};
