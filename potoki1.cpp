#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <fstream>
#include <windows.h> 
#include <conio.h> 
#include <thread>
#include <string>
#include <mutex>

using namespace std;
const int n = 8;
int counter = 0;
//HANDLE hSemaphore;//семафор
//HANDLE ghMutex; //мьютекс
CRITICAL_SECTION cs; //Критические секции
int cot;

DWORD WINAPI ThreadFunc(PVOID t)
{
    //WaitForSingleObject(hSemaphore, INFINITE);//семафор
    //WaitForSingleObject(ghMutex, INFINITE); //мьютекс
    EnterCriticalSection(&cs); //Критические секци

    cout << counter << endl;
    system((std::string("D:\\test\\Potoki2\\Debug\\Potoki2.exe ") + std::to_string(counter)).c_str());
    counter++;

    //ReleaseSemaphore(hSemaphore, 1, NULL);//семафор
    //ReleaseMutex(ghMutex);//мьютекс
    LeaveCriticalSection(&cs); //Критические секции

    return NULL;
}

vector<string> generate_ngrams(string w) {
    vector<string> ngrams;


    for (int i = 0; i < w.length() - 2; i++)
    {
        ngrams.push_back(w.substr(i, 3));
        cot++;
    }

    return ngrams;
}

int main()
{
    vector<string> str2Ng;
    vector<string> fragments;
    string text = "the big clock on the tower of the palace of westminster in london is the capital";
    string textFrag;
    char output_file[60];

    for (int i = 0; i < text.length(); i += 10)
    {
        fragments.push_back(text.substr(i, 10));
    }
    for (int i = 0; i < fragments.size(); i++) {
        for (int j = 0; j < 10; j++) {
            if (fragments[i][j] == ' ') {
                fragments[i][j] = '_';
            }
        }
    }
    for (int i = 0; i < fragments.size(); i++)
    {
        cout << "Fragment " << i << " = " << fragments[i] << endl;
        textFrag = fragments[i];
        str2Ng = generate_ngrams(textFrag);
        for (auto& itr : str2Ng)
        {
            cout << "Trigram = " << itr << endl;
        }

        sprintf(output_file, "%d.txt", i);
        ofstream output;
        output.open(output_file);
        ostream_iterator<string> output_iterator(output);
        copy(str2Ng.begin(), str2Ng.end(), output_iterator);
        output.close();
    }
    //hSemaphore = CreateSemaphore(NULL, 1, n, NULL); //семафор
    //ghMutex = CreateMutex(NULL, FALSE, NULL); //мьютекс
    InitializeCriticalSection(&cs); //Критические секции
    int Np = fragments.size();
    DWORD dwThreadID[n], dw;
    HANDLE hThread[n];

    for (int i = 0; i < n; i++) {
        hThread[i] = CreateThread(NULL, NULL, ThreadFunc, (PVOID)&i, NULL, &dwThreadID[i]);
    }
    dw = WaitForMultipleObjects(n, hThread, TRUE, INFINITE);

    ifstream to2map("D:\\test\\Potoki1\\frequency.txt");
    map<string, float> words;
    string keyMap;
    float valueMap;
    float tupak = 0;
    while (to2map >> keyMap >> valueMap)
    {
        words[keyMap] += valueMap;
    }
    to2map.close();

    cout << "\nOUTPUT: " << endl;
    for (auto& iter : words)
    {
        cout << "trigram: " << iter.first << "\tcount: (" << iter.second << ")" << "\tfrequency: (" << (100 * iter.second) / cot << ")%\n";
        tupak += (100 * iter.second) / cot;
    }
    cout << "total procent: " << tupak;
    ofstream Zeroq("D:\\test\\Potoki1\\frequency.txt");
    Zeroq << "";
    Zeroq.close();

    ofstream outputMap;
    outputMap.open("D:\\test\\Potoki1\\answer.txt");
    map<string, float>::iterator b = words.begin(), e = words.end();
    for (; b != e; b++)
    {
        outputMap << "trigram: " << b->first << "\tcount: (" << b->second << ")" << "\tfrequency: (" << (100 * b->second) / cot << ")%\n";
    }
    outputMap.close();

    return 0;
}
