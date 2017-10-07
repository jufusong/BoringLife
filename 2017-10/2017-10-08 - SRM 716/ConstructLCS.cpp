#include <bits/stdc++.h>

using namespace std;

class ConstructLCS {
public:
  string construct(int ab, int bc, int ca) {
    int tx = ab, ty = bc, tz = ca;
    vector<pair<int, int>> vec = {{ab, 1}, {bc, 2}, {ca, 3}};
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    ab = vec[0].first, bc = vec[1].first, ca = vec[2].first;
    string a = string(ca, '1') + string(ab, '0');
    string b = string(ab, '0') + string(bc, '1');
    string c = string(bc, '1');
    vector<pair<int, int>> v2 = {{tx + tz, 1}, {tx + ty, 2}, {ty + tz, 3}};
    sort(v2.begin(), v2.end());
    map<int, string> mp = {{v2[2].second, b}, {v2[1].second, a}, {v2[0].second, c}};
    return  mp[1] + " " + mp[2] + " " + mp[3];
  }
};

// CUT begin
ifstream data("ConstructLCS.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int ab, int bc, int ca, string __expected) {
    time_t startClock = clock();
    ConstructLCS *instance = new ConstructLCS();
    string __result = instance->construct(ab, bc, ca);
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
        int ab;
        from_stream(ab);
        int bc;
        from_stream(bc);
        int ca;
        from_stream(ca);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(ab, bc, ca, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507392794;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ConstructLCS (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
