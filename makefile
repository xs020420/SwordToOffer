
objects = offer.o lib.o
edit: $(objects)
	g++ -o edit $(objects)

offer.o: offer.cpp lib.h
	g++ -c offer.cpp

lib.o: lib.cpp lib.h
	g++ -c lib.cpp

.PHONY : clean
clean : rm edit $(objects)
