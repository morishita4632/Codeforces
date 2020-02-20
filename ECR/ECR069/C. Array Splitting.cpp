#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> diff(n - 1);
  repp(i, 0, n - 2) { diff[i] = a[i + 1] - a[i]; }

  sort(all(diff), greater<int>());
  ll ans = 0;
  repp(i, k - 1, n - 2) { ans += diff[i]; }
  cout << ans << endl;
}