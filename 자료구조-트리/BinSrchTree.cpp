#include "BinSrchTree.h"

int main() {
	BinSrchTree tree;

	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	cout << "����� ����:" << tree.getCount() << endl;
	cout << "�ܸ��� ����:" << tree.getLeafCount() << endl;
	cout << "Ʈ���� ����:" << tree.getHeight() << endl;

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);

	cout << " case1 => ��� 3����\n";
	tree.remove(3);
	cout << " case2 => ��� 68����\n";
	tree.remove(68);
	cout << " case3 => ��� 18����\n";
	tree.remove(18);

	tree.levelorder();

	cout << " case3 => ��� 35����\n";
	tree.remove(35);

	tree.levelorder();

	cout << "����� ����:" << tree.getCount() << endl;
	cout << "�ܸ��� ����:" << tree.getLeafCount() << endl;
	cout << "Ʈ���� ����:" << tree.getHeight() << endl;
}