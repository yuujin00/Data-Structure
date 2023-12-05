#pragma once
#include "AdjMatGraph.h" 
#include "CirrcularQueue.h"

// Ž�� ����� �߰��� ���� ��� ��� �׷��� Ŭ����
class SrchAMGraph : public AdjMatGraph {
protected:
	bool visited[MAX_VTXS];    // ���� �湮 ����
public:
	void resetVisited() {      // ��� ���� �湮���� �ʾҴٰ� ����
		for (int i = 0; i < size; i++) visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	// ���� �켱 Ž�� �Լ� (DFS)
	void DFS(int v) {
		visited[v] = true;            // ���� ������ �湮
		printf("%c ", getVertex(v));  // ���� �̸� ���

		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) DFS(w); // ���� + �湮 X -> ��ȯ ȣ��� �湮
		}
	}

	// �ʺ� �켱 Ž�� �Լ� (BFS)
	void BFS(int v) {
		visited[v] = true;            // ���� ������ �湮
		printf("%c ", getVertex(v));  // ���� �̸� ���

		CircularQueue que;
		que.enqueue(v);               // ���� ������ ť�� ����
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