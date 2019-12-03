#include "Trie.h"


Trie::Trie()
{
	root = new TrieNode;
	for (int i = 0; i < 26; i++)
	{
		root->children[i] = NULL;
	}
}

void Trie::insert(string word)
{
	insert(word, root, 0);
}

void Trie::insert(string word, TrieNode* node, int count)
{
	int tav = word[count] - 65;

	if (node->children[tav] == NULL)
	{
		TrieNode* son = new TrieNode;
		node->children[tav] = son;
		node->children[tav]->isEndOfWord = false;
	}
	if (word.length() - 1 <= count)
	{
		node->children[tav]->isEndOfWord = true;
		return;
	}

	insert(word, node->children[tav], ++count);
}

bool Trie::del(string word)
{
	return del(word, root, 0);
}

bool Trie::del(string word, TrieNode* node, int count)
{
	int tav = word[count] - 65;
	if (word.length() - 1 <= count)
	{
		if (node->isEndOfWord && node->children[tav] != NULL)
			return true;
		return false;		// to check this bug!!!
	}
	
	
	return false;
}
