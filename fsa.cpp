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
			string lhs = a + b;
			string rhs = b + a;
			if (keep_object(str, lhs))
			{
				new_objects.insert(lhs);
			}
			if (keep_object(str, rhs))
			{
				new_objects.insert(rhs);
			}
			if (lhs == str || rhs == str)
			{
				solution = true;
				goto skip;
			};
		}
	}

skip:
	for (auto no : new_objects)
	{
		objects.insert(no);
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
		// cout << sol << " ";
		// print_set(objects);
	}
	cout << "Solution found!" << "\n";

	return -1;
}

int main()
{
	string a = "ABRACadabRA";
	string b = "aabb";
	string c = a + a + a + a + a;

	string input = c;
	auto t1 = chrono::high_resolution_clock::now();

	int out = naive_string_assembly(input);

	auto t2 = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Time: " << elapsed << "ms \n";

	return 0;
}