/*
  apply, prodはverify済みだがやり途中
*/
//区間加算最小値取得クエリ
struct S {
   ll cnt10;
   ll cnt01;
   ll cnt0;
   ll cnt1;
};
using F = bool;
struct segtree {
   S op(S a, S b) {
      S ret;
      ret.cnt10 = a.cnt10 + b.cnt10 + a.cnt1 * b.cnt0;
      ret.cnt01 = a.cnt01 + b.cnt01 + a.cnt0 * b.cnt1;
      ret.cnt0 = a.cnt0 + b.cnt0;
      ret.cnt1 = a.cnt1 + b.cnt1;
      return ret;
   }
   S e() {
      return S({0,0,0,0});
   }
   S mapping(F f, S x) {
      return f ? S({x.cnt01, x.cnt10, x.cnt1, x.cnt0}) : x;
   }
   F composition(F f, F g) {
      return f ^ g;
   }
   F id() {
      return 0;
   }

   int N;
   int H;
   vector<S> data;
   vector<F> lazy;
   segtree(int n) {
      N = 1;
      H = 0;
      while (N < n) N <<= 1, H++;
      data.assign(N << 1, e());
      lazy.assign(N << 1, id());
   }
   //伝搬
   void all_apply(int idx, F f) {
      lazy[idx] = composition(lazy[idx], f);
      data[idx] = mapping(f, data[idx]);
   }
   void push(int idx) {
      all_apply(idx << 1, lazy[idx]);
      all_apply(idx << 1 | 1, lazy[idx]);
      lazy[idx] = id();
   }
   void prop(int l, int r) {
      for (int i = H; i ; i--) {
         if (((l>>i) << i) != l) { push((N + l) >> i); }
         if (((r>>i) << i) != r) { push((N + r - 1) >> i); }
      }
   }

   void apply(int l, int r, F f) {
      prop(l, r);
      int L = l + N, R = r + N;
      while (L < R) {
         if (R & 1) {
            R--;
            all_apply(R, f);
         }
         if (L & 1) {
            all_apply(L, f);
            L++;
         }
         R >>= 1; L >>= 1;
      }

      for (int i = 1; i <= H; i++) {
         if (((l>>i) << i) != l) {
            int idx = (N + l) >> i;
            data[idx] = op(data[idx << 1], data[idx << 1 | 1]);
         }
         if (((r>>i) << i) != r)  {
            int idx = (N + r - 1) >> i;
            data[idx] = op(data[idx << 1], data[idx << 1 | 1]);
         }
      }
   }
   S prod (int l, int r) {
      prop(l, r);
      S ans1 = e();
      S ans2 = e();
      int L = l + N, R = r + N;
      while (L < R) {
         if (R & 1) {
            R--;
            ans1 = op(data[R], ans1);
         }
         if (L & 1) {
            ans2 = op(ans2, data[L]);
            L++;
         }
         R >>= 1; L >>= 1;
      }
      return op(ans2, ans1);
   }
   void set (int i, S x) {
      i += N;
      data[i] = x;
      i >>= 1;
      while (i > 0) {
         data[i] = op(data[i << 1] , data[i << 1 | 1]);
         i >>= 1;
      }
   }
};
