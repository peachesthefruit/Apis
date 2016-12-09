CXX=	g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=	bash
PROGRAMS= measure honeybee

all: measure honeybee

honeybee: honeybee.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS)

test:	test-output test-memory test-time

test-output:	$(PROGRAMS)
	@echo Testing output 1...
	@diff --suppress-common-lines -y <(./honeybee -b b -n 2 < test/testInput.txt< test/testInput.txt) test/testOutput1.txt
	@echo Testing output 2...
	@diff --suppress-common-lines -y <(./honeybee -b d -n 3 < test/testInput.txt< test/testInput.txt) test/testOutput2.txt

test-memory:	$(PROGRAMS)
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./honeybee -b b -r b < test/testInput.txt 2>&1 | grep ERROR | awk '{print $$4}'`=0 ]

test-time:	$(PROGRAMS)
	@echo Testing time...
	@./measure ./honeybee -b a -n 2 < test/testInput.txt | tail -n 1 | awk '{ if ($$1 > 5) { print "Time limit exceeded"; exit 1} }'
