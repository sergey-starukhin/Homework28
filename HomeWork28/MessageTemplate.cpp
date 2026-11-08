#include "MessageTemplate.h"
#include <string>

using namespace std;

//static
void MessageTemplate::replaceAll(string& text, const string& from, const string& to) {
	size_t position = text.find(from);
	while (position != string::npos)
	{		
		text.replace(position, from.length(), to);
		position = text.find(from, position + to.length());
	}
}

string MessageTemplate::fill(const string& name, int score) const {
	string result = text;

	replaceAll(result, "{name}", name);
	replaceAll(result, "{score}", to_string(score));

	return result;
}

int MessageTemplate::countPlaceholders() const{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '{')
			count++;
	}
	return count;
}

