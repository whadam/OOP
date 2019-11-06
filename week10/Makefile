.SUFFIXES: .cpp .o

OBJECTS = main.o car.o bike.o vehicle.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
		$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
car.o : car.cpp
bike.o : bike.cpp
vehicle.o : vehicle.cpp
