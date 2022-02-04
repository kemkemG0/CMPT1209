/* This class defines a set of integers called MySet. Objects of the type MySet are a set including distinct integers, if they are not empty.
   Integers of the set may have any order and they may also change their order anytime if it helps implementing a more efficient function.
   
    This class includes three attributes:
    1) set: A pointer to a sequence of integers stored in the heap.
    2) size: An integer showing the number of integers included in the set.
    3) bufferSize: An integer showing the size of the buffer (i.e. the maximum number of integers that fit in the set at any point).
    The bufferSize is initially 10 and is increased by 50% if a single integer is about to be added to a full set. If more than one item is
        to be added to a full set and 50% increase is not enough, the set is increased enough to accomodate all the new values.

    This class also defines the following methods:
    1) A no-arg constructor that creates an empty set with the buffer size of 10.
    2) A parameterized constructor with two input parameters: an array of integers and the size of the array. This
        method creates a set including the distinct integers in the input array. The buffer size in this case is identified as described for adding 
        more than one value to the set.
    3) A copy constructor that creates a MySet object using an existing MySet object.
    4) The class destructor.
    5) The "add" method that accepts an integer as its input parameter and if the input value does not exist in the set, adds it to the set and returns true; 
        otherwise, it returns false and of course the value is not added to the set.
    6) Overload the "add" function to all the distinct values of an array of integers to the set.
    7) The "remove" method that accepts an integer as its input parameter and if the input value exists in the set, it is removed from the set, and
        the function returns true; otherwise, it returns false.
    8) The "has" method checks if the input parameter exists in the set. This method returns true if the input value is a member of the set 
        and returns false otherwise.
    9) The "unionWith" method creates and returns a new MySet object including all the integers of the current set and another set passed as function's input 
        parameter.
    10) The "intersectWith" method creates and returns the intersection of the set with another set passed in the function's input parameter.
        The intersection of two sets is a set including all the items that commonly exist in both sets.
    11) The "clear" method clears the set; empties the set and reset is to its initial state.
    12) The "getSize" method returns the number of items included in the set.
	13) The "print" method displays the set on the screen.
   */

#ifndef MY_SET_H
#define MY_SET_H
#include <set>//Only for a test function

template<typename T>
class MySet {
public:
	MySet();
	MySet(const T sequence[], int size);
	MySet(const MySet& anotherSet);
	~MySet();
	bool add(T item);
	bool add(const T sequence[], int size);
	bool remove(T item);
	bool has(T item) const;
	MySet unionWith(const MySet& anotherSet) const;
	MySet intersectWith(const MySet& anotherSet) const;
	void clear();
	int getSize() const;
	void print() const;
    //for debug and test
    bool isSameSet(std::set<T>& checkSet)const;
private:
	T* set;
	int size;
	int bufferSize;
    void allocateNewBuffer(int size);
    
    
};
#endif