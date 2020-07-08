#include <iostream>
#include <vector>

using namespace std;

struct disjointSets
{
  vector<int> parent, rank;

  disjointSets(int n)
  {
    parent.resize(n);

    rank.resize(n, 0);

    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int u)
  {
    if (u != parent[u])
    {
      parent[u] = find(parent[u]);
    }

    return parent[u];
  }

  void merge(int x, int y)
  {
    x = find(x), y = find(y);

    if (rank[x] > rank[y])
      parent[y] = x;
    else
      parent[x] = y;

    if (rank[x] == rank[y])
      rank[y]++;
  }
};

int main()
{
  int n, m, p;
  int a, b, k, l;

  cin >> n >> m >> p;

  disjointSets neighborhoods(n);

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;

    neighborhoods.merge(a - 1, b - 1);
  }

  while (p--)
  {
    cin >> k >> l;

    k = neighborhoods.find(k - 1);
    l = neighborhoods.find(l - 1);

    if (neighborhoods.parent[k] == neighborhoods.parent[l])
      cout << "Lets que lets" << endl;
    else
      cout << "Deu ruim" << endl;
  }

  return 0;
}