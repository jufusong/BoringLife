#include <bits/stdc++.h>

namespace IO {
const int MT = 20 * 1024 * 1024; //modify size
char IO_BUF[MT];
int IO_PTR, IO_SZ;
//init
void begin() {
  IO_PTR = 0;
  IO_SZ = fread(IO_BUF, 1, MT, stdin);
}
template <typename T> inline bool scan_d(T &t) {
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' &&
         (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
    IO_PTR++;
  if (IO_PTR >= IO_SZ)
    return false;
  bool sgn = false;
  if (IO_BUF[IO_PTR] == '-')
    sgn = true, IO_PTR++;
  for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9';
       IO_PTR++)
    t = t * 10 + IO_BUF[IO_PTR] - '0';
  if (sgn)
    t = -t;
  return true;
}
inline bool scan_s(char s[]) {
  while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n')) IO_PTR++;
  if (IO_PTR >= IO_SZ) return false;
  int len = 0;
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n') s[len++] = IO_BUF[IO_PTR], IO_PTR++;
  s[len] = '\0';
  return true;
}
template <typename T> void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T> void println(T x) {
  print(x);
  putchar('\n');
}
}; // namespace IO

template<class T>
struct SparseTable {
  std::vector<std::vector<T>> f;
  std::vector<int> lg;
  SparseTable(){}
  SparseTable(const std::vector<T> &a) { init(a); }
  void init(const std::vector<T>& a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, std::vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

struct LCA {
  const std::vector<std::vector<int>>& g;
  SparseTable<std::pair<int, int>> st;
  std::vector<int> sp;
  std::vector<int> dep, dfn;

  LCA(const std::vector<std::vector<int>>& graph, int root = 1) : g(graph) {
    int sz = graph.size();
    dep = dfn = std::vector<int>(sz);
    dfs(root, -1, 0);
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < sp.size(); i++) {
      vec.emplace_back(dfn[sp[i]], sp[i]);
    }
    st.init(vec);
  }
  
  void dfs(int u, int fa, int d) {
    dep[u] = d + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u, d + 1);
        sp.push_back(u);
      }
    }
  }

  int query(int u, int v) {
    int l = dfn[u], r = dfn[v];
    if (l > r) std::swap(l, r);
    return st.query(l, r).second;
  }
};

struct FenwickTree {
  std::vector<long long> in;
  int N;
  FenwickTree() {}
  FenwickTree(int N) { init(N); }
  void init(int n) {
    N = n;
    in.assign(n + 1, 0);
  }
  int lowbit(int n) {return n & (-n);}
  void update(int p, long long val) {
    for (int i = p; i <= N; i += lowbit(i)) {
      in[i] += val;
    }
  }
  long long query(int p) {
    long long sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
};

using namespace std;

const int N = 300005;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct Matrix {
  static constexpr int md = mod;
  int rowCount, columnCount;
  vector<vector<int>> a;

  Matrix(int rowCount, int columnCount) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    a.assign(rowCount, vector<int>(columnCount));
  }
  
  static Matrix identityMatrix(int size) {
    Matrix result(size, size);
    for (int i = 0; i < size; i++) {
      result.a[i][i] = 1;
    }
    return result;
  }
  
  Matrix operator+(const Matrix &o) {
    assert(rowCount == o.rowCount);
    assert(columnCount == o.columnCount);
    Matrix result = *this;
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < columnCount; j++) {
        result.a[i][j] = (this->a[i][j] + o.a[i][j]) % md;
      }
    }
    return result;
  }

  Matrix operator*(const Matrix &o) {
    assert(columnCount == o.rowCount);
    Matrix result(rowCount, o.columnCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < o.columnCount; j++) {
        for (int k = 0; k < columnCount; k++) {
          result.a[i][j] = (result.a[i][j] + (long long)this->a[i][k] * o.a[k][j]) % md;
        }
      }
    }
    return result;
  }

  Matrix operator^(long long n) {
    assert(rowCount == columnCount);
    auto result = Matrix::identityMatrix(rowCount);
    auto t = *this;
    for (; n; n >>= 1, t = t * t) {
      if (n & 1) result = result * t;
    }
    return result;
  }
};

