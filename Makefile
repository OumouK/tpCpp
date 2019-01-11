CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: main.o cAire.o cFantassin.o cJoueur.o cUnite.o cCase.o cArcher.o cCatapulte.o 
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
