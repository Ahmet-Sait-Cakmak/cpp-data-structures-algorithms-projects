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

	void print_all_nodes_with_DFS_PreOrder_Search(Node* adress_of_node) {

		cout << adress_of_node->deger << ", ";

		if (adress_of_node->adress_of_leftChild != NULL) {

			print_all_nodes_with_DFS_PreOrder_Search(adress_of_node->adress_of_leftChild);
		}

		if (adress_of_node->adress_of_rightChild != NULL) {

			print_all_nodes_with_DFS_PreOrder_Search(adress_of_node->adress_of_rightChild);
		}
	}

	Node* search_with_DFS_PreOrder_Traversal(Node* adress_of_node, int arananDeger) {

		if (adress_of_node == NULL || adress_of_node->deger == arananDeger) {

			return adress_of_node;
		}

		if (adress_of_node->adress_of_leftChild != NULL) {

			return search_with_DFS_PreOrder_Traversal(adress_of_node->adress_of_leftChild, arananDeger);
		}
		else {

			return search_with_DFS_PreOrder_Traversal(adress_of_node->adress_of_rightChild, arananDeger);
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

	cout << "DFS PreOrder Search Algoritmasi ile yazilmis binary search tree: ";

	binarySearchTree1->print_all_nodes_with_DFS_PreOrder_Search(binarySearchTree1->root);

	cout << endl << endl;

	int arananDeger;

	cout << "Lutfen DFS PreOrder Search Algoritmasi ile binarySearchTree1 icinde aramak istediginiz degeri giriniz: ";

	cin >> arananDeger;
	
	if (binarySearchTree1->search_with_DFS_PreOrder_Traversal(binarySearchTree1->root, arananDeger) != NULL) {

		cout << "\nAranan deger binary search tree'de bulundu." << endl << endl;
	}
	else {

		cout << "\nAranan deger binary search tree'de bulunamadi." << endl << endl;
	}


	delete binarySearchTree1;

	return 0;
}