o_files: main.c gamePVP.c out.c gamePVE.c
	gcc -c main.c gamePVP.c out.c gamePVE.c

game: main.o gamePVP.o out.o gamePVE.o
	gcc main.o gamePVP.o out.o gamePVE.o -lm -o  game.exe
