#Makefile
TARGET=add-nbo


all: $(TARGET)

$(TARGET): util.o add-nbo.o
	g++ -o $(TARGET) util.o add-nbo.o

add-nbo.o: add-nbo.cpp

util.o: util.cpp

clean:
	rm -f $(TARGET)
	rm -f *.o