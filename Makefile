DEPS := main.o ca.o
BIN := gol

all: build

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(DEPS)
	$(CC) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)