#include <string>
#include <iostream>

int main()
{
	std::string a = "nice!";
	std::string b = "one";
	std::vector<std::string> v;

	v.push_back(a);
	v.push_back(b);

	for (int i = 0; i < v.size(); ++i)
	{
		printf("%s\n", v[i].c_str());
	}

	return 0;
}