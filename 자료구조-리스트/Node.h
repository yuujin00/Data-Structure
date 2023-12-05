#pragma once
#include <iostream>

class Node
{
	Node* link;
	int data;
public:
	Node(int val=0):data(val),link(NULL){}
	~Node(){}
	// node ������ ��ȯ
	Node* getLink() { return link; }
	// node ����
	void setLink(Node* next) { link = next; }
	// node ���
	void display() { printf(" <%2d>", data); }
	// ������ ���� �˻�
	bool hasData(int val) { return data == val; }
	// ������ NodeNedt 
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	// ������ NodeNext
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

