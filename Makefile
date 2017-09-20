
test: stats_test
	./stats_test

stats_test: stats.hh stats_test.cc
	g++ -std=c++11 stats_test.cc -o stats_test

clean:
	rm -f stats_test
