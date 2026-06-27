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

	void deleteLastNode() {

		if (number_of_nodes == 0) {

			cout << "Linked list is empty. No nodes to delete." << endl;
			return;
		}
		else if (number_of_nodes == 1) {

			delete head;
			head = NULL;
			tail = NULL;
		}
		else {

			Node* adress_of_nodeToDelete = tail;
			tail = tail->adress_of_previousNode;
			tail->adress_of_nextNode = NULL;
			delete adress_of_nodeToDelete;
		}

		number_of_nodes--;
	}

	void addFirst(int _deger) {

		Node* adress_of_newNode = new Node(_deger);

		if (number_of_nodes == 0) {

			head = adress_of_newNode;
			tail = adress_of_newNode;
		}
		else {

			adress_of_newNode->adress_of_nextNode = head;
			head->adress_of_previousNode = adress_of_newNode;
			head = adress_of_newNode;
		}

		number_of_nodes++;
	}

	void deleteFirstNode() {

		if (number_of_nodes == 0) {

			cout << "Linked list is empty. No nodes to delete." << endl;

			return;
		}
		else if (number_of_nodes == 1) {

			delete head;

			head = NULL;
			tail = NULL;
		}
		else {

			Node* adress_of_nodeToDelete = head;
			head = head->adress_of_nextNode;
			head->adress_of_previousNode = NULL;

			delete adress_of_nodeToDelete;
		}

		number_of_nodes--;
	}

	void getNode(int _index) {

		if (_index < 0 || _index >= number_of_nodes) {

			cout << "The index you entered is out of bounds. Please provide an index between 0 and " << number_of_nodes - 1 << "." << endl << endl;
		}
		else {

			Node* adressHolder = head;

			if (_index < number_of_nodes / 2) {

				for (int i = 0; i < _index; i++) {

					adressHolder = adressHolder->adress_of_nextNode;
				}
			}
			else {

				adressHolder = tail;

				for (int i = number_of_nodes - 1; i > _index + 1; i--) {

					adressHolder = adressHolder->adress_of_previousNode;
				}

				cout << "Adrees of the node at index " << _index << " in the linked list: " << adressHolder << endl << endl;

				cout << "Value of the node at index " << _index << " in the linked list: " << adressHolder->deger << endl << endl;
			}
		}
	}

	void setNode(int _index, int _newValue) {

		if (_index < 0 || _index >= number_of_nodes) {

			cout << "The index you entered is out of bounds. Please provide an index between 0 and " << number_of_nodes - 1 << "." << endl << endl;
		}
		else {

			Node* adressHolder = head;

			if (_index <= number_of_nodes / 2) {

				for (int i = 0; i < _index; i++) {

					adressHolder = adressHolder->adress_of_nextNode;
				}

				adressHolder->deger = _newValue;

				cout << "Node at index " << _index << " in the linked list has been updated to " << adressHolder->deger << endl << endl;
			}
			else {

				for (int i = number_of_nodes - 1; i > _index; i--) {

					adressHolder = adressHolder->adress_of_previousNode;
				}

				adressHolder->deger = _newValue;

				cout << "Node at index " << _index << " in the linked list has been updated to " << adressHolder->deger << endl << endl;
			}
		}
	}

	void insertNode(int _index, int _deger) {

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

			if (_index <= number_of_nodes / 2) {

				Node* adress_holder_of_leftNode = head;

				for (int i = 0; i < _index - 1; i++) {

					adress_holder_of_leftNode = adress_holder_of_leftNode->adress_of_nextNode;
				}


				Node* adress_holder_of_rightNode = adress_holder_of_leftNode->adress_of_nextNode;


				adress_of_newNode->adress_of_previousNode = adress_holder_of_leftNode;
				adress_of_newNode->adress_of_nextNode = adress_holder_of_rightNode;
				adress_holder_of_leftNode->adress_of_nextNode = adress_of_newNode;
				adress_holder_of_rightNode->adress_of_previousNode = adress_of_newNode;

				number_of_nodes++;
			}
			else {

				Node* adress_holder_of_rightNode = tail;

				for (int i = (number_of_nodes - 1); i >= (_index + 2); i--) {

					adress_holder_of_rightNode = adress_holder_of_rightNode->adress_of_previousNode;
				}


				Node* adress_holder_of_leftNode = adress_holder_of_rightNode->adress_of_previousNode;


				adress_of_newNode->adress_of_previousNode = adress_holder_of_leftNode;
				adress_of_newNode->adress_of_nextNode = adress_holder_of_rightNode;
				adress_holder_of_leftNode->adress_of_nextNode = adress_of_newNode;
				adress_holder_of_rightNode->adress_of_previousNode = adress_of_newNode;

				number_of_nodes++;
			}
		}
	}
};

int main() {

	DoublyLinkedList* adress_of_doublyLinkedList1 = new DoublyLinkedList(12);

	adress_of_doublyLinkedList1->appendList(5);

	adress_of_doublyLinkedList1->appendList(24);

	adress_of_doublyLinkedList1->appendList(9);

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();

	adress_of_doublyLinkedList1->insertNode(3, 52);

	cout << "\nAfter inserting 52 at index 3: " << endl << endl;

	adress_of_doublyLinkedList1->printList();

	adress_of_doublyLinkedList1->getNumberOfNodes();

	adress_of_doublyLinkedList1->printHead();

	adress_of_doublyLinkedList1->printTail();



	delete adress_of_doublyLinkedList1;

	return 0;
}

