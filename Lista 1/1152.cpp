#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> ppi;

vector<ppi> edges;
vector<ppi> mst;

int v, e, totalCost = 0;

struct disjointSets {
  vector<int> parent, rank;

  disjointSets(int n) {
    parent.resize(n);

    rank.resize(n, 0);

    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int u) {
    if (u != parent[u]) {
      parent[u] = find(parent[u]);
    }

    return parent[u];
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);

    if (rank[x] > rank[y])
      parent[y] = x;
    else
      parent[x] = y;

    if (rank[x] == rank[y]) rank[y]++;
  }
};

void inputRead() {
  edges.reserve(e);
  mst.reserve(v-1);

  edges.clear();
  mst.clear();

  totalCost = 0;

  for (int i = 0; i < e; i++) {
    int x, y, z;

    cin >> x >> y >> z;

    totalCost += z;

    edges.push_back(make_pair(z, make_pair(x, y)));
  }
}

void kruskal() {
  sort(edges.begin(), edges.end());

  disjointSets ds(v);

  int c = 1;

  vector<ppi>::iterator it;

  for (it = edges.begin(); c < v; it++)
  {
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.find(u);
    int set_v = ds.find(v);

    if (set_u != set_v) {
      mst.push_back(make_pair(it->first, make_pair(u,v)));

      ds.merge(set_u, set_v);
      c++;
    }
  }
}

int main() {
  while (cin>>v>>e, v||e) {
    inputRead();
    kruskal();

    vector<ppi>::iterator it;
    for (it = mst.begin(); it != mst.end(); it++){
      int w = it->first;
      totalCost -= w;
    }

    cout << totalCost << endl;
  }

  return 0;
}