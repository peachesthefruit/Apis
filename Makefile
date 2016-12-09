CXX=	g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=	bash
PROGRAMS= apis measure honeybee

all: apis measure honeybee

apis:	apis.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

honeybee: honeybee.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS)

test:	test-output test-memory test-time

test-output:	apis
	@echo Testing output...
	@diff --suppress-common-lines -y <(./apis < input.txt) output.txt

test-memory:	apis
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./apis < input.txt 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-time:	$(PROGRAMS)
	@echo Testing time...
	@./measure ./apis < input.txt | tail -n 1 | awk '{ if ($$1 > 5.0) { print "Time limit exceeded"; exit 1} }'
