#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;


string input;
int start;
int current;
int count;


void out(const string & str)
{
	if (str != input)
	{
		if (current >= start)
		{
			cout << str << endl;
			count--;
		}

		if (count == 0)
		{
			exit(0);
		}

		current++;
	}
}

int main(int argc, char** argv)
{
	current = 0;
	start = atoi(argv[1]);
	count = atoi(argv[2]);
	cin >> input;

	cerr << "start=" << start << endl;
	cerr << "count=" << count << endl;
	cerr << "input=" << input << endl;

	string allLetters = "qwertyuiopasdfghjklzxcvbnm";
	string allNumbers = "1234567890";
	string allSymbols = "!@#$%^&*()_+-={}[]:\";'<>?,./~`|\\";

	string allChars = allLetters + allNumbers + allSymbols;
	for (int i = 0; i < allLetters.length(); ++i)
	{
		allChars += toupper(allLetters[i]);
	}


	cerr << "=> toupper/tolower" << endl;
	for (int i = 0; i < input.length(); ++i)
	{
		if (islower(input[i]))
		{
			string copy = input;
			copy[i] = toupper(copy[i]);
			out(copy);
		}

		if (isupper(input[i]))
		{
			string copy = input;
			copy[i] = tolower(copy[i]);
			out(copy);
		}
	}


	cerr << "=> replace one character" << endl;
	for (int i = 0; i < input.length(); ++i)
	{
		string copy = input;
		for (int j = 0; j < allChars.length(); ++j)
		{
			copy[i] = allChars[j];
			out(copy);
		}
	}

	cerr << "=> insert one character" << endl;
	for (int i = 0; i <= input.length(); ++i)
	{
		string copy = input;
		copy.insert(i, 1, 0);
		for (int j = 0; j < allChars.length(); ++j)
		{
			copy[i] = allChars[j];
			out(copy);
		}
	}

	cerr << "=> switch" << endl;
	for (int i = 0; i < input.length() - 1; ++i)
	{
		string copy = input;
		char t = copy[i];
		copy[i] = copy[i+1];
		copy[i+1] = t;
		out(copy);
	}

	cerr << "=> remove one" << endl;
	for (int i = 0; i < input.length(); ++i) {
		string copy = input;
		copy.erase(i, 1);
		out(copy);
	}
}

