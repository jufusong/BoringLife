 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500005;

namespace AT {
  
  ll LCA(ll u, ll v) {
    while (u != v) {
      if (u > v) u >>= 1;
      else v >>= 1;
    }
    return u;
  }

  ll construct(const vector<ll> &vec) {
    vector<pair<ll, ll>> b;
    for (auto x : vec) {
      ll y = x;
      while (y < (1LL << 62)) y <<= 1;
      b.push_back({y, x});
    }
    //    vector<ll> a = vec;
    auto cmp = [](ll u, ll v) {
      ll tu = u, tv = v;
      while (u / 2 != v / 2) {
        if (u > v) u >>= 1;
        else v >>= 1;
      }
      if (u == v) {
        return u == tu;
      }
      return u < v;
    };
    auto cmp1 = [&cmp](ll u, ll v) {
      return u == v || cmp(u, v);
    };
    auto cmp2 = [&cmp1](ll u, ll v) {
      return cmp1(u, v) || LCA(u, v) == v;
    };
    sort(b.begin(), b.end());
    //    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i < (int)vec.size(); i++) {
      ll lca = LCA(b[i].second, b[i - 1].second);
      ll y = lca;
      while (y < (1LL << 62)) y <<= 1;
      b.push_back({y, lca});
      //      a.push_back(LCA(b[i], a[i - 1]));
    }
    //    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end());
    vector<ll> a(b.size());
    for (int i = 0; i < b.size(); i++) {
      a[i]= b[i].second;
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<ll> sd;
    ll ans = 0;
    for (auto v : a) {
      for (; !sd.empty() && !(cmp1(sd.back(), v) && cmp2(v, sd.back())); sd.pop_back());
      if (!sd.empty()) {
        ll t = v;
        while (t != sd.back()) {
          t /= 2;
          ans++;
        }
      }
      sd.push_back(v);
    }
    return ans;
  }

} // namespace AT

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  bool ff = false;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] == 1) ff = true;
  }
  if (!ff) a.push_back(1);
  cout << AT::construct(a) << endl;
  return 0;
}
