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

	int getHead() {

		if (head != NULL) {

			return head->deger;
		}
		else {

			cout << "Queue is empty!" << endl;
			return -1;
		}
	}

	int getTail() {

		if (tail != NULL) {

			return tail->deger;
		}
		else {

			cout << "Queue is empty!" << endl;
			return -1;
		}
	}

	int getNumberOfNodes() {

		return number_of_nodes;
	}

	void enqueue(int _deger) {

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
};


int main() {

	Queue* queue1 = new Queue(12);

	queue1->enqueue(24);

	queue1->enqueue(7);

	queue1->enqueue(15);
	
	queue1->printQueue();

	cout << "Number of nodes in the queue: " << queue1->getNumberOfNodes() << endl << endl;

	cout << "Head value of the queue: " << queue1->getHead() << endl << endl;

	cout << "Tail value of the queue: " << queue1->getTail() << endl << endl;


	delete queue1;

	return 0;
}
