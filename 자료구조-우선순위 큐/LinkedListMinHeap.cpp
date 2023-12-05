//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_ELEMENT	100
//using namespace std;
//
//inline void error(char* str) {
//	fprintf(stderr, "%s\n", str);
//	exit(1);
//};
//
//class LinkedNode {
//private:
//	LinkedNode* link;
//	int data;
//	char category;
//public:
//	LinkedNode() { link = NULL; data = 0; category = ' '; }
//	LinkedNode(char c, int d) { link = NULL; category = c; data = d; }
//	LinkedNode* getLink() { return link; }
//	void setLink(LinkedNode* next) { link = next; }
//	char getCategory() { return category; }
//	void setCategory(char c) { category = c; }
//	void displayCatAndData() { cout << " <" << category << " " << data << "> "; }
//	void displayData() { cout << " <" << data << "> "; }
//	int getData() { return data; }
//
//	void insertNext(LinkedNode* n) {
//		if (n != NULL) n->link = link;
//		link = n;
//	}
//
//	LinkedNode* removeNext() {
//		LinkedNode* remove = NULL;
//		if (link != NULL) {
//			remove = link;
//			link = remove->link;
//			remove->link = NULL;
//		}
//		return remove;
//	}
//};
//
//class LinkedList {
//private:
//	LinkedNode* org;
//public:
//	LinkedList() :org(NULL) { }
//
//	void clear() {
//		while (!isEmpty()) {
//			LinkedNode* temp = org;
//			org = org->getLink();
//			delete temp;
//		}
//		org = NULL;
//	}
//	LinkedNode* getHead() { return org; }
//	bool isEmpty() { return org == NULL; }
//
//	LinkedNode* getEntry(int pos) {
//		LinkedNode* n = org;
//		for (int i = 0; i < pos && n != NULL; i++)
//			n = n->getLink();
//		return n;
//	}
//
//	void insert(int pos, LinkedNode* n) {
//		if (pos < 0 || (pos > 0 && isEmpty()))
//			return;
//
//		if (pos == 0) {
//			n->setLink(org);
//			org = n;
//		}
//		else {
//			LinkedNode* prev = getEntry(pos - 1);
//			if (prev != nullptr)
//				prev->insertNext(n);
//		}
//	}
//
//	LinkedNode* remove(int pos) {
//		LinkedNode* prev = getEntry(pos - 1);
//		return prev->removeNext();
//	}
//
//	int size() {
//		int count = 0;
//		for (LinkedNode* n = getHead(); n != NULL; n = n->getLink())
//			count++;
//		return count;
//	}
//
//	void displayCatAndData(const char* str = "List") {
//		printf("%s[list size %2d] : ", str, size());
//		for (LinkedNode* n = getHead(); n != NULL; n = n->getLink())
//			n->displayCatAndData();
//		printf("\n");
//	}
//
//	void displayData(const char* str = "List") {
//		printf("%s[list size %2d] : ", str, size());
//		for (LinkedNode* n = getHead(); n != NULL; n = n->getLink())
//			n->displayData();
//		printf("\n");
//	}
//
//};
//
//class HeapNode
//{
//public:
//	int	key;
//
//	HeapNode() { key = 0; }
//	bool hasKey(int val) { return key == val; }
//	void setKey(int k) { key = k; }
//	int getKey() const { return key; }
//};
//
//class MinHeap
//{
//private:
//	HeapNode node[MAX_ELEMENT];
//	int size;
//public:
//	MinHeap() :size(0) { }
//	bool isEmpty() { return size == 0; }
//	bool isFull() { return size == MAX_ELEMENT - 1; }
//
//	HeapNode& getParent(int i) { return node[i / 2]; }
//	HeapNode& getLeft(int i) { return node[i * 2]; }
//	HeapNode& getRight(int i) { return node[i * 2 + 1]; }
//
//	void insert(int key) {
//		if (isFull()) return;
//		int i = ++size;
//
//		while (i != 1 && key < getParent(i).getKey()) {
//			node[i] = getParent(i);
//			i /= 2;
//		}
//		node[i].setKey(key);
//	}
//
//	HeapNode remove() {
//		if (isEmpty()) error;
//		HeapNode item = node[1];
//		HeapNode last = node[size--];
//		int parent = 1;
//		int child = 2;
//		while (child <= size) {
//			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey()) child++;
//			if (last.getKey() <= node[child].getKey()) break;
//
//			node[parent] = node[child];
//			parent = child;
//			child *= 2;
//		}
//		node[parent] = last;
//		return item;
//	}
//};
//
//
//void sortThreeListsByCategory(LinkedList* list1, LinkedList* list2, LinkedList* list3) {
//	LinkedList mergedList;
//
//	LinkedNode* node1 = list1->getHead();
//	LinkedNode* node2 = list2->getHead();
//	LinkedNode* node3 = list3->getHead();
//
//	while (node1 != NULL || node2 != NULL || node3 != NULL) {
//		if (node1 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node1->getCategory(), node1->getData()));
//			node1 = node1->getLink();
//		}
//		if (node2 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node2->getCategory(), node2->getData()));
//			node2 = node2->getLink();
//		}
//		if (node3 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node3->getCategory(), node3->getData()));
//			node3 = node3->getLink();
//		}
//	}
//
//	for (int i = 0; i < mergedList.size(); i++) {
//		for (int j = i + 1; j < mergedList.size(); j++) {
//			LinkedNode* node1 = mergedList.getEntry(i);
//			LinkedNode* node2 = mergedList.getEntry(j);
//			if (node1->getData() > node2->getData()) {
//				mergedList.remove(j);
//				mergedList.insert(i, node2);
//			}
//			else if (node1->getData() == node2->getData() && node1->getCategory() > node2->getCategory()) {
//				mergedList.remove(j);
//				mergedList.insert(i, node2);
//			}
//		}
//	}
//
//	list1->clear();
//	list2->clear();
//	list3->clear();
//
//	LinkedNode* node = mergedList.getHead();
//	while (node != NULL) {
//		char category = node->getCategory();
//		int data = node->getData();
//		LinkedNode* newNode = new LinkedNode(category, data);
//
//		if (category == 'A')
//			list1->insert(list1->size(), newNode);
//		else if (category == 'B')
//			list2->insert(list2->size(), newNode);
//		else if (category == 'C')
//			list3->insert(list3->size(), newNode);
//
//		node = node->getLink();
//	}
//}
//
//
//
//LinkedList* sortThreeListsByDataOnly(LinkedList* list1, LinkedList* list2, LinkedList* list3) {
//	LinkedList mergedList;
//
//	LinkedNode* node1 = list1->getHead();
//	LinkedNode* node2 = list2->getHead();
//	LinkedNode* node3 = list3->getHead();
//
//	while (node1 != NULL || node2 != NULL || node3 != NULL) {
//		if (node1 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node1->getCategory(), node1->getData()));
//			node1 = node1->getLink();
//		}
//
//		if (node2 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node2->getCategory(), node2->getData()));
//			node2 = node2->getLink();
//		}
//
//		if (node3 != NULL) {
//			mergedList.insert(mergedList.size(), new LinkedNode(node3->getCategory(), node3->getData()));
//			node3 = node3->getLink();
//		}
//	}
//
//	for (int i = 0; i < mergedList.size(); i++) {
//		for (int j = i + 1; j < mergedList.size(); j++) {
//			LinkedNode* node1 = mergedList.getEntry(i);
//			LinkedNode* node2 = mergedList.getEntry(j);
//			if (node1->getData() > node2->getData()) {
//				mergedList.remove(j);
//				mergedList.insert(i, node2);
//			}
//		}
//	}
//	return new LinkedList(mergedList);
//}
//
//
//
//int main()
//{
//	LinkedList* list1 = new LinkedList();
//	LinkedList* list2 = new LinkedList();
//	LinkedList* list3 = new LinkedList();
//
//	list1->insert(0, new LinkedNode('A', 331));
//	list1->insert(0, new LinkedNode('C', 79));
//	list1->insert(0, new LinkedNode('A', 21));
//	list1->insert(0, new LinkedNode('C', 87));
//	list1->insert(0, new LinkedNode('B', 471));
//	list1->insert(0, new LinkedNode('C', 130));
//	list1->insert(0, new LinkedNode('A', 27));
//	list1->insert(0, new LinkedNode('B', 93));
//
//
//	list2->insert(0, new LinkedNode('C', 103));
//	list2->insert(0, new LinkedNode('A', 421));
//	list2->insert(0, new LinkedNode('C', 112));
//	list2->insert(0, new LinkedNode('A', 336));
//	list2->insert(0, new LinkedNode('B', 421));
//	list2->insert(0, new LinkedNode('C', 331));
//	list2->insert(0, new LinkedNode('A', 521));
//	list2->insert(0, new LinkedNode('B', 31));
//
//
//	list3->insert(0, new LinkedNode('C', 93));
//	list3->insert(0, new LinkedNode('B', 189));
//	list3->insert(0, new LinkedNode('A', 66));
//	list3->insert(0, new LinkedNode('B', 672));
//	list3->insert(0, new LinkedNode('B', 79));
//	list3->insert(0, new LinkedNode('A', 81));
//	list3->insert(0, new LinkedNode('C', 303));
//	list3->insert(0, new LinkedNode('B', 269));
//
//	printf("Unsorted and mixed lists\n");
//	list1->displayCatAndData();
//	list2->displayCatAndData();
//	list3->displayCatAndData();
//	printf("\n\n");
//
//	sortThreeListsByCategory(list1, list2, list3);
//	printf("Sorting three lists based data and category\n");
//	list1->displayCatAndData();
//	list2->displayCatAndData();
//	list3->displayCatAndData();
//	printf("\n\n");
//
//	printf("Sorting three lists based data only\n");
//	LinkedList* list4 = sortThreeListsByDataOnly(list1, list2, list3);
//	list4->displayData();
//
//	return 0;
//}
