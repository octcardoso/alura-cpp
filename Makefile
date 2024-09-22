CXXFLAGS = -std=c++11

forca: jogo-da-forca.cpp
	g++ *.o -o forca.out $(CXXFLAGS)
