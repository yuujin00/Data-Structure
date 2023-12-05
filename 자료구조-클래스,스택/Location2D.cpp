#include "Location2D.h"    // Ŭ����
#include <stack>           // STL stack ���
using namespace std;

const int MAZE_SIZE = 6;            // �̷� �� ũ�� (����,����) ����
char map[MAZE_SIZE][MAZE_SIZE] = {  // �̷� �� ������
	{'1','1','1','1','1','1'},      // 1�� ��
	{'e','0','1','0','0','1'},      // e�� �Ա�
	{'1','0','0','0','1','1'},      // 0�� ��  
	{'1','0','1','0','1','1'},       
	{'1','0','1','0','0','x'},      // x�� �ⱸ
	{'1','1','1','1','1','1'}
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void main() {
	stack<Location2D> locStack;            // ��ġ ���� ��ü ����
	Location2D entry(1, 0);                // �Ա� ��ü
	locStack.push(entry);                  // ���ÿ� �Ա� ��ġ ����

	while (locStack.empty() == false) {    // ������ ������� �ʴµ���
		Location2D here = locStack.top();  // ���ÿ� ��ü ����
		locStack.pop();                    // ���ÿ� ��ü ����

		int r = here.getRow(), c = here.getCol();
		printf("(%d,%d) ", r, c);          // ������ �б�
		if (map[r][c] == 'x') {            
			printf("�̷� Ž�� ����\n");    // �����ϸ� ����
			return;
		}
		else {                             // �ⱸ�� �ƴϸ� ���� ��ġ��
			map[r][c] = '.';               // ���� ��ġ�� "������"ó��
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));
		}
	}
	printf("�̷� Ž�� ����\n");
}