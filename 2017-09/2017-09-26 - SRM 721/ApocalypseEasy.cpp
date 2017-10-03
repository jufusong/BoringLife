#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int M = 2000000;
const int inf = 1e9;

struct Edge {
  int v, w, next;
} g[M];
int cnt = 0, head[N], st, ed, dis[N], cur[N];
void init() {
  memset(head, -1, sizeof(head));
  cnt = 0;
}
void addedge(int u, int v, int w = 1) {
  g[cnt].v = v, g[cnt].w = w, g[cnt].next = head[u], head[u] = cnt++;
  g[cnt].v = u, g[cnt].w = 0, g[cnt].next = head[v], head[v] = cnt++;
}
bool bfs() {
  memset(dis, -1, sizeof(dis));
  dis[st] = 0;
  std::queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; ~i; i = g[i].next) {
      int v = g[i].v, w = g[i].w;
      if (w && dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
        if (v == ed)
          return true;
      }
    }
  }
  return false;
}
int dfs(int u, int limit) {
  if (u == ed)
    return limit;
  int ans = 0;
  for (int &i = cur[u]; ~i; i = g[i].next) {
    int v = g[i].v, w = g[i].w;
    if (w && dis[v] == dis[u] + 1) {
      int t = dfs(v, std::min(limit - ans, w));
      g[i].w -= t;
      g[i ^ 1].w += t;
      ans += t;
      if (ans == limit)
        break;
    }
  }
  if (!ans)
    dis[u] = -1;
  return ans;
}
int dinic(int n) {
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++)
      cur[i] = head[i];
    ans += dfs(st, inf);
  }
  return ans;
}

class ApocalypseEasy {
public:
  int maximalSurvival(vector<int> p, vector<int> position, int t) {
    int n = p.size() + 1;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      g[p[i]].push_back(i + 1);
      g[i + 1].push_back(p[i]);
    }
    init();
    st = n * (t + 1) * 2 + 1, ed = n * (t + 1) * 2 + 2;
    int mm = n * (t + 1);
    set<int> se;
    for (auto x : position) {
      addedge(st, x + 1, 1);
      se.insert(x + 1);
    }
    for (int i = 0; i <= t; i++) {
      for (int j = 1; j <= n; j++) {
        addedge(n * i + j, mm + n * i + j, 100);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!se.count(i)) {
        addedge(mm + n * t + i, ed, 1);
      }
    }
    for (int i = 0; i < n; i++) {
      g[i].push_back(i);
    }
    for (int i = 0; i < t; i++) {
      for (int j = 1; j <= n; j++) {
        for (auto x : g[j - 1]) {
          int v = x + 1;
          addedge(mm + n * i + j, n * (i + 1) + v, 100);
        }
      }
    }
    return dinic(ed);
  }
};

// CUT begin
ifstream data("ApocalypseEasy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> p, vector<int> position, int t, int __expected) {
    time_t startClock = clock();
    ApocalypseEasy *instance = new ApocalypseEasy();
    int __result = instance->maximalSurvival(p, position, t);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> p;
        from_stream(p);
        vector<int> position;
        from_stream(position);
        int t;
        from_stream(t);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, position, t, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506474663;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ApocalypseEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
