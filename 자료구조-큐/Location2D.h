#pragma once
class Location2D {
public:
	int row;  // 현재위치의 행 번호
	int col;  // 현재위치의 열 번호
	Location2D(int r = 0, int c = 0) { row = r; col = c; }
	// 위치 p가 자신의 이웃인지 검사하는 함수
	bool isNeighbor(Location2D& p) {
		return((row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	// p가 자신과 같은 위치인지를 검사(연산자 오버로딩 사용= 연산자 새로 정의)
	bool operator==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};
