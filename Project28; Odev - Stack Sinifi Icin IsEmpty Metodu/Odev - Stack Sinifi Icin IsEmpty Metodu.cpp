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

class Stack {

private:

	Node* top;
	int number_of_nodes;

public:

	Stack() {

		top = NULL;
		number_of_nodes = 0;
	}

	Stack(int _deger) {

		Node* adress_of_newNode = new Node(_deger);
		top = adress_of_newNode;
		number_of_nodes = 1;
	}

	~Stack() {

		Node* adressHolder = top;

		while (top != NULL) {

			top = top->adress_of_nextNode;

			delete adressHolder;

			adressHolder = top;
		}

		cout << "Stack sinifina ait destructor cagrildi." << endl << endl;
	}

	void printStack() {

		cout << "Stack: " << endl << endl;

		Node* adressHolder = top;

		while (adressHolder != NULL) {

			cout << adressHolder->deger << endl;

			adressHolder = adressHolder->adress_of_nextNode;
		}

		cout << endl;
	}

	void printTop() {

		if (top != NULL) {

			cout << "Top value: " << top->deger << endl << endl;
		}
		else {

			cout << "Stack is empty." << endl << endl;
		}
	}

	int getNumberOfNodes() {

		return number_of_nodes;
	}

	void push(int _deger) {

		Node* adress_of_newNode = new Node(_deger);
		adress_of_newNode->adress_of_nextNode = top;
		top = adress_of_newNode;

		number_of_nodes++;
	}

	int pop() {

		if (top != NULL) {

			int value_of_poppedNode = top->deger;
			Node* adress_of_poppedNode = top;
			top = top->adress_of_nextNode;

			delete adress_of_poppedNode;

			number_of_nodes--;

			return value_of_poppedNode;
		}
		else {

			cout << "Stack is empty. Cannot pop." << endl << endl;

			exit(-1); 
		}
	}

	bool isEmpty() {

		if (top == NULL) {

			return true;
		}

		else {

			return false;
		}
	}
};

int main() {

	Stack* stack1 = new Stack;

	stack1->printStack();

	cout << "Is the stack empty? " << endl << endl;

	if (stack1->isEmpty()) {

		cout << "Yes, the stack is empty." << endl << endl;
	}

	else {
		cout << "No, the stack is not empty." << endl << endl;
	}

	stack1->push(5);

	stack1->push(8);

	stack1->push(40);

	cout << "After pushing 5, 8, and 40 to the stack: " << endl << endl;

	stack1->printStack();

	cout << "Is the stack empty? " << endl << endl;

	if (stack1->isEmpty()) {

		cout << "Yes, the stack is empty." << endl << endl;
	}

	else {
		cout << "No, the stack is not empty." << endl << endl;
	}

	cout << "Number of nodes in the stack: " << stack1->getNumberOfNodes() << endl << endl;

	stack1->printTop();

	
	delete stack1;

	return 0;
}