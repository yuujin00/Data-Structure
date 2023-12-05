#pragma once
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph {
	int label[MAX_VTXS];   // ������ ���� �ʵ� �߰�
public:
	void labelDFS(int v, int color) {
		visited[v] = true; // ���� ������ �湮 
		label[v] = color;  // ���� ������ ����
		for (int w = 0; w < size; w++)
			if (isLinked(v, w) && visited[w] == false)
				labelDFS(w, color);
	}

	void findConnectedComponent() {
		int count = 1;
		for (int i = 0; i < size; i++)
			if (visited[i] == false)
				labelDFS(i, ++count);
		
		printf("�׷��� ���Ἲ�� ���� = %d\n", count);
		for (int i = 0; i < size; i++)
			printf("%c=%d ", getVertex(i), label[i]);
		printf("\n");
	}
};