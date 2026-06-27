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

	void getNode(int _index) {

		if (_index < 0 || _index >= number_of_nodes) {

			cout << "The index you entered is out of bounds. Please provide an index between 0 and " << number_of_nodes - 1 << "." << endl << endl;
		}
		else {

			Node* adressHolder = head;

			for (int i = 0; i < _index; i++) {
				adressHolder = adressHolder->adress_of_nextNode;
			}

			cout << "Adrees of the node at index " << _index << " in the linked list: " << adressHolder << endl << endl;

			cout << "Value of the node at index " << _index << " in the linked list: " << adressHolder->deger << endl << endl;
		}
	}

	void setValueOfNode(int _index, int _newValue) {

		if (_index < 0 || _index >= number_of_nodes) {

			cout << "The index you entered is out of bounds. Please provide an index between 0 and " << number_of_nodes - 1 << "." << endl << endl;
		}
		else {

			Node* adressHolder = head;

			for (int i = 0; i < _index; i++) {

				adressHolder = adressHolder->adress_of_nextNode;
			}

			adressHolder->deger = _newValue;

			cout << "Node at index " << _index << " in the linked list has been updated to: " << adressHolder->deger << endl << endl;
		}
	}

	void insertNewNode(int _index, int _deger) {

		if (_index < 0 || _index > number_of_nodes) {

			cout << "The index you entered is out of bounds. Please provide an index between 0 and " << number_of_nodes << "." << endl << endl;
		}
		else if (_index == 0) {

			addFirst(_deger);
		}
		else if (_index == number_of_nodes) {

			appendList(_deger);
		}
		else {

			Node* adress_of_newNode = new Node(_deger);
			Node* adressHolder = head;

			for (int i = 0; i < _index - 1; i++) {
				adressHolder = adressHolder->adress_of_nextNode;
			}

			adress_of_newNode->adress_of_nextNode = adressHolder->adress_of_nextNode;
			adressHolder->adress_of_nextNode = adress_of_newNode;

			number_of_nodes++;
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

	adress_of_linkedList1->insertNewNode(-3, 50);

	adress_of_linkedList1->insertNewNode(0, 50);

	adress_of_linkedList1->printList();

	adress_of_linkedList1->insertNewNode(1, 1);

	adress_of_linkedList1->printList();

	adress_of_linkedList1->insertNewNode(7, 42);

	adress_of_linkedList1->printList();

	adress_of_linkedList1->insertNewNode(99, 17);


	delete adress_of_linkedList1;

	return 0;
}