#include <iostream>
#include "Car.h"
//
//void main() {
//	Car myCar(0, "권유진", 5);       // 자동차 객체 myCar 생성
//	myCar.gear = 4;  // myCar의 멤버변수 gear를 4로 수정
//	myCar.speedUp(); // myCar의 멤버변수 speedUp을 호출
//	myCar.display();
//
//}

// 스포츠카 클래스 (자식 클래스) : 자동차 클래스에 터보 기능 추가
//class SportCar: public Car
//{
//public:
//	bool bTurbo;      // 터보장치 on?
//	void setTurbo(bool bTur) { bTurbo = bTur; }
//	void speedUp() {  // 터보가 on되어있으면 가속이 빨
//		if (bTurbo) speed += 20;
//		else Car::speedUp();
//	}
//};
//
//void main() {
//	Car a(30,"myCar", 3), b(60, "yourCar", 4);
//	//b = a;
//
//	a.display();
//	b.display();
//}
