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


class Queue {

private:

	Node* head;
	Node* tail;
	int number_of_nodes;

public:

	Queue() {

		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
	}

	Queue(int _deger) {

		Node* adress_of_newNode = new Node(_deger);
		head = adress_of_newNode;
		tail = adress_of_newNode;
		number_of_nodes = 1;
	}

	~Queue() {

		Node* adressHolder = head;

		while (head != NULL) {

			head = head->adress_of_nextNode;

			delete adressHolder;

			adressHolder = head;
		}

		cout << "Queue sinifina ait destructor cagrildi." << endl;
	}

	void printQueue() {

		cout << "Queue: ";

		Node* adressHolder = head;

		while (adressHolder != NULL) {

			cout << adressHolder->deger << " ";

			adressHolder = adressHolder->adress_of_nextNode;
		}

		cout << endl << endl;
	}
};
