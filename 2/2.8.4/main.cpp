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
map<char,char> dic(auto t)
{
	map<char,char> m;
	for(auto q:t)
	for(auto s:q)
	{
		if(s!=' ')
			m[s]='*';
	}
	return m;
}
map<char,char> copyDic(auto t,auto d)
{
	map<char,char> m;
		for(auto s:t)
		{
			if(s!=' ')
				m[s]=d[s];
		}
	return m;
}
string copyS(auto s)
{
	string x="";
	for(auto c:s)
		x+=c;
	return x;
}

auto build(auto t)
{
	string x;
	for(auto s:t)
		x+=s+" ";
	return x;
}

auto bad(auto s)
{
	for(auto &c:s)
		if(c!=' ')
			c='*';
	return s;
}

auto repl(auto *s,auto ss,char x, char y,auto *m)
{
	int r=0;
	map<char,char> mm=copyDic(ss,*m);
	string sss=copyS(*s);
	
	for(int i=0;i<ss.size();i++)
		if(ss[i]==x){
			if(mm[x]=='*'||mm[x]==y)
				sss[i]=y,r++,mm[x]=y;
			else if(mm[x]!='*'&&mm[x]!=y){
				cout<<&sss<<" "<<s<<endl;
				return -1;
			}
		}
	*m=copyDic(ss,mm);
	*s=copyS(sss);
	return r;
}
auto rLen(auto *s,auto ss,auto w,auto t,auto *m)
{
	int r=0;
	for(int i=0;i<w.size();i++)
	{
		int l=w[i].size(),q=0;
		for(int j=0;j<w.size()&&!q;j++)
			q=w[j].size()==l&&i!=j;
		if(!q)
		{
			set<string> a;
			string rrrr;
			for(auto ssss:t)
			{
				if(ssss.size()==l)
				{
					a.insert(ssss);
					rrrr=ssss;
				}
			}

			if(a.size()!=1)
				return -1;
			int r=0;
			for(int j=0;j<w[i].size();j++)
			{
				int tttt=repl(s,ss,rrrr[j],w[i][j],m);
				if(tttt==-1)
					return -1;
				r+=tttt;
			}

			
		}

	}
	return r;
	
}

auto rSame(auto *s,auto ss,auto w,auto t,auto *m)
{
	int r=0;
	for(auto f:w)
		for(auto g:t)
		{
			if(f.size()==g.size())
			{
				set<char>a,b;
				for(auto h:f)
					a.insert(h);
				for(auto h:g)
					b.insert(h);
				if(a.size()==b.size())
				{
					int x=0;
					for(int h=0;h<f.size();h++)
					{
						int t=repl(s,ss,g[h],f[h],m);
						if(t==-1)
						{
							x=0;
							break;
						}
						x+=t;
					}
					r+=x;
				}
			}
		}
	return r;
}
auto superdescifrador(auto w, auto t)
{
	string a,b=build(t);
	int r=0;
	a=b;
	auto map=dic(t);
	//r+=repl(&a,b,'x','a');
	int tt=rLen(&a,b,w,t,&map);
	if(tt==-1)
		return bad(a);
	r+=tt;
	tt=rSame(&a,b,w,t,&map);
	if(tt==-1)
		return bad(a);
	r+=tt;
	/*if(r!=a.size()-t.size())
		return bad(a);*/
	return a;
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