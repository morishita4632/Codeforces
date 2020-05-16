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
const int INF = 1001001001001001001ll;
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
#pragma endregion

struct R {
  ll l, r, len;
  R() = default;
  R(ll l, ll r) : l(l), r(r) {
    len = r - l + 1;
  }

  bool operator<(const R& another) const {
    return (len == another.len) ? (l > another.l) : (len < another.len);
  };
};

signed main() {
  int t;
  cin >> t;

  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> ans(n);

    priority_queue<R> q;
    q.push(R(0, n - 1));
    int i = 1;
    while (!q.empty()) {
      auto now = q.top();
      q.pop();
      int l = now.l, r = now.r;
      int m = (l + r) / 2;

      ans[m] = i++;
      int ml = m - 1, mr = m + 1;
      if (ml - l >= 0)
        q.push(R(l, ml));
      if (r - mr >= 0)
        q.push(R(mr, r));
    }
    cout << ans << endl;
  }
}