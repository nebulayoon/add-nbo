#Makefile
TARGET=add-nbo


all: $(TARGET)

$(TARGET): add-nbo.o
	g++ -o $(TARGET) add-nbo.o

add-nbo.o: add-nbo.cpp

clean:
	rm -f $(TARGET)
	rm -f *.o