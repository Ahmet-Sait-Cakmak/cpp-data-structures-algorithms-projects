#include<iostream>

using namespace std;

class Node {

public:

	int deger;
	Node* adress_of_nextNode;
	Node* adress_of_previousNode;

	Node(int _deger) {

		deger = _deger;
		adress_of_nextNode = NULL;
		adress_of_previousNode = NULL;
	}
};

class DoublyLinkedList {

private:

	Node* head;
	Node* tail;
	int number_of_nodes;

public:

	DoublyLinkedList() {

		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
	}


	DoublyLinkedList(int _deger) {

		Node* adress_of_newNode = new Node(_deger);
		head = adress_of_newNode;
		tail = adress_of_newNode;
		number_of_nodes = 1;
	}


	~DoublyLinkedList() {

		cout << "LinkedList sinifina ait destructor cagrildi." << endl;

		Node* adressHolder = head;

		while (adressHolder != NULL) {

			head = head->adress_of_nextNode;

			delete adressHolder;

			adressHolder = head;
		}
	}
};

int main() {

	DoublyLinkedList* adress_of_doublyLinkedList1 = new DoublyLinkedList(12);

	delete adress_of_doublyLinkedList1;

	return 0;
}

