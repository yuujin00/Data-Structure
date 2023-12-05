#pragma once
#include "AdjMatGraph.h"
#include "VertexSets.h"
#include "MinHeap.h"

class WGraphMST :public WGraph {
public:
	// Kruskal �ּ� ��� ���� Ʈ�� ���α׷�
	void Kruskal() {
		MinHeap heap;
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++)
				if (hasEdge(i, j))
					heap.insert(getEdge(i, j), i, j);   // ��� ����(����ġ) �ּ����� ����
		}

		VertexSets set(size); // size��ŭ ���� ����
		int edgeAccepted = 0; // ���õ� ������ ��
		while (edgeAccepted < size - 1) {
			const HeapNode& e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getV2());     // �ּ� ����ġ ���� ��, �θ� ���� ��ȯ
			if (uset != vset) {                    // �� �θ��� ������ ���� �ʴٸ�(����ŬX) -> ��
				printf("���� �߰� : %c - %c (���: %d)\n",
					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);   // �ΰ��� ������ ����.
				edgeAccepted++;
			}
		}
	}

	//Prim MST �˰���
	void Prim(int s) {
		bool selected[MAX_VTXS];  // ����
		int dist[MAX_VTXS];       // ���ۺ��� Ư�� �������� �ּ� ����ġ
		int parent[MAX_VTXS];     // MST�� ���� ������ ������ �迭
		for (int i = 0; i < size; i++) {  // �迭 �ʱ�ȭ
			dist[i] = INF;
			selected[i] = false;
			parent[i] = -1;
		}
		dist[s] = 0;  // ���� ����
		for (int i = 0; i < size; i++) {
			int u = getMinVertex(selected, dist);
			selected[u] = true;
			if (dist[u] == INF) return;
			if (parent[u] != -1) {
				printf("���� �߰�: %c - %c (���: %d)\n", getVertex(parent[u]), getVertex(u), dist[u]);
			}
			for (int v = 0; v < size; v++) {
				if (getEdge(u, v) != INF) {
					if (!selected[v] && getEdge(u, v) < dist[v]) {
						dist[v] = getEdge(u, v);  // v������ �ּҰ���ġ ������Ʈ
						parent[v] = u;  // ���� ���� ����
					}
				}
			}
		}
	}

	// MST�� ���Ե��� ���� ������ �߿� MST�� ����ġ(dist)�� �ּ��� ���� ����
	int getMinVertex(bool* selected, int* dist) {
		int minv = 0;
		int mindist = INF;
		for (int v = 0; v < size; v++) {
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];       // ���� dist�� ���� ���� ����ġ�� ���� ������ �ι�° ������ ���� �ε��� ��ȯ
				minv = v;
			}
		}
		return minv;
	}

	void load(const char* filename) {
		ifstream file(filename);
		if (!file) {
			cout << "Error: ������ �� �� �����ϴ�." << endl;
			return;
		}

		int numVertices;
		file >> numVertices; // ���� ������ ���Ͽ��� �о��
		reset(); // �׷��� �ʱ�ȭ

		// ���� �̸��� ���� ������ �о��
		char name;
		int weight;
		for (int i = 0; i < numVertices; i++) {
			file >> name;
			insertVertex(name); // ���� ����
			for (int j = 0; j < numVertices; j++) {
				file >> weight;
				if (weight != 0)
					setEdge(i, j, weight); // ���� ���� ����
			}
		}

		file.close();
	}
};