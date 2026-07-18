class Solution {
	public:
	#define pp pair<int, int>
	vector<vector<pp>> graph;
	unordered_set<int>visited;
	
	void add_edge(int &u, int &v, int &wt) {
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt});
	}
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
	    graph.resize(V);
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			add_edge(u, v, wt);
			
		}
		unordered_map<int, pp>m;
		priority_queue<pp, vector<pp>, greater<pp>> pq;
		
		for (int i = 0; i<V ; i++) {
			m[i] = {INT_MAX, -1};
		}
		m[src] = {0, -1};
		pq.push({0, src});
		
		while (pq.size()) {
			int wt = pq.top().first;
			int node = pq.top().second;
			if (visited.find(node) != visited.end()) {
				pq.pop();
				continue;
			}
			pq.pop();
			visited.insert(node);
			for (auto neighbour : graph[node]) {
				if (visited.find(neighbour.first) == visited.end() && m[node].first + neighbour.second<m[neighbour.first].first) {
					m[neighbour.first].first = m[node].first + neighbour.second;
					m[neighbour.first].second = node;
					pq.push({m[neighbour.first].first, neighbour.first});
				}
			}
			
		}
		vector<int>finalans(V);
		for (auto x : m) {
			
			finalans[x.first] = x.second.first;
		}
		return finalans;
		
	}
};
