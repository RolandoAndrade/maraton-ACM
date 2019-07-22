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
	vector<int> r;
	int i;
	while(ss>>i)
		r.push_back(i);
	return r;
}

auto clean(auto s)
{
	vector<string> q;
	int com = 0;
	int i = 0;
	string ax = "";
	while(i<s.size())
	{
		if(s[i]==',')
			com++;
		if(com==2)
		{
			q.push_back(ax);
			ax="";
			com=0;
			i+=2;
			continue;
		}
		if(s[i]==':')
		{
			q.push_back(ax);
			break;
		}
		ax+=s[i];
		i++;
	}
	return q;
}

int minErdosNumber(auto authors, auto team)
{
	int min = -1;
	for(auto author: team)
	{
		if(min==-1||(authors[author]<min&&authors[author]!=-1))
		{
			min = authors[author];
		}
	}
	return min;
}

auto update(auto authors, auto teams)
{
	int changes = 1;
	while(changes)
	{
		changes = 0;
		for(auto team: teams)
		{
			int min = minErdosNumber(authors,team);
			if(min != -1)
			{
				min++;
				for(auto author: team)
				{
					if(authors[author]!=0&&(authors[author]==-1||authors[author]>min))
					{
						changes = 1;
						authors[author]=min;
					}
				}
			}
		}
	}
	return authors;
}

auto numeroDeErdos(auto v)
{
	map<string,int> authors;
	vector<vector<string>> teams;
	for(auto line:v)
	{
		vector<string> ax = clean(line);
		teams.push_back(ax);
		for(auto author: ax)
		{
			if(author!="Erdos, P.")
				authors[author] = -1;
			else
				authors[author] = 0;
		}
	}
	return update(authors,teams);
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int q=1;
	int n;
	scanf("%i\n",&n);
	while(n--)
	{
		int books, writers;
		scanf("%i %i\n",&books,&writers);
		vector<string> v;
		while(books--)
		{
			string s;
			getline(cin, s);
			v.push_back(s);
		}
		map<string,int> authors = numeroDeErdos(v);
		cout<<"Scenario "<<q++<<endl;
		while(writers--)
		{
			string s;
			getline(cin, s);
			cout<<s<<" "<<(authors[s]!=-1?to_string(authors[s]):"infinity")<<endl;
		}
	}
	return 0;
}