#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > graph;
vector<int> team;
// array for storing team number of players
// (0=unknown, 1=team1, 2=team2)

void dfs(int player, int teamNum)
{
	team[player] = teamNum; // saving team number for current player

	int nextTeamNum = 1 + (teamNum==1)*1;
	// if current teamNum==1, next teamNum will be 2 and viceversa

	for( int i: graph[player] )
		if( team[i] == 0 )
			// team[i]==0 indicates unvisited node in graph
			dfs( i, nextTeamNum );
}

int findMargin(vector<int> P, vector<int> F)
{
	int N = P.size(), k = (int)F.size() / 2;

	// creating graph:
	graph.clear();
	graph.resize(N);
	for(int i=0; i<k; i++)
	{
		graph[ --F[2*i] ].push_back( --F[2*i+1] );
		graph[ F[2*i+1] ].push_back( F[2*i] );
	}

	team.clear();
	team.resize(N,0); // team array set to zero as all players are unknown
	dfs(0,1);

	for(int i: team)
		if(i==0)
			// if team for any player is still unknown,
			// it means graph was not fully connected
			return -1;

	int winLoss = 0; // win loss difference for team1
	for(int i=0; i<k; i++)
	{
		if(  ( team[F[2*i]] == 1 )  ^  ( P[ F[2*i] ] > P[ F[2*i+1] ] )  )
			winLoss--;

		else
			winLoss++;
	}

	return abs(winLoss);
}

int main()
{
	int t, N, k;
	cin>> t;

	vector<int> P,F;

	while(t--)
	{
		cin>> N;
		P.resize(N);
		for(int i=0; i<N; i++)
			cin>> P[i];

		cin>> k;
		F.resize(2*k);
		for(int i=0; i<2*k; i++)
			cin>> F[i];

		cout<< findMargin(P,F) << endl;
	}

	return 0;
}