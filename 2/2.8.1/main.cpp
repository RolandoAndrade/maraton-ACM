#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>



using namespace std;


vector<int> getN(string s)
{
	vector<int> r;
	stringstream ss;
	int i;
	ss<<s;
	while(ss>>i)
	{
		r.push_back(i);
	}
	return r;
}
string secuencia(auto v)
{
	sort(begin(v),end(v));
	int a=v[0];
	for(int i=1;i<v.size();i++)
	{
		if(v[i]!=a&&v[i]!=a+1)
			return "Not jolly";
		a=v[i];
	}
	return "Jolly";
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	string s;
	while(getline(cin,s))
	{
		vector<int> v=getN(s);

		cout<<secuencia(v)<<endl;
	}
	return 0;
}