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


using namespace std;


vector<string> getN(string s)
{
	vector<string> r;
	stringstream ss;
	string i;
	ss<<s;
	while(ss>>i)
	{
		r.push_back(i);
	}
	return r;
}

int getPos(char a)
{
	string s="23456789TJQKA";
	return s.find(a);
}

int comp(string p,string q)
{
	char a=p[0],b=q[0];
	return getPos(a)>getPos(b);
}

int escalera(auto v)
{
	vector<int> n;
	for(auto s:v)
		n.push_back(getPos(s[0]));
	sort(begin(n),end(n));
	int t=n[0];
	for(int i=1;i<n.size();i++)
	{
		if(t+1!=n[i]) return 0;
		t=n[i];
	}
	return 1;
}

int palo(auto v)
{
	char last=v[0][1];
	for(auto s:v)
		if(s[1]!=last) return 0;
	return 1;
}

int escaleraColor(auto v)
{
	return escalera(v)&&palo(v);
}

int poquer(auto v)
{
	for(auto s:v)
	{
		int c=0;
		for(auto q:v) c+=q[0]==s[0];
		if(c==4) return 1;
	}
	return 0;
}

int full(auto v)
{
	//because is not poquer
	set<char>a;
	for(auto s:v)
		a.insert(s[0]);
	return a.size()==2;
}

int trio(auto v)
{
	for(auto s:v)
	{
		int c=0;
		for(auto q:v) c+=q[0]==s[0];
		if(c==3) return 1;
	}
	return 0;
}

int countPairs(auto v)
{
	//because is not trio
	set<char>a;
	for(auto s:v)
		a.insert(s[0]);
	return v.size()-a.size();
}

int getMax(auto v)
{
	int maxi=-1;
	for(auto s:v)
		maxi=max(maxi,getPos(s[0]));
	return maxi;
}

string manosPoquer(auto v)
{
	vector<string> w,b;
	b.insert(end(b),begin(v),begin(v)+5);
	w.insert(end(w),begin(v)+5,begin(v)+10);
	if(escaleraColor(w)&&!escaleraColor(b))
		return "White wins";
	if(escaleraColor(b)&&!escaleraColor(w))
		return "Black wins";
	if(poquer(w)&&!poquer(b))
		return "White wins";
	if(poquer(b)&&!poquer(w))
		return "Black wins";
	if(full(w)&&!full(b))
		return "White wins";
	if(full(b)&&!full(w))
		return "Black wins";
	if(palo(w)&&!palo(b))
		return "White wins";
	if(palo(b)&&!palo(w))
		return "Black wins";
	if(escalera(w)&&!escalera(b))
		return "White wins";
	if(escalera(b)&&!escalera(w))
		return "Black wins";
	if(trio(w)&&!trio(b))
		return "White wins";
	if(trio(b)&&!trio(w))
		return "Black wins";
	if(countPairs(w)>countPairs(b))
		return "White wins";
	if(countPairs(w)<countPairs(b))
		return "Black wins";
	if(getMax(w)>getMax(b))
		return "White wins";
	if(getMax(w)<getMax(b))
		return "Black wins";
	return "Tie";
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);

	string s;
	while(getline(cin,s))
	{
		vector<string> v=getN(s);
		cout<<manosPoquer(v)<<endl;
	}
	return 0;
}