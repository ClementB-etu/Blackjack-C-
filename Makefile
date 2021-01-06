CC=gcc -Wall
RM=rm -f
SRC=$(wildcard *.c)
HEAD=$(wildcard *.h)
OBJ=$(SRC:.c=.o)
EXE=Bj


$(EXE) : $(OBJ)
	@$(CC) $^ -o $@

%.o : ./src/%.c
	$(CC) -c $^


.PHONY : clean

clean :
	@$(RM) *.o
	@$(RM) $(EXE)
