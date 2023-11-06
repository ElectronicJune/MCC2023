#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Card{
  ll a, b, c, d;
  ll all_sum, part_sum;
  Card(ll p, ll q, ll r, ll s): a(p), b(q), c(r), d(s){
    all_sum = a + b + c + d;
    part_sum = a + b;
  } 
};

bool comparePart(Card &x, Card &y){
  return x.part_sum < y.part_sum;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  ll n, m;
  cin >> n >> m;
  vector<Card> cards;
  for (ll i = 0; i < n; ++i){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cards.push_back(Card(a, b, c, d));
  }
  sort(cards.rbegin(), cards.rend(), comparePart);
  ll max_sum = 0;
  for (ll i = 0; i < n; ++i){
    ll sum = 0;
    for (ll j = 0; j < m - (i >= m); ++j){
      if (j != i){
        sum += cards[j].part_sum;
      }
    }
    sum += cards[i].all_sum;
    max_sum = max(max_sum, sum);
  }
  cout << max_sum;
  return 0;
}