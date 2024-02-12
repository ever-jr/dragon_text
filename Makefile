LIBS=-lncurses -lpanel
FLAGS=-Wall -Wextra
SOURCE_FILES=src/**.c

# name: drac
dragon_text: run

run: build
	@./drac
	@rm drac

build:
	@gcc main.c $(SOURCE_FILES) -o drac $(LIBS) $(FLAGS)
