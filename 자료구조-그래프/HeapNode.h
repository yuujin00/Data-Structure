#pragma once
#include <iostream>
using namespace std;

class HeapNode {
	int key;  // ������ ����ġ
	int v1;   // ����1
	int v2;   // ����2
public:
	HeapNode() : key(0), v1(0), v2(0) {}
	HeapNode(int k, int  u, int v) :key(k), v1(u), v2(v) {}
	void setKey(int k, int  u, int v) { key = k; v1 = u; v2 = v; }
	int getKey() const { return key; }
	int getV1() const { return v1; }
	int getV2() const { return v2; }
	void display() { printf("%4d", key); }
};
