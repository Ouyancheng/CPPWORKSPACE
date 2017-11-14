#include <iostream>
#include <string>
#include <cctype>
using namespace std;
struct node {
	char current;
	node *left;
	node *right;
	node(char current, node *left, node *right) : current(current), left(left), right(right) {}
};

node *root = nullptr;
string str;
size_t currentIndex;

char peekNextToken() {
	while (isspace(str[currentIndex])) {
		++currentIndex;
	}
	return str[currentIndex];
}
char popNextToken() {
	char c = peekNextToken();
	currentIndex++;
	return c;
}

// After pasing a sub-tree, the pointer will be set to the next token. 
node * parseBinaryTree() {
	char peekedChar = peekNextToken();
	if (isalpha(peekedChar)) {
		node *left, *right;

		char current = popNextToken();

		popNextToken(); // eat '('

		left = parseBinaryTree();

		popNextToken(); // eat ','

		right = parseBinaryTree();

		popNextToken(); // eat ')'

		return new node(current, left, right);
	} else if (peekedChar == ',' || peekedChar == ')') {
		return nullptr;
	} else {
		cout << "Error in paring token: " << peekedChar << endl;
		return nullptr;
	}
}
void inorderTraverse(node *);
void preorderTraverse(node *);
void postorderTraverse(node *);
int main() {
	getline(cin, str);
	root = parseBinaryTree();
	inorderTraverse(root);
	cout << endl;
	preorderTraverse(root);
	cout << endl;
	postorderTraverse(root);
	cout << endl;
	return 0;
}
void inorderTraverse(node *root) {
	if (root) {
		inorderTraverse(root->left);
		cout << root->current << " ";
		inorderTraverse(root->right);
	}
}
void preorderTraverse(node *root) {
	if (root) {
		cout << root->current << " ";
		preorderTraverse(root->left);
		preorderTraverse(root->right);
	}
}
void postorderTraverse(node *root) {
	if (root) {
		postorderTraverse(root->left);
		postorderTraverse(root->right);
		cout << root->current << " ";
	}
}