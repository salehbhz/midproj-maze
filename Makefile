CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS =   ./obj/main.o  ./obj/room.o

TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) 

./obj/room.o: ./cpp/room.cpp
	$(CXX) $(CXXFLAGS) ./cpp/room.cpp -o ./obj/room.o

# ./obj/solve.o: ./cpp/solve.cpp
# 	$(CXX) $(CXXFLAGS) ./cpp/solve.cpp -o ./obj/solve.o

./obj/main.o: ./cpp/main.cpp  
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
