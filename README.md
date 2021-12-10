# Computer Science 327 P2
## Compilation and Execution
### To compile and Execute
- Run `make`
- Run `./gol`
### To remove compiled files
- Run `make clean`
---
## About this Programme
This programme emulates Conway's Game of Life within a graphical client.

There are no currently known bugs with the code.

There is, however, an issue due to being single threaded; Attempting to enter a new command while the previous command is still running will cause the newly input one to be disregarded. The program is locked until execution of the current command ends. This problem can be solved by multithreading the graphical drawing portion and the processing of user inputs.
