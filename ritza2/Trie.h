#pragma once
#include <iostream>
#include <string>

using namespace std;

// Trie node
struct TrieNode
{
	struct TrieNode* children[26];
	TrieNode* parent;
	// isEndOfWord is true if the node
	// represents end of a word
	bool isEndOfWord = false;
};

class Trie
{	
	TrieNode* root;

	void insert(string, TrieNode*);
	bool del(string, TrieNode*);
	bool check(TrieNode*);
	bool search(string, TrieNode*);
	void printAutoSuggestions(string, TrieNode*);
	TrieNode* searchLetter(string, TrieNode*);
	static int count;


public:
	Trie();
	void insert(string);
	bool del(string);
	bool search(string);
	int printAutoSuggestions(TrieNode*);
};

