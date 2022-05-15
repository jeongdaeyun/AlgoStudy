#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int V;
vector<pair<int, int>>tree[100001];
vector<bool>visit;
int max_dist;
int max_node;

void Move(int start, int distance) {
	visit[start] = true;
	int next_node = 0;
	if (max_dist < distance) {
		max_dist = max(max_dist, distance);
		max_node = start;
	}
	for (int cnt = 0; cnt < tree[start].size(); ++cnt) {
		next_node = tree[start][cnt].first;
		int n_dist = distance + tree[start][cnt].second;
		if (!visit[next_node]) {
			visit[next_node] = true;
			Move(next_node, n_dist);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0, x = 0;
	int current_node = 0;
	int linked_node = 0;
	int num = 0;
	int first = 0;

	cin >> V;
	visit = vector<bool>(V + 1, 0);

	for (y = 1; y <= V; ++y) {
		cin >> current_node;
		while (1) {
			cin >> linked_node;
			if (linked_node == -1) break;
			cin >> num;
			tree[current_node].push_back({ linked_node,num });
		}
		if (tree[current_node].size() == 1) first = current_node;
	}


	Move(first, 0);
	fill(visit.begin(), visit.end(), false);
	Move(max_node, 0);

	cout << max_dist;
}