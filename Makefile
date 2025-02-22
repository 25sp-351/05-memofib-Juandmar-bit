CC = clang
CFLANGS = -Wall -Wextra -g
EXEC = fibonacci
SRC = fibonacci.c memoize.c

all: $(EXEC)

$(EXEC): $(SRC)
		$(CC) $(CFLANGS) -o $(EXEC) $(SRC)

rebuild: clean all

run: $(EXEC)
		@echo "Running ..."
		./$(EXEC)

clean: 
		rm -f $(EXEC)