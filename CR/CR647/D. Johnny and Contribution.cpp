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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<int>> g(n);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    g[a[i]].pb(b[i]);
    g[b[i]].pb(a[i]);
  }
  vector<int> t(n);
  typedef pair<int, int> P;
  vector<P> pr(n);

  rep(i, n) {
    cin >> t[i];
    t[i]--;
    pr[i] = P(t[i], (i + 1));
  }

  bool ok = true;
  rep(i, n) {
    int T = t[i];
    vector<bool> exist(T + 1, false);
    for (int j : g[i]) {
      if (t[j] <= T)
        exist[t[j]] = true;
    }

    bool OK = true;
    rep(j, T) {
      if (!exist[j])
        OK = false;
    }
    if (exist[T])
      OK = false;

    if (!OK)
      ok = false;
  }

  if (!ok) {
    cout << -1 << '\n';
    return 0;
  }

  sort(all(pr));
  vector<int> p(n);
  rep(i, n) {
    p[i] = pr[i].se;
  }
  cout << p << endl;
}