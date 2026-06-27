#include <iostream>

using namespace std;


class Node {

public:

	int deger;
	Node* adress_of_leftChild;
	Node* adress_of_rightChild;

	Node(int _deger) {

		deger = _deger;
		adress_of_leftChild = NULL;
		adress_of_rightChild = NULL;
	}
};
