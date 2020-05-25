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
    root = 0;
    nnode =0;
    int i;
    for(i=0;i<26;i++)
    {
        //-1 means no edge for ('a'+i)th
        //character

        node[root][i]=-1;

    }
    
}

bool search(char p[])
{
    
    int len = strlen(p);
    int i;
    int nn =0;
    for(i=0;i<len;i++){
        cout<<"tumi kon chat er bal";
    if(node[nn][p[i]-'a']==-1)
    {
        return 0;
    }
    nn = node[nn][p[i]-'a'];
    }
    cout<<isWord[i]<<endl;
    return 1;
    

}

void insert()
{
    scanf("%s",S);
    int len = strlen(S);
    int now = root;

    for(int i=0;i<len;i++)
    {
        if(node[now][S[i]-'a'] == -1)
        {

            node[now][S[i]-'a']=++nnode;
            for(int j =0;j<26;j++)
            {
                node[nnode][j]=-1;
            }
        }
        now = node[now][S[i]-'a'];
    }
    //mark the word that ended at this node
    isWord[now]=1;
}

int main()
{
    //for(int i=0;i<5;i++){
    initialize();
    insert();
    initialize();
    insert();
    char g[10];
    cin>>g;
    int b=search(g);
    cout<<"b"<<b<<endl;
}


