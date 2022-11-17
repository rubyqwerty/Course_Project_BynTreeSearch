#pragma once

struct node {
	int value = 0;
	node* left = nullptr;
	node* right = nullptr;
	node(int _value) : value(_value), left(nullptr), right(nullptr) {}
};