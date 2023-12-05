//#include <iostream>
//#include <cstring>
//#pragma once
//
//class Car {
//protected:
//	int speed;       // 속도(private)
//	char name[40];   // 이름(private)
//public:
//	int gear;        // 기어(public)
//	Car(){}         // 기본 생성자
//	~Car(){}        // 소멸자
//	Car(int s,const char* n, int g) {
//		speed = s;
//		strcpy_s(name, n);
//		gear = g;
//	}
//	void changeGear(int g = 4) {
//		gear = g;    // 기어 단수를 변경하는 멤버 함수
//	}
//	void speedUp() {
//		speed += 5;  // 속도를 5씩 증가 멤버 함수
//	}
//	void display() {
//		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed); // 자동차의 정보를 화면에 출력
//	}
//	void WhereAmI() { printf("객체 주소 = %x\n", this); }
//};
//
