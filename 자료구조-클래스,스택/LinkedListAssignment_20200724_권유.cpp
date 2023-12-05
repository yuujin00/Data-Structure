//#include <iostream>
//#include <string>
//using namespace std;
//
//inline void error(char* str) {
//	fprintf(stderr, "%s\n", str);
//	exit(1);
//};
//
//class Node {
//	Node* link; // pointer to next node
//	int	data; // data field of 'this' node
//
//public:
//	Node(int val=0) : data(val),link(NULL) { }
//	Node* getLink() { return link; }
//	void setLink(Node* next) { link=next; }
//	void display() { printf(" <%2d>", data); }
//	int getData() { return data; }
//
//	// insert new node (n) next to current node
//	void insertNext(Node* n) {
//		if (n != NULL) {
//			n->link = link;
//			link = n;
//		}
//	}
//	// remove next node from current node
//	Node* removeNext() {
//		Node* removed = link;
//		if (removed != NULL)
//			link = removed->link;
//		return removed;
//	}
//};
//
//class LinkedList {
//	Node org;	// head node (not head pointer!)
//
//public:
//	LinkedList(): org(0) { }
//	~LinkedList() { clear(); }
//
//	void clear() { while (!isEmpty()) delete remove(0); }
//	Node* getHead() { return org.getLink(); }
//	bool isEmpty() { return getHead() == NULL; }
//
//	// return node in position 'pos' from the list
//	Node* getEntry(int pos) {
//		Node* n = &org;
//		for (int i = -1; i < pos; i++, n = n->getLink())
//			if (n == NULL) break;
//		return n;
//	}
//
//	// insert new node (n) in position 'pos'
//	void insert(int pos, Node* n) { 
//		Node* prev = getEntry(pos - 1);
//		if (prev != NULL)
//			prev->insertNext(n);
//	}
//
//	// remove a node in position 'pos'
//	Node* remove(int pos) { 
//		Node* prev = getEntry(pos - 1);
//		return prev->removeNext();
//	}
//
//	// return size of list
//	int size() { 
//		int count = 0;
//		for (Node* p = getHead();p != NULL;p = p->getLink())
//			count++;
//		return count;
//	}
//
//	// display data fields of nodes in the list
//	void display(const char* str = "List") {
//		printf(str);
//		printf("[list size %2d] :", size());
//		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
//			printf(" <%2d>", p->getData());
//		}
//		printf("\n");
//	}
//
//	// reverse list
//	void reverse() { 
//		int count = 0;
//		for (int i = 0; i < size(); i++) {
//			Node* p = remove(size() - 1);
//			insert(count++, p);
//		}
//	}
//
//	// return new list that have data fields of two lists in descending order
//	LinkedList* mergeTwoLists(LinkedList* list2) {
//		LinkedList* mergeList = new LinkedList();
//
//		Node* p = this->getHead();
//		Node* q = list2->getHead();
//
//		while (p != NULL || q != NULL) {
//			if (q == NULL || (p != NULL && p->getData() > q->getData())) {
//				mergeList->insert(mergeList->size(), new Node(p->getData()));
//				p = p->getLink();
//			}
//			else {
//				mergeList->insert(mergeList->size(), new Node(q->getData()));
//				q = q->getLink();
//			}
//		}
//		return mergeList;
//	}
//};
//
//int main()
//{
//	LinkedList* list1 = new LinkedList(), * list2 = new LinkedList();
//	LinkedList* list3;
//
//	list1->insert(0, new Node(80));
//	list1->insert(0, new Node(50));
//	list1->insert(0, new Node(40));
//	list1->insert(0, new Node(10));
//
//	list1->display("List1(   before    )");
//	list1->reverse();
//	list1->display("List1(after reverse)");
//
//	list2->insert(0, new Node(70));
//	list2->insert(1, new Node(60));
//	list2->insert(2, new Node(30));
//	list2->insert(3, new Node(20));
//	list2->display("List2(     now     )");
//
//	list3 = list1->mergeTwoLists(list2);
//	list3->display("List3( List1+List2 )");
//
//	list1->clear();
//	list2->clear();
//	list1->display("List1(     end     )");
//	list2->display("List2(     end     )");
//
//	return 0;
//}