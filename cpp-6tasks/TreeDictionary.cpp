#include "TreeDictionary.h"
using namespace std;

TreeDictionary::TreeDictionary()
{
	root = nullptr;
	size = 0;
}

TreeDictionary::TreeDictionary(const TreeDictionary& copy)
{
	if (copy.root == nullptr) {
		return;
	}
	copyTree(root, copy.root);
	size = copy.size;
}

TreeDictionary::TreeDictionary(TreeDictionary&& move)
{
	size = move.size;
	swap(root, move.root);
}

Node::Node(string word, unsigned int frequency, int bal, Node* right, Node* left)
{
	this->word = word;
	this->bal = bal;
	this->frequency = frequency;
	this->right = right;
	this->left = left;
}

//удаление слова с двумя потомками, на вход: левый ко ень и удаляемое слово
void TreeDictionary::del2(Node*& rootLeft, Node*& toDel)
{
	if (rootLeft->right) {//если у левого есть что-то сп ава
		del2(rootLeft->right, toDel);
	}
	toDel->word = rootLeft->word;//пе еносим слово, частоту
	toDel->frequency = root->frequency;
	toDel = rootLeft;
	rootLeft = rootLeft->left;
}

void TreeDictionary::copyTree(Node* root, Node* copy)
{
	if (!copy) {
		return;
	}
	root = new Node(copy->word, copy->bal, copy->frequency);
	copyTree(root->left, copy->left);
	copyTree(root->right, copy->right);
}


void TreeDictionary::deleteTree(Node* root)
{
	if (!root) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

unsigned int TreeDictionary::findWord(Node* root, string word)
{
	if (!root) {
		return 0;
	}
	if (root->word.compare(word) == 0) {
		return root->frequency;
	}
	if (root->word.compare(word) > 0) {
		return findWord(root->left, word);
	}
	if (root->word.compare(word) < 0) {
		return findWord(root->right, word);
	}
}

//добавить слово
void TreeDictionary::addWord(Node*& root, string& word)
{
	if (!root) {
		root = new Node(word);
		return;
	}
	if (root->word.compare(word) == 0) {
		root->frequency++;
		return;
	}
	if (root->word.compare(word) > 0) {
		addWord(root->left, word);
	}
	if (root->word.compare(word) < 0) {
		addWord(root->right, word);
	}
}


void TreeDictionary::deleteWord(Node*& root, string& word)
{
	if (!root) {
		return;
	}
	if (root->word.compare(word) > 0) {
		deleteWord(root->left, word);
		return;
	}
	if (root->word.compare(word) < 0) {
		deleteWord(root->right, word);
		return;
	}
	Node* pDel = root;
	if (root->frequency > 1) {
		root->frequency--;
	}
	else {
		if (!root->right) {
			root = root->left;
			delete pDel;
			return;
		}
		if (!root->left) {
			root = root->right;
			delete pDel;
			return;
		}
		del2(root->left, pDel);
		delete pDel;
	}
}

//вывод дерева
void TreeDictionary::printTree(ostream& os, Node* root)
{
	if (!root) { return; }
	printTree(os, root->left);
	os << root->word << " - " << root->frequency << endl;
	printTree(os, root->right);
}

TreeDictionary::~TreeDictionary()
{
	size = 0;
	deleteTree(root);
}


TreeDictionary& TreeDictionary::operator=(const TreeDictionary& copy)
{
	if (this == &copy) {
		return *this;
	}
	deleteTree(root);
	root = nullptr;
	size = copy.size;
	copyTree(root, copy.root);
}


TreeDictionary& TreeDictionary::operator=(TreeDictionary&& move)
{
	size = move.size;
	swap(root, move.root);
	move.deleteTree(move.root);
	return *this;
}

unsigned int TreeDictionary::findWord(string word)
{
	return findWord(root, word);
}

void TreeDictionary::addWord(string word)
{
	size++;
	addWord(root, word);
}

void TreeDictionary::deleteWord(string word)
{
	size--;
	deleteWord(root, word);
}

unsigned int TreeDictionary::countWords()
{
	return size;
}

ostream& operator<< (ostream& os, TreeDictionary& obj)
{
	obj.printTree(os, obj.root);
	return os;
}