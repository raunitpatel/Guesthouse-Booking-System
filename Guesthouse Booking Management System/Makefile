CC = g++
CFLAGS = -Wall -g -w

SOURCES = main.cpp constanddest.cpp bookroom.cpp facilities.cpp menu.cpp
HEADERS = header.h
EXECUTABLE=run

all: $(EXECUTABLE)

$(EXECUTABLE):$(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(EXECUTABLE)
