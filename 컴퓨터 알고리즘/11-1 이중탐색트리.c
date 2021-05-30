#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct {
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

void expandExternal(TreeNode* w)	//172p
{
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = NULL;
	l->right = NULL;
	l->parent = w;
	r->left = NULL;
	r->right = NULL;
	r->parent = w;
	w->left = l;
	w->right = r;
}

TreeNode* treeSearch(TreeNode* v, int k) {
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else
		return treeSearch(v->right, k);
}

int findElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (isExternal(w))
		return 0;
	else
		return w->key;
}

void insertItem(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w))
		return;
	else {
		w->key = k;
		expandExternal(w);
	}
}

TreeNode* sibling(TreeNode* z) {		//형제노드 받아오기
	if (z->parent->left == z)
		return z->parent->right;
	else
		return z->parent->left;
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z) {
	TreeNode* w = z->parent;
	TreeNode* g = w->parent;
	TreeNode* zs = sibling(z);
	zs->parent = g;

	if (g == NULL) {
		T->root = zs;
	}
	else {
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
	free(z);
	free(w);
	return zs;
}

TreeNode* inOrderSucc(TreeNode* w) {
	w = w->right;
	while (w->left != NULL)
		w = w->left;
	return w;
}

int removeElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);

	if (isExternal(w))
		return 0;

	TreeNode* z, * y;
	z = w->left;
	if (!isExternal(z))		//하나라도 외부노드라면
		z = w->right;
	if(isExternal(z))
		reduceExternal(T, z);
	else     //case2
	{
		z = inOrderSucc(w);
		y = z->parent;
		w->key = y->key;
		reduceExternal(T, z);
	}
	return k;
}

void preOrder(TreeNode* root) {
	if (isExternal(root))
		return;
	printf("[%d] ", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 9);
	insertItem(T, 2);
	insertItem(T, 1);
	preOrder(T->root);
	removeElement(T, 2);
	preOrder(T->root);

	return 0;
}
