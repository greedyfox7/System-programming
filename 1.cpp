#include <iostream>
using namespace std;
int main()
{
    int a=5, sum=0, num=0;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++){
        if(arr[i] > a)
            sum += arr[i];
        else if (arr[i] <a)
            num +=1;
    }
    cout<<sum<<endl<<num<<endl;
    return 0;
}
