#include<iostream>

using namespace std;

class Node {

public:

	int deger;
	Node* adress_of_nextNode;

	Node(int _deger) {

		deger = _deger;
		adress_of_nextNode = NULL;
	}
};

class LinkedList {

private:

	Node* head;
	Node* tail;
	int number_of_nodes;


public:

	LinkedList() {

		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
	}

	LinkedList(int _deger) {

		Node* adress_of_newNode = new Node(_deger);
		head = adress_of_newNode;
		tail = adress_of_newNode;
		number_of_nodes = 1;
	}

	~LinkedList() {

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

	void appendList(int _deger) {

		Node* adress_of_newNode = new Node(_deger);

		if (number_of_nodes == 0) {

			head = adress_of_newNode;
			tail = adress_of_newNode;

		}
		else {

			tail->adress_of_nextNode = adress_of_newNode;
			tail = adress_of_newNode;
		}

		number_of_nodes++;
	}

	void printList() {

		Node* adressHolder = head;

		while (adressHolder != NULL) {

			cout << adressHolder->deger << ", ";

			adressHolder = adressHolder->adress_of_nextNode;
		}

		cout << endl << endl;
	}

	void deleteLastNode() {

		if (number_of_nodes == 0) {

			cout << "Linked list is empty. No nodes to delete." << endl;
		}
		else {

			Node* adressHolder1 = head;
			Node* adressHolder2 = head;

			while (adressHolder1->adress_of_nextNode != NULL) {

				adressHolder2 = adressHolder1;
				adressHolder1 = adressHolder1->adress_of_nextNode;
			}

			tail = adressHolder2;
			tail->adress_of_nextNode = NULL;
			number_of_nodes--;

			if (number_of_nodes == 0) {

				head = NULL;
				tail = NULL;
			}
			else {

				delete adressHolder1;
			}
		}
	}

	void addFirst(int _deger) {

		Node* adress_of_newNode = new Node(_deger);

		if (number_of_nodes == 0) {

			head = adress_of_newNode;
			tail = adress_of_newNode;
		}
		else {

			adress_of_newNode->adress_of_nextNode = head;
			head = adress_of_newNode;
		}

		number_of_nodes++;
	}

	void deleteFirst() {

		if (number_of_nodes == 0) {

			cout << "Linked list is empty. No nodes to delete." << endl;
		}

		else if (number_of_nodes == 1) {

			Node* adressHolder = head;
			head = NULL;
			tail = NULL;
			
			delete adressHolder;

			number_of_nodes--;
		}

		else {

			Node* adressHolder = head;
			head = head->adress_of_nextNode;

			delete adressHolder;

			number_of_nodes--;
		}
	}
};


int main() {

	LinkedList* adress_of_linkedList1 = new LinkedList(12);

	adress_of_linkedList1->appendList(5);

	adress_of_linkedList1->appendList(24);

	adress_of_linkedList1->appendList(8);

	adress_of_linkedList1->appendList(7);

	adress_of_linkedList1->getNumberOfNodes();

	adress_of_linkedList1->printHead();

	adress_of_linkedList1->printTail();

	adress_of_linkedList1->printList();

	adress_of_linkedList1->deleteFirst();

	adress_of_linkedList1->printList();

	delete adress_of_linkedList1;

	return 0;
}