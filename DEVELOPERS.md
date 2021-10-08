# Computer Science 327 Part B - DEVELOPERS
## Short Summary of Each Source File
- `main.c`
  - Runs base code utilising the dca1d
  - Methods
    - `main(int argc, char **argv)`
      - Inputs: 5 additional command line arguments in the following order
        - `int` of Cells within 1DCA
        - `int` of possible states
        - `wrap` or `nowrap` to indiciate how it should treat edge cases
        - `int` to show initial state, `-1` is valid and will randomize the start state
        - `int` of how many steps to go though
      - Actions: checks all input vals to make sure they are valid, creates 
      - Outputs: none
- `ca.c`
  - Contains methods to interact with struct `ca_data`
  - Methods
    - `void display1DCA(struct ca_data *data)`
      - Inputs: a pointer to a struct of ca_data
      - Actions: prints the data to `stdout`
      - Outputs: to `stdout`
    - `int set1DCACell(struct ca_data *data, unsigned int index, unsigned char setVal)`
      - Inputs: a pointer to a struct of ca_data, an index to store at, and the value to store
      - Actions: sets the data's array of data at `index` to the value passed in
      - Outputs: `1` on sucess, `0` on failure
    - `void init1DCA(struct ca_data *data, int initVal)`
      - Inputs: a pointer to a struct of ca_data and a value all cells should begin with
      - Actions: sets initial starting values of the data struct
      - Outputs: none, writes to memory
    - `struct ca_data * create1DCA(int numCells, unsigned char initialVal)`
      - Inputs: number of cells the array within ca_data should be, and the initial starting value
      - Actions: Creates and returns a ca_data struct
      - Outputs: A ca_data struct with various elements within 
    - `void stepCA( struct ca_data *data, unsigned char (*function)(struct ca_data *, int), int edgeCase)`
      - Inputs: a pointer to a struct of ca_data, a function pointer for what should occur each step, and a flag on how to act on each step
      - Actions: Takes the data struct passed in, gives it to the function passed in, and based on the flag, it will place it accordingly into the struct
      - Outputs: none Writes to pointer's memory

---
## Data Structures
This programme utilises a struct that contains an array along with a few other primitive data types