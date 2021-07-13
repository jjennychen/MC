#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

void read(string filename, bool &invalid, vector<string> &sentence_list);
void encode(bool &main_page);
void decode(bool &main_page);