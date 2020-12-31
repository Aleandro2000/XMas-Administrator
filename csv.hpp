#ifndef CSV_FILE
#define CSV_FILE

#include <bits/stdc++.h>

using namespace std;

class csvInput
{
    vector<vector<string>> array;
    vector<string> v;
	unsigned long long lines=0;
public:
    ~csvInput();
    void data_csv_read(string);
    void show(string);
    vector<vector<string>> getArray();
    void clearArray();
};

csvInput::~csvInput()
{}

void csvInput::data_csv_read(string file)
{
    ifstream in(file);
    string line, field;

	this->lines=0;

    while (getline(in, line))
    {
        this->v.clear();
        stringstream ss(line);
		++this->lines;
        while (getline(ss, field, ','))
            this->v.push_back(field);
        this->array.push_back(this->v);
    }
	in.close();
}

void csvInput::show(string file)
{
    ifstream in(file);
    string line;

    while (getline(in, line))
        cout<<line<<'\n';

	in.close();
}

vector<vector<string>> csvInput::getArray()
{
    return this->array;
}

void csvInput::clearArray()
{
    this->array.clear();
}

#endif