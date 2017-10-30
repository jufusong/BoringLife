#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  multiset<string> se;
  for (auto c : s) {
    se.insert(string(1, c));
  }
  while (se.size() > 1) {
    string x = *se.begin(), y = *se.rbegin();
    se.erase(se.begin());
    auto it = se.end();
    --it;
    se.erase(it);
    se.insert(x + y);
  }
  cout << *se.begin() << endl;
  return 0;
}
