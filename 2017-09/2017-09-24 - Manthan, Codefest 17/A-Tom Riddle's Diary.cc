#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  set<string> se;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (se.count(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
      se.insert(s);
    }
  }
  return 0;
}
