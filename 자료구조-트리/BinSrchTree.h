#pragma once
#include "BInaryNode.h"
#include "BinaryTree.h"

class BinSrchTree :public BinaryTree{
public:
	// 순환적 일반 함수
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL)return NULL;
		if (key == n->getData()) return n;
		else if (key < n->getData()) return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}

	// 반복적 일반 함수
	BinaryNode* searchIter(BinaryNode* n, int key) {
		while (n != NULL) {
			if (key == n->getData()) return n;
			else if (key < n->getData()) n = n->getLeft();
			else n = n->getRight();
		}
		return NULL;
	}

	BinaryNode* search(int key) {
		BinaryNode* node = searchIter(getRoot(), key);
		if (node != NULL) cout << "탐색성공: 키 값이" << node->getData() << "인 노드= " << node << endl;
		else cout << "탐색실패" << endl;
		return node;
	}

	// 순환 삽입 (n: 삽입 노드)
	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL)r->setLeft(n);
			else insertRecur(r->getLeft(),n);
		}
		else {
			if (r->getRight() == NULL) r->setRight(n);
			else insertRecur(r->getRight(), n);
		}
	}

	void insert(BinaryNode* n) {
		if (n == NULL)return;
		if (isEmpty()) setRoot(n);
		else insertRecur(getRoot(), n);
	}

	// 삭제
	void remove(BinaryNode* parent, BinaryNode* node) {
		// 삭제1 : 삭제노드 단말
		if (node->isLeaf()) {
			if (parent == NULL) setRoot(NULL);
			else {
				if (parent->getLeft() == node) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
		}
		// 삭제2 : 삭제노드 서브 트리 중 하나만 가지고 있는 경우
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
			if (node == getRoot())
				setRoot(child);
			else {
				if (parent->getLeft() == node) parent->setLeft(child);
				else parent->setRight(child);
			}
		}
		// 삭제3 : 삭제노드 서브 트리 모두(2개) 가지고 있는 경우
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}
			if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
			else succp->setRight(succ->getLeft());
			node->setData(succ->getData());
			node = succ;
		}
	}

	void remove(int key) {
		if (isEmpty())return;
		BinaryNode* parent = NULL;
		BinaryNode* node = getRoot();

		while (node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}

		if (node == NULL) {
			cout << "Error: key is not in the tree!" << endl;
			return;
		}
		else remove(parent, node);
	}
	
};

