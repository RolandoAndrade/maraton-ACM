#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>



using namespace std;

int search(auto m, int ii, int ij, int di, int dj, string word)
{
	int r = 0, i = ii, j =ij;

	for(; i<m.size() && -1 < i && j<m[i].size() && -1 < j && r < word.size(); i+=di, j+=dj, r++)
	{
		if(toupper(m[i][j])!=toupper(word[r]))
			return 0;
	}
	return r==word.size();
}


auto waldorf(auto m, string word)
{
	for(int i = 0; i<m.size();i++)
	{
		for(int j = 0; j < m[i].size(); j++)
		{
			if(search(m,i,j,1,0,word)||search(m,i,j,0,1,word)||search(m,i,j,-1,0,word)||
			   search(m,i,j,0,-1,word)||search(m,i,j,1,1,word)||search(m,i,j,-1,-1,word)||
			   search(m,i,j,1,-1,word)||search(m,i,j,-1,1,word))
			{
				cout<<(i+1)<<" "<<(j+1)<<endl;
				return 0;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int p,q,r,w;
		scanf("%i %i\n",&p,&q);
		r=p;
		vector<string> matrix;
		while(r--)
		{
			string s;

			getline(cin,s);
			matrix.push_back(s);
		}
		scanf("%i\n",&w);
		while(w--)
		{
			string s;
			getline(cin,s);
			waldorf(matrix,s);
		}
	}
	return 0;
}