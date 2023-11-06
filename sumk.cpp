#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll sum = 0;
ll n, k;
vector<ll> arr;
vector<ll> subset;

ll power(ll base, ll exponent, ll mod){
  ll ans = 1;
  for (ll i = static_cast<ll>(floor(log(exponent)/log(2))); i >= 0; --i){
    ans *= ans;
    ans %= mod;
    if (exponent & (1 << i)){
      ans *= base;
    }
    ans %= mod;
  }
  return ans;
}

void search(ll index){
  if (index == n){
    ll sub_sum = 0;
    for (ll &i : subset){
      sub_sum += i;
      sub_sum %= 998244353;
    }
    sum += power(sub_sum, k, 998244353);
    sum %= 998244353;
  }else{
    search(index + 1);
    subset.push_back(arr[index]);
    search(index + 1);
    subset.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n >> k;
  arr.resize(n);
  for (ll i = 0; i < n; ++i){
    ll number;
    cin >> number;
    arr[i] = number % 998244353;
  }
  search(0);
  cout << sum;
  return 0;
}
