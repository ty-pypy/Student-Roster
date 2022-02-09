# Student-Roster

This is the first program that I wrote. The goal is to take an array containing information 
for five students, parse it to create instances of a Student class, and add these 
Students to a Roster. Once the Roster is built, several functions are performed on it:

1) Print all Students
2) Search for Students with invalid emails (errors in the string) and print them
3) For each Student, print the average number of days remaining to complete their classes
4) Print Students whose degree matched a specific input
5) Remove a Student according to their ID, print the Roster, and try to remove the Student again


What was learned:
* This was a challenging first language to use since C++ allows for memory management and
is much more explicit compared to a language such as Python.
* Dynamic Allocation was challenging to understand. When the remove function is called, the Student located
in a different location then appears twice if the size of the array is not reduced.
* It was interesting to see the use of Header files and the leave of control the user has 
when writing code in a language such as C++.
* Pointers, Dynamic Allocation, Constructors and Destructors, Header files, static, Variable Declaration.

What can be improved:
* After writing several other programs, it appears that refactoring this program would be 
beneficial. It is my understanding that the main file typically only contains the main function.
