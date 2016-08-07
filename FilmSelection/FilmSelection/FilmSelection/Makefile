CC=g++
CFLAGS= -g -c -Wall -std=c++14
LDFLAGS=
SOURCES=main.cpp Channel.cpp Film.cpp FilmSelection.cpp User.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=filmselection
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Channel.o: Channel.cpp
	$(CC) $(CFLAGS) Channel.cpp

Film.o: Film.cpp
	$(CC) $(CFLAGS) Film.cpp

FilmSelection.o: FilmSelection.cpp
	$(CC) $(CFLAGS) FilmSelection.cpp

User.o: User.cpp
	$(CC) $(CFLAGS) User.cpp

clean:
	erase /s main.o User.o FilmSelection.o Film.o Channel.o
