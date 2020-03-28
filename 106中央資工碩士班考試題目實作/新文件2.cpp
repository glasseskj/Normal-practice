#include<iostream>
using namespace std;
int A[6]={0,1,2,3,4,5};
int min(int i,int j)
{
    int n;
    int m=(i+j)/2;
    if(i==j)
    {
        return A[i];    
    }    
    else
    {
        if(min(i,m)<min(m+1,j)) n=min(i,m);
        else n=min(m+1,j);
        cout<<i<<" "<<j<<" "<<n<<endl;
        return n;
    }
} 
int main()
{
    int L;
    L=min(0,5);
}
