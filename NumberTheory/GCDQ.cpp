#include <iostream>
using namespace std;
#define ll long long int

ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

void solve(){
  int n, q;
  cin >> n >> q;
  ll *a = new ll[n+1];
  for(int i = 1; i <= n; i++) cin >> a[i];
  ll *pgcd = new ll[n+1];
  ll *sgcd = new ll[n+1];
  pgcd[1] = a[1];
  for(int i = 2; i <= n; i++){
    pgcd[i] = gcd(a[i], pgcd[i-1]);
  }
  sgcd[n] = a[n];
  for(int i = n-1; i > 0; i--){
    sgcd[i] = gcd(a[i], sgcd[i+1]);
  }
  int l, r;
  ll *temp = new ll[q];
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    if(l == 1) temp[i] = sgcd[r+1];
    else if(r == n) temp[i] = pgcd[l-1];
    else temp[i] = gcd(pgcd[l-1], sgcd[r+1]);
  }
  for(int i = 0; i < q; i++) cout << temp[i] << endl;
}

int main(void){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
