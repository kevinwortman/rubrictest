///////////////////////////////////////////////////////////////////////////////
// stats_solution.hpp
//
// Solution code for stats.hpp . This would be kept private to the
// instructor. If you run the tests against this code, they all pass.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>
#include <numeric>
#include <vector>

// Given a non-empty vector of numbers, return the maximum element.
int stat_max(const std::vector<int> numbers) {
  assert( !numbers.empty() );
  return *max_element(numbers.begin(), numbers.end());
}

// Given a non-empty vector of numbers, return the mean average.
int stat_mean(const std::vector<int> numbers) {
  assert( !numbers.empty() );
  return std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();
}

// Given a non-empty vector of numbers, return the median.
int stat_median(const std::vector<int> numbers) {
  assert( !numbers.empty() );
  
  std::vector<int> sorted(numbers);
  std::sort(sorted.begin(), sorted.end());

  int n = numbers.size(),
    middle = n / 2;
  
  if ( (n % 2) == 1 ) {
    // odd case
    return sorted[middle];
  } else {
    // even case
    return (sorted[middle - 1] + sorted[middle]) / 2;
  }

  return 0;
}
