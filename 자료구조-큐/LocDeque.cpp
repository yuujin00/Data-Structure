//#include "Location2D.h"
//#include <deque>           // STL stack ���
//using namespace std;
//
//const int MAZE_SIZE = 6;            // �̷� �� ũ�� (����,����) ����
//char map[MAZE_SIZE][MAZE_SIZE] = {  // �̷� �� ������
//	{'1','1','1','1','1','1'},      // 1�� ��
//	{'e','0','1','0','0','1'},      // e�� �Ա�
//	{'1','0','0','0','1','1'},      // 0�� ��  
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},      // x�� �ⱸ
//	{'1','1','1','1','1','1'}
//};
//
//bool isValidLoc(int r, int c) {
//	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)return false;
//	else return map[r][c] == '0' || map[r][c] == 'x';
//}
//
//void main() {
//	deque<Location2D> locDeque;     // ��ġ �� ��ü ����
//	Location2D entry(1, 0);         // �Ա� ��ü
//	locDeque.push_front(entry);           // ���� �Ա� ��ġ ����
//
//	while (locDeque.empty() == false) {     // ���� ������� �ʴ� ����
//		Location2D here = locDeque.front(); // ���� front ��� ��ü ����
//		locDeque.pop_front();                     // �� ��� ��ü ����
//		int r = here.row, c = here.col;
//		printf("(%d,%d)", r, c);
//		if (map[r][c] == 'x') {
//			printf("�̷� Ž�� ����\n");
//			return;
//		}
//		else {                             // �ⱸ�� �ƴϸ� ���� ��ġ��
//			map[r][c] = '.';               // ���� ��ġ�� "������"ó��
//			// ���ð� ���� ( ���Լ���)
//			/*
//			if (isValidLoc(r - 1, c))locDeque.push_front(Location2D(r - 1, c));
//			if (isValidLoc(r + 1, c))locDeque.push_front(Location2D(r + 1, c));
//			if (isValidLoc(r, c - 1))locDeque.push_front(Location2D(r, c - 1));
//			if (isValidLoc(r, c + 1))locDeque.push_front(Location2D(r, c + 1));
//			*/
//
//			// ť�� ���� ( ���Լ���)
//			if (isValidLoc(r - 1, c))locDeque.push_back(Location2D(r - 1, c));
//			if (isValidLoc(r + 1, c))locDeque.push_back(Location2D(r + 1, c));
//			if (isValidLoc(r, c - 1))locDeque.push_back(Location2D(r, c - 1));
//			if (isValidLoc(r, c + 1))locDeque.push_back(Location2D(r, c + 1));
//		}
//	}
//	printf("�̷� Ž�� ����\n");
//}