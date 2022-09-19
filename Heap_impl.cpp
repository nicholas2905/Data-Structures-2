#include <iostream>
#include "Heap.hpp"
#include <sstream>
using namespace std;

Heap::Heap(int n)
{
    cout << "Please enter the size of the tree:\n"; // function asks the user to input the size of the tree
    cin >> Size_of_the_Tree; // user inputs the size of the tree
    data = new int(Size_of_the_Tree + 1); // size of the tree increases by 1 in order to allow the user to input a new node
    nextFreeSlot = 1;
};

// Function that deletes data in order to free up dynamic memory 
Heap::~Heap()
{
    delete data; // deleting the array
};

// Function that returns the index of the left son of node 'i'
// Function also checks to verify that the son fits into the size of the tree
int Heap::Left_Son(int i) // int 'i' is the object of the function, the parent of the son node
{
    // checks to see if the node fits into the size of the tree 
    if ((2*i) < Size_of_the_Tree) // Size_of_the_Tree is an inputted value from the function Heap(int n)
    {
        // case where the node fits in to the size of the tree
        return (2*i); // function returns the index of the node
    }
    // case where the function does not fit into the size of the tree
    else 
    {
        return -1; // function will return -1, indicating that the node is out of range
    }
}

// Function that returns the index of the right son of node 'i'
// Function also checks to verify that the son fits into the size of the tree
int Heap::Right_Son(int i) // int 'i' is the object of the function, the parent of the son node
{
    // checks to see if the node fits into the size of the tree 
    if (((2*i) + 1) < Size_of_the_Tree) // Size_of_the_Tree is an inputted value from the function Heap(int n)
    {
        // case where the node fits in to the size of the tree
        return ((2*i) + 1); // function returns the index of the node
    }
    // case where the function does not fit into the size of the tree
    else 
    {
        return -1; // function will return -1, indicating that the node is out of range
    }
}


// Function that returns the index of the parent of node 'i'
int Heap::Parent(int i) // int 'i' is the object of the function, the parent of the son node
{
    // checks to see if the node is in range 
    if ((i/2) < 1) // if the index is less than 1 then the node is out of range
    {
       return -1; // function will reutn -1, indicating that the parent is out of range
    }
    // case where the parent is in range
    else 
    {
        return (i/2); // function will return the index of the parent
    }
}

// Function that swaps the nodes
int Heap::Swap(int i, int j) // the two nodes in this case are i and j
{
    // swapping variable that helps to swap the values
    int swapping_varibale = j; // swapping_variable takes acts as a duplicate of one of the nodes and makes sure no data is lost
    if (i > j || j > i) // function can proceed if 'i' is greater than 'j' OR if 'j' is greater than 'i'
    {
        j = i; // 'j' takes in the value of 'i'
        i = swapping_varibale; // 'i' takes in the swapping_variable, which has the original value of 'j'
        return 0; // function returns 0 to show that it was successful
    }
    // case where neither 'i' is greater than 'j' nor 'j' is greater than 'i'
    else
    {
        return -1; // function returns -1 to show failure
    }
}

// Function that adds in a new element 
int Heap::push(int x)
{
    // Case where the array is not full
    if (nextFreeSlot != -1)
    {
        // Case where the inserted node is a smaller value than that of its parent 
        if (x < Parent(x))
        {
          nextFreeSlot = x; // The inserted element remains in the next slot
          return 0; // function is successful
        }
        // Case where the inserted node is a larger value than that of its parent
        else if (x > Parent(x))
        {
            Swap(x, Parent(x)); // The new node swaps with the parent
            nextFreeSlot = Parent(x); // The parent node becomes the next slot
            return 0; // function is successful
        }
    }
    // Case where the array is full
    else
    {
        return -1; // Function returns -1 to show failure
    }
}

// Displays the data of the nodes
string Heap::toString()
{
    for (int num = 0; num < Size_of_the_Tree; num++) // function repeats until the tree is completed
    {
        cout << "[" << data[num] << "]" << ", "; // data of each element is presented
    }
    return 0;
}