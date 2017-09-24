#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < 5; i++) {
    string s, t;
    cin >> s >> t;
    map<string, int> mp;
    queue<string> q;
    q.push(s);
    mp[s] = 0;
    while (!q.empty() && !mp.count(t)) {
      string u = q.front();
      q.pop();
      int d = mp[u];
      for (int i = 1; i < n; i++) {
        string xx = u;
        swap(xx[0], xx[i]);
        if (!mp.count(xx)) {
          mp[xx] = d + 1;
          q.push(xx);
        }
      }
    }
    cout << mp[t] << endl;
  }
  return 0;
}
