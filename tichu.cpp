#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  ll n, m;
  cin >> n >> m;
  if (n == m){
    cout << n;
    return 0;
  }
  set<ll> cards_set;
  for (ll i = 0; i < n - m; ++i){
    ll card;
    cin >> card;
    cards_set.insert(card); 
  }
  vector<ll> cards(cards_set.begin(), cards_set.end());
  ll max_run = 0;
  for (int i = 0; i < cards.size() - 1; ++i){
    ll j = i + 1;
    ll run = 1;
    ll next_elem = cards[i] + 1;
    ll wild = m;
    while (j < cards.size() && cards[j] == next_elem || wild > 0){
      if (j < cards.size() && next_elem == cards[j]){
        ++run;
        ++j;
        ++next_elem;
      }else{
        --wild;
        ++run;
        ++next_elem;
      }
    }
    max_run = max(max_run, run);
  }
  cout << max_run;
  return 0;
}