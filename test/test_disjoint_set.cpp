#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <diy/dsa/disjoint_set.hpp>
TEST_CASE("test_disjoint_set", "[disjoint_set]") {
  diy::DisjointSet set(10);
  set.union_set(1, 3);
  REQUIRE(set.find(1) == set.find(3));
  REQUIRE(set.find(1) != set.find(5));
  set.union_set(1, 5);
  set.union_set(5, 9);
  REQUIRE(set.find(1) == set.find(9));
  REQUIRE(set.find(3) == set.find(9));
}