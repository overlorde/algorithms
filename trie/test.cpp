#include <bits/stdc++.h>
using namespace std;



#define MAX_NODE 100000
#define MAX_LEN 100

char S[MAX_LEN];
int node[MAX_NODE][26];
int root,nnode;
int isWord[MAX_NODE];

//call before inserting any words into trie

void initialize()
{
    isWord[MAX_NODE]={0};

    root = 0;
    nnode =0;
    int i;
    for(i=0;i<10;i++)
    {
        node[root][i]=-1;
    }
    
}



void insert()
{
    scanf("%s",S);
    int len = strlen(S);
    int now = root;

    for(int i=0;i<len;i++)
    {
        if(node[now][S[i]-'0'] == -1)
        {
            
            node[now][S[i]-'0']=++nnode;
            for(int j =0;j<10;j++)
            {
                node[nnode][j]=-1;
            }
        }
        now = node[now][S[i]-'0'];
    }
    //mark the word that ended at this node
    isWord[now]++;
   // printf("isWord[now] : %d\n",isWord[now]);
   // printf("now pos : %d\n",now);

}

bool search(char p[])
{
    int nn = 0;
    int now = root;
    int len = strlen(p);
    int i;
    for(i=0;i<len;i++)
    {
        printf("inside loop isWord[now]: %d\n",isWord[nn]);
        if(isWord[nn]==1)
        {
            return 0;
        }
      
        nn = node[nn][p[i]-'0'];    
    }
    printf("outside loop isWord[now]: %d\n",isWord[nn]);
    cout<<"nn val :"<<nn<<endl;
    if(isWord[nn]>1)
    {
        return 0;
    }
    return 1;
}

bool cmp(string s1,string s2)
{
    return s1.size()>s2.size();
}

int main()
{
    
   vector<string> v;
   for(int i=0;i<5;i++)
   {
       string b;
       cin>>b;
       v.push_back(b);
   }
    sort(v.begin(),v.end(),cmp);
    for(auto x: v)
    {
        cout<<x<<endl;
    }
    
    
}