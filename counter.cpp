#include "counter.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

Counter::Counter(string f) : filename(f){}

void Counter::start(){
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Could not open file - " << filename << endl;
    }

    string line;

    while (!file.eof())
    {
        getline(file, line);
        if (!line.empty()) {
            words++;
            lines++;
        }
        sort(line);
    }


    file.close();
}


void Counter::sort(string l)
{
    for (char& c : l)
    {
        total_chars++;
        if (c == 0x20) {
            spaces++;
            words++;
        } else {
            char_count[c]++;
        }

    }
}


void Counter::digest()
{
    cout << "Words : " << words << endl;
    cout << "Spaces : " << spaces << endl;
    cout << "Lines : " << lines << endl;
    cout << "Chars : " << total_chars << endl;
    
    for (auto i = char_count.begin(); i != char_count.end(); i++)
    {
        cout << i->first << " : " << i->second << " times" << endl;
    } 
}