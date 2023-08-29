CC = gcc
CFLAGS = -Wall -O2

SOURCES = *.c
EXECUTABLE = test

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)
