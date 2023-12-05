#pragma once
#include <iostream>
#define MAX_LIST_SIZE 100

class ArrayList
{
	int data[MAX_LIST_SIZE];
	int length;
public:
	ArrayList() { length = 0; }
	~ArrayList() {}

	//����
	void insert(int pos, int e) {
		if (!isFull() && pos >= 0 && pos <= length) {
			for (int i = length; i > pos; i--)
				data[i] = data[i - 1];
			data[pos] = e;
			length++;
		}
		else printf("��ȭ���� ���� �Ǵ� ���� ��ġ ����");
	}

	//����
	void remove(int pos) {
		if (!isEmpty() && pos >= 0 && pos < length) {
			for (int i = pos + 1; i < length; i++)
				data[i - 1] = data[i];
			length--;
		}
		else printf("������� ���� �Ǵ� ���� ��ġ ����");
	}

	//pos��° �׸� ��ȯ
	int getEntry(int pos) { return data[pos]; }

	//����
	bool isEmpty() { return length == 0; }

	//��ȭ
	bool isFull() { return length == MAX_LIST_SIZE; }

	//item �׸� ���� Ȯ��
	bool fine(int item) {
		for (int i = 0; i < length; i++)
			if (data[i] == item) return true;
		return false;
	}

	//pos ��ġ ����
	void replace(int pos, int e) {
		data[pos] = e;
	}

	//�迭 ���� ��ȯ
	int size() { return length; }

	//�迭 ���
	void display() {
		printf("[�迭����Ʈ ��ü�׸� �� =%2d]: ", size());
		for (int i = 0; i < size(); i++)
			printf("[%2d] ", data[i]);
		printf("\n");
	}

	//��� ����
	void clear() { length = 0; }
};
