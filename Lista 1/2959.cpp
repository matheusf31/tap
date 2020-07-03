#include <iostream>
#include <vector>

using namespace std;

#define MAXSIZE 400

int par[MAXSIZE];

struct disjointSets
{
  vector<int> parent, rank;

  disjointSets(int n)
  {
    parent.resize(n);

    rank.resize(n, 0);

    for (int i = 1; i <= n; i++)
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

  int findConnection(int k, int l)
  {
    if (parent[k] == k)
      return 0;

    if (parent[k] != l)
    {
      findConnection(parent[k], l);
    }

    return 1;
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
  // n -> num de bairros, m -> num de conexões, p -> num de perguntas
  int n, m, p;
  int a, b, k, l;
  int existPath1, existPath2;

  cin >> n >> m >> p;

  disjointSets neighborhoods(n);

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;

    neighborhoods.merge(a, b);
  }

  // for (int i = 1; i <= n; i++)
  //   cout << i << '\t';
  // cout << endl;

  // for (int i = 1; i <= n; i++)
  //   cout << neighborhoods.parent[i] << '\t';
  // cout << endl;

  while (p--)
  {
    cin >> k >> l;

    existPath1 = neighborhoods.findConnection(k, l);
    existPath2 = neighborhoods.findConnection(l, k);

    if (existPath1 || existPath2)
    {
      cout << "Lets que lets" << endl;
    }
    else
    {
      cout << "Deu ruim" << endl;
    }
  }

  return 0;
}