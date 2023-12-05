//#include "Location2D.h"
//#include <queue>           // STL queue ���
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
//	queue<Location2D> locQueue;     // ��ġ ť ��ü ����
//	Location2D entry(1, 0);         // �Ա� ��ü
//	locQueue.push(entry);           // ť�� �Ա� ��ġ ����
//
//	while (locQueue.empty() == false) {     // ť�� ������� �ʴ� ����
//		Location2D here = locQueue.front(); // ť�� front ��� ��ü ����
//		locQueue.pop();                     // ť ��� ��ü ����
//		int r = here.row, c = here.col;
//		printf("(%d,%d)", r, c);
//		if (map[r][c] == 'x') {
//			printf("�̷� Ž�� ����\n");
//			return;
//		}
//		else {                             // �ⱸ�� �ƴϸ� ���� ��ġ��
//			map[r][c] = '.';               // ���� ��ġ�� "������"ó��
//			if (isValidLoc(r - 1, c))locQueue.push(Location2D(r - 1, c));
//			if (isValidLoc(r + 1, c))locQueue.push(Location2D(r + 1, c));
//			if (isValidLoc(r, c - 1))locQueue.push(Location2D(r, c - 1));
//			if (isValidLoc(r, c + 1))locQueue.push(Location2D(r, c + 1));
//		}
//	}
//	printf("�̷� Ž�� ����\n");
//}