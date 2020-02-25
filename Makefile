CC = g++
CFLAGS = -Wall -Wextra -O2 -g
LDLIBS = -lm

build: algo.o algo2.o
	@g++ algo.o algo2.o tester.cpp $(CFLAGS) -o test

algo.o: algo.cpp
	@g++ algo.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	@g++ algo2.cpp -c $(CFLAGS)

algo_test.o: tester.cpp
	@g++ tester.cpp -o test $(CFLAGS)

generator: generator.o
	@g++ generator.o -o generator $(CFLAGS)

generator.o:
	@g++ generator.cpp -c $(CFLAGS)

.PHONY: clean
clean:
	@rm -rf *.o test outF outM generator