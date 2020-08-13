#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
  string word;
  ull fat[1001], test, ans;
  map<char, ull> freq;
  map<char, ull>::iterator it;

  fat[0] = 1;
  fat[1] = 1;
  fat[2] = 2;
  fat[3] = 6;

  for (int i = 4; i < 1001; i++) fat[i] = (i * fat[i - 1]);

  while (getline(cin, word)) {
    int wordSize = word.size();

    for (int i = 0; i < wordSize; i++) freq[word[i]]++;

    ans = 1;

    for (it = freq.begin(); it != freq.end(); it++) {
      test = it->second;

      if (test > 1) ans *= fat[test];
    }

    cout << (fat[wordSize] / ans) % 1000000007 << endl;

    freq.clear();
  }

  return 0;
}
