# 159102_Assignment2
ZEJU FAN 21019135

This program is a simple interpreter for the MASSEY machine code.

1.
Must include:
int memory[256];
int reg[16]; // note: "register" is a reserved word
int pc, ir;

2.Understand the rules of MasseyCode
1RXY Load register R with the value XY.
e.g. 1213 means load register R2 with the hexadecimal number 13 (19 in decimal).
20RS Load register R with the number in register S.
e.g. 20A7 means load register R10 with the number in register R7.
3RXY Load register R with the number in the memory location at address XY.
e.g. 34AB means load register R4 with the contents from memory location AB
4RXY Store the number in register R in the memory location at address XY.
e.g. 45B1 means store the contents of register R5 in the memory location B1
5RST Add the numbers in registers S and T and load the result into register R.
Note: this is floating point addition.
e.g. 534E means add the numbers in R4 and R14 and load the result into R3.
6RST Add the numbers in registers S and T and load the result into register R.
Note: this is integer addition using 2’s complement arithmetic.
e.g. 6823 means add the contents of R2 and R3 and load the result into R8.
70R0 Negate register R. (Carry out complement and add 1 – in effect, multiply R with -1)
e.g. 70A0 means multiply the number in R10 by -1.
8R0X Shift the number in register R to the right X times.
e.g. 8403 means that the number in R4 must be shifted 3 bits to the right.
9R0X Shift the number in register R to the left X times.
e.g. 9602 means that the number in R6 must be shifted 2 bits to the left.
ARST AND the numbers in registers S and T and load the result into register R.
e.g. A045 means AND the numbers in R4 and R5 and load the result into R0.
BRST OR the numbers in registers S and T and load the result into register R.
e.g. BC74 means OR the numbers in R7 and R4 and load the result into R12.
CRST XOR the numbers in registers S and T and load the result into register R.
e.g. C5F3 means XOR the numbers in R15 and R3 and load the result into R5.
DRXY Jump to the instruction at address XY if the value in register R is equal
to the value in register R0.
e.g. D43C means the following: (a) compare the contents of R4 with R0.
(b) if they are equal load 3C into the program counter.
E000 Halt

3.  The key point is to judge by the first digit
4.  Processing hexadecimal codes
5.  The output must be four digits


problem：When the first digit is "4", the value of PC is not output

