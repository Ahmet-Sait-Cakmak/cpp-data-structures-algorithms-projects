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


	void printHead() {

		if (head != NULL) {
			cout << "Head: " << head->deger << endl << endl;
		}
	}


	void printTail() {

		if (tail != NULL) {
			cout << "Tail: " << tail->deger << endl << endl;
		}
	}


	void getNumberOfNodes() {

		cout << "Number of nodes in the linked list: " << number_of_nodes << endl << endl;
	}


	void printList() {

		Node* adressHolder = head;

		while (adressHolder != NULL) {

			cout << adressHolder->deger << ", ";

			adressHolder = adressHolder->adress_of_nextNode;
		}

		cout << endl << endl;
	}

	void appendList(int _deger) {

		Node* adress_of_newNode = new Node(_deger);

		if (number_of_nodes == 0) {

			head = adress_of_newNode;
			tail = adress_of_newNode;

		}
		else {

			tail->adress_of_nextNode = adress_of_newNode;
			adress_of_newNode->adress_of_previousNode = tail;
			tail = adress_of_newNode;
		}

		number_of_nodes++;
	}

};

int main() {

	DoublyLinkedList* adress_of_doublyLinkedList1 = new DoublyLinkedList(12);

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();

	cout << "\nAppending 5 to the end of the list..." << endl << endl;

	adress_of_doublyLinkedList1->appendList(5);

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();

	cout << "\nAppending 24 to the end of the list..." << endl << endl;

	adress_of_doublyLinkedList1->appendList(24);

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();

	cout << "\nAppending 9 to the end of the list..." << endl << endl;

	adress_of_doublyLinkedList1->appendList(9);

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();

	


	delete adress_of_doublyLinkedList1;

	return 0;
}

