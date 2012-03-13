CC=gcc
ECHO=echo
RM=rm -f

all: clean
	$(CC) example.c -o example -g -ggdb -L../lib -lhashmap -I../lib

clean: 
	@$(RM) example

run:
	@$(ECHO) export LD_LIBRARY_PATH=../lib/ 
	@$(ECHO) ./example
