#include <iostream>

using namespace std;

struct tree_element {
	int value; 
	struct tree_element* left;
	struct tree_element* right;
};


tree_element* create_tree_element(int i) {
	tree_element* elem = new tree_element;
	elem->value = i;
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void insert_into_tree(tree_element* root, tree_element* elem) {
	if (elem->value < root->value) {
		if (root->left == NULL) {
			root->left = elem;
		}else{
			insert_into_tree(root->left, elem);
		}
}else{
		if (root->right == NULL) {
			root->right = elem;
		}
		else {
			insert_into_tree(root->right, elem);
		}
	}
}

void print_tree(tree_element* cur_elem) {
	if (cur_elem->left != NULL) {
		print_tree(cur_elem->left);
	}
	cout << "Value = " << cur_elem->value << endl;
	if (cur_elem->right != NULL) {
		print_tree(cur_elem->right);
	}
}

int main()
{
	int a[7] = { -3,-7,2,42,7,3,12 };
	tree_element* root = create_tree_element(4);
		for (int i = 0; i < 7; i++) {
			tree_element* el = create_tree_element(a[i]);
			insert_into_tree(root, el);
		}
	cout << "My tree:" << endl;
	print_tree(root);
	system("pause");
	return 0;
}
