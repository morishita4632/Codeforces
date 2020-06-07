#pragma region head
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
#pragma endregion

int btoi(string s) {
  int res = 0;
  for (char c : s) {
    res *= 2;
    res += c - '0';
  }
  return res;
}

string itob(int n, int m) {
  string res;
  while (m-- > 0) {
    res.pb('0' + n % 2);
    n /= 2;
  }
  reverse(all(res));
  return res;
}

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    vector<int> b(n);
    set<int> st;

    rep(i, n) {
      cin >> a[i];
      b[i] = btoi(a[i]);
      st.insert(b[i]);
    }

    int mn = 0, mx = bit(m) - 1;

    int ok = 0, ng = mx + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      int l = (mid - 1) - mn + 1;
      int r = mx - (mid + 1) + 1;

      rep(i, n) {
        if (b[i] < mid)
          l--;

        if (b[i] > mid)
          r--;
      }

      (l <= r ? ok : ng) = mid;
    }

    while (true) {
      if (st.find(ok) == st.end()) {
        cout << itob(ok, m) << endl;
        break;
      }
      ok--;
    }
  }
}