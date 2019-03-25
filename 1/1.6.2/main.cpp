#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


vector<string> buscaminas(vector<string> v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int c=0;
			for(int k=max(0,i-1);k<v.size()&&k<i+2;k++)
			{
				for(int l=max(0,j-1);l<v[i].size()&&l<j+2;l++)
				{
					c+=v[k][l]=='*'&&(k!=i||l!=j);
				}
			}
			if(v[i][j]!='*')
				v[i][j]='0'+c;
		}
	}
	return v;
}

void print(vector<string> v,int i)
{
	cout<<"Field #"<<i<<endl;
	for(auto a:v)
	{
		for(char b:a)
			cout<<b;
		cout<<endl;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int i,j,k=1;
	freopen("input.txt","r",stdin);
	while(scanf("%d %d",&i,&j)&&i!=0)
	{
		vector<string> v;
		while(i-->=0)
		{
			string s;
			getline(cin,s);
			if(s.size()) v.push_back(s);
		}
		print(buscaminas(v),k++);

	}
	return 0;
}