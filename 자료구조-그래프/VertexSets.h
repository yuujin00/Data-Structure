#pragma once
#define MAX_VTXS 256

// ���� ���� Ŭ����
class VertexSets {
	int parent[MAX_VTXS];  // �θ� ������ id
	int nSets;             // ������ ����
public:
	VertexSets(int n) : nSets(n) {
		for (int i = 0; i < nSets; i++) parent[i] = -1;  
	}  // ��� ������ ������ ���տ� ����.

	bool isRoot(int i) { return parent[i] < 0; }  // -1�̸� �ش� ������ ������ �θ� ����
 
	int findSet(int v) {
		while (!isRoot(v)) v = parent[v];  
		return v;
	}  // v�� ���� ���� ��ȯ

	void unionSets(int s1, int s2) {
		parent[s1] = s2;
		nSets--;
	}  // ���� s1 + s2


};

