#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  multiset<int> se;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    se.insert(t);
  }
  int m;
  cin >> m;
  for (int i = 0, t; i < m; i++) {
    cin >> t;
    if (!se.count(t)) {
      cout << "NO" << endl;
      return 0;
    }
    se.erase(se.find(t));
  }
  cout << "YES" << endl;
  return 0;
}
