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

void preprocess_string(string *str_ptr)
{
	for (int i = 0; i < (*str_ptr).length(); ++i)
	{
		(*str_ptr)[i] = tolower((*str_ptr)[i]);
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

/**
 * Returns
 * 	-1 on ERROR
 *  integer >= 0 representing the assembly index for the string
 */
int naive_string_assembly(string str)
{
	cout << "Naive String Assembly (slow)" << "\n";
	cout << "Input String: " << str << "\n";
	preprocess_string(&str);
	cout << "Preprocessed: " << str << "\n";
	set<string> atoms = atomize_string(str);
	cout << "Atoms: ";
	print_set(atoms);

	return -1;
}

int main()
{
	string a = "ABRACADABRA";
	int out = naive_string_assembly(a);
	return 0;
}