/*
ID: farhans4
LANG: CPP
PROG: ride
*/

#include <bits/stdc++.h>

int carp(int *x)
{
    int p = 1;
    int i;

    while(1)
    {
        if(*x)
        {
            *x = *x % 64;
            p *= *x++;
        }
        else{
            break;
        }
    }
    return p;
}

int main()
{
    char a[100],b[100];
    FILE *in = fopen("ride.in","r"),*out = fopen("ride.out","w");

    fscanf(in,"%s\n%s\n",a,b);
    fclose(in);

    if(carp(a)%47 == carp(b)%47)
    {
        fprintf(out,"Go\n");
    }
    else{
        fprintf(out,"STAY\n");
    }
    fclose(out);
    exit(0);
}