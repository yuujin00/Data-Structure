#pragma once
#include "Node.h"

#define MAX_VTXS 256

// 인접 리스트를 이용한 그래프의 클래스
class AdjListGraph {
protected:
	int size;                      // 정점의 개수
	char vertices[MAX_VTXS];       // 정점 정보
	Node* adj[MAX_VTXS];           // 각 정점의 인접 리스트
public:
	AdjListGraph() :size(0) {}
	~AdjListGraph() { reset(); }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS - 1; }

	char getVertex(const int& i) { return vertices[i]; }

	// 그래프 초기화
	void reset() {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL) delete adj[i];
	}

	// 정점 삽입
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: 그래프 정점 개수 초과" << endl;
	}

	// 간선 삽입
	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);   // 인접 리스트에 추가
		adj[v] = new Node(u, adj[v]);   // 무방향 그래프
	}

	void display() {
		printf("%d\n", size);              // 정점 개수 출력
		for (int i = 0; i < size; i++) {   // 행의 정보 출력
			printf("%c ", getVertex(i));   // 정점의 이름 출력
			for (Node* v = adj[i]; v != NULL; v = v->getLink()) { // 인접 리스트 정보 출력
				printf(" %c", getVertex(v->getId()));
				printf("%3d", v->getId());
			}
			printf("\n");
		}
	}

	// 정점 인접 정점 집합 반환
	Node* adjacent(int v) { return adj[v]; }
};
