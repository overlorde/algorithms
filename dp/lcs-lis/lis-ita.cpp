#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[MAX_N];

int lisit(vector<int> A)
{
    for(int i = A.size()-1;i>=0;i--)
    {
        int ans = 0;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[j]>A[i])
            {
                ans = max(ans,mem[j]);
            }
        }
        mem[i]=ans+1;
    }

    int final_ans = 0;
    for(int i=0;i<A.size();i++)
    {
        final_ans =  max(final_ans,mem[i]);//updating for every index
    }

    return final_ans;

}
int main()
{
    vector<int> A;

    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int x;cin>>x;A.push_back(x);
    }

    int ans = lisit(A);

    cout<<ans;
}