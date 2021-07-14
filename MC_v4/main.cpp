#include "include/translator.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool main_page = true;
    while (main_page == true)
    {
        char answer;
        //ask the user they want to encode or decode
        cout << "Welcome to the main page!" << endl;
        cout << "Enter \"1\" to convert ASCII into Morse Code, \"2\" to convert Morse Code into ASCII, or \"3\" to exit: ";
        cin.get(answer);
        cin.ignore();
        if (answer == '1')
        {
            encode(main_page);
        }
        else if (answer == '2')
        {   
            decode(main_page);
        }
        else if (answer == '3')
        {
            cout << "Thank you! Bye!" << endl;
            main_page = false;
        }
        else
        {
            cout << "Please enter a valid number. " << endl;
        }
    }
}