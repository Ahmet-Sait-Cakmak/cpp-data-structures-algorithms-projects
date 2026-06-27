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

};


int main() {

	LinkedList* adress_of_linkedList1 = new LinkedList(12);

	return 0;
}