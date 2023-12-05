#pragma once
#include <iostream>
using namespace std;

class HeapNode {
	int key;  // 간선의 가중치
	int v1;   // 정점1
	int v2;   // 정점2
public:
	HeapNode() : key(0), v1(0), v2(0) {}
	HeapNode(int k, int  u, int v) :key(k), v1(u), v2(v) {}
	void setKey(int k, int  u, int v) { key = k; v1 = u; v2 = v; }
	int getKey() const { return key; }
	int getV1() const { return v1; }
	int getV2() const { return v2; }
	void display() { printf("%4d", key); }
};
