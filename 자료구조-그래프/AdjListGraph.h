#pragma once
#include "Node.h"

#define MAX_VTXS 256

// ���� ����Ʈ�� �̿��� �׷����� Ŭ����
class AdjListGraph {
protected:
	int size;                      // ������ ����
	char vertices[MAX_VTXS];       // ���� ����
	Node* adj[MAX_VTXS];           // �� ������ ���� ����Ʈ
public:
	AdjListGraph() :size(0) {}
	~AdjListGraph() { reset(); }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS - 1; }

	char getVertex(const int& i) { return vertices[i]; }

	// �׷��� �ʱ�ȭ
	void reset() {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL) delete adj[i];
	}

	// ���� ����
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: �׷��� ���� ���� �ʰ�" << endl;
	}

	// ���� ����
	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);   // ���� ����Ʈ�� �߰�
		adj[v] = new Node(u, adj[v]);   // ������ �׷���
	}

	void display() {
		printf("%d\n", size);              // ���� ���� ���
		for (int i = 0; i < size; i++) {   // ���� ���� ���
			printf("%c ", getVertex(i));   // ������ �̸� ���
			for (Node* v = adj[i]; v != NULL; v = v->getLink()) { // ���� ����Ʈ ���� ���
				printf(" %c", getVertex(v->getId()));
				printf("%3d", v->getId());
			}
			printf("\n");
		}
	}

	// ���� ���� ���� ���� ��ȯ
	Node* adjacent(int v) { return adj[v]; }
};
