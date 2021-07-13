#include "../include/translator.hpp"
#include "../../ascii_data/morse.hpp"
#include <ctype.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void encode(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    
    while (true)
    {
        //get a use input
        string sentence;
        cout << "Please enter the message to encrypt(press <ENTER> to exit or enter \"MAIN\" to go back to the main page): ";
        getline(cin, sentence, '\n');
        if (sentence == "")
        {
            main_page = false;
            cout << "Thank you! Bye!" << endl;
            break;
        }
        else if (sentence == "MAIN")
        {
            break;
        }
        else
        {
            //check if the string contains only alphabets/numbers/spaces(no special chars)
            bool b = true;
            char letter_check;
            for (int i = 0; i < sentence.length(); i++)
            {
                letter_check = sentence[i];
                if (!(isalpha(letter_check) || isdigit(letter_check) || isspace(letter_check)))
                {
                    b = false;
                    break;
                }
            }

            //convert the message (if contains special characters -> print "Please enter...")
            if (b)
            {
                char letter;
                for (int i = 0; i < sentence.length(); i++)
                {
                    letter = sentence[i];
                    if (isalpha(letter) || isdigit(letter))
                    {
                        string key;
                        key = tolower(sentence[i]);
                        cout << codeData[key] + " ";
                    }
                    else if (isspace(letter))
                    {
                        cout << "/ ";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "Please enter a message that contains only alphabets/numbers/spaces (no special characters). Thank you.";
            }
        }
    }
}

void decode(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    while (true)
    {
        //get a user input
        string sentence;
        cout << "Please enter the morse code(press <ENTER> to exit or enter \"MAIN\" to go back to the main page): ";
        getline(cin, sentence, '\n');
        if (sentence == "")
        {
            main_page = false;
            cout << "Thank you! Bye!" << endl;
            break;
        }
        else if (sentence == "MAIN")
        {
            break;
        }
        else
        {
            stringstream input(sentence);

            //split the input and put the morse codes into a vector
            vector<string> code;
            string word;

            while (getline(input, word, ' '))
            {
                code.push_back(word);
            }


            //check if the string contains only alphabets/numbers/spaces(no special chars)
            bool b = true;
            char letter_check;
            for (int i = 0; i < sentence.length(); i++)
            {
                letter_check = sentence[i];
                if (!(letter_check == '-' || letter_check == '/'|| letter_check == '.' || isspace(letter_check)))
                {
                    b = false;
                    break;
                }
            }

            //convert the message (if contains special characters -> print "Please enter...")
            if (b)
            {
                for (string str : code)
                {
                    if (str == "/")
                    {
                        cout << " ";
                    }
                    else
                    {
                        for (auto codeMap : codeData)
                        {
                            if (codeMap.second == str)
                            {
                                cout << codeMap.first;
                            }
                        
                        }
                    }
                }
                cout << endl;
                }
            else
            {
                cout << "Please enter a valid morse code. Than you.";
            }
        }
    }
}