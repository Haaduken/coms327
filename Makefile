DEPS := main.o
BIN := gol

all: build

%.o: %.cpp
	$(GCC) -c -o $@ $< $(CFLAGS)

build: $(DEPS)
	$(GCC) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)