#include <string>
#include <iostream>
#include <set>
#include <chrono>
#include <stdio.h>
#include <math.h>

#define LOG_ASM_TIME
#define LOG_ASM_OBJS

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
			string merged = a + b;
			if (keep_object(str, merged))
			{
				new_objects.insert(merged);
			}
			if (merged == str)
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

void log_obj(set<string> &objects, int t)
{
#ifdef LOG_ASM_TIME
	printf("%zu Objects at t=%d\n", objects.size(), t);
#endif
#ifdef LOG_ASM_OBJS
	print_set(objects);
	cout << "\n";
#endif
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
	int t = 0;
	log_obj(objects, t);
	int sol = naive_assemble_objects(str, objects);
	log_obj(objects, ++t);
	while (sol != true)
	{
		sol = naive_assemble_objects(str, objects);
		log_obj(objects, ++t);
	}
	cout << "Solution found!" << "\n";

	return -1;
}

int time_pred(string str)
{
	return ceil(log2(str.length()));
}

int main()
{
	string a = "ABRACadabRA";
	string b = "aabb";
	string c = a + a;
	string d = "aabbabdc";
	string e = "3051725927184861";
	string f = "abcdefghijklmnop";
	string input = f;

	auto t1 = chrono::high_resolution_clock::now();

	int out = naive_string_assembly(input);

	auto t2 = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Time: " << elapsed << "ms \n";
	cout << "Pred Time steps: " << time_pred(input) << "\n";

	return 0;
}