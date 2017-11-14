#include "BinarySearchTree.h"
#include <cstdlib>
int main()
{
	//system("chcp 437");

	BinarySearchTree bst;
	unsigned int n;
	int temp;
	cin >> n;
	for (unsigned int i = 0; i < n; i++)
	{
		cin >> temp;
		bst.insertElement(temp);
	}

	//bst.deleteElement(2);
	//bst.LRotate(bst.root);

	cout << endl;
	bst.inorderTraverse();
	cout << endl;
	bst.preorderTraverse();
	cout << endl;
	bst.postorderTraverse();
	cout << endl;
	bst.layerTraverse();
	cout << endl;

	cout << bst.getHeight(bst.root) << endl;

	/*cout << "Before size: " << bst.getSize() << endl;
	unsigned int s = bst.getSize();
	for (unsigned int i = 0; i < s; i++)
	{
		cout << bst.popMinElement() << " ";
	}
	cout << endl;
	cout << "After size: " << bst.getSize() << endl;*/

	system("pause");
	return 0;
}