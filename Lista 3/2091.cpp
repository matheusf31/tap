#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  while (cin >> n && n) {
    long long arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n);

    bool find = false;
    int index = 0;

    for (int i = 0; i < n - 1; i += 2) {
      if (arr[i] != arr[i + 1]) {
        find = true;
        index = i;
        break;
      }
    }

    if (!find && arr[n - 1] != arr[n - 2] && (arr[n - 2] == arr[n - 3]))
      index = n - 1;

    if (!find && arr[n - 1] == arr[n - 2] && (arr[n - 2] == arr[n - 3]))
      index = n - 1;

    cout << arr[index] << endl;
  }

  return 0;
}