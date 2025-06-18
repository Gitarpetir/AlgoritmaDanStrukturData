#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **root, int newData){
	if (*root == NULL){
		Node *newNode;
		newNode = new Node;
		newNode->data = newData;
		newNode->left = NULL;
		newNode->right = NULL;
		(*root) = newNode;
		(*root)->left = NULL;
		(*root)->right = NULL;
		cout << "Data has been added\n";
	}
	else if (newData < (*root)->data){
		insert(&((*root)->left), newData);
	}
	else if (newData > (*root)->data){
		insert(&((*root)->right), newData);
	}
	else if (newData == (*root)->data){
		cout << "Data is already exist\n";
	}
}

void preOrder(Node *root){
	if (root != NULL){
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node *root){
	if (root != NULL){
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void postOrder(Node *root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
}

int main(){
    int opt, val;
    Node *tree;
    tree = NULL;

    do {
    	system("cls");

		cout << "1. Insert\n";
		cout << "2. PreOrder\n";
		cout << "3. InOrder\n";
		cout << "4. PostOrder\n";
		cout << "5. Exit\n";
	
		cout << "\nOption: "; cin >> opt;

		switch (opt) {
			case 1:
				cout << "\n Input:";
				cout << "\n ------";
				cout << "\n New data: ";
				cin >> val;
				insert(&tree, val);
				break;

			case 2:
				cout << "PreOrder Traversal\n";
				cout << "==========================\n";
				if (tree == NULL) {
					cout << "Tree is empty!\n";
				}
				else {
					preOrder(tree);
					cout << endl;
				}
				break;

			case 3:
				cout << "InOrder Traversal\n";
				cout << "==========================\n";
				if (tree == NULL) {
					cout << "Tree is empty!\n";
				}
				else {
					inOrder(tree);
					cout << endl;
				}
				break;

			case 4:
				cout << "PostOrder Traversal\n";
				cout << "==========================\n";
				if (tree == NULL) {
					cout << "Tree is empty!\n";
				}
				else {
					postOrder(tree);
					cout << endl;
				}
				break;

			case 5:
				return 0;
				
			default:
				cout << "Option is not valid! Please re-enter your option";
				break;
		}
		getch();
    } while(opt != 5);
    return 0;
}
