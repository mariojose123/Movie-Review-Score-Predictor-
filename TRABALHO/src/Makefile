CC = gcc
CFLAGS = -g -O2
LFLAGS = -lm

OBJS = HashTable.o WordEntry.o main.o

EXEC = program

%.o: %.c $(DEPS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	@echo "Linking $(EXEC)\n"
	@$(CC) -o $(EXEC) $(OBJS) $(LFLAGS)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS) $(EXEC) *~

