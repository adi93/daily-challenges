/*
 * A unival tree (which stands for "universal value") is a tree where all nodes have the same value. 
 * Given the root to a binary tree, count the number of unival subtrees.
 */
#include	<stdlib.h>
#include	<iostream>
#include	<iomanip>
template <typename T>
struct Node {
	int value;
	Node<T> *left;
	Node<T> *right;
	Node<T>(int value) {
		this->value = value;
	}
};

template <typename T>
bool countNumberUnivalTrees (Node<T>* root, int & result)
{
	if (root == NULL) return true;

	bool left = countNumberUnivalTrees(root->left, result);
	bool right = countNumberUnivalTrees(root->right, result);

    // If any of the subtrees is not singly, then this
    // cannot be singly.
    if (left == false || right == false)
       return false;
 
    // If left subtree is singly and non-empty, but data
    // doesn't match
    if (root->left && root->value != root->left->value)
        return false;
 
    // Same for right subtree
    if (root->right && root->value != root->right->value)
        return false;

	result++;
	return true;

}
template <typename T>
int countNumberUnivalTrees (Node<T>* root)
{
	int result = 0;
	countNumberUnivalTrees(root, result);
	return result;
}		/* -----  end of function countNumberUnivalTrees  ----- */


int main ( int argc, char *argv[] )
{
	Node<int>* a = new Node<int>(5);
	a->left = new Node<int>(4);
	a->right = new Node<int>(5);
	a->left->left = new Node<int>(4);
	a->left->right = new Node<int>(4);
	a->right->right = new Node<int>(5);
	
	std::cout << "Result is: " << countNumberUnivalTrees(a) << "\n";
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* pseudo code
 * 
 * */
