#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    set<string> se;
    for (int j = 0; j < (int)a[i].size(); j++) {
      for (int k = 1; j + k <= (int)a[i].size(); k++) {
        se.insert(a[i].substr(j, k));
      }
    }
    for (auto s : se) {
      mp[s]++;
    }
  }
  for (auto s : a) {
    int p = s.size();
    string t = s;
    for (int j = 0; j < (int)s.size(); j++) {
      for (int k = 1; j + k <= (int)s.size(); k++) {
        if (mp[s.substr(j, k)] == 1 && k < p) {
          p = k;
          t = s.substr(j, k);
        }
      }
    }
    cout << t << endl;
  }
  return 0;
}
