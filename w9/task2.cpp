#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

std::vector<std::string> results;
std::vector<std::pair<std::string, int>> equals;

struct TrieNode
{
	TrieNode* children;
	bool fullWord;
	char value;
	TrieNode()
	{
		value = '\0';
		fullWord = false;
	}
};

bool find(TrieNode* root, std::string input)
{
	TrieNode* res = root;

	for(int i = 0; i < input.size(); i++)
	{
		int pos = input[i] - 'a';
		if(input[i] == res->children[pos].value)
		{
			res = &res->children[pos];	
		}
		else return false;
	}
	return res->fullWord;
}
void insert(TrieNode* root, std::string input)
{
	TrieNode* res = root;
	std::string newName = "";
	bool generated = false;
	for(int i = 0; i < input.size(); i++)
	{
		int pos = input[i] - 'a';
		if(input[i] == res->children[pos].value)
		{
			newName.push_back(input[i]);
			res = &res->children[pos];
			
		}
		else if(res->children[pos].value == '\0')
		{
			res->children[pos].value = input[i];
			res->children[pos].children = new TrieNode[26]; 
			newName.push_back(input[i]);
			if(!generated)
			{
				results.push_back(newName);
				generated = true;
			}
			res = &res->children[pos];	
		}
	}
	if(!generated)
	{
		results.push_back(newName);
		generated = true;
	}
	res->fullWord = true;
}

int findEqual(std::string input)
{
	int s = equals.size();

	for(int i = 0; i < s; i++)
	{
		if(equals[i].first == input)
		{
			equals[i].second++;
			return equals[i].second;
		}
	}
	//The string is not present
	equals.push_back(std::pair<std::string, int>(input, 2));
	return 2;
}
int main()
{
	int n;
	std::string input;

	std::cin >> n;

	TrieNode* root = new TrieNode();
	root->children = new TrieNode[26];

	
	for(int i = 0; i < n; i++)
	{
		std::cin >> input;
		if(!find(root, input)) insert(root, input);
		else
		{
			std::string newName = input;
			newName += " "; 
			newName+= std::to_string(findEqual(input));
			results.push_back(newName);
		}
	}

	for(int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << std::endl;
	}
	
	return 0;
}