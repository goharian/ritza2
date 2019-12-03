#pragma once
#include <iostream>
using namespace std;

// Trie node
struct TrieNode
{
	struct TrieNode* children[26];
	//TrieNode* parent;
	// isEndOfWord is true if the node
	// represents end of a word
	bool isEndOfWord;
};

class Trie
{	
	TrieNode* root;

	void insert(string, TrieNode*, int);
	bool del(string, TrieNode*, int);

public:
	Trie();
	void insert(string);
	bool del(string);
};

