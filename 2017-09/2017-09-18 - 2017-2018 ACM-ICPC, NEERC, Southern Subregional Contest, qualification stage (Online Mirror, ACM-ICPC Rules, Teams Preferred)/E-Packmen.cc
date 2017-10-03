#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') a.push_back(i);
    if (s[i] == 'P') b.push_back(i);
  }
  int low = 0, high = 2 * n;
  while (low <= high) {
    int mid = (low + high) / 2;
    auto st = a;
    reverse(st.begin(), st.end());
    bool flag = true;
    for (auto x : b) {
      if (st.empty()) break;
      if (x - st.back() > mid) {
        flag = false;
        break;
      }
      int mm = min(st.back(), x);
      while (!st.empty() && (st.back() <= x || st.back() - mm + min(x - mm, st.back() - x) <= mid)) st.pop_back();
    }
    flag &= st.empty();
    if (!flag) low = mid + 1;
    else high = mid - 1;
  }
  cout << low << endl;
  return 0;
}
