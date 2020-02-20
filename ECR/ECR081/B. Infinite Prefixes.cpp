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

template <typename T>
struct nvector {
  int edge, tot;
  vector<T> vec;

  nvector(int edge) : edge(edge), tot(edge * 2 + 1), vec(tot) {
  }
  nvector(int edge, T init) : edge(edge), tot(edge * 2 + 1), vec(tot, init) {
  }

  T& operator[](int pos) {
    return vec[pos + edge];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const nvector<T>& nvector) {
  s << nvector.vec;
  return s;
}

signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    vector<int> cnt(n);
    cnt[0] = (s[0] == '0' ? 1 : -1);
    repp(i, 1, n - 1) {
      cnt[i] = cnt[i - 1] + (s[i] == '0' ? 1 : -1);
    }

    if (cnt[n - 1] == 0) {
      bool exist = false;
      rep(i, n) {
        if (cnt[i] == x)
          exist = true;
      }

      if (exist)
        cout << -1 << '\n';
      else
        cout << 0 << endl;
    } else {
      map<int, int> m;
      rep(i, n) {
        m[cnt[i]]++;
      }
      int ans = 0;
      if (x == 0)
        ans++;

      repp(i, -100000, 100000) {
        if ((x - i) % cnt[n - 1] == 0 && (x - i) / cnt[n - 1] >= 0) {
          if (m.find(i) != m.end())
            ans += m[i];
        }
      }
      cout << ans << endl;
    }
  }
}
