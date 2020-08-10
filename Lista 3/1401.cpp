#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  string letters;

  cin >> n;

  while(n--) {
    cin >> letters;

    sort(letters.begin(), letters.end());

    do {
      cout << letters << endl;
    } while (next_permutation(letters.begin(), letters.end()));

    cout << endl;
  }

  return 0;
}