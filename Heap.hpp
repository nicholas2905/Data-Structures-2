#include <string>
#include <stdio.h>
#define Heap_hpp
using namespace std;

// Creating the class 'Heap'
class Heap
{
    private:
        int * data;             // An array of integers, allocated through the constructor
        int nextFreeSlot;       // keeps track of the next free slot to insert a new element, -1 if array is full
        int Left_Son(int i);    // Returns the index of the left son of node i (2*i); -1 if out of range
        int Right_Son(int i);   // Returns the index of the right son of node i (2*i + 1); -1 if out of range
        int Parent(int i);      // Returns the index of the parent of node i (i/2); -1 if out of range
        int Swap(int i, int j); // Swaps two nodes in the heap - checks if one is the parent of the other; returns 0 if success, -1 if failure
        int Size_of_the_Tree;

    public:
        int ExHeap();
        Heap Example(int n);
        Heap(int n);            // n is the number of cells in the array
        ~Heap();                // Needs a destructor to free dynamic memory
        int push(int x);        // adds a new element; returns 0 if success, -1 if failure
        int pop();              // Gets the value of the root element and removes it from the heap
        void toString();        // textual representation of the contents of the heap - for display & debug purposes mainly
};
