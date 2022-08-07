// 010-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "diy/dsa/segment_tree.hpp"
#include "diy/dsa/segment_tree_2.hpp"
TEST_CASE("test_segment_tree") {
  using namespace diy;
  std::vector<int> inputs{1, 3, 5, 7, 9};

  diy::SegmentTree tree(inputs);

  SECTION("test range sum of [L,R)") {
    REQUIRE(tree.query(0, 1) == 1);
    REQUIRE(tree.query(1, 3) == 8);
    REQUIRE(tree.query(3, 5) == 16);
    REQUIRE(tree.query(1, 5) == 24);
  }
  SECTION("update some value") {
    tree.update(2, 4);
    tree.update(4, 6);
    //{1,3,4,7,6}
    REQUIRE(tree.query(0, 1) == 1);
    REQUIRE(tree.query(1, 3) == 7);
    REQUIRE(tree.query(3, 5) == 13);
    REQUIRE(tree.query(1, 5) == 20);
  }
}

TEST_CASE("test segment tree v2") {
  using namespace diy;
  std::vector<int> inputs{1, 3, 5, 7, 9};

  diy::SegmentTree2 tree(inputs);

  SECTION("test range sum of [L,R)") {
    REQUIRE(tree.query(0, 1) == 1);
    REQUIRE(tree.query(1, 3) == 8);
    REQUIRE(tree.query(3, 5) == 16);
    REQUIRE(tree.query(1, 5) == 24);
  }
  SECTION("update some value") {
    tree.update(2, 4);
    // tree.update(4, 6);
    //{1,3,4,7,6}
    // REQUIRE(tree.query(0, 1) == 1);
    // REQUIRE(tree.query(1, 3) == 7);
    // REQUIRE(tree.query(3, 5) == 13);
    // REQUIRE(tree.query(1, 5) == 20);
  }
}