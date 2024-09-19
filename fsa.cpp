#include <string>
#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

set<string> atomize_string(string str)
{
	set<string> s;
	for (int i = 0; i < str.length(); ++i)
	{
		string cs;
		cs.push_back(str[i]);
		s.insert(cs);
	}
	return s;
}

void preprocess_string(string &str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = tolower(str[i]);
	}
}

void print_set(set<string> s)
{
	for (const auto &_s : s)
	{
		cout << _s << " ";
	}
	cout << "\n";
}

void naive_assemble_objects(std::set<string> &objects)
{
	set<string> new_objects;
	for (const auto &a : objects)
	{
		for (const auto &b : objects)
		{
			new_objects.insert(a + b);
			new_objects.insert(b + a);
		}
	}
	for (const auto &no : new_objects)
	{
		objects.insert(no);
	}
}

/**
 * Returns
 * 	-1 on ERROR
 *  integer >= 0 representing the assembly index for the string
 */
int naive_string_assembly(string str)
{
	cout << "Naive String Assembly (slow)" << "\n";
	cout << "Input String: " << str << "\n";
	preprocess_string(str);
	cout << "Preprocessed: " << str << "\n";
	set<string> atoms = atomize_string(str);
	cout << "Atoms: ";
	print_set(atoms);

	//
	// NAIVE ALGO
	//

	// 1. history starts as just the atoms
	set<string> objects = atoms;
	// 2. Compute all object combinations to create new objects and add to the pool
	naive_assemble_objects(objects);
	cout << "objects: ";
	print_set(objects);

	return -1;
}

int main()
{
	string a = "ABRACadabRA";
	int out = naive_string_assembly(a);
	return 0;
}