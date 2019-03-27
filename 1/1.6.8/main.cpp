#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int getMax(auto v,auto *x)
{
	int maxi=0,mini=0;
	for(int i=1;i<v.size();i++)
	{
		if(v[maxi]<v[i])
			maxi=i;
		else if(v[mini]>v[i])
			mini=i;
	}
	if(v[maxi]>v.size()/2+1)
		return maxi;
	
	for(int i=0;i<(*x).size();i++)
		if((*x)[i][mini]==1)
			for(int j=0;j<(*x)[i][j];j++)
				(*x)[i][j]=(*x)[i][j]-1;
	return -1;
}

string votacion(auto n, auto v)
{
	string r="";
	while(1)
	{
		vector<int> q(n.size(),0);
		for(auto a:v)
			for(int i=0;i<a.size();i++)
				if(a[i]==1)
					q[i]++;
		/*for(auto a:v)
		{
			for(auto b:a)
				cout<<b<<" ";
			cout<<endl;
		}*/
		int maxi=getMax(q,&v);
		if(maxi!=-1){
			for(int i=0;i<q.size();i++)
				if(q[i]==q[maxi])
				{	
					if(r.size()>0)
						r+="\n";
					r+=n[i];
				}
			break;
		}

	}
	return r;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	string s;
	int i;
	getline(cin,s);
	i=stoi(s);
	getline(cin,s);
	while(i--)
	{
		getline(cin,s);
		int j=stoi(s);
		vector<string> n;
		while(j--)
		{
			getline(cin,s);
			n.push_back(s);
		}
		vector<vector<int>> v;
		while(getline(cin,s)&&s.size()>0)
		{
			vector<int> a;
			string d="";
			for(char c:s)
			{
				if(c==' ')
				{
					a.push_back(stoi(d));
					d="";
				}
				else
					d+=c;
			}
			a.push_back(stoi(d));
			v.push_back(a);
		}
		cout<<votacion(n,v)<<endl;
	}
	return 0;
}