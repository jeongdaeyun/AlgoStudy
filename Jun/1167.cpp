#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int V;
vector<pair<int, int>>tree[100001];
vector<bool>visit;
int max_dist;
int max_node;

void dfs(int dest, int dist) {
	visit[dest] = true;
	int next_node = 0;
	if (max_dist < dist) {
		max_dist = dist;
		max_node = dest;
	}
	for (int cnt = 0; cnt < tree[dest].size(); ++cnt) {
		next_node = tree[dest][cnt].first;
		int n_dist = dist + tree[dest][cnt].second;
		if (!visit[next_node]) {
			visit[next_node] = true;
			dfs(next_node, n_dist);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num = 0;
	int current_node = 0;
	int linked_node = 0;
	int dist = 0;
	int first = 0;

	cin >> V;
	visit = vector<bool>(V + 1, 0);

	for (num = 1; num <= V; ++num) {
		cin >> current_node;
		while (1) {
			cin >> linked_node;
			if (linked_node == -1) break;
			cin >> dist;
			tree[current_node].push_back({ linked_node,dist });
		}
		if (tree[current_node].size() == 1) first = current_node;
	}

	dfs(first, 0);
	fill(visit.begin(), visit.end(), false);
	dfs(max_node, 0);

	cout << max_dist;
}