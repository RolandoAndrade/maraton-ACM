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
int sumAll(auto w)
{
	int r = 0;
	for(auto q: w)
		r+= q;
	return r;
}

pair<vector<int>,vector<int>> searchEscalera(auto w)
{
	vector<int> cortas;
	vector<int> largas;
	for(int i = 0; i<w.size();i++)
	{
		vector<int> a{1,2,3,4,5};
		vector<int> e{2,3,4,5,6};
		sort(w[i].begin(),w[i].end());
		if(w[i]==a||w[i]==e)
			largas.push_back(i);
		int start = -1;
		if(w[i][0]+1==w[i][1])
			start = 0;
		else if(w[i][1]+1==w[i][2])
			start = 1;
		if(start!=-1)
		{

			int last = a[start];
			int k = last+1;
			int esc = 1;
			for(int j = start+1; j<start+4 &&esc;j++)
			{
				esc =k==w[i][j];
				k++;
			}
			if(esc)
				cortas.push_back(i);
		}
		

	}
	return make_pair(cortas,largas);
}

vector<int> searchFull(auto w)
{
	vector<int> f;
	int i = 0;
	for(auto q:w)
	{
		set<int> s(q.begin(),q.end());

		if(s.size()==2)
		{
			int pp = count(q.begin(),q.end(),q[0]);
			if(pp==2||pp==3)
			{
				f.push_back(i);
			}
		}
		i++;
	}
	return f;
}

vector<int> searchReps(auto w, int num)
{
	vector<int> r;
	int i=0;
	for(auto q: w)
	{
		if(count(q.begin(),q.end(),q[0])==num||count(q.begin(),q.end(),q[1])==num||count(q.begin(),q.end(),q[2])==num)
		{
			r.push_back(i);
		}
		i++;
	}
	return r;
}

vector<pair<int,int>> sum(auto w, int num)
{
	vector<pair<int,int>> r;
	int i=0;
	for(auto q: w)
	{
		for(auto c:q)
		{
			if(c==num)
			{
				r.push_back(make_pair(i,c*count(q.begin(),q.end(),c)));
				break;
			}
		}
		i++;
	}
	return r;
}

void playFiveSame(auto fiveSame,auto *ans, auto *played)
{
	if(fiveSame.size())
	{
		(*played)[fiveSame[0]]=1;
		(*ans)[9] = 50;
	}
}

void playFull(auto full, auto *ans, auto *played, auto w)
{
	if(full.size())
	{
		int min = 99, index = -1;
		for(auto t: full)
		{
			int ax = sumAll(w[t]);
			if(ax<min)
			{
				min = ax;
				index = t;
			}
		}
		if(index>0)
		{
			(*played)[index]=1;
			(*ans)[12] = 40;
		}

	}
}

void playEscaleraLarga(auto el, auto ec, auto *ans, auto *played)
{
	if(el.size())
	{
		for(auto t: el)
		{
			for(auto u: ec)
			{
				if(t!=u)
				{
					(*played)[t]=1;
					(*ans)[11] = 35;
					return;
				}
			}
		}
		(*played)[el[0]]=1;
		(*ans)[11] = 35;
	}
}

void playEscaleraCorta(auto ec, auto *ans, auto *played)
{
	for(auto t: ec)
	{
		if(!(*played)[t])
		{
			(*played)[t]=1;
			(*ans)[10] = 25;
			return;
		}
	}
}


void playSame(auto fourSame, auto *ans, auto *played, auto w, int rrr)
{
	int max = -1, index = -1;
	for(auto t: fourSame)
	{
		if(!(*played)[t])
		{
			int val = sumAll(w[t]);
			if(val>max)
			{
				max= val;
				index = t;
			}
		}
	}
	if(max>0)
	{
		(*played)[index]=1;
		(*ans)[rrr] = max;
	}
}

void playFree(auto w,auto *ans, auto *played)
{
	int max = -1, index = -1;
	for(int i = 0; i < w.size();i++)
	{
		if(!(*played)[i])
		{
			int ax = sumAll(w[i]);
			if(ax>max)
			{
				max = ax;
				index = i;
			}
		}
	}
	if(index>0)
	{
		(*played)[index]=1;
		(*ans)[6] = max;
	}
}

void playEnd(auto sum, auto *ans, auto *played, int rrr)
{
	int max = -1, index = -1;
	for(auto s:sum)
	{
		if(!(*played)[s.first])
		{
			if(s.second>max)
			{
				max = s.second;
				index = s.first;
			}
		}
	}
	if(index>0)
	{
		(*played)[index]=1;
		(*ans)[rrr] = max;
	}
}

auto totalPoints(auto ans)
{
	int s = 0;
	for(auto q:ans)
		s+=q;
	ans[14]=s;
	return ans;
}

auto yahtzee(auto w)
{
	pair<vector<int>,vector<int>> escaleras = searchEscalera(w);
	vector<int> full = searchFull(w);
	vector<int> fiveSame = searchReps(w,5);
	vector<int> fourSame = searchReps(w,4);
	vector<int> treeSame = searchReps(w,3);
	vector<pair<int,int>> sum1 = sum(w,1);
	vector<pair<int,int>> sum2 = sum(w,2);
	vector<pair<int,int>> sum3 = sum(w,3);
	vector<pair<int,int>> sum4 = sum(w,4);
	vector<pair<int,int>> sum5 = sum(w,5);
	vector<pair<int,int>> sum6 = sum(w,6);
	vector<int> ans(15,0);
	vector<int> played(13,0);
	/*Esta forma no es buena, mejor era tomar 5 iguales, escalera larga y corta y full, 
	luego hacer las sumas ponderadas de las partidas que se podrían formar y tomar la mayor*/
	playEnd(sum6,&ans,&played,5);
	playFiveSame(fiveSame, &ans,&played);
	playFull(full, &ans, &played,w);
	playEscaleraLarga(escaleras.second, escaleras.first, &ans,&played);
	playEscaleraCorta(escaleras.first, &ans,&played);
	playSame(fourSame, &ans,&played, w,8);
	playEnd(sum4,&ans,&played,3);
	playSame(treeSame, &ans,&played, w,7);
	playFree(w,&ans, &played);
	playEnd(sum5,&ans,&played,4);
	playEnd(sum3,&ans,&played,2);
	playEnd(sum2,&ans,&played,1);
	playEnd(sum1,&ans,&played,0);
	int s = 0;
	for(int i = 0;i<6;i++,s+=ans[i]);
	if(s>62) ans[13]=35;
	return totalPoints(ans);
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	int a, b, c, d, e;
	
	while(scanf("%i %i %i %i %i",&a,&b,&c,&d,&e)!=EOF)
	{
		vector<vector<int>>round;
		round.push_back(vector<int>{a,b,c,d,e});
		for(int i = 0; i < 12; i++)
		{
			scanf("%i %i %i %i %i",&a,&b,&c,&d,&e);
			round.push_back(vector<int>{a,b,c,d,e});
		}
		vector<int> res = yahtzee(round);
		for(int i: res)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}