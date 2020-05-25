#include <bits/stdc++.h>
using namespace std;



long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<long long> hash2(string const& s)
{
	long long int  p = 31;
	const int  m =1e9+9;
	vector<long long> hash_value,pref_sum;
	long long h = 0;

	for(int i=0;i<s.size();i++)
	{
		if(i==0)
		{
		    h = ((long long int)s[i])%m;
            hash_value.push_back(h);
            cout<<h<<" ";
		}
		else{
        long long j = binpow(p,i,m);

		h = ((long long int)(s[i]))*j;
		cout<<h<<" ";
		hash_value.push_back(h);
		}
	}
	cout<<endl;
	pref_sum.push_back(hash_value[0]);
	long long int x = hash_value[0];
	for(int i=1;i<s.size();i++)
	{
		x+=hash_value[i];
		pref_sum.push_back(x);
	}
	return pref_sum;
}

int main()
{
	string s;
	cin>>s;
	//will return the prefix sum of the array
	vector<long long> v;
	v = hash2(s);
	for(auto x : v)
    {
        cout<<x<<" ";
    }

}
