#include "BInaryNode.h"
#include "CircularQueue.h"
#pragma once

class BinaryTree {
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) { }
	void setRoot(BinaryNode* n) { root = n; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	// ������ȸ : ���� -> ��Ʈ -> ������
	// Tree Ŭ���������� ����
	void inorder() { printf("\n inorder: "); inorder(root); }
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			cout << " ["<< node->getData() << "] ";
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	
	// ������ȸ : ��Ʈ -> ���� -> ������
	void preorder(){ printf("\n preorder: "); preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			cout << " [" << node->getData() << "] ";
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}

	// ������ȸ : ���� -> ������ -> ��Ʈ
	void postorder(){ printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			cout << " [" << node->getData() << "] ";
		}
	}
	// ������ȸ
	void levelorder(){
		printf("\n Level Order: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* node = q.dequeue();
				if (node != NULL) {
					cout << " [" << node->getData() << "] ";
					q.enqueue(node->getLeft());
					q.enqueue(node->getRight());
				}
			}
			cout << "\n";
		}
	}

	// ����Ʈ�� ��� ���� ��ȯ
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	// ����Ʈ�� ���� ��ȯ
	int getHeight(){ return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	// ����Ʈ�� �ܸ���� ���� ��ȯ
	int getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft())+ getLeafCount(node->getRight());
	}
};