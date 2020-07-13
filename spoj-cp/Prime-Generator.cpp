#include <iostream>

using namespace std;

int main() {
  int t, m, n;

  cin >> t;

  while (t--) {
    cin >> m >> n;

    for (int aux = m; aux <= n; aux++) {
      bool prime = aux == 2 || aux % 2 == 1;
      int divisor = 2;

      if (aux == 1) continue;

      while (prime && divisor * divisor <= aux) {
        if (aux % divisor == 0) prime = false;

        divisor++;
      }

      if (prime) {
        cout << aux << endl;
      }
    }

    cout << endl;
  }

  return 0;
}