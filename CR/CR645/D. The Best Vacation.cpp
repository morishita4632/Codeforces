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

int s(int num) {
  return (num * (num + 1)) / 2;
}

signed main() {
  int n, x;
  cin >> n >> x;

  int m = 2 * n;
  vector<int> d(m);
  rep(i, n) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  reverse(all(d));

  vector<int> sum(m + 1), hug(m + 1);
  rep(i, m) {
    sum[i + 1] = sum[i] + d[i];
    hug[i + 1] = hug[i] + s(d[i]);
  }

  int ans = 0;
  rep(i, n) {
    auto iter = upper_bound(all(sum), sum[i] + x);
    int ind = distance(sum.begin(), iter);

    int temp = hug[ind - 1] - hug[i];
    int res = x - (sum[ind - 1] - sum[i]);
    temp += s(d[ind - 1]) - s(d[ind - 1] - res);
    chmax(ans, temp);
  }

  cout << ans << endl;
}