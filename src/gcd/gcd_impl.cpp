﻿#include "gcd.hpp"

namespace CYT_DSA {
int GCD::gcd1(int a, int b) {
  if (b == 0) return a;
  return gcd1(b, a % b);
}

int GCD::gcd2(int a, int b) {
  int t{};  // last a
  while (b != 0) {
    t = a;
    a = b;
    b = t % b;
  }
  return a;
}

int GCD::gcd3(int a, int b) {
  if (!a) return b;  // 注意边界条件
  if (!b) return a;
  int r = 0;
  while (!(a & 1) && !(b & 1)) {
    a >>= 1;
    b >>= 1;
    r++;
  }
  while (true) {
    while (!(a & 1)) a >>= 1;
    while (!(b & 1)) b >>= 1;
    if (a > b)
      a = a - b;
    else
      b = b - a;
    if (a == 0) return b << r;
    if (b == 0) return a << r;
  }
  return -1;  // 此步不可能执行
}

}  // namespace CYT_DSA