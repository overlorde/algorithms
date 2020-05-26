#include <bits/stdc++.h>
using namespace std;
int ar[9];

int ternary_search(int l,int r,int x)
{
    if(r>=l){

    int mid1 = l+(r-1)/3;
    int mid2 = r-(r-1)/3;
    
    if(ar[mid1] == x)
    {
        return mid1;
    }
    if(ar[mid2] == x)
    {
        return mid2;
    }
    if(x<ar[mid1])
    {
        return ternary_search(l,mid1-1,x);
    }
    else if(x>ar[mid2])
    {
        return ternary_search(mid2+1,r,x);
    }
    else 
        return ternary_search(mid1+1,mid2-1,x);
    }
    return -1;
}

int main()
{
  for(int i=0;i<9;i++)
  {
      cin>>ar[i];
  }

    int f = ternary_search(0,8,12);

    cout<<f<<endl;
    

}