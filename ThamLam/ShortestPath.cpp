#include <bits/stdc++.h>

using namespace std;
vector<int> dijkstra(int s, vector< vector<pair<int, int>> > &adj){
	priority_queue< pair<int, int> , vector< pair<int, int>> , greater<pair<int, int>> > q;
	q.push({0, 0});
	vector<int> dist(s, INT_MAX);
	dist[0] = 0;
	while(!q.empty()){
		int u = q.top().first;
		q.pop();
		for(auto &i : adj[u]){
			int v = i.first;
			int w = i.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push({v, dist[v]});
			}
		}
	}
	return dist;
}
int main(){
	int v = 5; // so dinh cua graph
	vector< vector<pair<int, int>> > adj(v);
	adj[0].push_back({1, 10});
	adj[0].push_back({4, 3});
	adj[1].push_back({2,2});
	adj[1].push_back({4, 4});
	adj[2].push_back({3, 9});
	adj[3].push_back({2, 7});
	adj[4].push_back({1, 1});
	adj[4].push_back({2, 8});
	adj[4].push_back({3, 2});
	vector<int> dist = dijkstra(v, adj);
	for(int i = 0 ; i < dist.size() ; i++){
		cout << i << " : " << dist[i] << endl;
	}
}