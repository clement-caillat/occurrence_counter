#include "counter.hpp"
#include <iostream>
#include <conio.h>


using namespace std;


int main()
{
    string file;
    cout << "Enter file name : ";
    cin >> file;

    Counter counter = Counter(file);

    counter.start();

    counter.digest();


    getch();

    return 0;
}