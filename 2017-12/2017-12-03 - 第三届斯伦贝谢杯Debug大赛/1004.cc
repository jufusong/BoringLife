#include <bits/stdc++.h>

using namespace std;

char s[10005];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<string> vec(n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      vec[i] = string(s);
      string t = vec[i];
      reverse(t.begin(), t.end());
      vec[i] = max(vec[i], t);
    }
    sort(vec.begin(), vec.end(), [](const string& s, const string& t){
        return s + t > t + s;
      });
    string ans;
    for (auto& x : vec) {
      ans += x;
    }
    for (int i = 0; i < n; ++i) {
      string t;
      for (int j = 0; j < n; j++) {
        if (j != i) t += vec[j];
      }
      for (int j = 1; j < vec[i].size(); j++) {
        string s1 = vec[i].substr(0, j);
        string s2 = vec[i].substr(j);
        string rs1 = s1;
        string rs2 = s2;
        reverse(rs1.begin(), rs1.end());
        reverse(rs2.begin(), rs2.end());
        ans = max(ans, rs1 + t + rs2);
        ans = max(ans, s2 + t + s1);
      }
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
