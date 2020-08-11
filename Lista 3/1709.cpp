#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  int pos = 2;
  int ans = 1;

  while (pos != 1) {
    if (pos <= n / 2)
      pos += pos;
    else
      pos -= (n - pos + 1);

    ++ans;
  }

  cout << ans << endl;

  return 0;
}