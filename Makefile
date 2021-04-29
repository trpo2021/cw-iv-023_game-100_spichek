all: main game menu
	gcc main.o gamePVP.o out.o gamePVE.o -lm -o  game.exe

main:
	gcc -c src/main/main.c

game:
	gcc -c src/game/gamePVE.c
	gcc -c src/game/gamePVP.c

menu:
	gcc -c src/menu/out.c

clean:
	rm -rf *.o all
