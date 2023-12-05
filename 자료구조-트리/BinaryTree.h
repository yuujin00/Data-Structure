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

	// 중위순회 : 왼쪽 -> 루트 -> 오른쪽
	// Tree 클래스에서의 구현
	void inorder() { printf("\n inorder: "); inorder(root); }
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			cout << " ["<< node->getData() << "] ";
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	
	// 전위순회 : 루트 -> 왼쪽 -> 오른쪽
	void preorder(){ printf("\n preorder: "); preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			cout << " [" << node->getData() << "] ";
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}

	// 후위순회 : 왼쪽 -> 오른족 -> 루트
	void postorder(){ printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) postorder(node->getLeft());
			if (node->getRight() != NULL) postorder(node->getRight());
			cout << " [" << node->getData() << "] ";
		}
	}
	// 레벨순회
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

	// 이진트리 노드 개수 반환
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	// 이진트리 높이 반환
	int getHeight(){ return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	// 이진트리 단말노드 개수 반환
	int getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft())+ getLeafCount(node->getRight());
	}
};