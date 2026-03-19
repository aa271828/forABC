using S = pll;
using F = ll;
S op(S a, S b) {
   if (a.first < b.first) return a;
   if (b.first < a.first) return b;
   return {a.first, a.second + b.second};
}
S e() {
   return S({INF, 0});
}
S mapping(F f, S x) {
   return {x.first + f, x.second};
}
F composition(F f, F g) {
   return f + g;
}
F id() {
   return 0;
}
struct segtree {
   ll N=1ll<<32;
   ll H=32;
   struct Node {
      ll l;
      ll r;
      ll h;
      S data;
      F lazy;
      Node(ll hh) {
         l = -1;
         r = -1;
         h = hh;
         data = {0,1ll<<(32-h)};
         lazy = id();
      }
   };
   vector<Node> D;
   ll new_node(ll h) {
      D.push_back(Node(h));
      return D.size() - 1;
   }
   segtree() {
      new_node(0);
   }
   //反映
   void node_apply(ll idx, F f) {
      D[idx].data = mapping(f, D[idx].data);
      D[idx].lazy = composition(D[idx].lazy, f);
   }
   //伝搬
   void push(ll idx) {
      if (D[idx].l == -1) D[idx].l = new_node(D[idx].h+1);
      if (D[idx].r == -1) D[idx].r = new_node(D[idx].h+1);
      node_apply(D[idx].l, D[idx].lazy);
      node_apply(D[idx].r, D[idx].lazy);
      D[idx].lazy = id();
   }
   void pull(ll idx) {
      D[idx].data = op(D[D[idx].l].data, D[D[idx].r].data);
   }

   void apply_inner(ll idx, ll L, ll R, ll ql, ll qr, F f) {
      if (qr <= L || R <= ql) return;
      if (ql <= L && R <= qr) {
         node_apply(idx, f);
         return;
      }
      push(idx);
      ll mid = (L + R) / 2;
      apply_inner(D[idx].l, L, mid, ql, qr, f);
      apply_inner(D[idx].r, mid, R, ql, qr, f);
      pull(idx);
   }
   void apply(ll l, ll r, F f) {
      apply_inner(0, 0, N, l, r, f);
   }
   S prod_inner (ll idx, ll L, ll R, ll ql, ll qr) {
      if (qr<=L || R <= ql) return e();
      if (ql<=L && R <= qr) return D[idx].data;
      push(idx);
      ll mid = (L + R) / 2;
      return op(prod_inner(D[idx].l, L, mid, ql, qr), prod_inner(D[idx].r, mid, R, ql, qr));
   }
   S prod(ll l, ll r) {
      return prod_inner (0, 0, N, l, r);
   }
   void set_point_inner(ll idx, ll L, ll R, ll pos, S x) {
      if (R - L == 1) {
         D[idx].data = x;
         return ;
      }
      push(idx);
      ll mid = (L + R) / 2;
      if (pos < mid) {
         set_point_inner(D[idx].l, L, mid, pos, x);
      }
      else {
         set_point_inner(D[idx].r, mid, R, pos, x);
      }
      pull(idx);
   }
   void set(ll idx, S x) {
      set_point_inner(0, 0, N, idx, x);
   }
};
