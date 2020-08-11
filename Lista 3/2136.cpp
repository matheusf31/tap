#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int oldWinnerLength = 0;
  string name, option, winner;
  vector<string> yesOption, noOption;

  while (cin >> name && name != "FIM") {
    cin >> option;

    if (option == "YES") {
      if (find(yesOption.begin(), yesOption.end(), name) == yesOption.end()) {
        yesOption.push_back(name);
      }

      if (name.length() > oldWinnerLength) {
        oldWinnerLength = name.length();
        winner = name;
      }
    } else {
      if (find(noOption.begin(), noOption.end(), name) == noOption.end()) {
        noOption.push_back(name);
      }
    }
  }

  sort(yesOption.begin(), yesOption.end());
  sort(noOption.begin(), noOption.end());

  vector<string>::iterator it;
  for (it = yesOption.begin(); it < yesOption.end(); it++) cout << *it << endl;
  for (it = noOption.begin(); it < noOption.end(); it++) cout << *it << endl;

  cout << "\n"
       << "Amigo do Habay:" << endl;
  cout << winner << endl;

  return 0;
}