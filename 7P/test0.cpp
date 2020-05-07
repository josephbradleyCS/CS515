#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
  Map m;
  m.insert("a", "a");
  m.insert("b", "b");
  assert(m.size() == 2);
}
