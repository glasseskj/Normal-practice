#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
string countAndSay(int n) 
{
    if(n==1)
    {
        return "1";
    }
    char transfer[10]={'0','1','2','3','4','5','6','7','8','9'};
    string pre=countAndSay(n-1);
    string re="";
    char now_char=pre[0];
    int count=1;
    for(int i=1;i<pre.size();i++)
    {
        if(now_char==pre[i])
        {
            count++;
        }
        else
        {
            re=re+transfer[count]+now_char;
            count=1;
            now_char=pre[i];
        }
    }
    re=re+transfer[count]+now_char;
    return re;
}
int main()
{
    char c=34,d=44;
    ofstream in;
    in.open("com.txt",ios::trunc);
    string a=countAndSay(25);
    in<<c<<a<<c<<d<<endl<<endl;
    a=countAndSay(26);
    in<<c<<a<<c<<d<<endl<<endl;
    a=countAndSay(27);
    in<<c<<a<<c<<d<<endl<<endl;
    a=countAndSay(28);
    in<<c<<a<<c<<d<<endl<<endl;
    a=countAndSay(29);
    in<<c<<a<<c<<d<<endl<<endl;
    a=countAndSay(30);
    in<<c<<a<<c<<d<<endl<<endl;
    in.close();
    return 0;
}
