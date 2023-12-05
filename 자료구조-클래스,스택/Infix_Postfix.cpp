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
//	while ((c = getc(fp)) != '\n') {   // �����Է�������
//		if (c >= '0' && c <= '9') {    // ���ڷ� �����ϸ�
//			ungetc(c, fp);             // ���ڸ� ��������
//			fscanf_s(fp, "%lf", &val); // double�� �ٽ� �о��
//			printf("%4.1f", val);      // ���� �б�
//		}
//		else if (c == '(')st.push(c);
//		else if (c == ')') {
//			while (!st.isEmpty()) {
//				op = st.pop();         // '(' ������
//				if (op == '(')break;
//				else printf("%c", op); // ()�ȿ� �ִ� ������ �б�
//			}
//		}
//		//������ +-/* ��� �켱���� ó�� ��
//		else if (c == '+' || c == '-' || c == '*' || c == '/') {
//			while (!st.isEmpty()) {
//				op = st.peek();
//				if (precedence(c) <= precedence(op)) { // ���� ���� ������ �켱������ ������
//					printf("%c", op);                  // �а�
//					st.pop();                          // ������
//				}
//				else break;
//			}
//			st.push(c);                                // �ִ´�
//		}
//	}
//	while (!st.isEmpty())
//		printf("%c", st.pop());                        // ������������� ������.                        
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
//		else if (c >= '0' && c <= '9') { // ���ڷ� �����ϸ�
//			ungetc(c, fp);               // ���ڷ� ��������
//			fscanf_s(fp, "%lf", &val);   // double�� �ٽ� �о��
//			st.push(val);                // �� ���ÿ� �ֱ�
//		}
//	}
//	while (!st.isEmpty())
//		printf("%f", st.pop());       // �� ������ �б�
//}
//
//int main() {
//	printf("�����Է� (Infix)=");
//	infix2Postfix();
//	cout << endl;
//	printf("�����Է� (Postfix)=");
//	calcPostfixExpr();
//}