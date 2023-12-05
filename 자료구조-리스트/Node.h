#pragma once
#include <iostream>

class Node
{
	Node* link;
	int data;
public:
	Node(int val=0):data(val),link(NULL){}
	~Node(){}
	// node 포인터 반환
	Node* getLink() { return link; }
	// node 설정
	void setLink(Node* next) { link = next; }
	// node 출력
	void display() { printf(" <%2d>", data); }
	// 데이터 존재 검사
	bool hasData(int val) { return data == val; }
	// 삽일할 NodeNedt 
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	// 삭제할 NodeNext
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

