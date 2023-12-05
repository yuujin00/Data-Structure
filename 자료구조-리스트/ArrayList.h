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

	//삽입
	void insert(int pos, int e) {
		if (!isFull() && pos >= 0 && pos <= length) {
			for (int i = length; i > pos; i--)
				data[i] = data[i - 1];
			data[pos] = e;
			length++;
		}
		else printf("포화상태 오류 또는 삽입 위치 오류");
	}

	//삭제
	void remove(int pos) {
		if (!isEmpty() && pos >= 0 && pos < length) {
			for (int i = pos + 1; i < length; i++)
				data[i - 1] = data[i];
			length--;
		}
		else printf("공백상태 오류 또는 삭제 위치 오류");
	}

	//pos번째 항목 반환
	int getEntry(int pos) { return data[pos]; }

	//공백
	bool isEmpty() { return length == 0; }

	//포화
	bool isFull() { return length == MAX_LIST_SIZE; }

	//item 항목 존재 확인
	bool fine(int item) {
		for (int i = 0; i < length; i++)
			if (data[i] == item) return true;
		return false;
	}

	//pos 위치 변경
	void replace(int pos, int e) {
		data[pos] = e;
	}

	//배열 길이 반환
	int size() { return length; }

	//배열 출력
	void display() {
		printf("[배열리스트 전체항목 수 =%2d]: ", size());
		for (int i = 0; i < size(); i++)
			printf("[%2d] ", data[i]);
		printf("\n");
	}

	//요소 제거
	void clear() { length = 0; }
};
