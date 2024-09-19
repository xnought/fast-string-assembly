#include <string>
#include <iostream>
#include <set>

#include <stdio.h>

std::set<char> atomize_string(std::string str)
{
	std::set<char> s;
	for (int i = 0; i < str.length(); ++i)
	{
		s.insert(str[i]);
	}
	return s;
}

void preprocess_string(std::string *str_ptr)
{
	for (int i = 0; i < (*str_ptr).length(); ++i)
	{
		(*str_ptr)[i] = std::tolower((*str_ptr)[i]);
	}
}

void print_set(std::set<char> s)
{
	for (const auto &_s : s)
	{
		std::cout << _s << " ";
	}
	std::cout << "\n";
}

/**
 * Returns
 * 	-1 on ERROR
 *  integer >= 0 representing the assembly index for the string
 */
int naive_string_assembly(std::string str)
{
	std::cout << "Naive String Assembly (slow)" << "\n";
	std::cout << "Input String: " << str << "\n";
	preprocess_string(&str);
	std::cout << "Preprocessed: " << str << "\n";
	std::set<char> atoms = atomize_string(str);
	std::cout << "Atoms: ";
	print_set(atoms);

	return -1;
}

int main()
{
	std::string a = "ABRACADABRA";
	int out = naive_string_assembly(a);
	return 0;
}