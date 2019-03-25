#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int res(int n)
{
	int c=1;
	while(n!=1)
	{
		if(n%2) n=3*n+1;
		else n/=2;
		c++;
	}
	return c;
}

int p3n1(int a, int b)
{
	int r=0;
	while(a<=b)
	{
		r=max(r,res(a++));
	}
	return r;
}

int main(int argc, char const *argv[])
{
	string s="Hola";
	char *a;
	int i,j;
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&i,&j)!=EOF)
	{
		cout<<i<<" "<<j<<" "<<p3n1(i,j)<<endl;
	}
	return 0;
}