# C++ STL (Standard Template Library) — Notes

## What is STL?
STL stands for **Standard Template Library**. It is a collection of pre-built **algorithms, containers, iterators, and functions** in C++ that saves you from writing lengthy code every time you need a container (like an array-like structure) or an algorithm. Instead of implementing these from scratch, STL gives you ready-to-use, optimized components.

---

## Basic C++ Code Skeleton

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code here
    return 0;
}
```

- `#include <bits/stdc++.h>` — This single header includes **all standard libraries** (math.h, string.h, etc.) so you don't need to include them one by one.
- `using namespace std;` — Without this line, you'd have to prefix everything with `std::` (e.g., `std::cin`, `std::cout`). This line lets you just write `cin`, `cout` directly.

---

## Functions Recap

### 1. Void Function (returns nothing)
```cpp
void print() {
    cout << "Raj";
}
```

### 2. Return-type Function
```cpp
int sum(int a, int b) {
    return a + b;
}

int s = sum(1, 5); // s = 6
cout << s;
```
The return type can be `int`, `double`, or any other data type.

---

## STL is divided into 4 parts:
1. **Algorithms**
2. **Containers** (vector, list, deque, stack, queue, set, map, etc.)
3. **Functions**
4. **Iterators**

---

## Pairs

Part of the **utility library**. Used to store two values together.

```cpp
pair<int, int> p = {1, 3};
cout << p.first;   // 1
cout << p.second;  // 3
```

- Data type can be anything: `int`, `double`, `string`, `char`, etc.
- `p.first` accesses the first value, `p.second` accesses the second value.

### Nested Pairs (storing more than 2 values)
```cpp
pair<int, pair<int, int>> p = {1, {3, 4}};

p.first;          // 1
p.second.first;   // 3
p.second.second;  // 4
```
You can nest pairs further to store 4, 5, or more values.

### Array of Pairs
```cpp
pair<int, int> arr[3];
arr[1].second; // access second element of pair at index 1
```
Pair can be used as a data type — even inside arrays.

---

## Vectors

A **vector** is a dynamic array — unlike a normal array (fixed size), a vector can grow or shrink in size at runtime. Use vector when you don't know the exact size needed beforehand.

### Declaration
```cpp
vector<int> v;
```

### Adding Elements
```cpp
v.push_back(1);     // adds 1 at the back
v.emplace_back(2);  // adds 2 at the back (generally faster than push_back)
```

### Vector of Pairs
```cpp
vector<pair<int,int>> v;
v.push_back({1, 2});     // needs curly braces
v.emplace_back(1, 2);    // no curly braces needed
```

### Declaring with Predefined Size
```cpp
vector<int> v(5, 100); // 5 elements, each = 100
vector<int> v(5);      // 5 elements, each = 0 (or garbage, compiler dependent)
```

### Copying a Vector
```cpp
vector<int> v2(v1); // v2 is a copy of v1
```

Even after declaring a fixed size, you can still `push_back()` more elements — vectors are always dynamic.

### Accessing Elements
```cpp
v[0];       // access like array
v.at(0);    // alternative (rarely used)
```

### Iterators
An iterator points to the **memory address** of an element (not the value itself).

```cpp
vector<int>::iterator it = v.begin();
cout << *it;      // dereference to get the value
it++;             // move to next memory location
```

- `v.begin()` → points to the first element.
- `v.end()` → points to memory location **right after** the last element (not the last element itself).
- `v.rbegin()` → reverse begin (points to last element, moves backward).
- `v.rend()` → reverse end (points right before first element).

> Note: `rbegin()`/`rend()` are rarely used in practice but good to know.

### Printing a Vector

**Method 1: Index-based loop**
```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

**Method 2: Iterator-based loop**
```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

**Method 3: Using `auto`**
`auto` automatically detects the data type — no need to explicitly write `vector<int>::iterator`.
```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

**Method 4: For-each loop**
```cpp
for (auto it : v) {
    cout << it << " ";
}
```

### Erase Function

**Erase a single element:**
```cpp
v.erase(v.begin() + 1); // deletes element at index 1
```

**Erase a range of elements:**
```cpp
v.erase(v.begin() + 1, v.begin() + 4);
// deletes elements from index 1 to 3 (index 4 is NOT included — "end" is excluded)
```

### Insert Function

**Insert a single element:**
```cpp
v.insert(v.begin(), 300);        // insert 300 at the beginning
v.insert(v.begin() + 1, 5);      // insert 5 at index 1
```

**Insert multiple copies of an element:**
```cpp
v.insert(v.begin() + 1, 2, 5); // insert two 5's starting at index 1
```

**Insert one vector into another:**
```cpp
v.insert(v.begin() + 1, v2.begin(), v2.end());
```

### Other Common Vector Functions

| Function | Description |
|---|---|
| `v.size()` | Returns number of elements |
| `v.pop_back()` | Removes the last element |
| `v.swap(v2)` | Swaps contents of two vectors |
| `v.clear()` | Empties the entire vector |
| `v.empty()` | Returns `true` if vector is empty, else `false` |

---

## List

Similar to vector, but also supports **front operations** efficiently.

```cpp
list<int> l;
l.push_back(4);
l.push_front(5);   // adds at front (cheap operation)
l.emplace_front(x);
```

- Internally implemented as a **doubly linked list** (vs. vector's array-based structure).
- `push_front()` is very cheap for a list, but inserting at the front of a vector is costly.
- All other functions (`begin`, `end`, `rbegin`, `rend`, `size`, `clear`, `empty`) work the same as in vector.

---

## Deque (DQ)

Similar to list and vector — supports operations at both ends.

```cpp
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
dq.back();
dq.front();
```

---

## Stack (LIFO)

**LIFO** = Last In, First Out — the last element added is the first one removed.

```cpp
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.emplace(5); // same as push

st.top();   // returns the last inserted element (does NOT remove it)
st.pop();   // removes the top element
st.size();  // number of elements
st.empty(); // true/false
st.swap(st2); // swaps two stacks
```

> **Important:** No random/index-based access is allowed in a stack — only `push`, `pop`, and `top`.
> All stack operations run in **O(1)** constant time.

---

## Queue (FIFO)

**FIFO** = First In, First Out — like a real-world queue/line, the first person in is the first to leave.

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(4);

q.back();   // returns/refers to the last element (can modify: q.back() += 5;)
q.front();  // returns the first element (does NOT remove it)
q.pop();    // removes the front element
q.size();
q.empty();
```

All operations run in **O(1)** constant time, similar to stack.

---

## Coming Up Next
- Priority Queue
- Set, Map
- STL Algorithms & Functions

---

### Quick Summary Table

| Container | Type | Key Feature |
|---|---|---|
| Pair | Utility | Stores 2 (or more, nested) values together |
| Vector | Dynamic array | Fast random access, costly front insert |
| List | Doubly linked list | Fast front/back insert, no random access |
| Deque | Double-ended queue | Fast insert/delete at both ends |
| Stack | LIFO | push, pop, top only |
| Queue | FIFO | push, pop, front, back only |