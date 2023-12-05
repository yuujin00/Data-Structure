//#include <iostream>
//#include <fstream>
//#include "OperandStack.h"
//#include "ArrayStack.h"
//using namespace std;
//
//int precedence(char op) {
//	switch (op)
//	{
//	case '(':case ')':return 0;
//	case '+':case '-':return 1;
//	case '*':case '/':return 2;
//	}
//}
//
//void infix2Postfix(FILE* fp = stdin) {
//	char c,op;
//	double val;
//	ArrayStack st;
//
//	while ((c = getc(fp)) != '\n') {   // 엔터입력전까지
//		if (c >= '0' && c <= '9') {    // 숫자로 시작하면
//			ungetc(c, fp);             // 문자를 돌려놓고
//			fscanf_s(fp, "%lf", &val); // double로 다시 읽어라
//			printf("%4.1f", val);      // 숫자 읽기
//		}
//		else if (c == '(')st.push(c);
//		else if (c == ')') {
//			while (!st.isEmpty()) {
//				op = st.pop();         // '(' 꺼내기
//				if (op == '(')break;
//				else printf("%c", op); // ()안에 있던 연산자 읽기
//			}
//		}
//		//연산자 +-/* 라면 우선순위 처리 비교
//		else if (c == '+' || c == '-' || c == '*' || c == '/') {
//			while (!st.isEmpty()) {
//				op = st.peek();
//				if (precedence(c) <= precedence(op)) { // 스택 안의 연산자 우선순위가 높으면
//					printf("%c", op);                  // 읽고
//					st.pop();                          // 꺼내고
//				}
//				else break;
//			}
//			st.push(c);                                // 넣는다
//		}
//	}
//	while (!st.isEmpty())
//		printf("%c", st.pop());                        // 비어있지않으면 꺼낸다.                        
//}
//
//
//void calcPostfixExpr(FILE* fp = stdin) {
//	char c;
//	double val;
//	OperandStack st;
//
//	while ((c = getc(fp)) != '\n') {
//		if (c == '+' || c == '-' || c == '*' || c == '/') {
//			double val2 = st.pop();
//			double val1 = st.pop();
//			switch (c)
//			{
//			case '+': st.push(val1 + val2); break;
//			case '-': st.push(val1 - val2); break;
//			case '*': st.push(val1 * val2); break;
//			case '/': st.push(val1 / val2); break;
//			}
//		}
//		else if (c >= '0' && c <= '9') { // 숫자로 시작하면
//			ungetc(c, fp);               // 문자로 돌려놓고
//			fscanf_s(fp, "%lf", &val);   // double로 다시 읽어라
//			st.push(val);                // 값 스택에 넣기
//		}
//	}
//	while (!st.isEmpty())
//		printf("%f", st.pop());       // 값 꺼내서 읽기
//}
//
//int main() {
//	printf("수식입력 (Infix)=");
//	infix2Postfix();
//	cout << endl;
//	printf("수식입력 (Postfix)=");
//	calcPostfixExpr();
//}