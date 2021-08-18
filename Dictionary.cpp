#include <iostream>
#include <fstream>
#include <regex>
#include "converter.h"

using namespace std;

string ltrim(const string& str) {
	return std::regex_replace(str, regex("^\\s+"), string(""));
}

string rtrim(const string& str) {
	return regex_replace(str, regex("\\s+$"), string(""));
}

string trim(const string& str) {
	return ltrim(rtrim(str));
}


int main()
{
	ofstream output_file;
	output_file.open("ru_en.txt");
	ofstream bad_words_file;
	bad_words_file.open("bad_words.txt");

	string input_file_name = "en_ru.txt";
	ifstream input_file(input_file_name);
	if (input_file.is_open())
	{
		string line;
		string english_word;
		vector<string> str_out;
		while (getline(input_file, line))
		{
			if (!convert(line, english_word, str_out))
			{
				bad_words_file << line << endl;
			}
			else
			{
				for (size_t i = 0; i < str_out.size(); i++)
				{
					
					line = trim(str_out[i]);
					if (line.find(" ") == string::npos)
					{
						output_file << line << "\t" << english_word << endl;
					}
					else
					{
						bad_words_file << english_word << "\t" << line << endl;
					}
				}
			}
		}
		bad_words_file.close();
		output_file.close();
		input_file.close();
	}
	else cout << "Unable to open input file";
}