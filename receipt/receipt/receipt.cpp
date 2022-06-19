// Receipt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<cstdlib>
using namespace std;
int main()
{
    char title[20] = "LunchBox";
    srand((unsigned)time(NULL));
    int random = rand();


    ofstream fout("receipt.txt"); // txt file create
    cout << "\n\t";

    for (int i = 0; i < 45; i++)
    {
        cout << "_";
    }

    cout << endl;
    cout << "\n\t\t\t card/cash\n";
    cout << "\t\t   _____________________\n";
    cout << "\n\t\t     TITLE..." << title << "\n";

    cout << "\n\n\t\t  Order NO..........." << random << "\n\n";

    cout << "\n\t  Date and Time........" << __DATE__ << " " << __TIME__ "\n";


    cout << "\n\n\t\t>>Thank You For Visiting<<\n";

    cout << "\t______________________________________________";




    cout << "\n\t\t\t " << "\n";




    return 0;
}


