CC = gcc
AR = ar rc
FLAG_EXE = -lm -o
O_FLAG = -Wall -Wextra -I src -c -MP -MMD
BIN = bin/
GAME_DIR = src/game/
MAIN_DIR = src/main/
MENU_DIR = src/menu/
TEST_DIR = src/test/
GAME_OBJ = obj/$(GAME_DIR)
MAIN_OBJ = obj/$(MAIN_DIR)
MENU_OBJ = obj/$(MENU_DIR)
TEST_OBJ = obj/$(TEST_DIR)

all: game test

game: game.exe

test: test.exe

test.exe: test_ar clean
	$(CC) $(BIN)test.a $(FLAG_EXE) $(BIN)$@

game.exe: game_ar
	$(CC) $(BIN)game.a $(FLAG_EXE) $(BIN)$@

game_ar: main.o gamePVE.o gamePVP.o out.o check.o
	$(AR) $(BIN)game.a $(GAME_OBJ)gamePVE.o $(GAME_OBJ)gamePVP.o $(MENU_OBJ)out.o $(MAIN_OBJ)main.o $(MENU_OBJ)check.o

test_ar: test_main.o test.o check.o
	$(AR) $(BIN)test.a $(TEST_OBJ)test_main.o $(TEST_OBJ)test.o $(MENU_OBJ)check.o

main.o: $(MAIN_DIR)main.c
	$(CC) $(O_FLAG) $(MAIN_DIR)main.c -o $(MAIN_OBJ)$@

gamePVE.o: $(GAME_DIR)gamePVE.c
	$(CC) $(O_FLAG) $(GAME_DIR)gamePVE.c -o $(GAME_OBJ)$@

gamePVP.o: $(GAME_DIR)gamePVP.c
	$(CC) $(O_FLAG) $(GAME_DIR)gamePVP.c -o $(GAME_OBJ)$@

out.o: $(MENU_DIR)out.c
	$(CC) $(O_FLAG) $(MENU_DIR)out.c -o $(MENU_OBJ)$@

test_main.o: $(TEST_DIR)test_main.c
	$(CC) $(O_FLAG) $(TEST_DIR)test_main.c -o $(TEST_OBJ)$@

test.o: $(TEST_DIR)test.c
	$(CC) $(O_FLAG) $(TEST_DIR)test.c -o $(TEST_OBJ)$@

check.o: $(MENU_DIR)check.c
	$(CC) $(O_FLAG) $(MENU_DIR)check.c -o $(MENU_OBJ)$@

.PHONY: clean
clean:
	$(RM) $(GAME_OBJ)*.o $(MAIN_OBJ)*.o $(MENU_OBJ)*.o $(TEST_OBJ)*.o
	$(RM) $(GAME_OBJ)*.d $(MAIN_OBJ)*.d $(MENU_OBJ)*.d $(TEST_OBJ)*.d
