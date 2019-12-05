#include "Trie.h"
#include <iostream>
using namespace std;

int Trie::count;

Trie::Trie()
{
	root = new TrieNode;
	root->parent = NULL;
	for (int i = 0; i < 26; i++)
	{
		root->children[i] = NULL;
	}
}

void Trie::insert(string word)
{
	insert(word, root);
}

void Trie::insert(string word, TrieNode* node)
{
	int tav = word[0] - 'a';

	if (node->children[tav] == NULL)
	{
		cout << tav << endl;
		TrieNode* son = new TrieNode;
		son->parent = node;
		node->children[tav] = son;
		node->children[tav]->isEndOfWord = false;
	}
	if (word.length() -1 == 1)							// if (word.length() - 1 == 1)	 
	{
		node->isEndOfWord = true;		// node->children[tav]->isEndOfWord = true;
		return;
	}

	insert(word.substr(1, word.length()), node->children[tav]);
}

bool Trie::del(string word)
{
	TrieNode* node = searchLetter(word, root);
	if (node == NULL || !node->isEndOfWord)
		return false;
	node->isEndOfWord = false;

	for (int i = 0; i < word.length() - 1; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (node->children[i] != NULL)
				return true;
		}
		TrieNode* parent = node->parent;
		delete node;
		node = parent;
	}
	
	return true;

	// return del(word, root, 0);
}

//bool Trie::del(string word, TrieNode* node)
//{
	//int tav = word[0] - 'a';
	////check if the letter is exist!!!!
	//if (node->children[tav] == NULL)
	//	return false;

	////End of word
	////if (word.length() - 1 <= count)
	////{
	////	if (node->children[tav] != NULL && node->children[tav]->isEndOfWord )
	////	{
	////		node->children[tav]->isEndOfWord = false;
	////		if (check(node->children[tav]))
	////		{
	////			delete node->children[tav];
	////			node->children[tav] = NULL;
	////		}
	////		return true;
	////	}
	////	return false;		// to check this bug!!!
	////}

	//if (word.length() == 1)
	//{
	//	if (node->isEndOfWord)
	//	{
	//		node->isEndOfWord = false;
	//		if (check(node->children[tav]))
	//			delete node;
	//		return true;
	//	}
	//	return false;		// to check this bug!!!
	//}

	//bool exists = del(word.substr(1, word.length()), node->children[tav]);
	//if (check(node->children[tav]))
	//{
	//	delete node->children[tav];
	//	node->children[tav] = NULL;
	//}
	//return exists;
//}

bool Trie::check(TrieNode* node)
{
	for (int i = 0; i < 26; i++)
	{
		if (node->children[i] != NULL)
			return false;
	}
	return true;
}

bool Trie::search(string word)
{
	return search(word, root);
}

bool Trie::search(string word, TrieNode* node)
{
	int tav = word[0] - 'a';
	//check if the letter is exist
	if (node == NULL)
		return false;

	//End of word
	if (word.length() == 1)
	{
		if (node->isEndOfWord)
			return true;
		return false;
	}

	return search(word.substr(1, word.length()), node->children[tav]);
}

int Trie::printAutoSuggestions(TrieNode* node)
{
	count = 0;
	if (node == root)
	{
		printAutoSuggestions("", node);
		return count;
	}
	
	TrieNode* tmp = node->parent;
	for (int i = 0; i < 26; i++)
	{
		if (tmp->children[i] == node)
		{
			printAutoSuggestions((string)("a" + i), node);
			return count;
		}
	}
}

void Trie::printAutoSuggestions(string word, TrieNode* node)
{
	if (node->isEndOfWord)
	{
		cout << word << endl;
		count++;
	}
	
	for (int i = 0; i < 26; i++)
	{	
		if (node->children[i] != NULL)
		{		
			word += ('a' + i);
			printAutoSuggestions(word, node->children[i]);
			word.substr(0, word.length() - 1);
		}	
	}
}

TrieNode* Trie::searchLetter(string word, TrieNode* node)
{
	int tav = word[0] - 'a';
	//check if the letter is exist
	if (node == NULL)
		return NULL;

	//End of word
	if (word.length() == 1)
	{
		if (node->isEndOfWord)
			return node;
		return NULL;
	}

	search(word.substr(1, word.length()), node->children[tav]);
}



