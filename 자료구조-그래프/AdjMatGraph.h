#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_VTXS 256

// 인접 행렬을 이용한 그래프의 클래스
class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS];       // n 1차원 배열
	int adj[MAX_VTXS][MAX_VTXS];   // n x n 2차원 배열
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; } // 정점 반환
	int getEdge(int i, int j) { return adj[i][j]; } // 간선 반환
	void setEdge(int i, int j, int val) { adj[i][j] = val; } // 간선 설정  + 가중치(val)
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS - 1; }

	// 그래프 초기화 --> 공백 상태의 그래프
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	// 정점 삽입
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else cout << "Error: 그래프 정점 개수 초과" <<endl;
	}

	// 간선 삽입 : 무방향 그래프 경우
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);    // 무뱡향이라 가능 (방향그래프에선 삭제)
	}

	// 그레프 정보 출력
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);               // 정점 개수 출력
		for (int i = 0; i < size; i++) {		 // 각 행의 정보 출력
			fprintf(fp, "%c ", getVertex(i));    // 정점의 이름 출력
			for (int j = 0; j < size; j++)       // 간선 정보 출력
				fprintf(fp, " %3d", getEdge(i, j)); 
			fprintf(fp, "\n");
		}
	}
};

#define INF 9999          // 값이 INF 이상이면 간선이 없음.

// 가중치 그래프를 표현하는 클래스
class WGraph : public AdjMatGraph {
public:
	void insertEdge(int u, int v, int weight) {
		if (weight > INF)weight = INF;
		setEdge(u, v, weight);
	}
	bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }
};