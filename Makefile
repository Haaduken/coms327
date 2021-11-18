DEPS := GraphicsClient.o main.o
BIN := sand

all: build

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

build: $(DEPS)
	$(CXX) -o $(BIN) $(DEPS) $(CFLAGS)

clean:
	@rm -f *.o $(BIN)