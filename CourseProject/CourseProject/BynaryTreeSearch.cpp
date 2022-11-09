#include "pch.h"
#include "BynaryTreeSearch.h"

void BynaryTreeSearch::push(int value, node* edge)
{
	if (!root)	root = new node(value);
	else
	{
		if (!edge) edge = root;
		if (value < edge->value)
			if (!edge->left)
				edge->left = new node(value);
			else
				push(value, edge->left);
		else
			if (!edge->right)
				edge->right = new node(value);
			else
				push(value, edge->right);
	}
}

int BynaryTreeSearch::search(int key, node* edge)
{
	if (!root)	return 0;
	if (!edge) edge = root;
	if (key == edge->value) return 1;
	if (key < edge->value)
		if (!edge->left)
			return 0;
		else
			return search(key, edge->left);
	else
		if (!edge->right)
			return 0;
		else
			return search(key, edge->right);
}

int BynaryTreeSearch::min_elem_in_the_subtree(node* edge, node* parent)
{
	if (!edge->left && !edge->right)
	{
		if (parent->value <= edge->value) parent->right = nullptr;
		else parent->left = nullptr;
		int n = edge->value;
		delete edge;
		return n;
	}
	if (!edge->left)
	{
		if (parent->value > edge->value) parent->left = edge->right;
		else parent->right = edge->right;
		int n = edge->value;
		delete edge;
		return n;
	}
	return min_elem_in_the_subtree(edge->left, edge);
}

int BynaryTreeSearch::deleteNode(int key, node* edge, node* parent)
{
	if (!root)	return -1; 
	if (!edge) edge = root;
	if (key == root->value) return 0;
	if (key == edge->value)
	{
		if (!edge->left && !edge->right)
		{
			if (parent->value > edge->value) parent->left = nullptr;
			else  parent->right = nullptr;
			delete edge;
		}
		else if (edge->left && edge->right)
		{
			edge->value = min_elem_in_the_subtree(edge->right, edge);
		}
		else if (edge->left)
		{
			if (parent->value > edge->value) parent->left = edge->left;
			else parent->right = edge->left;
			delete edge;
		}
		else
		{
			if (parent->value > edge->value) parent->left = edge->right;
			else parent->right = edge->right;
			delete edge;
		}
		return 1;
	}
	if (key < edge->value)
		if (!edge->left)
			return 0; 
		else
			return deleteNode(key, edge->left, edge);
	else
		if (!edge->right)
			return 0; 
		else
			return deleteNode(key, edge->right, edge);
}

int BynaryTreeSearch::replace(int value1, int value2)
{
	if (!deleteNode(value1))
		return 0; 
	push(value2);
	return 1;
}

void BynaryTreeSearch::clear(node* edge)
{
	if (!edge) edge = root;
	if (!edge) return;
	if (edge->left)
		clear(edge->left);
	if (edge->right)
		clear(edge->right);
	delete[] edge;
}


void BynaryTreeSearch::bypassing(int* Array, node* edge)
{
	if (!edge) edge = root;
	if (edge->left) bypassing(Array, edge->left);
	*(Array++) = edge->value;
	if (edge->right) bypassing(Array, edge->right);
}


void BynaryTreeSearch::Visualization(int x, int y, int val, node* edge)
{
	if (!edge) edge = root;
	if (edge->left)
	{
		arrowsCor.push_back({ x,y,0,x-val,y+80 });
		Visualization(x - val, y + 80, val / 2, edge->left);
	}
	coordinate.push_back({ x,y,edge->value });
	if (edge->right)
	{
		arrowsCor.push_back({ x,y,0,x + val,y + 80 });
		Visualization(x + val, y + 80, val / 2, edge->right);
	}
}