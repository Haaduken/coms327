DEPS := main.o dca1d.o
BIN := odca

all: build

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

build: dca1d.o $(DEPS)
	$(CC) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)