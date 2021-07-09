#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  //store the data in a map
  map<string, string> codeData;
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

  //get a use input
  cout << "Please enter the morse code: ";
  string sentence;
  getline(cin, sentence);
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
    cout << "Please enter a message that contains only alphabets/numbers/spaces (no special characters). Thank you.";
  }
}