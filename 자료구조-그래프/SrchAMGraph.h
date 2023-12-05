#pragma once
#include "AdjMatGraph.h" 
#include "CirrcularQueue.h"

// 탐색 기능이 추가된 인접 행렬 기반 그래프 클래스
class SrchAMGraph : public AdjMatGraph {
protected:
	bool visited[MAX_VTXS];    // 정점 방문 정보
public:
	void resetVisited() {      // 모든 정점 방문하지 않았다고 설정
		for (int i = 0; i < size; i++) visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	// 깊이 우선 탐색 함수 (DFS)
	void DFS(int v) {
		visited[v] = true;            // 현재 정점을 방문
		printf("%c ", getVertex(v));  // 정점 이름 출력

		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) DFS(w); // 연걸 + 방문 X -> 순환 호출로 방문
		}
	}

	// 너비 우선 탐색 함수 (BFS)
	void BFS(int v) {
		visited[v] = true;            // 현재 정점을 방문
		printf("%c ", getVertex(v));  // 정점 이름 출력

		CircularQueue que;
		que.enqueue(v);               // 시작 정점을 큐에 저장
		while (!que.isEmpty()) {
			int v = que.dequeue();
			for(int w=0; w<size; w++)
				if (isLinked(v, w) && visited[w] == false) {
					visited[w] = true;
					printf("%c ", getVertex(w));
					que.enqueue(w);
				}
		}
	}

	void load(const char* filename) {
		ifstream file(filename);
		if (!file) {
			cout << "Error: 파일을 열 수 없습니다." << endl;
			return;
		}

		int numVertices;
		file >> numVertices; // 정점 개수를 파일에서 읽어옴
		reset(); // 그래프 초기화

		// 정점 이름과 간선 정보를 읽어옴
		char name;
		int weight;
		for (int i = 0; i < numVertices; i++) {
			file >> name;
			insertVertex(name); // 정점 삽입
			for (int j = 0; j < numVertices; j++) {
				file >> weight;
				if (weight != 0)
					setEdge(i, j, weight); // 간선 정보 설정
			}
		}

		file.close();
	}

};