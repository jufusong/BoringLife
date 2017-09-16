#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAXL = 2;

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % mod) {
    if (m & 1) ans = ans * n % mod;
  }
  return ans;
}

struct MAT{
  int len;
  ll a[MAXL][MAXL];
  MAT(int l = MAXL){
    memset(a, 0, sizeof(a));
    len = l;
  }
  friend MAT operator * (const MAT& x, const MAT& y){
    int len = x.len;
    MAT ans(len);
    for(int i = 0; i < len; i ++){
      for(int j = 0; j < len; j ++){
        for(int k = 0; k < len; k ++){
          ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]) % mod;
        }
      }
    }
    return ans;
  }
  friend MAT operator ^ (const MAT& x, ll n){
    int len = x.len;
    MAT ans(len);
    MAT a = x;
    for(int i = 0; i < len; i ++){
      ans.a[i][i] = 1;
    }
    while (n){
      if (n & 1){
        ans = ans * a;
      }
      a = a * a;
      n >>= 1;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    ll p, q, k;
    cin >> p >> q >> k;
    ll t = powMod(p, mod - 2, mod);
    MAT mat(2);
    mat.a[0][0] = mat.a[1][1] = (p - q) * t % mod;
    mat.a[0][1] = mat.a[1][0] = q * t % mod;
    mat = (mat ^ k);
    cout << mat.a[0][0] << endl;
  }
  return 0;
}
