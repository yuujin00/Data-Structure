#include "CircularDeque.h"

void main() {
	CircularDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2)deq.addFront(i);  // 홀수를 앞에서 삽입
		else deq.addRear(i);        // 짝수를 뒤에서 삽입
	}
	deq.display();
	deq.deleteFront(); // 앞에서 삭제
	deq.deletRear();   // 뒤에서 삭제
	deq.deleteFront();
	deq.display();
}