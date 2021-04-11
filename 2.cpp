#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
    ifstream fin("outline.txt");
    string str;
    float procent=0;
    int full_str=0;
    getline(fin, str);
    map<string, float> words;
    for (int i = 0; i < str.size() - 2; i+=3)
    {
        words[str.substr(i, 3)]++;
        full_str++;
    }
    cout << "total trigrams :" << full_str << endl;
    cout << "unique trigrams :" << words.size() << endl;
    cout << "Result :" << endl;
    for (auto& iter : words)
    {
        cout <<"trigram: " << iter.first << "\tcount: (" << iter.second << ")\tfrequency: ("<< (100*iter.second)/ full_str <<")%\n";
        procent += ((100 * iter.second) / full_str);
    }

    cout << "\nTotal percent: " << procent<<endl;

	return 0;

}
