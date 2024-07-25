#include <assert.h>
#include <cassert>
#include <iostream>
using namespace std;
class VectorWithCapacityTrick
{
private:
  int *arr = nullptr;
  int size{0};
  int capacity{};

public:
  // Initialize Vector constructor
  VectorWithCapacityTrick(int size);
  // Intialize Vector Detructor
  ~VectorWithCapacityTrick();
  // Capacity trick
  void expand_capacity();
  // Set element in Vector
  void set(int idx, int value);
  // print vector element
  void print();
  // put element in end of vector
  void push_back(int value);
  // insert element by index
  void insert(int idx, int value);
  // Home Work Problem #1 right rotate
  void right_rotate();
  // Home Work Problem #2 left rotate
  void left_rotate();
  // Home Work Problem #3 right rotate with n steps
  void right_rotate(int n);
  // Home Work Problem #4 Delete an index and retrun it's value
  int pop(int idx);
  // Home Work Problem #5 Improved Search to find the value and shift one step left
  int find_transposition(int value);
};

// Constructor
VectorWithCapacityTrick::VectorWithCapacityTrick(int size) : size(size)
{
  if (size < 0)
    size = 1;
  capacity = size + 10;
  arr = new int[capacity];
}

// Detructor
VectorWithCapacityTrick::~VectorWithCapacityTrick()
{
  delete[] arr;
  arr = nullptr;
}

// Capacity Expanded
void VectorWithCapacityTrick::expand_capacity()
{
  capacity = capacity * 2;
  cout << "Expand capacity to " << capacity << endl;
  int *arr2 = new int[capacity]{};
  for (int i = 0; i < size; i++)
    arr2[i] = arr[i];
  swap(arr, arr2);
  delete[] arr2;
}

// Push back with capacity trick
void VectorWithCapacityTrick::push_back(int value)
{
  if (size == capacity)
    expand_capacity();
  arr[size++] = value;
}

// set element in vector by idx
void VectorWithCapacityTrick::set(int idx, int value)
{
  assert(0 <= idx && idx < size);
  arr[idx] = value;
}

// insert element in vector by index
void VectorWithCapacityTrick::insert(int idx, int value)
{
  assert(0 <= idx && idx < size);
  if (size == capacity)
    expand_capacity();
  for (int i = size - 1; i >= idx; i--)
    arr[i + 1] = arr[i];
  arr[idx] = value;
  ++size;
}

// print all vecotr element
void VectorWithCapacityTrick::print()
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Home work #1
void VectorWithCapacityTrick::right_rotate()
{
  int temp = arr[size - 1];
  for (int i = size - 1; i >= 0; i--)
    arr[i + 1] = arr[i];
  arr[0] = temp;
}

// Home work #2
void VectorWithCapacityTrick::left_rotate()
{
  int temp = arr[0];
  for (int i = 1; i < size; i++)
    arr[i - 1] = arr[i];
  arr[size - 1] = temp;
}

// Home work #3
void VectorWithCapacityTrick::right_rotate(int n)
{
  // if number greater then size e.g(2000000000) get mod % by size because it is cycle
  n %= size;
  while (n--)
  {
    right_rotate();
  }
}

// Home work #4
int VectorWithCapacityTrick::pop(int idx)
{
  int temp = arr[idx];
  for (int i = idx; i < size; i++)
    arr[i] = arr[i + 1];
  size--;
  return temp;
}

// Home work #5
int VectorWithCapacityTrick::find_transposition(int value)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == value)
    {
      if (i == 0) // In case search find in index 0
        return 0;
      // swap operation
      int temp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = temp;
      return i - 1;
    }
  }
  return -1; // not found
}

int main()
{
  VectorWithCapacityTrick v(5);
  for (int i = 0; i < 5; i++)
  {
    v.set(i, i);
  }

  cout << "Vector Element: ";
  v.print();

  v.right_rotate(2000000000);
  v.print();

  v.pop(2);
  v.print();

  cout << v.find_transposition(2) << endl;
  cout << v.find_transposition(3) << endl;
  v.print();

  return 0;
}