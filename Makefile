CC = gcc
AR = ar rc
RM = rm -Force
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

game: $(BIN)game.exe

test: $(BIN)test.exe
	$(BIN)test.exe

$(BIN)test.exe: $(BIN)test.a
	$(CC) $(TEST_OBJ)test_main.o $(TEST_OBJ)test.o $(MENU_OBJ)check.o $(FLAG_EXE) $@

$(BIN)game.exe: $(BIN)game.a
	$(CC) $(BIN)game.a $(FLAG_EXE) $@

$(BIN)game.a: $(MAIN_OBJ)main.o $(GAME_OBJ)gamePVE.o $(GAME_OBJ)gamePVP.o $(MENU_OBJ)out.o $(MENU_OBJ)check.o
	$(AR) $@ $(GAME_OBJ)gamePVE.o $(GAME_OBJ)gamePVP.o $(MENU_OBJ)out.o $(MAIN_OBJ)main.o $(MENU_OBJ)check.o

$(BIN)test.a: $(TEST_OBJ)test_main.o $(TEST_OBJ)test.o $(MENU_OBJ)check.o
	$(AR) $@ $(TEST_OBJ)test_main.o $(TEST_OBJ)test.o $(MENU_OBJ)check.o

$(MAIN_OBJ)main.o: $(MAIN_DIR)main.c
	$(CC) $(O_FLAG) $(MAIN_DIR)main.c -o $@

$(GAME_OBJ)gamePVE.o: $(GAME_DIR)gamePVE.c
	$(CC) $(O_FLAG) $(GAME_DIR)gamePVE.c -o $@

$(GAME_OBJ)gamePVP.o: $(GAME_DIR)gamePVP.c
	$(CC) $(O_FLAG) $(GAME_DIR)gamePVP.c -o $@

$(MENU_OBJ)out.o: $(MENU_DIR)out.c
	$(CC) $(O_FLAG) $(MENU_DIR)out.c -o $@

$(TEST_OBJ)test_main.o: $(TEST_DIR)test_main.c
	$(CC) $(O_FLAG) $(TEST_DIR)test_main.c -o $@

$(TEST_OBJ)test.o: $(TEST_DIR)test.c
	$(CC) $(O_FLAG) $(TEST_DIR)test.c -o $@

$(MENU_OBJ)check.o: $(MENU_DIR)check.c
	$(CC) $(O_FLAG) $(MENU_DIR)check.c -o $@

.PHONY: clean
clean:
	$(RM) $(GAME_OBJ)*.o $(MAIN_OBJ)*.o $(MENU_OBJ)*.o $(TEST_OBJ)*.o
	$(RM) $(GAME_OBJ)*.d $(MAIN_OBJ)*.d $(MENU_OBJ)*.d $(TEST_OBJ)*.d
	$(RM) $(BIN)*.exe $(BIN)*.a
