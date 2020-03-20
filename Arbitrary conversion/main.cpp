//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char int_to_str[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int input_base,input_num;
    cout<<"What is the origin number?"<<endl;
    cin>>input_num;
    cout<<"What is the target base(2 means binary and so on)?"<<endl;
    cin>>input_base;
    string re="";
    while(input_num!=0)
    {
        int temp=input_num%input_base;
        re=int_to_str[temp]+re;
        input_num=input_num/input_base;
    }
    cout<<re<<endl;
    return 0;
}
