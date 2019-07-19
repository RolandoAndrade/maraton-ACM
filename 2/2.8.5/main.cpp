#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <utility>
#include <set>
#include <map>


using namespace std;
auto translate(int i)
{
	string n;
	string p;
	int k=i%13;
	switch(k)
	{
		case 0:
			n="Ace";
			break;
		case 10:
			n="Jack";
			break;
		case 11:
			n="Queen";
			break;
		case 12:
			n="King";
			break;
		default:
			n=to_string(k+1);
	}
	if(i>39)
	{
		p="Spades";
	}
	else if(i>26)
	{
		p="Hearts";
	}
	else if(i>13)
	{
		p="Diamonts";
	}
	else
	{
		p="Clubs";
	}
	return n+" of "+p;
}
auto getN(string s)
{
	stringstream ss;
	ss<<s;
	vector<int> r;
	int i;
	while(ss>>i)
		r.push_back(i);
	return r;
}
auto generateCards()
{
	vector<int> v;
	for(int i=1;i<53;i++)
		v.push_back(i);
	return v;
}


void manosDeCartas(int mz, auto m, auto *cards)
{
	vector<int> v ((m.begin()+52*(mz-1)),(m.begin()+52*(mz-1)+52)),w;

	for(int a:v)
	{
		w.push_back((*cards)[a-1]);
	}
	(*cards)=w;
}



int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%i\n",&n);
	vector<string>w;
	int m=0;
	string k;
	vector<int>cards=generateCards();
	while(n--)
	{
		scanf("%i\n",&m);
		getline(cin,k);
		while(m-->0)
		{
			int mz;
			scanf("%i",&mz);
			manosDeCartas(mz,getN(k),&cards);
		}
	}
	for(int i: cards)
	{
		cout<<translate(i)<<endl;
	}
	
	return 0;
}