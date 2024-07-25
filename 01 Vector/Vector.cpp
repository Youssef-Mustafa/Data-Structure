#include <assert.h>
#include <cassert>
#include <iostream>
using namespace std;
class Vector
{
private:
  int *arr = nullptr;
  int size = 0;

public:
  Vector(int size); // Vector class constructor
  ~Vector();        // Vector class Destractor

  // Define Functionalities
  // 1-Get to get data
  int get(int idx);
  // 2-Set to set data (idx,value)
  void set(int idx, int value);
  // 3-Print the vector
  void print();
  // 4-Find value
  int find(int value);
  // 5-Get front (first Element)
  int get_front();
  // 6-Get Back (last element)
  int get_back();
  // 7-Push back (append/put element in last of array)
  /*
    *First Push back
    ! Simple and fast but unsafe if the array reaches its capacity, leading to potential undefined behavior.
    *Second Push Back
    ! Safe and robust with proper memory management and resizing but with a higher time complexity due to the
    ! need for copying elements and reallocating memory.

  */
  void push_back_weak(int value);
  void push_back(int value);
  // 8-Size of vector
  int get_size();
};

// Constructor
Vector::Vector(int size) : size(size)
{
  if (size < 0)
    size = 1;
  arr = new int[size];
}

// Detractor
Vector::~Vector()
{
  delete[] arr;
  arr = nullptr;
}

// get element by index
int Vector::get(int idx)
{
  assert(0 <= idx && idx < size);
  return arr[idx];
}

// set value in index
void Vector::set(int idx, int value)
{
  assert(0 <= idx && idx < size);
  arr[idx] = value;
}

// print all vecotr element
void Vector::print()
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// find value if exist or not
int Vector::find(int value)
{
  for (int i = 0; i < size; i++)
    if (arr[i] == value)
      return i;
  return -1; // not find the value
}

// Get first element in array
int Vector::get_front()
{
  return arr[0];
}

// Get last element in array
int Vector::get_back()
{
  return arr[size - 1];
}

// Put element in last of array
void Vector::push_back_weak(int value)
{
  size++;
  arr[size - 1] = value;
}
void Vector::push_back(int value)
{
  //* 1) Create a new array of size+1
  int *arr2 = new int[size + 1];
  //* 2) Copy the old array to new
  for (int i = 0; i <= size; i++)
    arr2[i] = arr[i];
  //* 3) Add new element and increase size;
  arr2[size++] = value;
  //* 4) Swap the arrays
  swap(arr, arr2);
  //* 4) Delete array 2
  delete[] arr2;
}

// Get size of vector
int Vector::get_size()
{
  return size;
}

// * Usage
// ! I am not using all functionality in main feel free to use it
int main()
{

  Vector v(10);
  for (int i = 0; i < 10; i++)
    v.set(i, i);

  cout << "Vector Elements: ";
  v.print(); // 0 1 2 3 4 5 6 7 8 9

  cout << "Find the value 5: " << v.find(5) << ", " << "Find the value 55: " << v.find(55) << endl; // 5 -1

  //? Push Back usage
  v.push_back(10);
  v.push_back(11);
  v.push_back(12);
  cout << "Vector Elements after push back: ";
  v.print();

  return 0;
}
