#include <string>
#include <iostream>
#include <set>
#include <chrono>
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

bool keep_object(string &str, string &object)
{
	bool smaller = object.length() <= str.length();
	bool substr = str.find(object) != string::npos;
	return smaller && substr;
}

// Returns if a solution was found or not during this assembly iteration
bool naive_assemble_objects(string &str, set<string> &objects)
{
	set<string> new_objects;
	bool solution = false;
	for (auto a : objects)
	{
		for (auto b : objects)
		{
			new_objects.insert(a + b);
			new_objects.insert(b + a);
		}
	}
	for (auto no : new_objects)
	{
		if (keep_object(str, no))
		{
			objects.insert(no);
			if (no == str)
			{
				solution = true;
				break;
			};
		}
	}

	return solution;
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
	int sol = naive_assemble_objects(str, objects);
	// cout << sol << " ";
	// print_set(objects);
	while (sol != true)
	{
		sol = naive_assemble_objects(str, objects);
		cout << sol << " ";
		print_set(objects);
	}
	cout << "Solution found!" << "\n";

	return -1;
}

int main()
{
	string a = "ABRACadabRA";
	string b = "aabb";

	auto t1 = chrono::high_resolution_clock::now();

	int out = naive_string_assembly(a);

	auto t2 = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Time: " << elapsed << "ms \n";

	return 0;
}