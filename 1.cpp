#include <iostream>
#include <cstdlib>
using namespace std;


void OneOrNull(int* arr, int i, int j, int Nlen, const int N1)
{
	asm(
		"movl     %[Nlen], %%eax \n\t"
		"mull     %[i]\n\t"
		"addl     %[j], %%eax \n\t"
		"movl     %[arr], %%ebx \n\t"
		
		"movl %[i], %%esi \n\t"
		"cmpl %[j], %%esi \n\t"
		"jne notequal \n\t"
		"je equ\n\t"
		
		"notequal: \n\t"
		"movl $0 ,(%%ebx,%%eax,4)  \n\t"
		"movl %[N1],%%edx \n\t"
		"addl %[j],%%esi \n\t"
		"cmp %%esi,%%edx \n\t"
		"je equ \n\t"
		"jmp end\n\t"
		
		"equ: \n\t"
		"movl $1,(%%ebx,%%eax,4) \n\t"
		"jmp end\n\t"
		

		"end:\n\t"
		:
		:[Nlen]"m"(Nlen), [i]"m"(i), [j]"m"(j), [arr]"m"(arr),[N1]"m"(N1)
		:"eax", "ebx","edx", "esi"
		);

}

int main()
{
    srand( time(0) );
    int N = 3+rand()%6;
    cout<<"N = "<<N<<endl;
    
    int x[N][N];
    const int N1 = N-1;
    cout<<"матрица до выполнения задания"<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        	x[i][j] = 1+rand()%10;
        	cout << x[i][j] << "\t";	
        }
        cout << "\n";
    }
    cout<<"матрица после выполнения задания"<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            OneOrNull((int*)x, i, j, N, N1);
            cout << x[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
