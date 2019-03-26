#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int move(int *i, int d)
{
	if(*i!=d)
	{
		*i=d;
		return 1;
	}
	return 0;
}

int regOp(int *i,int d, int s)
{
	int c=move(i,s);
	c+=move(i,d);
	return c;
}

int operate(int a, int b, int c,int *i, vector<int> *reg)
{
	int r=0;
	switch(a)
	{
		case 0:
			r+=move(i,c);
			if((*reg)[c])
				r+=move(i,b);
		case 1:
			return 1;
		case 2:
			r+=move(i,b);
			(*reg)[b]=c;
			return r+1;
		case 3:
			r+=move(i,b);
			(*reg)[b]=((*reg)[b]+c)%1000;
			return r+1;
		case 4:
			r+=move(i,b);
			(*reg)[b]=((*reg)[b]*c)%1000;
			return r+1;
		case 5:
			r+=regOp(i,b,c);
			(*reg)[b]=(*reg)[c];
			return r;
		case 6:
			r+=regOp(i,b,c);
			(*reg)[b]=((*reg)[b]+(*reg)[c])%1000;
			return r;		
	}
}

int interprete(auto v)
{
	int r=0;
	int i=0;
	vector<int> reg={0,0,0,0,0,0,0,0,0,0};
	for(auto s:v)
	{
		int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0';
		r+=operate(a,b,c,&i,&reg);
		if(a==1)
			break;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int i;
	freopen("input.txt","r",stdin);
	scanf("%d",&i);
	vector<string> v;
	string p;
	getline(cin,p);getline(cin,p);
	while(i--)
	{
		while(getline(cin,p)&&p.size()==3)
			v.push_back(p);
		cout<<interprete(v)<<endl;
	}
	
	return 0;
}