#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>



using namespace std;

auto WERTYU(string s)
{
	string q = "QWERTYUIOPAASDFGHJKLZXCVBNM,";
	string r = "";
	for(auto c: s)
	{
		int p = q.find(c);
		if(p>0)
		{
			r+=q[p-1];
		}
		else
		{
			r+=" ";
		}
	}
	return r;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	string s;
	while(getline(cin,s))
	{
		cout<<WERTYU(s)<<endl;
	}
	return 0;
}