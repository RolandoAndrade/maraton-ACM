#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double elviaje(vector<double> v)
{
	float p=0,r=0;
	for(auto t:v)
	{
		cout<<t<<" ";
		p+=t;
	}
	p/=v.size();
	
	p=floor(p*100+0.5)/100;
	
	for(auto t:v)
	{
		if(t>p)
		{
			t=(double)((int)(t*100+.5))/100;
			r+=t-p;
		}
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int i;
	freopen("input.txt","r",stdin);
	while(scanf("%d",&i)!=EOF&&i!=0)
	{
		vector<double> v;
		while(i-->0)
		{
			double j;
			scanf("%lf",&j);
			v.push_back(j);
		}
		printf("$%.2lf\n",elviaje(v));

	}
	return 0;
}