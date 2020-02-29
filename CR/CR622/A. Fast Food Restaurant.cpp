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

signed main() {
  int t;
  cin >> t;
  vector<vector<int>> combi(7, vector<int>(3));
  rep(b, bit(3)) {
    if (b == 0)
      continue;
    rep(i, 3) {
      combi[b - 1][i] = (b >> i) & 1;
    }
  }

  while (t-- > 0) {
    vector<int> A(3);
    rep(i, 3) {
      cin >> A[i];
    }
    vector<int> a(7);
    iota(all(a), 0);

    int ans = 0;
    do {
      int cnt = 0;
      auto B = A;
      rep(i, 7) {
        bool ok = true;
        rep(j, 3) {
          if (B[j] == 0 && combi[a[i]][j])
            ok = false;
        }
        if (ok) {
          cnt++;
          rep(j, 3) {
            B[j] -= combi[a[i]][j];
          }
        }
      }
      chmax(ans, cnt);
    } while (next_permutation(all(a)));
    cout << ans << endl;
  }
}