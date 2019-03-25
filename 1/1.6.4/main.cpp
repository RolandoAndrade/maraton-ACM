#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> fillVetical(vector<vector<char>> v,int i, int j, int s)
{
	for(;i<=s;i++)
		v[i][j]='|';
	return v;
}

vector<vector<char>> fillHorizontal(vector<vector<char>> v,int i, int j, int s)
{
	for(;j<=s;j++)
		v[i][j]='-';
	return v;
}

vector<vector<char>> fill(vector<vector<char>> v,int a, int b,int s)
{
	int col=v[0].size()-b*(s+3)-s-3;
	if(a==2||a==3||a==4||a==7||a==8||a==9||a==0) v=fillVetical(v,1,col+s+2,s);
	if(a==6||a==3||a==4||a==7||a==8||a==9||a==0||a==5) v=fillVetical(v,s+2,col+s+2,v.size()-2);
	if(a==4||a==5||a==6||a==8||a==9||a==0) v=fillVetical(v,1,col,s);
	if(a==2||a==6||a==8||a==0) v=fillVetical(v,s+2,col,v.size()-2);

	if(a==2||a==3||a==5||a==7||a==8||a==9||a==0||a==6) v=fillHorizontal(v,0,col+1,col+s);
	if(a==2||a==3||a==5||a==4||a==8||a==9||a==0||a==6) v=fillHorizontal(v,s+1,col+1,col+s);
	if(a==2||a==3||a==5||a==8||a==9||a==0||a==6) v=fillHorizontal(v,2*s+2,col+1,col+s);

	if(a==1)
	{
		v = fillVetical(v,1,col+s/2+1,s);
		v = fillVetical(v,s+2,col+s/2+1,2*s+1);
	}
	return v;

}

vector<vector<char>> pantalla(int s, int n)
{
	int col=((int)log10(n)+1)*(s+3);
	int row=2*s+3;
	vector<char>ax(col,' ');
	vector<vector<char>> v(row,ax);
	int i=0;
	while(n>0)
	{
		int a=n%10;
		v=fill(v,a,i++,s);
		n/=10;
	}
	return v;
}

void print(vector<vector<char>> v)
{
	for(auto q:v)
	{
		for(auto r:q)
			cout<<r;
		cout<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int i,j;
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&i,&j)!=EOF&&i!=0)
	{
		print(pantalla(i,j));
		cout<<endl;
	}
	return 0;
}