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