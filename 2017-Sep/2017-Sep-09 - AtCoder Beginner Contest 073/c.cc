#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  set<int> se;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (se.count(x)) {
      se.erase(x);
    } else {
      se.insert(x);
    }
  }
  cout << se.size() << endl;
  return 0;
}
