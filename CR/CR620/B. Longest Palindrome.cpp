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
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

signed main() {
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  rep(i, n) {
    cin >> S[i];
  }

  vector<bool> used(n, false);
  deque<int> ans;

  typedef pair<string, string> P;
  vector<P> p;
  rep(i, n) {
    repp(j, i + 1, n - 1) {
      if (used[i] || used[j])
        continue;

      auto temp = S[i];
      reverse(all(temp));
      if (temp == S[j]) {
        p.pb(mp(S[i], S[j]));
        used[i] = true, used[j] = true;
      }
    }
  }

  string center = "";
  rep(i, n) {
    if (used[i])
      continue;
    auto temp = S[i];
    reverse(all(temp));
    if (temp == S[i])
      center = temp;
  }

  int num = len(p) * 2 * m + len(center);
  cout << num << endl;
  rep(i, len(p)) {
    cout << p[i].fi;
  }
  cout << center;
  repr(i, len(p) - 1, 0) {
    cout << p[i].se;
  }
  cout << '\n';
}