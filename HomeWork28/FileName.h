#pragma once
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


class FileName
{
private:
	string name;

public:
	FileName(const string& name_) : name(name_) {};

	// getters
	string getName() const;
	string getExtension() const;
	string getBaseName() const;
	bool isImage() const;

	// setters
	void changeExtension(const string& newExtension);

	void print() const;
};

inline string FileName::getName() const {
	return name;
}

inline string FileName::getExtension() const {
	size_t index = name.find('.');
	if (index == string::npos)
		return "";

	while (true) {
		size_t next = name.find('.', index + 1);
		if (next == string::npos)
			return name.substr(index + 1);
		else
			index = next;
	}
}

inline string FileName::getBaseName() const {
	size_t index = name.find('.');
	if (index == string::npos)
		return name;

	while (true) {
		size_t next = name.find('.', index + 1);
		if (next == string::npos)
			return name.substr(0, index);
		else
			index = next;
	}
}

inline void FileName::changeExtension(const string& newExtension) {
	name = getBaseName() + "." + newExtension;
}

inline bool FileName::isImage() const {
	string ext = getExtension();
	return ext == "png" || ext == "jpg" || ext == "gif"; 
}

inline void FileName::print() const {
	cout << name << " | ім'я: " << getBaseName() << " | розширення: [" << getExtension() << "]";
	if (isImage())
		cout << " | зображення" << endl;
	else
		cout << endl;
}
