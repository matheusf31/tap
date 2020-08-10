#include <iostream>

using namespace std;

int main() {
  unsigned long long fat[100002];

  int n;

  // pra desconsiderar as permutações entre os 3 amigos que seria (3! = 3*2*1)
  fat[3] = 1;

  // calcula-se o fatorial antes pq temos vários casos de teste, portanto os valores já ficam prontos e não é necessário recalcular
  for (int i = 4; i <= 100000; i++)
    fat[i] = (i*fat[i-1]) % 1000000009;

  while(cin >> n && n) {
    cout << fat[n] << endl;
  }

  return 0;
}
