#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

pair<int,int> find(auto v, char c)
{
	pair<int,int> r;
	for(int i=0;i<v.size();i++)
	{
		int f=v[i].find(c);
		if(f!=-1)
		{
			r.first=i;
			r.second=f;
			break;
		}
	}
	return r;
}

int checkC(auto v, int row, int col, int mayus)
{
	for(int i=row-1;i>=0;i--)
	{
		if(v[i][col]!='.')
		{
			char r=mayus?'R':'r';
			char q=mayus?'Q':'q';
			if(v[i][col]==r||v[i][col]==q)
				return 1;
			break;
		}
	}
	for(int i=row+1;i<v.size();i++)
	{
		if(v[i][col]!='.')
		{
			char r=mayus?'R':'r';
			char q=mayus?'Q':'q';
			if(v[i][col]==r||v[i][col]==q)
				return 1;
			break;
		}
	}

	return 0;
}

int checkR(auto v, int row, int col,int mayus)
{
	for(int i=col-1;i>=0;i--)
	{
		if(v[row][i]!='.')
		{
			char r=mayus?'R':'r';
			char q=mayus?'Q':'q';
			if(v[row][i]==r||v[row][i]==q)
				return 1;
			break;
		}
	}
	for(int i=col+1;i<v[0].size();i++)
	{
		if(v[row][i]!='.')
		{
			char r=mayus?'R':'r';
			char q=mayus?'Q':'q';
			if(v[row][i]==r||v[row][i]==q)
				return 1;
			break;
		}
	}
	return 0;
}

int checkD(auto v,int row, int col, int mayus)
{ 
	int i=row-1,j=col-1,z=0;
	for(;i>=0&&j>=0;i--,j--,z++)
	{
		if(v[i][j]!='.')
		{
			if(!z&&!mayus&&v[i][j]=='p')
			{
				return 1;
			}
			char r=mayus?'B':'b';
			char q=mayus?'Q':'q';
			if(v[i][j]==r||v[i][j]==q)
				return 1;
			break;
		}
	}
	i=row-1,j=col+1,z=0;
	for(;i>=0&&j<v[0].size();i--,j++,z++)
	{
		if(v[i][j]!='.')
		{
			if(!z&&!mayus&&v[i][j]=='p')
			{
				return 1;
			}
			char r=mayus?'B':'b';
			char q=mayus?'Q':'q';
			if(v[i][j]==r||v[i][j]==q)
				return 1;
			break;
		}
	}
	i=row+1,j=col-1,z=0;
	for(;i<v.size()&&j>=0;i++,j--,z++)
	{
		if(v[i][j]!='.')
		{
			if(!z&&mayus&&v[i][j]=='P')
			{
				return 1;
			}
			char r=mayus?'B':'b';
			char q=mayus?'Q':'q';
			if(v[i][j]==r||v[i][j]==q)
				return 1;
			break;
		}
	}
	i=row+1,j=col+1,z=0;
	for(;i<v.size()&&j<v[0].size();i++,j++,z++)
	{
		if(v[i][j]!='.')
		{
			if(!z&&mayus&&v[i][j]=='P')
			{
				return 1;
			}
			char r=mayus?'B':'b';
			char q=mayus?'Q':'q';
			if(v[i][j]==r||v[i][j]==q)
				return 1;
			break;
		}
	}
	return 0;
}

int checkH(auto v,int row, int col, int mayus)
{
	char c=mayus?'H':'h';
	return (row>1&&col>0&&v[row-2][col-1]==c)||(row>1&&col<v[0].size()-1&&v[row-2][col+1]==c)||
	(row<v.size()-2&&col>0&&v[row+2][col-1]==c)||(row<v.size()-2&&col<v[0].size()-1&&v[row+2][col+1]==c)||
	(row>0&&col>1&&v[row-1][col-2]==c)||(row>0&&col<v[0].size()-2&&v[row-1][col+2]==c)||
	(row<v.size()-1&&col>1&&v[row+1][col-2]==c)||(row<v.size()-1&&col<v[0].size()-2&&v[row+1][col+2]==c);

}


int whiteC(auto v)
{
	pair<int,int> loc=find(v,'K');
	int row=loc.first,col=loc.second;
	return checkC(v,row,col,0)||checkR(v,row,col,0)||checkD(v,row,col,0)||checkH(v,row,col,0);
}

int blackC(auto v)
{
	pair<int,int> loc=find(v,'k');
	int row=loc.first,col=loc.second;
	return checkC(v,row,col,1)||checkR(v,row,col,1)||checkD(v,row,col,1)||checkH(v,row,col,1);
}

string jaque(vector<string> v,int i)
{
	string r="Game #"s+to_string(i)+":  ";
	if(whiteC(v))
		return r+"white king is in check";
	if(blackC(v))
		return r+"black king is in check";
	return r+"no king is in check";

}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	vector<string> s={"........","........","........","........","........","........","........","........"};
	int i=1;
	while(1)
	{
		vector<string> v;
		string p;
		while(getline(cin,p)&&p.size()==8)
			v.push_back(p);
		if(v==s)
			break;
		cout<<jaque(v,i++)<<endl;
	}
	
	return 0;
}