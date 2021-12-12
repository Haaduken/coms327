DEPS := main.o ca.o
BIN := odca

all: build

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(DEPS)
	$(CC) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)