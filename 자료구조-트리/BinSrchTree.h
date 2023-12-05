#pragma once
#include "BInaryNode.h"
#include "BinaryTree.h"

class BinSrchTree :public BinaryTree{
public:
	// ��ȯ�� �Ϲ� �Լ�
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL)return NULL;
		if (key == n->getData()) return n;
		else if (key < n->getData()) return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}

	// �ݺ��� �Ϲ� �Լ�
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
		if (node != NULL) cout << "Ž������: Ű ����" << node->getData() << "�� ���= " << node << endl;
		else cout << "Ž������" << endl;
		return node;
	}

	// ��ȯ ���� (n: ���� ���)
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

	// ����
	void remove(BinaryNode* parent, BinaryNode* node) {
		// ����1 : ������� �ܸ�
		if (node->isLeaf()) {
			if (parent == NULL) setRoot(NULL);
			else {
				if (parent->getLeft() == node) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
		}
		// ����2 : ������� ���� Ʈ�� �� �ϳ��� ������ �ִ� ���
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
			if (node == getRoot())
				setRoot(child);
			else {
				if (parent->getLeft() == node) parent->setLeft(child);
				else parent->setRight(child);
			}
		}
		// ����3 : ������� ���� Ʈ�� ���(2��) ������ �ִ� ���
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

