#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key, value;
	while(map_file >> key && getline(map_file, value))
		if(value.size() > 1)
			trans_map.insert({key, value.substr(1)});
		else
			throw runtime_error("No rule for " + key);
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.end())
		return map_it->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool first_word = true;
		while(stream >> word)
		{
			if(first_word)
				first_word = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	ifstream map_file("11_33_data_map.txt");
	ifstream in("11_33_data.txt");

	word_transform(map_file, in);

	return 0;
}