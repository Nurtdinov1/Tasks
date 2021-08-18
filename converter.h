#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool convert(string str_in, string& english_word, vector<string>& str_out)
{
	bool success = true;
	str_out.clear();

	size_t cursor = str_in.find("\t");
	english_word = str_in.substr(0, cursor);
	string tmp = str_in.substr(cursor + 1);

	cursor = tmp.find_last_of("(");
	while (cursor != string::npos)
	{
		size_t end_cursor = tmp.find(")", cursor + 1);
		if (end_cursor == string::npos)
		{
			return false;
		}
		tmp.erase(cursor, end_cursor - cursor + 1);
		cursor = tmp.find_last_of("(");
	}
	if (tmp.length() == 0)
	{
		return false;
	}


	string russian_word;
	stringstream test(tmp);
	while (getline(test, russian_word, ','))
	{
		str_out.push_back(russian_word);
	}
	if (str_out.size() == 0)
	{
		return false;
	}

	return success;
}