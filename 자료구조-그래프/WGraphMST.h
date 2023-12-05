#pragma once
#include "AdjMatGraph.h"
#include "VertexSets.h"
#include "MinHeap.h"

class WGraphMST :public WGraph {
public:
	// Kruskal 최소 비용 신장 트리 프로그램
	void Kruskal() {
		MinHeap heap;
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++)
				if (hasEdge(i, j))
					heap.insert(getEdge(i, j), i, j);   // 모든 간선(가중치) 최소힙에 삽입
		}

		VertexSets set(size); // size만큼 집합 생성
		int edgeAccepted = 0; // 선택된 간선의 수
		while (edgeAccepted < size - 1) {
			const HeapNode& e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getV2());     // 최소 가중치 선택 후, 부모 정점 반환
			if (uset != vset) {                    // 두 부모의 정점이 같지 않다면(사이클X) -> 합
				printf("간선 추가 : %c - %c (비용: %d)\n",
					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);   // 두개의 집합을 합함.
				edgeAccepted++;
			}
		}
	}

	//Prim MST 알고리즘
	void Prim(int s) {
		bool selected[MAX_VTXS];  // 정점
		int dist[MAX_VTXS];       // 시작부터 특정 정점까지 최소 가중치
		int parent[MAX_VTXS];     // MST의 간선 정보를 저장할 배열
		for (int i = 0; i < size; i++) {  // 배열 초기화
			dist[i] = INF;
			selected[i] = false;
			parent[i] = -1;
		}
		dist[s] = 0;  // 시작 정점
		for (int i = 0; i < size; i++) {
			int u = getMinVertex(selected, dist);
			selected[u] = true;
			if (dist[u] == INF) return;
			if (parent[u] != -1) {
				printf("간선 추가: %c - %c (비용: %d)\n", getVertex(parent[u]), getVertex(u), dist[u]);
			}
			for (int v = 0; v < size; v++) {
				if (getEdge(u, v) != INF) {
					if (!selected[v] && getEdge(u, v) < dist[v]) {
						dist[v] = getEdge(u, v);  // v까지의 최소가중치 업데이트
						parent[v] = u;  // 간선 정보 저장
					}
				}
			}
		}
	}

	// MST에 포함되지 않은 정점들 중에 MST와 가중치(dist)가 최소인 정점 선택
	int getMinVertex(bool* selected, int* dist) {
		int minv = 0;
		int mindist = INF;
		for (int v = 0; v < size; v++) {
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];       // 현재 dist를 통해 가장 가중치가 작은 간선의 두번째 정점에 대한 인덱스 반환
				minv = v;
			}
		}
		return minv;
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