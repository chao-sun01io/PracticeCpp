#include <algorithm>
#include <iostream>
#include <ostream>
#include <random>
#include <vector>

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_vector.hpp"
#include "diy/dsa/merge_sort.hpp"

class SortFixture {
 public:
  SortFixture() : data(150) {
    // fill the vectors with random numbers
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(-100000, 100000);

    std::generate(data.begin(), data.end(), std::bind(dis, std::ref(mt)));
    sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
  }

 protected:
  std::vector<int> data;
  std::vector<int> sorted_data;
};

TEST_CASE_METHOD(SortFixture, "[sort][mergeSort]") {
  mergeSort(data);
  REQUIRE_THAT(data, Catch::Matchers::Equals(sorted_data));
}