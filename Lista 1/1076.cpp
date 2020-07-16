#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> visited;

int ans, v, e;

void dfs(int source) {
  visited[source] = 1;

  for (int i = 0; i < v; ++i) {
    if (graph[source][i])
      if (!visited[i]) dfs(i), ans++;
  }
}

int main() {
  int testNumber, startPoint, l1, l2;

  cin >> testNumber;

  while (testNumber--) {
    cin >> startPoint >> v >> e;

    visited.resize(v, 0);
    graph.resize(v, vector<int>(v, 0));

    visited.assign(v, 0);
    graph.assign(v, vector<int>(v, 0));

    while (e--) {
      cin >> l1 >> l2;

      graph[l1][l2] = graph[l2][l1] = 1;
    }

    ans = 0;

    dfs(startPoint);

    printf("%d\n", ans * 2);
  }

  return 0;
}