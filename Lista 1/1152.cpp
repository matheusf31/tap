#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f;

vector<list<pi> > graph;
vector<int> dist;
vector<int> parent;
vector<bool> visited;
int v, e, totalCost = 0;

void inputRead() {
  dist.resize(v, INF);
  parent.resize(v, -1);
  visited.resize(v, false);
  graph.resize(v);

  dist.assign(v, INF);
  parent.assign(v, -1);
  visited.assign(v, false);
  graph.clear();

  totalCost = 0;

  for (int i = 0; i < e; i++) {
    int x, y, z;

    cin >> x >> y >> z;

    totalCost += z;

    graph[x].push_back(make_pair(z, y));
    graph[y].push_back(make_pair(z, x));
  }
}

void dijkstra() {
  priority_queue<pi, vector<pi>, greater<pi> > pq;
  pq.push(make_pair(0, 0));

  dist[0] = 0;

  list<pi>::iterator it;

  while (!pq.empty()) {
    int weight = pq.top().first;
    int vertice = pq.top().second;

    pq.pop();

    if (visited[vertice]) continue;

    visited[v] = true;

    for (it = graph[vertice].begin(); it != graph[vertice].end(); it++) {
      if (dist[it->second] > weight + it->first) {
        parent[it->second] = vertice;
        dist[it->second] = weight + it->first;
        pq.push(make_pair(dist[it->second], it->second));
      }
    }
  }
}

int main() {
  cin >> v >> e;

  while (v != e != 0) {
    inputRead();
    dijkstra();

    for (int i = 0; i < v; i++) {
      // cout << '(' << setw(2) << dist[i] << ") : " << i;
      int distTotal = dist[i];

      int j = parent[i];

      while (j != -1) {
        // cout << " -> " << j;
        distTotal -= dist[j];
        j = parent[j];
      }

      totalCost -= distTotal;

      // cout << endl;
    }

    cout << totalCost << endl;

    cin >> v >> e;
  }

  return 0;
}