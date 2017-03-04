/*
*  Author : __daemon 
*  Problem : https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/choosing-the-judges-7/description/
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 1000000009
#define rep(i,n) for(int i=0;i<n;i++)
#define fr first
#define sc second
#define clr(a) memset(a,0LL,sizeof a);
#define sn(t) scanf("%lld",&t)
#define pn(t) printf("%lld",t)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool isalpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}

ll modpow(ll base,ll exp,ll mod){
  ll ret=1;
  base=base%mod;
  while(exp){
    if(exp&1)ret *= base ;
    base *= base;
    exp>>=1LL;
  }
  return ret;
}

map<ll,ll> m;

void solve(){
  ll t,count=0;
  sn(t);
  while(t--){
    ll n,i;
    sn(n);
    ll a[n];
    rep(i,n){
        sn(a[i]);
    }
    ll dp[n][2];
    dp[0][0] = 0LL;
    dp[0][1] = a[0];
    for(i = 1 ; i < n ; i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = a[i] + dp[i-1][0];
    }
    printf("Case %lld: ",++count);
    pn(max(dp[n-1][0],dp[n-1][1]));
    printf("\n");
  }
}


int main(){
  std::ios::sync_with_stdio(false);
  solve();
} 
