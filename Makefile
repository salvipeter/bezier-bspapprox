all: bspapprox-test

INCLUDES=-I../libgeom -I/usr/include/eigen3 -I.
LIBS=-L../libgeom/debug -lgeom -lgmp

CFLAGS=-std=c11 -Wall -pedantic -g
CXXFLAGS=-std=c++17 -Wall -pedantic -g $(INCLUDES)

bspapprox-test: bspapprox-test.o bspapprox.o reduction.o bezier-extractions.o
	$(CXX) -o $@ $^ $(LIBS)
