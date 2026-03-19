ll hilbertOrder(ll x, ll y, ll pow) {
   if (pow == 0) return 0;
   //4分割する
   ll h = 1ll << (pow - 1); //基準値
   if (x < h) {
      if (y < h) {
         return h * h * 3 + hilbertOrder(y, x, pow - 1);
      }
      else {
         return h * h * 0 + hilbertOrder(2 * h - y - 1, h - x - 1, pow - 1);
      }
   }
   else {
      if (y < h) {
         return h * h * 2 + hilbertOrder(x - h, y, pow - 1);
      }
      else {
         return h * h * 1 + hilbertOrder(x - h, y - h, pow - 1);
      }
   }
}
