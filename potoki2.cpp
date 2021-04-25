#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <fstream>
#include <windows.h> 
#include <conio.h> 

using namespace std;

int main(int argc, char** argv)
{
    char output_file[50];
    string str;
    string text = "";
    float procent = 0;
    int full_str = 0;

    sprintf(output_file, "D:\\test\\Potoki1\\Potoki1\\%s.txt", argv[1]);
    ifstream fin;
    fin.open(output_file);
    getline(fin, str);
    text += str;

    map<string, float> words;
    for (int i = 0; i < text.size() - 2; i += 3)
    {
        words[text.substr(i, 3)]++;
        full_str++;
    }
    cout << "total trigrams :" << full_str << endl;
    cout << "unique trigrams :" << words.size() << endl;
    cout << "Result :" << endl;
    for (auto& iter : words)
    {
        cout << "trigram: " << iter.first << "\tcount: (" << iter.second << endl;;
    }


    ofstream outputMap;
    outputMap.open("D:\\test\\Potoki1\\frequency.txt", std::ios::app);
    map<string, float>::iterator b = words.begin(), e = words.end();
    for (; b != e; b++)
    {
        outputMap << b->first << " " << b->second << endl;
    }
    outputMap.close();

}
