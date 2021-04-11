#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <fstream>
#include <iterator>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

vector<string> trigrams(string w) {
    vector<string> grams;

    for (int i = 0; i < w.length() - 2; i++)
    {
        grams.push_back(w.substr(i, 3));
    }

    return grams;
}


int main()
{
    printf("I'm the parent.\n");
    printf("My PID is %d\n", getpid());
    vector<string> str2g;
    string text = "the big clock on the tower of the palace of westminster in london is";
    int N = text.length();

    str2g = trigrams(text);

    for (auto& itr : str2g)
    {
        cout << itr << endl;
    }

    ofstream output_file("outline.txt");
    ostream_iterator<string> output_iterator(output_file);
    copy(str2g.begin(), str2g.end(), output_iterator);
    output_file.close();
    
    int pid;
    int status, died;
    pid=fork();
    switch(pid) 
    {
    	case -1: 
    		printf("can't fork\n");
 		exit(-1);
 	case 0 :
 		printf(" I'm the child of PID %d\n", getppid());
 		printf(" My PID is %d\n", getpid());
 		execlp("./second", "./second", NULL, NULL);
 		exit(0);
 	default: 
 		sleep(5);
 		if (pid & 1)
 			kill(pid,SIGKILL);
 		died= wait(&status);
 		printf("kill\n");
    }
    return 0;
}
