#pragma once
#include <iostream>
#include "Node.h"

class LinkedList
{
	Node org;   // ��� ���
public:
	LinkedList() : org(0){}
	~LinkedList() { clear(); }

	// ��� ����
	void clear() { while (!isEmpty())delete remove(0); }
	// ��� ������ ��ȯ
	Node* getHead() { return org.getLink(); }
	// �������
	bool isEmpty() { return getHead() == NULL; }

	// pos��° �׸� ��ȯ
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	// pos��ġ�� node ����
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos��ġ�� node ����
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	//pos��° node ��ü
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//node Data Ž��
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}

	// ����Ʈ �׸� ���� ��ȯ
	int size() {
		int count = 0;
		for (Node* p = getHead();p != NULL;p = p->getLink())
			count++;
		return count;
	}

	// ����Ʈ ���
	void display() {
		printf("[��ü �׸� ��= %2d] : ", size());
		for (Node* p = getHead();p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};
