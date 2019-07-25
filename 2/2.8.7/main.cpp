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

auto puntuacion(auto w)
{

	vector<vector<vector<int>>> ans(100, vector<vector<int>>(9, vector<int>(2)));
	for(auto a: w)
	{
		int conc = stoi(a[0]);
		int prob = stoi(a[1]);
		int time = stoi(a[2]);
		int q = a[3][0];
		if(q=='I')
			time = 20;
		if(q=='C'||q=='I')
		{
			ans[conc-1][prob-1][0]+=time;
			ans[conc-1][prob-1][1]=q;
		}
	}
	vector<vector<int>> sol;
	int i = 1;
	for(auto a: ans)
	{
		int solutions = 0;
		int time = 0;
		for(auto b:a)
		{
			if(b[1]=='C')
			{
				solutions++;
				time+=b[0];
			}
		}
		if(solutions>0)
		{
			int inserted = 0; 
			for (int i = 0; i < sol.size() && !inserted; ++i)
			{
				if(solutions>sol[i][1]||(solutions==sol[i][1]&&time<sol[i][2]))
				{
					sol.insert(sol.begin()+i,vector<int>{i,solutions,time});
					inserted = 1;
				}
			}
			if(!inserted)
			{
				sol.push_back(vector<int>{i,solutions,time});
			}
		}
		i++;
	}
	return sol;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int n,k;
	scanf("%i\n",&n);
	while(n--)
	{

		int a, b, c;
		char d;
		string line;
		getline(cin, line);
		vector<string> v = getN(line);
		vector<vector<string>> w;
		while(v.size()>0)
		{
			w.push_back(v);
			getline(cin, line);
			v = getN(line);
		}
		vector<vector<int>> r = puntuacion(w);
		for(auto rr: r)
		{
			cout<<rr[0]<<" "<<rr[1]<<" "<<rr[2]<<endl;
		}
	}
	return 0;
}