#include <atcoder/convolution>
vl operator * (const vl &a, const vl &b) {
   vl ret = atcoder::convolution(a, b);
  return ret;
}
vl operator + (const vl &a, const vl &b) {
   vl ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size())(ret[i] += b[i]) %= MOD;
   return ret;
}
vl operator - (const vl &a, const vl &b) {
   vl ret = a;
   ret.resize(max(a.size(), b.size()));
   rep(i,0,b.size())(ret[i] -= b[i]) %= MOD;
   return ret;
}
vl even(vl a) {
   vl ret;
   rep(i,0,(a.size() + 1) / 2) ret.push_back(a[2 * i]);
   return ret;
}
vl odd(vl a) {
   vl ret;
   rep(i,0,a.size() / 2) ret.push_back(a[2 * i + 1]);
   return ret;
}
vl mainasu(vl a) {
   rep(i,0,a.size() / 2) a[2 * i + 1] = (-a[2 * i + 1])%MOD;
   return a;
}
ll bostan_mori (vl p, vl q, ll n) {
   if (n == 0) return p[0] * minv(q[0]) % MOD;
   vl q0 = even(q), q1 = odd(q);
   vl r = p * mainasu(q);
   vl r0 = even(r), r1 = odd(r);
   vl s = q0 * q0 - vl({0, 1}) * q1 * q1;
   if (n % 2 == 0) return bostan_mori(r0, s, n / 2);
   else return bostan_mori(r1, s, (n - 1) / 2);
}
