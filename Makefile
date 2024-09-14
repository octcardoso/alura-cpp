CXXFLAGS = -std=c++11

forca: jogo-da-forca.cpp
	g++ jogo-da-forca.cpp -o forca.out $(CXXFLAGS)
