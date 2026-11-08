#pragma once
#include <string>

using namespace std;


class MessageTemplate
{
private:
	string text;

	static void replaceAll(string& text, const string& from, const string& to);

public:
	MessageTemplate(const string& text_) : text(text_){};

	//getters
	int countPlaceholders() const;

	//setters
	string fill(const string& name, int score) const;
};

