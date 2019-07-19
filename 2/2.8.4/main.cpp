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

auto getN(string s)
{
	stringstream ss;
	ss<<s;
	vector<string> r;
	string i;
	while(ss>>i)
		r.push_back(i);
	return r;
}


int lenTotal(auto s)
{
	int q =0;
	for(auto c:s)
		q+=c.size();
	return q;
}

auto build(auto t)
{
	string q="";
	for(auto s:t)
	{
		q+=s+" ";
	}
	return q.substr(0, q.size()-1);
}

auto createDic()
{
	map<char,char> m;
	for(char i='a';i<='z';i++)
	{
		m[i]='*';
	}
	return m;
}

auto changeDic(auto *dic, auto a, auto w)
{
	map<char,char> m=*dic;
	for(int i=0;i<a.size();i++)
	{
		if(m[w[i]]=='*')
		{
			m[w[i]]=a[i];
		}
		else if(m[w[i]]!=a[i])
		{
			return 0;
		}
	}
	*dic=m;
	return 1;
}

int isFull(auto s, auto dic)
{
	int q=0;
	for(char c:s)
		if((dic[c])!='*')
			q++;
	return q==s.size();
}

auto getSol(auto s, auto dic)
{
	string r="";
	for(auto c:s)
		if(c!=' ')
			r+=dic[c];
		else
			r+=' ';
	return r;
}

int decipher(auto w, auto t,auto *dic)
{
	for(auto s:t)
	{
		if(!isFull(s,*dic))
		{
			for (int i = 0; i < w.size(); ++i)
			{
				if(w[i].size()==s.size()&&changeDic(dic,w[i],s))
				{
					vector<string> q = w;
					q.erase(q.begin()+i);
					if(decipher(q,t,dic))
						return 1;
				}
			}
		}
	}
	return 0;
}

auto superdescifrador(auto w, auto t)
{
	string a = build(t);
	map<char,char> dic=createDic();
	decipher(w,t,&dic);
	return getSol(a,dic);
}


int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%i",&n);
	vector<string>w;
	string k;
	getline(cin,k);
	while(n--)
	{
		getline(cin,k);
		w.push_back(k);
	}
	while(getline(cin,k))
	{
		string g=superdescifrador(w,getN(k));
		cout<<g<<endl;
	}
	return 0;
}