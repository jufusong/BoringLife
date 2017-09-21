#include <bits/stdc++.h>

using namespace std;

string a[] = {"rat",   "ox",    "tiger",  "rabbit",  "dragon", "snake",
              "horse", "sheep", "monkey", "rooster", "dog",    "pig"};

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    auto index = [](string s) {
      for (int i = 0; i < 12; i++) {
        if (s == a[i]) return i;
      }
      return 0;
    };
    int x = index(s), y = index(t);
    int z = (y - x + 12) % 12;
    if (z == 0) z = 12;
    cout << z << endl;
  }
  return 0;
}
