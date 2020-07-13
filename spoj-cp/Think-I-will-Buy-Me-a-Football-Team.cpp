#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> rsum;
vector<int> csum;

int main() {
  int n, sum, owned, diff, caseTest = 1;

  while (scanf("%d", &n) == 1 && n) {
    graph.resize(n, vector<int>(n, 0));
    rsum.resize(n);
    csum.resize(n);

    for (int i = sum = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> owned;

        graph[i][j] = owned;
        sum += graph[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = rsum[i] = csum[i] = 0; j < n; ++j) {
        rsum[i] += graph[i][j];
        csum[i] += graph[j][i];
      }
    }

    for (int i = diff = 0; i < n; i++) {
      if (rsum[i] > csum[i]) diff += rsum[i] - csum[i];
    }

    cout << caseTest++ << ". " << sum << " " << diff << " " << endl;
  }
  return 0;
}