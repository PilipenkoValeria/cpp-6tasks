#pragma once
#include "iostream"
#include "string"
using namespace std;

struct Node {
	string word;
	unsigned int frequency;
	int bal;
	Node* right, * left;
	Node(string word, unsigned int frequency = 1U, int bal = 0, Node* right = nullptr, Node* left = nullptr);
};

class TreeDictionary
{
private:
	Node* root;
	int size;
	void del2(Node*& rootLeft, Node*& toDel);
	void copyTree(Node* root, Node* copy);
	void deleteTree(Node* root);
	unsigned int findWord(Node* root, string word);
	void addWord(Node*& root, string& word);
	void deleteWord(Node*& root, string& word);
	void printTree(ostream& os, Node* root);
public:
	TreeDictionary();
	TreeDictionary(const TreeDictionary& copy);
	TreeDictionary(TreeDictionary&& move);
	~TreeDictionary();
	TreeDictionary& operator=(const TreeDictionary& copy);
	TreeDictionary& operator=(TreeDictionary&& move);
	unsigned int findWord(string word);
	void addWord(string word);
	void deleteWord(string word);
	unsigned int countWords();
	friend ostream& operator<< (ostream& os, TreeDictionary& obj);
};
