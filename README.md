# 🧮 Arbitrary Precision Calculator (APC)

**Author:** B.JAYASURYA
**Roll No.:** 25017B_167
**Date:** 31 / 10 / 2025
**Language:** C  
**Environment:** Ubuntu / Visual Studio Code  

-----------------------------------------------------------------------------------------------------

## 📘 Project Overview

The **Arbitrary Precision Calculator (APC)** is a C-based program that performs arithmetic operations on **very large integers** — larger than what built-in C data types like `int`, `long`, or `double` can handle.

It uses a **Doubly Linked List (Dlist)** to store each digit of the numbers, allowing accurate computation of **unlimited-length integers**.

---------------------------------------------------------------------------------------------

## ⚙️ Features

✅ Supports all basic operations:
- **Addition (+)**
- **Subtraction (-)**
- **Multiplication (×, x,)**
- **Division (/)**  
- **Modulo (%)**

✅ Handles **positive and negative numbers** correctly  
✅ Removes **leading zeros** in results  
✅ Detects **division/modulo by zero** safely  
✅ Prints results in linked-list format:
## head->-1->2->3<-tail

## 🧩 Data Structure Used

### **Doubly Linked List**
````````````````````````````````````````````````````````````````````````````````````````````````c
typedef struct Dlist
{
    int data;              // single digit (0–9 or negative for first node)
    struct Dlist *prev;    // link to previous node
    struct Dlist *next;    // link to next node
} Dlist;
Each node holds one digit of the number.
For example, -123 is stored as:
head->-1->2->3<-tail
-----------------------------------------------------------------------------------------------------
Supported Operations
➕ Addition

Same signs → add magnitudes

Different signs → subtract smaller from larger and take sign of larger number
Example: -5 + 2 → head->-3<-tail

➖ Subtraction

Same signs → subtract magnitudes

Different signs → perform addition and take sign of first operand
Example: -2 - 2 → head->-4<-tail

✖️ Multiplication

Sign of result = sign1 × sign2

Example:

1 x -12 → head->-1->2<-tail

-3 x -3 → head->9<-tail

➗ Division

Performs long division using linked lists

Division by zero safely handled

Sign of result = negative if operands have different signs
Example:

-10 / 2 → head->-5<-tail

-10 / 0 → Error: Division by zero

🔢 Modulo

Uses repeated subtraction to find remainder

Follows C language sign rule: remainder takes sign of dividend
Example:

-5 % 2 → head->-1<-tail

5 % -2 → head->1<-tail
``````````````````````````````````````````````````````````````````````````````````````````````````````c
⚡ Error Handling
Error Type	Message
Division by zero	Error: Division by zero
Modulo by zero	Error: Modulo by zero
Invalid operator	Error: Invalid operator 'x'
Memory allocation failure	memory is not allocated.
---------------------------------------------------------------------------------------------------------
 Algorithm Flow

 => Input Parsing

=> Reads operands and operator from command-line arguments

=> Extracts sign and digits

=> Convert Numbers → Linked Lists

=> Each digit stored as a node in Dlist

=> Perform Operation

=> Operator determines which function to call

=> Result Formatting

=> Removes leading zeros

=> Stores sign in first node.
Output

Displays result in linked-list format

Example:

head->-2->5<-tail
`````````````````````````````````````````````````````````````````````````````````````````````````````c
🧩 File Structure
📁 ArbitraryPrecisionCalculator/
├── main.c              # Handles input, operator logic, and output
├── addition.c          # Addition logic
├── subtraction.c       # Subtraction logic
├── multiplication.c    # Multiplication logic
├── division.c          # Division logic
├── modulo.c            # Modulo logic
├── apc.h               # Header file (typedefs & prototypes)
└── README.md           # Documentation (this file)
-------------------------------------------------------------------------------------------------------
🏁 Conclusion

The Arbitrary Precision Calculator performs mathematical operations on numbers of any size using linked lists.
It correctly manages signs, carries, borrows, and overflows, mimicking real arithmetic at the data-structure level.

-> This project demonstrates:
-> Proficiency in Linked Lists
-> Strong understanding of operator logic
-> Dynamic memory handling
-> Error validation & sign management

---------------------- x------------------------------x---------------------------------------x---------------