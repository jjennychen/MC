#include "../include/translator.hpp"
#include "../../ascii_data/morse.hpp"
#include <string>
#include <map>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

void read(string filename, bool &invalid, vector<string> &sentence_list)
{
    ifstream file (filename);
    if (file.good())
    {
        invalid = false;
        string input;
        while (getline(file, input))
        {
            sentence_list.push_back(input); //use encode method here for each input
        }
    }
    else
    {
        invalid = true;
        cout << "Please enter a valid file name." << endl;
    }
}

void encode(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    string sentence;
    string filename;
    
    while (true)
    {
        //get a use input
        cout << "Please enter the file name to convert (press <ENTER> to exit or enter \"MAIN\" to go back to the main page): ";
        getline(cin, filename, '\n');
        
        if (filename == "")
        {
            main_page = false;
            cout << "Thank you! Bye!" << endl;
            break;
        }
        else if (filename == "MAIN")
        {
            break;
        }
        else
        {
            vector<string> sentence_list;

            //read file and see if it works
            bool invalid = false;
            read(filename, invalid, sentence_list);
            if (invalid == true) continue;

            //create a output file
            ofstream output ((filename + "_output").c_str(), ios::app);

            for (string sentence : sentence_list)
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
                            output << codeData[key] + " ";
                        }
                        else if (isspace(letter))
                        {
                            output << "/ ";
                        }
                    }
                    output << "\n";
                }
                else
                {
                    cout << "The file contains un-convertable characters. Please try again." << endl;
                }
            }
        }
    }
}

void decode(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    string sentence;
    string filename;

    while (true)
    {
        //get a user input
        cout << "Please enter the morse code(press <ENTER> to exit or enter \"MAIN\" to go back to the main page): ";
        getline(cin, filename, '\n');
        if (filename == "")
        {
            main_page = false;
            cout << "Thank you! Bye!" << endl;
            break;
        }
        else if (filename == "MAIN")
        {
            break;
        }
        else
        {
            vector<string> sentence_list;

            //read file and see if it works
            bool invalid = false;
            read(filename, invalid, sentence_list);
            if (invalid == true) continue;
            //create a output file
            ofstream output ((filename + "_output").c_str(), ios::app);

            for (string sentence : sentence_list)
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
                            output << " ";
                        }
                        else
                        {
                            for (auto codeMap : codeData)
                            {
                                if (codeMap.second == str)
                                {
                                    output << codeMap.first;
                                }
                            
                            }
                        }
                    }
                    output << endl;
                    }
                else
                {
                    cout << "Please enter a valid morse code. Than you." << endl;
                }
            }
        }
    }
}