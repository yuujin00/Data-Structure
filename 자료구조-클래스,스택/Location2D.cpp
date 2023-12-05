#include "Location2D.h"    // 클래스
#include <stack>           // STL stack 사용
using namespace std;

const int MAZE_SIZE = 6;            // 미로 맵 크기 (가로,세로) 고정
char map[MAZE_SIZE][MAZE_SIZE] = {  // 미로 맵 데이터
	{'1','1','1','1','1','1'},      // 1은 벽
	{'e','0','1','0','0','1'},      // e는 입구
	{'1','0','0','0','1','1'},      // 0은 길  
	{'1','0','1','0','1','1'},       
	{'1','0','1','0','0','x'},      // x는 출구
	{'1','1','1','1','1','1'}
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void main() {
	stack<Location2D> locStack;            // 위치 스택 객체 생성
	Location2D entry(1, 0);                // 입구 객체
	locStack.push(entry);                  // 스택에 입구 위치 삽입

	while (locStack.empty() == false) {    // 스택이 비어있지 않는동안
		Location2D here = locStack.top();  // 스택에 객체 복사
		locStack.pop();                    // 스택에 객체 삭제

		int r = here.getRow(), c = here.getCol();
		printf("(%d,%d) ", r, c);          // 꺼낸거 읽기
		if (map[r][c] == 'x') {            
			printf("미로 탐색 성공\n");    // 도착하면 성공
			return;
		}
		else {                             // 출구가 아니면 현재 위치를
			map[r][c] = '.';               // 현재 위치를 "지나옴"처리
			if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n");
}