GAME_DIR = src/game/
MAIN_DIR = src/main/
MENU_DIR = src/menu/
FLAGS_exeF = -Wall -Wextra -Werror
FLAG_exeS = -lm -o
FLAGS_o = -c
I = -I src

game: main game_ar
	gcc $(FLAGS_exeF) main.o game.a $(FLAG_exeS) game.exe

game_ar: game_PVE game_PVP menu
	ar rcs game.a gamePVE.o gamePVP.o out.o

main:
	gcc $(I) $(FLAGS_o) $(MAIN_DIR)main.c

game_PVE:
	gcc $(I) $(FLAGS_o) $(GAME_DIR)gamePVE.c

game_PVP:
	gcc $(I) $(FLAGS_o) $(GAME_DIR)gamePVP.c

menu:
	gcc $(I) $(FLAGS_o) $(MENU_DIR)out.c
