CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: main.o cAire.o cArcher.o cBase.o cCase.o cCatapulte.o cFantassin.o cJoueur.o cUnite.o  
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
