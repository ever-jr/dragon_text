# name: drac
dragon_text: run

run: build
	@./drac
	@rm drac

build:
	@gcc main.c entity.c -o drac -lncurses -Wall -Wextra
