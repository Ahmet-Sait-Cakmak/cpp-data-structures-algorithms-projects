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


class BinarySearchTree {

public:

	Node* root;

	BinarySearchTree() {

		root = NULL;
	}

	bool insertNode(int _deger) {

		Node* adress_of_newNode = new Node(_deger);

		if (root == NULL) {

			root = adress_of_newNode;

			return true;
		}

		Node* adressHolder = root;

		while (true) {

			if (adress_of_newNode->deger == adressHolder->deger) {

				cout << "Binary Search Tree'nin icinde" << adress_of_newNode->deger
					<< " degeri zaten mevcut. Bundan dolayi yeni node eklenemedi." << endl;

				return false;
			}

			if (adress_of_newNode->deger < adressHolder->deger) {

				if (adressHolder->adress_of_leftChild == NULL) {

					adressHolder->adress_of_leftChild = adress_of_newNode;

					return true;
				}
				else
					adressHolder = adressHolder->adress_of_leftChild;
			}
			else {

				if (adressHolder->adress_of_rightChild == NULL) {
					adressHolder->adress_of_rightChild = adress_of_newNode;
					return true;
				}
				else
					adressHolder = adressHolder->adress_of_rightChild;
			}
		}
	}
};


int main() {

	BinarySearchTree* binarySearchTree1 = new BinarySearchTree();

	binarySearchTree1->insertNode(52);

	binarySearchTree1->insertNode(27);

	binarySearchTree1->insertNode(15);

	binarySearchTree1->insertNode(30);

	binarySearchTree1->insertNode(78);

	binarySearchTree1->insertNode(65);

	binarySearchTree1->insertNode(53);

	binarySearchTree1->insertNode(76);

	binarySearchTree1->insertNode(12);

	cout << "Binary Search Tree'ye eklenen son node'un degeri: " << binarySearchTree1->root->adress_of_leftChild->adress_of_leftChild->adress_of_leftChild->deger << endl << endl;


	delete binarySearchTree1;

	return 0;
}