#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll pow(ll x, ll y) {
    x %= MOD;
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return  ret;
}

ll inv(ll x) {
    return pow(x, MOD - 2);
}

ll pyr(ll x) {
    if (x <= 0) return 0;
    x %= MOD;
    return x * (x + 1) % MOD * (x + 2) % MOD * inv(6) % MOD;
}

ll f(ll a, ll b, ll c) { 
    return pyr(c - 1) - pyr(c - b - 1) - pyr(c - a - 1) + pyr(c - a - b - 1); 
} 

class TriangleTriples {
    public:
    int count(int A, int B, int C) {
        ll ans = 1LL * A * B % MOD * C % MOD;
        ans = (ans - f(A, B, C) + MOD) % MOD;
        ans = (ans - f(B, C, A) + MOD) % MOD;
        ans = (ans - f(C, A, B) + MOD) % MOD;
        return ans;
    }
};

// CUT begin
ifstream data("TriangleTriples.sample");

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

bool do_test(int A, int B, int C, int __expected) {
    time_t startClock = clock();
    TriangleTriples *instance = new TriangleTriples();
    int __result = instance->count(A, B, C);
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
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int C;
        from_stream(C);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499513395;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TriangleTriples (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end