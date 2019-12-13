.SUFFIXES: .cpp .o

OBJECT = array_2d.o big_block.o color_block.o cross_block.o block.o fold_block.o tree_block.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECT)
		$(CXX) -o $(TARGET) $(OBJECT)

clean:
	rm -rf *.o

array_2d.o: array_2d.cpp
big_block.o: big_block.cpp
color_block.o: color_block.cpp
cross_block.o: cross_block.cpp
block.o: block.cpp
fold_block.o: fold_block.cpp
tree_block.o: tree_block.cpp
main.o: main.cpp
