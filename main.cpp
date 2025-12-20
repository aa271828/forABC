#include<bits/stdc++.h>
using namespace std;
using ll = long long;//int型は使わない
using pll = pair<ll , ll>;
using vl = vector<ll> ; //1D
using vvl = vector<vl> ;//2D
using vvvl = vector<vvl> ;//3D
using vvvvl = vector<vvvl>;//4D
using vvvvvl = vector<vvvvl>;//5D
using vvvvvvl = vector<vvvvvl>;//6D
using vvvvvvvl = vector<vvvvvvl>;//7D
using vp = vector<pll> ; //1D
using vvp = vector<vp> ;//2D
using vvvp = vector<vvp> ;//3D
using vvvvp = vector<vvvp>;//4D
using vvvvvp = vector<vvvvp>;//5D
using vvvvvvp = vector<vvvvvp>;//6D
using vvvvvvvp = vector<vvvvvvp>;//7D
using vi = vector<int> ; //1D
using vvi = vector<vi> ;//2D
using vvvi = vector<vvi> ;//3D
using vvvvi = vector<vvvi>;//4D
using vvvvvi = vector<vvvvi>;//5D
using vvvvvvi = vector<vvvvvi>;//6D
using vvvvvvvi = vector<vvvvvvi>;//7D
using vb = vector<bool> ; //1D
using vvb = vector<vb> ;//2D
using vvvb = vector<vvb> ;//3D
using vvvvb = vector<vvvb>;//4D
using vvvvvb = vector<vvvvb>;//5D
using vvvvvvb = vector<vvvvvb>;//6D
using vvvvvvvb = vector<vvvvvvb>;//7D
using vs = vector<string> ; //1D
using vvs = vector<vs> ;//2D
using vvvs = vector<vvs> ;//3D
using vvvvs = vector<vvvs>;//4D
using vvvvvs = vector<vvvvs>;//5D
using vvvvvvs = vector<vvvvvs>;//6D
using vvvvvvvs = vector<vvvvvvs>;//7D
[[maybe_unused]] const ll INF = 2e18 ;
[[maybe_unused]] const ll MOD = 998244353;
#define rep(i,a,b) for(ll i=(ll)a; i<(ll)b; i++)
#define rrep(i,a,b) for(ll i=(ll)b-1; i>=(ll)a; i--)
#define all(vec1) (vec1).begin(), (vec1).end()
#define yn(b,ex) if(1){if(b)cout << "Yes" << endl;else cout << "No" << endl ;if(ex)return 0;}
#define debug(var) cerr << #var << " : " << var << endl;

//fastio
struct FastIO {
    FastIO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} fastio;
//あまり(負の数対応)
template<typename T>
T ovr(T a,T b){
  T ret=a%b;
  if(ret<0)ret+=b;
  return ret;
}
const string MOD_bi = "111111111111111111111110110111";
//MOD下での逆元
ll minv(ll ina){
  ll a = ina % MOD;
  ll ret = 1;
  ll V = a;
  rep(i,0,MOD_bi.size()){
    if(MOD_bi[i]=='1')ret=(ret*V)%MOD;
    V=(V*V)%MOD;
  }
  return ret;
}

//指数をある値で割った余り
ll mpow(ll a , ll b , ll M){
    ll ret = 1;
    ll V = a;
    rep(i,0,64){
        if((b >> i) & 1)ret=(ret*V)%M;
        V=(V*V)%M;
    }
    return ret;
}
template<typename T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<typename T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
/////////main/////////

int main()
{
    
    return 0;
}
