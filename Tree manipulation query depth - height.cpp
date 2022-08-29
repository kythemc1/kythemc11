#include <bits/stdc++.h>
using namespace std;
#define Max 100001
vector <int> Node[Max];
int root;
int depth[Max];
int height[Max];
int par[Max];

void crease(int u) {
	if(u == -1) {
		return;
	}else {
		int v = par[u];
		height[v] = max(height[u] + 1, height[v]);
		crease(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(1) {
		string request;
		cin >> request;
		if(request == "*") {
			break;
		}else if(request == "MakeRoot") {
			cin >> root;
			height[root] = 1;
			depth[root] = 1;
			par[root] = -1;
		}else if(request == "Insert") {
			int u, v;
			cin >> u >> v;
			par[u] = v;
			Node[v].push_back(u);
			depth[u] = depth[v] + 1;
			height[u] = 1;
			if(height[v] == 1 ) {
				crease(u);
			}
		}else if(request == "Height") {
			int u; cin >> u;
			cout << height[u] << endl;
		}else{
			int u; cin >> u;
			cout <<depth[u] << endl;
		}
	}
	return 0;
}