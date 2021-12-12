DEPS := GraphicsClient.o main.o CellularAutomaton.o
BIN := gol

all: build

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

build: $(DEPS)
	$(CXX) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)