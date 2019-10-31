CFLAGS=-g
CPPFLAGS=-g -I../
LDFLAGS=-lSDL2 -lSDL2_mixer

all : songtest
.PHONY: all

songtest : songtest.o ../song.o ../player.o
	g++ -o songtest songtest.o ../song.o ../player.o $(LDFLAGS)

clean:
	rm *.o ../*.o songtest 