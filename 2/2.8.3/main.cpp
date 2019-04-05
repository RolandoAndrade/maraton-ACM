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

int hartals(int days, auto h)
{
	vector<int> v(days,0);
	for(auto a:h)
	{
		for(int i=1;i<=v.size();i++)
		{
			if(i%7!=0&&i%7!=6)
				if(!(i%a))
					v[i-1]=1;
		}
	}
	return count(v.begin(),v.end(),1);
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int i;
	scanf("%i",&i);
	while(i--)
	{
		int n,j;
		scanf("%i",&n);
		scanf("%i",&j);
		vector<int>h;
		while(j--)
		{
			int k;
			scanf("%i",&k);
			h.push_back(k);
		}
		cout<<hartals(n,h)<<endl;
	}
	return 0;
}