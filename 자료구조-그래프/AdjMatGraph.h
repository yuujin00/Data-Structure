#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_VTXS 256

// ���� ����� �̿��� �׷����� Ŭ����
class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS];       // n 1���� �迭
	int adj[MAX_VTXS][MAX_VTXS];   // n x n 2���� �迭
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; } // ���� ��ȯ
	int getEdge(int i, int j) { return adj[i][j]; } // ���� ��ȯ
	void setEdge(int i, int j, int val) { adj[i][j] = val; } // ���� ����  + ����ġ(val)
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS - 1; }

	// �׷��� �ʱ�ȭ --> ���� ������ �׷���
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	// ���� ����
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else cout << "Error: �׷��� ���� ���� �ʰ�" <<endl;
	}

	// ���� ���� : ������ �׷��� ���
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);    // �������̶� ���� (����׷������� ����)
	}

	// �׷��� ���� ���
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);               // ���� ���� ���
		for (int i = 0; i < size; i++) {		 // �� ���� ���� ���
			fprintf(fp, "%c ", getVertex(i));    // ������ �̸� ���
			for (int j = 0; j < size; j++)       // ���� ���� ���
				fprintf(fp, " %3d", getEdge(i, j)); 
			fprintf(fp, "\n");
		}
	}
};

#define INF 9999          // ���� INF �̻��̸� ������ ����.

// ����ġ �׷����� ǥ���ϴ� Ŭ����
class WGraph : public AdjMatGraph {
public:
	void insertEdge(int u, int v, int weight) {
		if (weight > INF)weight = INF;
		setEdge(u, v, weight);
	}
	bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }
};