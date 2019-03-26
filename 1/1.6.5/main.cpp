#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

auto caseI(int m,int n)
{
	vector<char>a(m-'0','0');
	vector<vector<char>> b(n-'0',a);
	return b;
}

auto caseC(auto v)
{
	for(auto &a:v)
		for(auto &b:a)
			b='0';
	return v;
}

auto caseL(int x,int y,char c, auto img)
{
	x-='1';
	y-='1';
	img[y][x]=c;
	return img;
}

auto caseV(int x,int y1,int y2,char c,auto img)
{
	x-='1';
	y1-='1';
	y2-='0';
	for(;y1<y2;y1++)
		img[y1][x]=c;
	return img;
}

auto caseH(int x1,int x2,int y,char c,auto img)
{
	x1-='1';
	x2-='0';
	y-='1';
	for(;x1<x2;x1++)
		img[y][x1]=c;
	return img;
}

auto caseK(int x1,int y1,int x2,int y2,char c,auto img)
{
	x1-='1';
	y1-='1';
	x2-='1';
	y2-='1';
	for(;x1<x2;x1++)
		for(int j=y1-'1';j<y2;j++)
			img[j][x1]=c;
	return img;
}

vector<vector<char>> caseF(int x,int y,char c,auto img)
{
	int cax=img[y][x];
	img[y][x]=c;
	if(x>0&&img[y][x-1]==cax)
		img = caseF(x-1,y,c,img);
	if(x<img[0].size()-1&&img[y][x+1]==cax)
		img = caseF(x+1,y,c,img);
	if(y>0&&img[y-1][x]==cax)
		img = caseF(x,y-1,c,img);
	if(y<img.size()-1&&img[y+1][x]==cax)
		img = caseF(x,y+1,c,img);
	return img;
}

auto caseS(auto s, auto v)
{
	cout<<s.substr(2)<<endl;
	for(auto a:v)
	{
		for(auto b:a)
			cout<<b;
		cout<<endl;
	}
	return v;
}
auto exec(auto a, auto img)
{
	switch(a[0])
	{
		case 'I': return caseI(a[2],a[4]);
		case 'C': return caseC(img);
		case 'L': return caseL(a[2],a[4],a[6],img);
		case 'V': return caseV(a[2],a[4],a[6],a[8],img);
		case 'H': return caseH(a[2],a[4],a[6],a[8],img);
		case 'K': return caseK(a[2],a[4],a[6],a[8],a[10],img);
		case 'F': return caseF(a[2]-'1',a[4]-'1',a[6],img);
		case 'S': return caseS(a,img);
	}
	return img;
}


void editor(auto v)
{
	vector<vector<char>> img;
	for(auto s:v)
	{
		img=exec(s,img);
	}
}

int main(int argc, char const *argv[])
{
	int i,j;
	freopen("input.txt","r",stdin);
	vector<string> v;
	string p;
	while(getline(cin,p)&&p!="X")
	{
		v.push_back(p);
	}
	editor(v);
	return 0;
}