#include<iostream>
using namespace std;

void printWord(int n, string arr[]){
    
    if(n==0){
        return;
    }

    //processing
    int digit=n%10;
    n=n/10;

    printWord(n,arr);

    cout<<arr[digit-1]<<" ";
}

int main(){
    string arr[10]={"one","two","three","four","five","six","seven","eight","nine"};
    
    printWord(8934,arr);

    return 0;
}