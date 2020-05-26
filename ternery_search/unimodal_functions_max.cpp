/*
Use of ternary search:

This concept is used in unimodal functions to determine the maximum or minimum value of that function. Unimodal functions are functions that, have a single highest value.

Let us consider a function
in the interval , and you are required to determine the for which is maximized. The function is unimodal in nature, i.e. it strictly increases in the interval and strictly decreases in the interval

.

This can be done by various other methods like double differentiation or by using a modified binary search. In the case when the function cannot be differentiated easily, ternary search is useful. It is less prone to errors and easy to implement when:

    Dealing with floating point integers
    Required maximum value is reached at the end of the interval.
*/
//complexity : O(log3N)

#include <bits/stdc++.h>
using namespace std;

double func(double x)
{
    return -1*1*x*x + 2*x +3;
}

double ts(double start,double end)
{
    double l = start,r = end;

    for(int i=0;i<200;i++)
    {
        double l1 = (l*2+r)/3;
        double l2 = (l+2*r)/3;

        if(func(l1) > func(l2)) //func(l1)<func(l2)
        {
            r = l2;
        }
        else{
            l = l1;
        }
    }

    double x=l;
    //min double x=l;
    return func(x);
}

int main()
{
    double start,endo;

    cin>>start>>endo;

    double f = ts(start,endo);

    cout<<f<<endl;

}






