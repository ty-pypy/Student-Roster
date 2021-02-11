#ifndef degree_hpp
#define degree_hpp

#include <stdio.h>

using namespace std;

//Set of enumerators to define Student degree types
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//Array of degreeTypes that matches the enumeration above to allow transition between and enumerator and a string
static string degreeTypes[] = {"SECURITY", "NETWORK", "SOFTWARE"};

#endif /* degree_hpp */
