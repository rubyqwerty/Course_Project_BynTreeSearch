#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include "Coordinate.h"

using namespace std;

class BynaryTreeSearch {
private:
	node* root = nullptr;
	int min_elem_in_the_subtree(node*, node* parent = nullptr);
public:
	vector<Coordinate> coordinate;
	vector<Coordinate> arrowsCor;
	void push(int, node* edge = nullptr);
	int search(int, node* edge = nullptr);
	int deleteNode(int, node* edge = nullptr, node* parent = nullptr);
	int replace(int, int);
	void clear(node* edge = nullptr);
	void bypassing(vector<int>&, node* edge = nullptr);
	void Visualization(int x, int y, int value, node* edge = nullptr);
	~BynaryTreeSearch() { clear(); };
};
