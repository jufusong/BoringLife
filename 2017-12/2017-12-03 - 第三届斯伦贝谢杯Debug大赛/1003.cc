#include <bits/stdc++.h>

using namespace std;

char t[300005];

int main(int argc, char *argv[]) {
  while (gets(t)) {
    string s(t);
    int n = s.size();
    vector<int> a(2 * n + 4);
    int now = n;
    //    a[now] = 1;
    long long ans = 0;
    for (auto c : s) {
      if (c == '(') {
        a[now]++;
        now--;
      } else {
        a[now++] = 0;
        ans += a[now];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
