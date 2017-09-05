#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> a;

bool check(int ix, int iy) {
  int n = a.size();
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (i != ix && i != iy && (ll)(i - ix) * (a[iy] - a[ix]) != (ll)(iy - ix) * (a[i] - a[ix])) {
      b.push_back(i);
    }
  }
  if (b.empty()) return false;
  if (b.size() == 1) return true;
  if ((ll)(b[1] - b[0]) * (a[iy] - a[ix]) != (ll)(iy - ix) * (a[b[1]] - a[b[0]])) return false;
  for (int i = 2; i < b.size(); i++) {
    int xx = b[0], yy = b[1];
    int t = b[i];
    if ((ll)(t - xx) * (a[yy] - a[xx]) != (ll)(yy - xx) * (a[t] - a[xx])) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << (check(0, 1) || check(0, 2) || check(1, 2) ? "Yes" : "No") << endl;
  return 0;
}
