#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> people;

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
  int m, n, mapIndex = 1, family = 0;
  string personA, relation, personB;
  set<int> families;

  cin >> m >> n;

  disjointSets parents(m);

  for (int i = 0; i < n; i++)
  {
    cin >> personA >> relation >> personB;

    if (people[personA] == 0)
    {
      people[personA] = mapIndex;
      mapIndex += 1;
    }

    if (people[personB] == 0)
    {
      people[personB] = mapIndex;
      mapIndex += 1;
    }

    parents.merge(people[personA] - 1, people[personB] - 1);
  }

  for (int j = 0; j < m; j++)
  {
    // if (parents.rank[j] != 0)
    // {
    //   family++;
    // }

    families.insert(parents.parent[j]);
  }

  // cout << family << endl;

  cout << families.size() << endl;

  return 0;
}