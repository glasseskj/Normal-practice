#include<iostream>
using namespace std;
char list[3]={'1','2','3'};
//char list[4]={'1','2','3','4'};
int count;
void swap(char a,char b,char temp)
{
    temp=list[a];
    list[a]=list[b];
    list[b]=temp;
}
void perm(char *list,int i,int n)
{
    int j,temp;
    if(i==n)
    {
        for(j=0;j<=n;j++)
        {
            cout<<list[j];
        }
        cout<<endl;
        count++;
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            swap(i,j,temp);
            perm(list,i+1,n);
            swap(i,j,temp);
        }
    }
}
int main()
{
    count=0;
    perm(list,0,2);
    //perm(list,0,3);
    cout<<endl<<"count = "<<count<<endl; 
}
