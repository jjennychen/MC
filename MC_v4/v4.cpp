#include "functions.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool main_page = true;

    do
    {
        //ask the user they want to encode or decode
        cout << "Welcome to the main page!";
        int answer;
        cout << "Enter \"1\" to convert ASCII into Morse Code / or \"2\" to convert Morse Code into ASCII: ";
        cin >> answer;
        if (answer == 1)
        {
            bool continue_bool = true;
            do
            {
                encode();
            } while (continue_bool == true);
        }
        else if (answer == 2)
        {   
            bool continue_bool = true;
            do
            {
                decode();
            } while (continue_bool == true);
        }
    } while (main_page == true);
}