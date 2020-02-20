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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}

// 1~xまででdと互いに素な個数
int f(int x, int d) {
  auto m = prime_factor(d);
  vector<int> div;
  for (auto item : m) {
    auto Fi = item.fi;
    auto Se = item.se;
    div.pb(Fi);
  }

  int n = len(div);

  int res = 0;
  rep(b, bit(n)) {
    int num = __builtin_popcount(b);
    int divisor = 1;
    rep(i, n) {
      if ((b >> i) & 1)
        divisor *= div[i];
    }
    res += x / divisor * (num % 2 ? -1 : 1);
  }

  return res;
}

signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int a, m;
    cin >> a >> m;
    int GCD = gcd(a, m);
    a /= GCD, m /= GCD;
    int ans = f(m + a - 1, m) - f(a - 1, m);
    cout << ans << endl;
  }
}