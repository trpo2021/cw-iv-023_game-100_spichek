game: main.o gamePVP.o out.o gamePVE.o
	gcc main.o gamePVP.o out.o gamePVE.o -lm -o  game.exe

gamePVE.o: gamePVE.c
	gcc -c gamePVE.c

gamePVP.o: gamePVP.c
	gcc -c gamePVP.c

out.o: out.c
	gcc -c out.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *.o game
