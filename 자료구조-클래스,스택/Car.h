//#include <iostream>
//#include <cstring>
//#pragma once
//
//class Car {
//protected:
//	int speed;       // �ӵ�(private)
//	char name[40];   // �̸�(private)
//public:
//	int gear;        // ���(public)
//	Car(){}         // �⺻ ������
//	~Car(){}        // �Ҹ���
//	Car(int s,const char* n, int g) {
//		speed = s;
//		strcpy_s(name, n);
//		gear = g;
//	}
//	void changeGear(int g = 4) {
//		gear = g;    // ��� �ܼ��� �����ϴ� ��� �Լ�
//	}
//	void speedUp() {
//		speed += 5;  // �ӵ��� 5�� ���� ��� �Լ�
//	}
//	void display() {
//		printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed); // �ڵ����� ������ ȭ�鿡 ���
//	}
//	void WhereAmI() { printf("��ü �ּ� = %x\n", this); }
//};
//
