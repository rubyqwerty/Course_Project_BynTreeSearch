#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct triple {
	int x;
	int y;
	int value;
	int x1;
	int y1;
};

struct node {
	int value = 0;
	node* left = nullptr;
	node* right = nullptr;
	node(int _value) : value(_value), left(nullptr), right(nullptr) {}
};

class BynaryTreeSearch {
private:
	node* root = nullptr;
	int min_elem_in_the_subtree(node*, node* parent = nullptr);
public:
	vector<triple> coordinate;
	vector<triple> arrowsCor;
	void push(int, node* edge = nullptr);
	int search(int, node* edge = nullptr);
	int deleteNode(int, node* edge = nullptr, node* parent = nullptr);
	int replace(int, int);
	void clear(node* edge = nullptr);
	void bypassing(int*, node* edge = nullptr);
	void Visualization(int x, int y, int value, node* edge = nullptr);
	~BynaryTreeSearch() { clear(); };
};
