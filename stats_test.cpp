///////////////////////////////////////////////////////////////////////////////
// stats_test.cpp
//
// Example of unit test for the stats.hh assignment.
//
///////////////////////////////////////////////////////////////////////////////

#include "rubrictest.hpp"

// Change this to "stats_solution.hh" to try testing the solution
// code.
#include "stats.hpp"

#include <algorithm>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

// Named function to test the stat_max function.
void test_stat_max() {
  // Example of exhaustively testing random numbers.
  const int MAX_LENGTH = 1000, TRIALS = 100;
  std::default_random_engine rng;
  std::uniform_int_distribution<int> length_dist(1, MAX_LENGTH);
  std::uniform_int_distribution<double> num_dist(0, 1000000);
  for (int i = 0; i < TRIALS; i++) {
    vector<int> numbers;
    int n = length_dist(rng);

    for (int j = 0; j < n; j++) {
      numbers.push_back(num_dist(rng));
    }

    stringstream message;
    message << "stat_max() of random vector with " << n << " elements";
    TEST_EQUAL(message.str(),
	       *max_element(numbers.begin(), numbers.end()),
	       stat_max(numbers));
  }
}

int main() {
  Rubric rubric;

  // Example of adding a criterion with a declared test function. This
  // is an easier part of the assignment so is only weighted for 1
  // point.
  rubric.criterion("max function", 1, test_stat_max);

  // Create some test data that can be used in multiple test
  // functions below.
  vector<int> one, five, six;
  one.push_back(1);
  for (int i = 1; i <= 6; i++) {
    if (i <= 5) {
      five.push_back(i);
    }
    six.push_back(i);
  }
  
  // Example of adding a criterion with a lambda-expression test
  // function. This is more concise but potentially confusing for
  // instructors unfamiliar with lambda expressions. This is more
  // difficult and weighted for 2 points.
  rubric.criterion("mean function", 2,
		   [&]() {
		     TEST_EQUAL("mean of one element", 1, stat_mean(one));
		     TEST_EQUAL("mean of five elements", (1+2+3+4+5)/5, stat_mean(five));
		     TEST_EQUAL("mean of five elements", (1+2+3+4+5+6)/6, stat_mean(six));
		   });

  // The median function has a different definition for odd-length and
  // even-length vectors. This rubric breaks those out as separate
  // criteria, so that an assignment that handles one case but not the
  // other can get partial credit. If you preferred you could merge
  // these into one criterion, and then the whole thing would be
  // all-or-nothing.
  rubric.criterion("median (odd case)", 1,
		   [&]() {
		     TEST_EQUAL("median of one element", 1, stat_median(one));
		     TEST_EQUAL("median of five elements", 3, stat_median(five));
		   });
  rubric.criterion("median (even case)", 1,
		   [&]() {
		     TEST_EQUAL("median of six elements", (3+4)/2, stat_median(six));
		   });

  return rubric.run();
}
