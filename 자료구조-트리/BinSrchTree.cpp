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

	cout << "노드의 개수:" << tree.getCount() << endl;
	cout << "단말의 개수:" << tree.getLeafCount() << endl;
	cout << "트리의 높이:" << tree.getHeight() << endl;

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);

	cout << " case1 => 노드 3삭제\n";
	tree.remove(3);
	cout << " case2 => 노드 68삭제\n";
	tree.remove(68);
	cout << " case3 => 노드 18삭제\n";
	tree.remove(18);

	tree.levelorder();

	cout << " case3 => 노드 35삭제\n";
	tree.remove(35);

	tree.levelorder();

	cout << "노드의 개수:" << tree.getCount() << endl;
	cout << "단말의 개수:" << tree.getLeafCount() << endl;
	cout << "트리의 높이:" << tree.getHeight() << endl;
}