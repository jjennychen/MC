#include <string>
#include <map>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void ascii(map<string, string> &codeData)
{
    //store the data in a map
    codeData["a"] = ".-";
    codeData["b"] = "-...";
    codeData["c"] = "-.-.";
    codeData["d"] = "-..";
    codeData["e"] = ".";
    codeData["f"] = "..-.";
    codeData["g"] = "--.";
    codeData["h"] = "....";
    codeData["i"] = "..";
    codeData["j"] = ".---";
    codeData["k"] = "-.-";
    codeData["l"] = ".-..";
    codeData["m"] = "--";
    codeData["n"] = "-.";
    codeData["o"] = "---";
    codeData["p"] = ".--.";
    codeData["q"] = "--.-";
    codeData["r"] = ".-.";
    codeData["s"] = "...";
    codeData["t"] = "-";
    codeData["u"] = "..-";
    codeData["v"] = "...-";
    codeData["w"] = ".--";
    codeData["x"] = "-..-";
    codeData["y"] = "-.--";
    codeData["z"] = "--..";
    codeData["1"] = ".----";
    codeData["2"] = "..---";
    codeData["3"] = "...--";
    codeData["4"] = "....-";
    codeData["5"] = ".....";
    codeData["6"] = "-....";
    codeData["7"] = "--...";
    codeData["8"] = "---..";
    codeData["9"] = "----.";
    codeData["0"] = "-----";
}

void encode(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    string sentence;
    while (true)
    {
        //get a use input
        cout << "Please enter the message to encrypt(press <ENTER> to exit): ";
        cin.ignore();
        getline(cin, sentence);
        if (sentence == "")
        {
            cout << "Thank you! Bye!" << endl;
            main_page = false;
            break;
        }
        else if (sentence == "MAIN")
        {
            main_page = true;
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

void decoder(bool &main_page)
{
    map<string, string> codeData;
    ascii(codeData);
    string sentence;
    while (true)
    {
        //get a user input
        cout << "Please enter the morse code(press <ENTER> to exit or enter \"MAIN\" to go back to the main page): ";
        cin.ignore();
        getline(cin, sentence);
        if (sentence == "")
        {
            cout << "Thank you! Bye!";
            main_page = false;
            break;
        }
        else if (sentence == "MAIN")
        {
            main_page = true;
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

int main()
{
    bool main_page = true;

    do
    {
        //ask the user they want to encode or decode
        cout << "Welcome to the main page!" << endl;
        int answer;
        cout << "Enter \"1\" to convert ASCII into Morse Code / or \"2\" to convert Morse Code into ASCII: ";
        cin >> answer;
        if (answer == 1)
        {
            encode(main_page);
        }
        else if (answer == 2)
        {   
            decoder(main_page);
        }
    } while (main_page == true);
}