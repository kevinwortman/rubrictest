
test: stats_test
	./stats_test

stats_test: stats.hpp stats_test.cpp
	g++ -std=c++11 stats_test.cpp -o stats_test

clean:
	rm -f stats_test
