#include <string>
#include <map>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <fstream>

//

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

void read(string filename, string &sentence, bool &invalid)
{
    ifstream file (filename);
    if (file.good())
    {
        invalid = false;
        string input;
        while (getline(file, input))
        {
            sentence += input; //use encode method here for each input
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
        // try
        // {
        //     if (std::ifstream file (filename))
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
        
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
            //read file and see if it works
            bool invalid = false;
            read(filename, sentence, invalid);
            if (invalid == true) continue;

            //create a output file
            ofstream output ((filename + "_output").c_str(), ios::app);

            //check if the string contains only alphabets/numbers/spaces(no special chars)
            bool b = true;
            char letter_check;
            for (int i = 0; i < sentence.length(); i++)
            {
                letter_check = sentence[i];
                if (!(isalpha(letter_check) || isdigit(letter_check) || isspace(letter_check) || letter_check == '\n'))
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
                    else if (letter == '\n')
                    {
                        output << "\n";
                    }
                }
            }
            else
            {
                cout << "The file contains un-convertable characters. Please try again." << endl;
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
                cout << "Please enter a valid morse code. Than you." << endl;
            }
        }
    }
}


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
            decoder(main_page);
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