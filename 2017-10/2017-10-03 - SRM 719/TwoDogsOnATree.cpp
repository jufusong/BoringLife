#include <bits/stdc++.h>

using namespace std;

class TwoDogsOnATree {
public:
  int maximalXorSum(vector<int> parent, vector<int> W) {
    int n = parent.size() + 1;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
      g[parent[i] + 1].push_back({i + 2, W[i]});
    }
    vector<int> a(n + 1);
    for (int u = 1; u <= n; u++) {
      for (auto e : g[u]) {
        int v = e.first, w = e.second;
        a[v] = a[u] ^ w;
      }
    }
    vector<bool> b(1024, false);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        b[a[i] ^ a[j]] = true;
      }
    }
    int mx = 0;
    for (int i = 0; i < 1024; i++) {
      for (int j = 0; j < 1024; j++) {
        if (b[i] && b[j]) {
          mx = max(mx, i ^ j);
        }
      }
    }
    return mx;
  }
};

// CUT begin
ifstream data("TwoDogsOnATree.sample");

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

bool do_test(vector<int> parent, vector<int> w, int __expected) {
    time_t startClock = clock();
    TwoDogsOnATree *instance = new TwoDogsOnATree();
    int __result = instance->maximalXorSum(parent, w);
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
        vector<int> parent;
        from_stream(parent);
        vector<int> w;
        from_stream(w);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, w, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507029196;
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
        cout << "TwoDogsOnATree (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
