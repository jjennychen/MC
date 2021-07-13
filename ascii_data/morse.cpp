#include "morse.hpp"
#include <map>
#include <string>

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