//#include "Location2D.h"
//#include <deque>           // STL stack 사용
//using namespace std;
//
//const int MAZE_SIZE = 6;            // 미로 맵 크기 (가로,세로) 고정
//char map[MAZE_SIZE][MAZE_SIZE] = {  // 미로 맵 데이터
//	{'1','1','1','1','1','1'},      // 1은 벽
//	{'e','0','1','0','0','1'},      // e는 입구
//	{'1','0','0','0','1','1'},      // 0은 길  
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},      // x는 출구
//	{'1','1','1','1','1','1'}
//};
//
//bool isValidLoc(int r, int c) {
//	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)return false;
//	else return map[r][c] == '0' || map[r][c] == 'x';
//}
//
//void main() {
//	deque<Location2D> locDeque;     // 위치 덱 객체 생성
//	Location2D entry(1, 0);         // 입구 객체
//	locDeque.push_front(entry);           // 덱에 입구 위치 삽입
//
//	while (locDeque.empty() == false) {     // 덱이 비어있지 않는 동안
//		Location2D here = locDeque.front(); // 덱의 front 상단 객체 복사
//		locDeque.pop_front();                     // 덱 상단 객체 삭제
//		int r = here.row, c = here.col;
//		printf("(%d,%d)", r, c);
//		if (map[r][c] == 'x') {
//			printf("미로 탐색 성공\n");
//			return;
//		}
//		else {                             // 출구가 아니면 현재 위치를
//			map[r][c] = '.';               // 현재 위치를 "지나옴"처리
//			// 스택과 같음 ( 후입선출)
//			/*
//			if (isValidLoc(r - 1, c))locDeque.push_front(Location2D(r - 1, c));
//			if (isValidLoc(r + 1, c))locDeque.push_front(Location2D(r + 1, c));
//			if (isValidLoc(r, c - 1))locDeque.push_front(Location2D(r, c - 1));
//			if (isValidLoc(r, c + 1))locDeque.push_front(Location2D(r, c + 1));
//			*/
//
//			// 큐와 같음 ( 선입선출)
//			if (isValidLoc(r - 1, c))locDeque.push_back(Location2D(r - 1, c));
//			if (isValidLoc(r + 1, c))locDeque.push_back(Location2D(r + 1, c));
//			if (isValidLoc(r, c - 1))locDeque.push_back(Location2D(r, c - 1));
//			if (isValidLoc(r, c + 1))locDeque.push_back(Location2D(r, c + 1));
//		}
//	}
//	printf("미로 탐색 실패\n");
//}