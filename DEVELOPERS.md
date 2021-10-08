# Computer Science 327 Part B - DEVELOPERS
## Short Summary of Each Source File
- `main.c`
  - Runs base code utilising the dca1d
  - Methods
    - `main(int argc, char **argv)`
      - Inputs: Unused Argument Count and Unused Argument Value Array
      - creates an unsigned char array for dca1d to interact with
      - does not take any command line inputs to execute, all configured within
      - `CELL_SIZE` can be changed to adjust size of unsigned char array
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
      - Inputs: a pointer to a struct of ca_data
      - Actions: 
      - Outputs: 
    - `struct ca_data * create1DCA(int numCells, unsigned char initialVal)`
      - Inputs: a pointer to a struct of ca_data
      - Actions: 
      - Outputs: 
    - `void stepCA( struct ca_data *data, unsigned char (*function)(struct ca_data *, int), int edgeCase)`
      - Inputs: a pointer to a struct of ca_data
      - Actions: 
      - Outputs: 

---
## Data Structures
This programme utilises a struct that contains 