vector<Matrix> M;

void init_fib() {
  M.push_back(Matrix::identityMatrix(2));
  Matrix m(2, 2);
  m.a[0][0] = 0;
  m.a[0][1] = m.a[1][0] = m.a[1][1] = 1;
  for (int i = 0; i < N; i++) {
    M.push_back(M.back() * m);
  }
}

inline int cal_fib(int a, int b, int n) {
  return ((long long)a * M[n].a[0][0] + (long long)b * M[n].a[1][0]) % mod;
}

struct A {
  FenwickTree fwa, fwb;
  int N;

  void init(int n) {
    n += 3;
    fwa.init(n), fwb.init(n);
    N = n;
  }

  void update(int a, int b, int d) {
    d = min(d, N - 1);
    fwa.update(d + 1, a);
    fwb.update(d + 1, b);
  }

  pair<int, int> query(int p) {
    p = min(p, N);
    return {(fwa.query(N) - fwa.query(p)) % mod, (fwb.query(N) - fwb.query(p)) % mod};
  }
};

A fw[N];
map<int, A> son[N];
vector<pair<int, int>> ff[N];

vector<vector<int>> g;
int sz[N], d[N], st[N], root, minn, top;
bool done[N];

void init(int n) {
  for (int i = 1; i <= n; ++i) {
    fw[i] = A();
    son[i].clear();
    ff[i].clear();
  }
}

void dfs1(int u, int fa, int n) {
  sz[u] = 1;
  int mx = 0;
  for (auto v : g[u]) {
    if (v != fa && !done[v]) {
      dfs1(v, u, n);
      sz[u] += sz[v];
      mx = max(mx, sz[v]);
    }
  }
  mx = max(mx, n - sz[u]);
  if (mx < minn) {
    minn = mx;
    root = u;
  }
}

int solve(int u, int n, int fa) {
  minn = inf;
  dfs1(u, -1, n);
  u = root;
  dfs1(u, -1, n);
  if (fa != -1) {
    ff[u] = ff[fa];
    ff[u].push_back({fa, u});
  }
  fw[u].init(n);
  done[u] = true;
  for (auto v : g[u]) {
    if (!done[v]) {
      int dd = sz[v];
      int rson = solve(v, sz[v], u);
      son[u][rson].init(dd);
    }
  }
  done[u] = false;
  return u;
}

int main(int argc, char *argv[]) {
  IO::begin();
  init_fib();
  int T;
  IO::scan_d(T);
  while (T--) {
    int n, Q;
    IO::scan_d(n);
    IO::scan_d(Q);
    init(n);
    g = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      IO::scan_d(u);
      IO::scan_d(v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    LCA lca(g);
    solve(1, n, -1);
    while (Q--) {
      int tp;
      IO::scan_d(tp);
      if (tp == 1) {
        int u, k, a, b;
        IO::scan_d(u);
        IO::scan_d(k);
        IO::scan_d(a);
        IO::scan_d(b);
        fw[u].update(a, b, k);
        for (auto& e: ff[u]) {
          int root = e.first, rs = e.second;
          int l1 = lca.query(root, u);
          int d = lca.dep[u] + lca.dep[root] - 2 * lca.dep[l1];
          if (d <= k) {
            int ta = cal_fib(a, b, d);
            int tb = cal_fib(a, b, d + 1);
            fw[root].update(ta, tb, k - d);
            son[root][rs].update(-ta, -tb, k - d);
          }
        }
      } else {
        int u;
        IO::scan_d(u);
        int a, b;
        tie(a, b) = fw[u].query(0);
        int ans = cal_fib(a, b, 0);
        for (auto& e : ff[u]) {
          int root = e.first, rs = e.second;
          int l1 = lca.query(root, u);
          int d = lca.dep[u] + lca.dep[root] - 2 * lca.dep[l1];
          int ta, tb, xa, xb;
          tie(ta, tb) = fw[root].query(d);
          tie(xa, xb) = son[root][rs].query(d);
          ans = (ans + cal_fib(ta + xa, tb + xb, d)) % mod;
        }
        ans = (ans + mod) % mod;
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
