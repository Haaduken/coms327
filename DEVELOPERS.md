# Computer Science 327 Part B - DEVELOPERS
## Short Summary of Each Source File
- `dca1d.c`
  - Contains methods to interact with an array of unsigned chars
  - Methods
    - `void init1DCA(int numCells, unsigned char *arr)`
      - Inputs: size of array and array
      - Sets all values to `0`
      - Outputs: none
    - `int set1DCACell(unsigned char *arr, int index, unsigned char setVal)`
      - Inputs: array, index, and value to set at index
      - Sets the value in the array at the specified index
      - Outputs: none
    - `void display1DCA(unsigned char *arr, int numCells)`
      - Inputs: array and the size of the array
      - prints the contents of the array to the terminal
      - Outputs: none
- `dca1d.h`
  - Header file for `dca1d.c`
  - Used within `main.c` to allow it to use methods from `dca1d.c`
- `main.c`
  - Runs base code utilising the dca1d
  - Methods
    - `main(int argc, char **argv)`
      - Inputs: Unused Argument Count and Unused Argument Value Array
      - creates an unsigned char array for dca1d to interact with
      - does not take any command line inputs to execute, all configured within
      - `CELL_SIZE` can be changed to adjust size of unsigned char array
      - Outputs: none

---
## Data Structures
This programme utilises an array that consists of unsigned chars. That is currently the only data structure it contains