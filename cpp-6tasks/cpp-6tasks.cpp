#include "TreeDictionary.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	TreeDictionary* tree = new TreeDictionary();
	tree->addWord("поезд");
	tree->addWord("магазин");
	tree->addWord("игра");
	tree->addWord("руководитель");
	tree->addWord("двигатель");
	tree->addWord("таблица");
	tree->addWord("поезд");
	tree->addWord("концепция");
	tree->addWord("нефть");
	tree->addWord("поезд");
	tree->addWord("нефть");
	tree->addWord("секретарь");
	tree->addWord("двигатель");

	cout << *tree;
	cout << "__________________________________" << endl;
	cout << "Кол-во слов в дереве: " << tree->countWords() << endl;
	cout << "Встречаемость слова \"поезд\" : " << tree->findWord("поезд") << endl;
	cout << "Встречаемость слова \"таблица\" : " << tree->findWord("таблица") << endl;
	cout << "Встречаемость слова \"нефть\" : " << tree->findWord("нефть") << endl;
	cout << "__________________________________" << endl;
	cout << "Удаление слов: секретарь, нефть, магазин" << endl;
	cout << "__________________________________" << endl;
	tree->deleteWord("секретарь");
	tree->deleteWord("нефть");
	tree->deleteWord("таблица");
	tree->deleteWord("магазин");
	cout << *tree << endl;
	cout << "Кол-во слов в дереве: " << tree->countWords() << endl;
	cout << "Встречаемость слова \"поезд\" :" << tree->findWord("поезд") << endl;
	cout << "Встречаемость слова \"таблица\" :" << tree->findWord("таблица") << endl;
	cout << "Встречаемость слова \"нефть\" :" << tree->findWord("нефть") << endl;
	system("pause");
	delete tree;
	return 0;
}
