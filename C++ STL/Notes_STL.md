# C++ STL for DSA --- Complete Lecture Notes

> **Source:** Lecture transcript provided for this study note.\
> **Purpose:** DSA-focused C++ STL reference for revision, coding
> practice, and GitHub documentation.\
> **Scope:** STL basics, pairs, containers, iterators, and commonly used
> algorithms.

------------------------------------------------------------------------

## 1. What is STL?

**STL = Standard Template Library**

STL is a collection of ready-to-use components in C++ that makes DSA
implementation much shorter and easier.

Instead of manually implementing common data structures and algorithms,
STL provides reusable:

1.  **Containers**
2.  **Algorithms**
3.  **Iterators**
4.  **Function objects / functions**

### Why STL is important for DSA

In competitive programming, coding interviews, and DSA problems, we
frequently need operations such as:

-   storing a dynamic list of values
-   sorting values
-   finding an element
-   maintaining unique values
-   maintaining key-value pairs
-   implementing stacks and queues
-   generating permutations
-   finding minimum/maximum elements

STL provides these operations through concise syntax.

### Main STL categories

  -----------------------------------------------------------------------
  Category                Purpose                 Examples
  ----------------------- ----------------------- -----------------------
  Containers              Store data              `vector`, `list`,
                                                  `deque`, `stack`,
                                                  `queue`, `set`, `map`

  Algorithms              Perform operations      `sort`, `max_element`,
                                                  `min_element`,
                                                  `next_permutation`

  Iterators               Point/traverse          `begin()`, `end()`
                          container elements      

  Functions / Comparators Customize behavior      `greater<>`, custom
                                                  comparator
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# 2. Basic C++ Skeleton

For DSA practice, a common competitive-programming style is:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Code
    return 0;
}
```

## `#include <bits/stdc++.h>`

This is a commonly used header in competitive programming that includes
most standard C++ libraries at once.

Normally, individual headers can be included:

``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
```

But:

``` cpp
#include <bits/stdc++.h>
```

is convenient when working on DSA problems.

> **Note:** `bits/stdc++.h` is widely used in competitive programming
> but is not part of the official ISO C++ standard. For
> production/library code, prefer specific standard headers.

## `using namespace std`

Without it:

``` cpp
std::cout << "Hello";
std::vector<int> v;
```

With:

``` cpp
using namespace std;

cout << "Hello";
vector<int> v;
```

`std::` is the namespace qualifier used for standard-library components.

------------------------------------------------------------------------

# 3. Functions

A function is a reusable block of code.

## 3.1 Void function

A `void` function does not return a value.

``` cpp
void printName()
{
    cout << "Raj";
}
```

Calling:

``` cpp
printName();
```

Output:

``` text
Raj
```

## 3.2 Return-type function

A function can return a value.

``` cpp
int sum(int a, int b)
{
    return a + b;
}
```

Usage:

``` cpp
int s = sum(1, 5);
cout << s;
```

Output:

``` text
6
```

The return type does not have to be `int`. It can be:

``` cpp
double
char
string
bool
```

or other valid C++ types.

------------------------------------------------------------------------

# 4. Pairs

A `pair` is a utility type that stores **two values together**.

It is available through the standard utility functionality.

## Basic syntax

``` cpp
pair<int, int> p = {1, 3};
```

Here:

-   `p.first` → `1`
-   `p.second` → `3`

``` cpp
cout << p.first << endl;
cout << p.second << endl;
```

Output:

``` text
1
3
```

## Pair can contain different data types

``` cpp
pair<int, double> p1 = {10, 20.5};

pair<string, int> p2 = {"Subhranshu", 100};

pair<char, string> p3 = {'A', "Apple"};
```

The two types do not have to be the same.

------------------------------------------------------------------------

## 4.1 Nested Pair

A pair can itself contain another pair.

Example:

``` cpp
pair<int, pair<int, int>> p = {1, {3, 4}};
```

Logical structure:

``` text
p
├── first  = 1
└── second
    ├── first  = 3
    └── second = 4
```

Access:

``` cpp
p.first           // 1
p.second.first    // 3
p.second.second   // 4
```

This can technically be nested further, although for many values a
`tuple` or a custom `struct/class` may be clearer.

------------------------------------------------------------------------

## 4.2 Array of Pairs

A pair can be used as an element type.

``` cpp
pair<int, int> arr[] =
{
    {1, 2},
    {3, 4},
    {5, 6}
};
```

Access:

``` cpp
cout << arr[1].first;
cout << arr[1].second;
```

Output:

``` text
3
4
```

This concept is especially useful when storing:

-   coordinates
-   `(value, index)`
-   `(key, value)`
-   graph edges
-   pairs of related values

------------------------------------------------------------------------

# 5. Vector

## What is a Vector?

A `vector` is a dynamic sequence container.

It behaves similarly to an array but can dynamically grow or shrink.

### Array vs Vector

  Array                                   Vector
  --------------------------------------- ------------------------------
  Usually fixed-size after creation       Dynamic size
  Direct indexing                         Direct indexing
  `arr[i]`                                `v[i]`
  Size cannot normally grow dynamically   Can grow using `push_back()`
  Useful when size is known               Useful when size may change

Use a vector when the number of elements is not known in advance or when
you need a resizable sequence.

------------------------------------------------------------------------

## 5.1 Declaration

``` cpp
vector<int> v;
```

Other examples:

``` cpp
vector<double> v1;
vector<char> v2;
vector<string> v3;
```

A vector can also contain complex types:

``` cpp
vector<pair<int, int>> v;
```

------------------------------------------------------------------------

# 6. `push_back()`

`push_back()` adds an element at the end.

``` cpp
vector<int> v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
```

Vector:

``` text
1 2 3
```

------------------------------------------------------------------------

# 7. `emplace_back()`

`emplace_back()` constructs/inserts an element at the end.

``` cpp
vector<int> v;

v.emplace_back(1);
v.emplace_back(2);
```

For simple types such as `int`, the practical difference is usually
insignificant.

A useful difference appears with compound objects.

Example:

``` cpp
vector<pair<int, int>> v;

v.push_back({1, 2});
v.emplace_back(3, 4);
```
Here is the breakdown of why `emplace_back` and `push_back` are different when working with objects like `std::pair` or custom classes:

---

### The Key Difference: Construction vs. Copying

* **`push_back({1, 2})`**:
1. Creates a **temporary object** (a `std::pair<int, int>`) in memory using `{1, 2}`.
2. **Copies (or moves)** that temporary object into the vector's allocated memory.
3. **Destroys** the temporary object.


* **`emplace_back(1, 2)`**:
1. Forwards the arguments `1` and `2` directly to the vector's underlying memory.
2. **Constructs the object in-place** inside the vector.
3. No temporary object is created, and no extra copy/move operation happens.



---

### Comparison Summary

| Feature | `v.push_back({1, 2})` | `v.emplace_back(1, 2)` |
| --- | --- | --- |
| **Syntax** | Requires braces `{}` or explicit object type | Takes raw constructor parameters |
| **How it works** | Creates a temporary object first, then copies/moves it into the vector | Constructs the object directly inside the vector |
| **Performance** | Slightly slower for complex objects (extra copy/move) | Faster/more efficient for complex objects |
| **Primary Use Case** | When you already have an existing object to add | When you are creating a new object on the fly |

---

### Why It Matters with Custom Classes

For basic types like `int`, there is zero performance difference. However, for custom objects with heavy constructors or copy operations, `emplace_back` avoids unnecessary overhead:

```cpp
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

vector<Person> people;

// push_back needs braces or a fully formed object:
people.push_back(Person("Alice", 25)); // Temporary created -> moved -> destroyed

// emplace_back takes the arguments directly:
people.emplace_back("Bob", 30);         // Constructed directly inside the vector

```

The second form constructs the pair directly in the vector.

### Important syntax difference

``` cpp
v.push_back({1, 2});
```

vs.

``` cpp
v.emplace_back(1, 2);
```

------------------------------------------------------------------------

# 8. Vector Initialization

## 8.1 Empty vector

``` cpp
vector<int> v;
```

## 8.2 Size and value

``` cpp
vector<int> v(5, 100);
```

Creates:

``` text
100 100 100 100 100
```

Size = `5`.

## 8.3 Size only

``` cpp
vector<int> v(5);
```

For `int`, the elements are value-initialized to `0`:

``` text
0 0 0 0 0
```

> Do not describe this as "garbage values" for normal `vector<int>(5)`
> construction.

## 8.4 Initialize from another vector

``` cpp
vector<int> v1(5, 20);
vector<int> v2(v1);
```

`v2` becomes a copy of `v1`.

------------------------------------------------------------------------

# 9. Vector is Dynamic

Even if a vector is initially created with a size:

``` cpp
vector<int> v(5, 20);
```

you can still add more elements:

``` cpp
v.push_back(1);
```

Now the vector contains 6 elements.

This is a major difference from a fixed-size array.

------------------------------------------------------------------------

# 10. Accessing Vector Elements

Suppose:

``` cpp
vector<int> v = {20, 10, 15, 5, 7};
```

Indexes:

``` text
Index:   0   1   2   3   4
Value:  20  10  15   5   7
```

## Using `[]`

``` cpp
cout << v[0];
cout << v[3];
```

Output:

``` text
20
5
```

This is similar to an array.

## Using `.at()`

``` cpp
cout << v.at(3);
```

`.at()` performs bounds checking and can throw an exception for an
invalid index.

For typical DSA code, `v[i]` is very common.

------------------------------------------------------------------------

# 11. Iterators

An iterator is an object used to refer to elements/positions in a
container and traverse them.

For a vector:

``` cpp
vector<int>::iterator it;
```

But modern C++ commonly uses:

``` cpp
auto it = v.begin();
```

## `begin()`

``` cpp
v.begin()
```

returns an iterator referring to the first element.

To access the value:

``` cpp
*(v.begin())
```

The `*` operator dereferences the iterator.

Example:

``` cpp
vector<int> v = {20, 10, 15};

cout << *(v.begin());
```

Output:

``` text
20
```

------------------------------------------------------------------------

# 12. Iterator Movement

If:

``` cpp
auto it = v.begin();
```

then:

``` cpp
*it
```

gives the first value.

Moving:

``` cpp
it++;
```

moves to the next element.

You can also use:

``` cpp
it + 2
```

for random-access iterators such as vector iterators.

Example:

``` cpp
cout << *(v.begin() + 2);
```

This accesses the third element.

### Important idea

For a vector:

``` text
begin()
  ↓
[20] [10] [15] [5] [7]
```

`begin() + 1` → `10`

`begin() + 2` → `15`

`begin() + 3` → `5`

------------------------------------------------------------------------

# 13. `end()` Iterator

This is one of the most important STL concepts.

For:

``` cpp
vector<int> v = {10, 20, 30, 40};
```

conceptually:

``` text
begin()
  ↓
[10] [20] [30] [40] end()
                      ↑
              position after last
```

`v.end()` does **not** point to `40`.

It points to the position **just after the last element**.

Therefore:

``` cpp
*(v.end())
```

must not be used to access the last element.

To access the last element through the iterator:

``` cpp
auto it = v.end();
--it;

cout << *it;
```

Output:

``` text
40
```

------------------------------------------------------------------------

# 14. Reverse Iterators

Two commonly encountered reverse iterator functions are:

``` cpp
rbegin()
rend()
```

For:

``` text
10 20 30 40
```

`rbegin()` refers to the last element:

``` text
40
```

and moving forward on a reverse iterator traverses:

``` text
40 → 30 → 20 → 10
```

`rend()` refers to the position before the first element in reverse
traversal.

Example:

``` cpp
for (auto it = v.rbegin(); it != v.rend(); ++it)
{
    cout << *it << " ";
}
```

Output:

``` text
40 30 20 10
```

------------------------------------------------------------------------

# 15. `back()`

``` cpp
v.back()
```

returns the last element.

Example:

``` cpp
vector<int> v = {10, 20, 30};

cout << v.back();
```

Output:

``` text
30
```

------------------------------------------------------------------------

# 16. Printing a Vector

## Method 1 --- Index loop

``` cpp
for (int i = 0; i < v.size(); i++)
{
    cout << v[i] << " ";
}
```

## Method 2 --- Iterator

``` cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

## Method 3 --- Range-based for loop

``` cpp
for (auto x : v)
{
    cout << x << " ";
}
```
Here is a complete, runnable C++ program demonstrating all three methods of printing a vector, along with their output.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare and initialize a vector
    vector<int> v = {10, 20, 30, 40, 50};

    // Method 1: Index loop
    cout << "Method 1 (Index loop): ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Method 2: Iterator loop
    cout << "Method 2 (Iterator):   ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Method 3: Range-based for loop
    cout << "Method 3 (Range-based): ";
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

```

### Output

```text
Method 1 (Index loop): 10 20 30 40 50 
Method 2 (Iterator):   10 20 30 40 50 
Method 3 (Range-based): 10 20 30 40 50 

```

---

### When to use which method?

| Method | Best Used For | Notes |
| --- | --- | --- |
| **1. Index Loop** | When you need the index number `i` (e.g., printing element positions or stepping by 2). | Works like traditional C arrays. |
| **2. Iterator Loop** | When working with STL algorithms or containers without index access (like `std::set` or `std::list`). | Uses pointers under the hood (`*it`). |
| **3. Range-based Loop** | Cleanest option when you just need to read every element from start to end. | Use `for (const auto &x : v)` to avoid making copies of large objects. |
This is generally the cleanest for simply reading every value.

------------------------------------------------------------------------

# 17. `auto`

`auto` allows the compiler to deduce the variable's type from the
initializer.

Instead of:

``` cpp
vector<int>::iterator it = v.begin();
```

you can write:

``` cpp
auto it = v.begin();
```

Instead of:

``` cpp
int a = 5;
```

you can write:

``` cpp
auto a = 5;
```

`a` becomes an `int`.

Example:

``` cpp
auto s = string("hello");
```

`s` becomes a `string`.

### Key idea

> `auto` does not mean "no type"; the compiler determines the type at
> compile time.

------------------------------------------------------------------------

# 18. Erasing Elements from a Vector

## 18.1 Erase one element

Suppose:

``` cpp
vector<int> v = {10, 20, 12, 23};
```

To erase the second element:

``` cpp
v.erase(v.begin() + 1);
```

Before:

``` text
10 20 12 23
```

After:

``` text
10 12 23
```

The elements after the erased position shift left.

------------------------------------------------------------------------

# 19. Erasing a Range

Suppose:

``` text
10 20 30 40 50
```

To erase `20` and `30`:

``` cpp
v.erase(v.begin() + 1, v.begin() + 3);
```

Important rule:

> The range is **\[start, end)** --- start is included, end is excluded.

So:

``` cpp
v.erase(first, last);
```

means:

``` text
erase first
through
one position before last
```

Visual:

``` text
10 [20 30] 40 50
    ↑     ↑
  start   end
```

`end` itself is not erased.

------------------------------------------------------------------------

# 20. Insert into Vector

## 20.1 Insert one element

``` cpp
vector<int> v = {10, 20, 30, 40};

v.insert(v.begin(), 5);
```

Result:

``` text
5 10 20 30 40
```

Insert at position 1:

``` cpp
v.insert(v.begin() + 1, 15);
```

------------------------------------------------------------------------

## 20.2 Insert multiple copies

``` cpp
v.insert(v.begin() + 1, 2, 5);
```

This inserts two copies of `5`.

Example:

``` text
Before:
10 20 30 40

After:
10 5 5 20 30 40
```

------------------------------------------------------------------------

## 20.3 Insert another vector/range

``` cpp
vector<int> v1 = {30, 10, 100, 100};
vector<int> v2 = {50, 50};

v1.insert(v1.begin(), v2.begin(), v2.end());
```

The range from `v2.begin()` to `v2.end()` is inserted into `v1`.

------------------------------------------------------------------------

# 21. Important Vector Functions

  Function            Meaning
  ------------------- -----------------------------------------
  `push_back(x)`      Add `x` at the end
  `emplace_back(x)`   Construct/add at the end
  `pop_back()`        Remove last element
  `size()`            Number of elements
  `begin()`           Iterator to first element
  `end()`             Iterator to position after last element
  `rbegin()`          Reverse iterator to last element
  `rend()`            Reverse end position
  `front()`           First element
  `back()`            Last element
  `insert()`          Insert element/range
  `erase()`           Remove element/range
  `clear()`           Remove all elements
  `empty()`           Check whether vector is empty
  `swap()`            Swap contents of two vectors

Example:

``` cpp
vector<int> v = {1, 2, 3};

cout << v.size();   // 3
cout << v.front();  // 1
cout << v.back();   // 3

v.pop_back();       // {1, 2}

v.clear();          // {}
cout << v.empty();  // 1 (true)
```

------------------------------------------------------------------------

# 22. List

`list` is a dynamic sequence container based on a doubly linked-list
structure.

Declaration:

``` cpp
list<int> ls;
```

## Basic operations

``` cpp
ls.push_back(2);
ls.push_front(1);

ls.emplace_back(3);
ls.emplace_front(0);
```

Result:

``` text
0 1 2 3
```

It supports operations such as:

``` cpp
begin()
end()
rbegin()
rend()
front()
back()
size()
empty()
clear()
swap()
```

### Important difference from vector

A list provides efficient insertion/removal at known positions through
its linked-list structure, while vector stores elements contiguously and
insertion in the middle may require shifting/moving elements.

For DSA, remember:

> **Vector:** dynamic array / contiguous storage\
> **List:** doubly linked list

------------------------------------------------------------------------

# 23. Deque

`deque` means **double-ended queue**.

Declaration:

``` cpp
deque<int> dq;
```

It supports insertion and removal from both ends.

``` cpp
dq.push_back(2);
dq.push_front(1);

dq.pop_back();
dq.pop_front();
```

Useful functions:

``` cpp
front()
back()
push_front()
push_back()
pop_front()
pop_back()
size()
empty()
clear()
```

A deque also supports indexing:

``` cpp
cout << dq[0];
```

------------------------------------------------------------------------

# 24. Stack

A stack follows:

> **LIFO = Last In, First Out**

Example:

``` text
Push 1
Push 2
Push 3
Push 4

Top → 4
```

The last inserted element is removed first.

Declaration:

``` cpp
stack<int> st;
```

## Main operations

### `push()`

``` cpp
st.push(1);
st.push(2);
st.push(3);
```

### `top()`

``` cpp
cout << st.top();
```

Output:

``` text
3
```

`top()` only reads the top element. It does not remove it.

### `pop()`

``` cpp
st.pop();
```

Removes the top element.

### Other functions

``` cpp
st.size();
st.empty();
st.swap(st2);
```

### Important

A stack does **not** provide normal random indexing such as:

``` cpp
st[0]; // invalid
```

------------------------------------------------------------------------

# 25. Queue

A queue follows:

> **FIFO = First In, First Out**

Real-life example: people standing in a ticket line.

Declaration:

``` cpp
queue<int> q;
```

## Operations

``` cpp
q.push(1);
q.push(2);
q.push(4);
```

Logical order:

``` text
Front → 1 2 4 ← Back
```

### `front()`

``` cpp
cout << q.front();
```

Output:

``` text
1
```

### `back()`

``` cpp
cout << q.back();
```

Output:

``` text
4
```

### `pop()`

``` cpp
q.pop();
```

Removes the front element.

Now:

``` text
Front → 2 4
```

Other functions:

``` cpp
q.size();
q.empty();
q.swap(q2);
```

------------------------------------------------------------------------

# 26. Priority Queue

A priority queue gives priority to the largest element by default.

``` cpp
priority_queue<int> pq;
```

Example:

``` cpp
pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10);
```

Then:

``` cpp
cout << pq.top();
```

Output:

``` text
10
```

The largest value is at the top.

### Main functions

``` cpp
pq.push(x);
pq.top();
pq.pop();
pq.size();
pq.empty();
pq.swap(pq2);
```

### Important complexity

For a priority queue implemented as a heap:

  Operation     Complexity
  ----------- ------------
  `push()`      `O(log n)`
  `top()`           `O(1)`
  `pop()`       `O(log n)`

------------------------------------------------------------------------

# 27. Min Priority Queue

By default:

``` cpp
priority_queue<int>
```

is a max-heap.

To make a min-heap:

``` cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Example:

``` cpp
pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10);

cout << pq.top();
```

Output:

``` text
2
```

### Terminology

``` text
Max Heap → maximum element at top
Min Heap → minimum element at top
```
Your understanding and summary of **Min Priority Queue** is completely spot-on!

Here is a full, runnable example along with a clear breakdown of *why* the syntax looks the way it does:

---

### Complete Code Example

```cpp
#include <iostream>
#include <queue>   // Required for priority_queue
#include <vector>  // Required for underlying container type
#include <functional> // Required for std::greater

using namespace std;

int main() {
    // Declare a Min-Heap (smallest element at top)
    priority_queue<int, vector<int>, greater<int>> minPQ;

    // Push elements into the queue
    minPQ.push(5);
    minPQ.push(2);
    minPQ.push(8);
    minPQ.push(10);

    // Access the smallest element
    cout << "Smallest element (top): " << minPQ.top() << endl; // Output: 2

    // Printing and removing elements in ascending order
    cout << "Elements in order of priority (Min to Max): ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " "; // Print current minimum
        minPQ.pop();               // Remove current minimum
    }
    cout << endl;

    return 0;
}

```

### Output

```text
Smallest element (top): 2
Elements in order of priority (Min to Max): 2 5 8 10 

```

---

### Decoding the Syntax: `<int, vector<int>, greater<int>>`

When declaring a min-heap, C++ requires three template parameters:

```cpp
priority_queue< Type, Container, Comparator > pq;

```

1. **`int`** $\rightarrow$ The data type stored inside the queue.
2. **`vector<int>`** $\rightarrow$ The underlying container used to hold the heap elements (defaults to `vector`).
3. **`greater<int>`** $\rightarrow$ The comparison functor. By default, C++ uses `less<int>`, which creates a **Max-Heap**. Passing `greater<int>` flips the logic so smaller elements have higher priority.

---

### Quick Heap Summary for DSA

| Heap Type | Declaration | `pq.top()` Returns |
| --- | --- | --- |
| **Max Heap** *(Default)* | `priority_queue<int> pq;` | Largest element |
| **Min Heap** | `priority_queue<int, vector<int>, greater<int>> pq;` | Smallest element |

> **Key Complexity:**
> * **Push / Pop:** $O(\log N)$
> * **Top:** $O(1)$
> 
>
------------------------------------------------------------------------

# 28. Set

A `set` maintains:

1.  **Unique elements**
2.  **Sorted order**

Declaration:

``` cpp
set<int> st;
```

Example:

``` cpp
st.insert(1);
st.insert(2);
st.insert(2);
st.insert(4);
st.insert(3);
```

Result:

``` text
1 2 3 4
```

The duplicate `2` is stored only once.

### Core definition

> **Set = sorted + unique**

------------------------------------------------------------------------

# 29. `find()` in Set

``` cpp
auto it = st.find(3);
```

If `3` exists, the iterator points to `3`.

If the element does not exist:

``` cpp
st.find(6) == st.end()
```

So the standard pattern is:

``` cpp
if (st.find(x) != st.end())
{
    cout << "Found";
}
else
{
    cout << "Not Found";
}
```

------------------------------------------------------------------------

# 30. Erase in Set

You can erase by value:

``` cpp
st.erase(5);
```

Or using an iterator:

``` cpp
auto it = st.find(5);

if (it != st.end())
{
    st.erase(it);
}
```

You can also erase a range:

``` cpp
st.erase(first, last);
```

Again:

> **Start is included, end is excluded.**

------------------------------------------------------------------------

# 31. `count()` in Set

Because a set stores unique values:

``` cpp
st.count(x);
```

returns:

``` text
1 → x exists
0 → x does not exist
```

Example:

``` cpp
if (st.count(5))
{
    cout << "Present";
}
```

------------------------------------------------------------------------

# 32. Lower Bound and Upper Bound

A set also supports:

``` cpp
st.lower_bound(x);
st.upper_bound(x);
```

### `lower_bound(x)`

Returns an iterator to the first element that is **greater than or equal
to** `x`.

### `upper_bound(x)`

Returns an iterator to the first element that is **strictly greater
than** `x`.

These are important in sorted containers.
------------------------------------------------------------------------
Here is a complete, runnable C++ program demonstrating `lower_bound` and `upper_bound` with `std::set`, along with output and clear explanations of how edge cases behave.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    // std::set automatically keeps elements sorted and unique
    set<int> st = {10, 20, 30, 40, 50};

    cout << "Set contents: ";
    for (int x : st) cout << x << " ";
    cout << "\n\n";

    // --- CASE 1: Value exists in the set (x = 30) ---
    auto lb1 = st.lower_bound(30); // >= 30
    auto ub1 = st.upper_bound(30); // > 30

    cout << "--- Searching for 30 (Value Exists) ---\n";
    cout << "lower_bound(30): " << *lb1 << " (First element >= 30)\n";
    cout << "upper_bound(30): " << *ub1 << " (First element > 30)\n\n";

    // --- CASE 2: Value does NOT exist in the set (x = 25) ---
    auto lb2 = st.lower_bound(25); // >= 25
    auto ub2 = st.upper_bound(25); // > 25

    cout << "--- Searching for 25 (Value Missing) ---\n";
    cout << "lower_bound(25): " << *lb2 << " (First element >= 25)\n";
    cout << "upper_bound(25): " << *ub2 << " (First element > 25)\n\n";

    // --- CASE 3: Value is larger than all elements (x = 60) ---
    auto lb3 = st.lower_bound(60);

    cout << "--- Searching for 60 (Out of Bounds) ---\n";
    if (lb3 == st.end()) {
        cout << "lower_bound(60): Reached st.end() (No element >= 60)\n";
    }

    return 0;
}

```

### Output

```text
Set contents: 10 20 30 40 50 

--- Searching for 30 (Value Exists) ---
lower_bound(30): 30 (First element >= 30)
upper_bound(30): 40 (First element > 30)

--- Searching for 25 (Value Missing) ---
lower_bound(25): 30 (First element >= 25)
upper_bound(25): 30 (First element > 25)

--- Searching for 60 (Out of Bounds) ---
lower_bound(60): Reached st.end() (No element >= 60)

```

---

### Key Takeaways

| Query ($x$) | `lower_bound(x)` ($\ge x$) | `upper_bound(x)` ($> x$) | Notes |
| --- | --- | --- | --- |
| **`30`** (present) | `30` | `40` | `lower_bound` points to the element itself; `upper_bound` skips to the next one. |
| **`25`** (missing) | `30` | `30` | Both point to `30` because it's the first element greater than `25`. |
| **`60`** (out of bounds) | `st.end()` | `st.end()` | Always check if the returned iterator equals `st.end()` before dereferencing (`*it`) to avoid segmentation faults! |

> **Time Complexity:**
> Both `st.lower_bound()` and `st.upper_bound()` run in **$O(\log N)$** time because `std::set` is implemented as a balanced binary search tree (Red-Black Tree).

------------------------------------------------------------------------

# 33. Set Complexity

For the standard ordered `set` implementation:

  Operation      Complexity
  ------------ ------------
  `insert()`     `O(log n)`
  `erase()`      `O(log n)`
  `find()`       `O(log n)`
  `count()`      `O(log n)`

------------------------------------------------------------------------

# 34. Multiset

A `multiset` is similar to `set`, but it **allows duplicate values**.

Declaration:

``` cpp
multiset<int> ms;
```

Example:

``` cpp
ms.insert(1);
ms.insert(1);
ms.insert(1);
ms.insert(2);
ms.insert(3);
```

Result:

``` text
1 1 1 2 3
```

### Definition

> **Multiset = sorted + duplicates allowed**

------------------------------------------------------------------------

## 34.1 Erase by Value

``` cpp
ms.erase(1);
```

This removes **all occurrences** of `1`.

If the multiset is:

``` text
1 1 1 2 3
```

after:

``` cpp
ms.erase(1);
```

it becomes:

``` text
2 3
```

## 34.2 Erase One Occurrence

To erase only one occurrence:

``` cpp
auto it = ms.find(1);

if (it != ms.end())
{
    ms.erase(it);
}
```

This removes only the element referred to by that iterator.

## 34.3 Erase a Range

``` cpp
ms.erase(first, last);
```

Again, `last` is excluded.

------------------------------------------------------------------------

# 35. Unordered Set

`unordered_set` provides:

-   unique elements
-   no sorted-order guarantee

Declaration:

``` cpp
unordered_set<int> us;
```

Example:

``` cpp
us.insert(1);
us.insert(5);
us.insert(2);
us.insert(3);
us.insert(1);
```

The duplicate `1` is not stored twice.

The iteration order is not guaranteed to be sorted.

### Complexity

Average-case:

  Operation      Average
  ------------ ---------
  `insert()`      `O(1)`
  `erase()`       `O(1)`
  `find()`        `O(1)`
  `count()`       `O(1)`

Worst-case for hash-table operations can become `O(n)`.

### Important

`lower_bound()` and `upper_bound()` are ordered-container operations and
are not provided by `unordered_set`.

------------------------------------------------------------------------

# 36. Map

A `map` stores data as:

``` text
key → value
```

Example:

``` text
Roll Number → Student Name
```

A key identifies a particular entry.

Declaration:

``` cpp
map<int, string> mp;
```

Here:

-   key = `int`
-   value = `string`

------------------------------------------------------------------------

# 37. Map Properties

A standard ordered `map` has:

1.  **Unique keys**
2.  **Keys sorted in ascending order by default**
3.  Values can be duplicated
4.  Each element is essentially a key-value pair

Example:

``` cpp
map<int, string> mp;

mp[23] = "Raj";
mp[25] = "Amit";
mp[28] = "Raj";
```

Duplicate values are allowed:

``` text
23 → Raj
25 → Amit
28 → Raj
```

But keys must be unique.

------------------------------------------------------------------------

# 38. Inserting into Map

## Using `[]`

``` cpp
mp[1] = 2;
mp[3] = 1;
mp[2] = 4;
```

Result is ordered by key:

``` text
1 → 2
2 → 4
3 → 1
```

## Using `insert()`

``` cpp
mp.insert({4, 10});
```

## Using `emplace()`

``` cpp
mp.emplace(5, 20);
```

------------------------------------------------------------------------

# 39. Accessing Map Values

``` cpp
cout << mp[1];
```

If:

``` text
1 → 2
```

output is:

``` text
2
```

### Important caution

Using `mp[key]` for a key that does not exist can insert that key with a
default-initialized value.

Example:

``` cpp
map<int, int> mp;

cout << mp[5];
```

`5` was absent, so accessing it this way can create:

``` text
5 → 0
```

For checking existence without insertion, prefer:

``` cpp
mp.find(5)
```

or:

``` cpp
mp.count(5)
```

------------------------------------------------------------------------

# 40. Traversing a Map

A map element behaves like a pair:

``` cpp
for (auto it = mp.begin(); it != mp.end(); ++it)
{
    cout << it->first << " " << it->second << endl;
}
```

Here:

``` cpp
it->first
```

is the key.

``` cpp
it->second
```

is the value.

### Range-based loop

``` cpp
for (auto it : mp)
{
    cout << it.first << " " << it.second << endl;
}
```

------------------------------------------------------------------------

# 41. Finding in Map

``` cpp
auto it = mp.find(3);
```

If key `3` exists, the iterator points to its key-value pair.

Access:

``` cpp
cout << it->first;
cout << it->second;
```

If the key does not exist:

``` cpp
it == mp.end()
```

------------------------------------------------------------------------

# 42. Map Lower and Upper Bound

Ordered maps support:

``` cpp
mp.lower_bound(key);
mp.upper_bound(key);
```

The meaning is based on the sorted keys.

Other common functions:

``` cpp
mp.size();
mp.empty();
mp.erase();
mp.clear();
mp.swap();
```

------------------------------------------------------------------------

# 43. Multimap

A `multimap` is similar to `map`, but duplicate keys are allowed.

Declaration:

``` cpp
multimap<int, string> mmap;
```

Example:

``` cpp
mmap.insert({1, "A"});
mmap.insert({1, "B"});
mmap.insert({2, "C"});
```

Possible logical contents:

``` text
1 → A
1 → B
2 → C
```

Properties:

-   keys are sorted
-   duplicate keys are allowed
-   each key can have multiple associated values

------------------------------------------------------------------------

# 44. Unordered Map

`unordered_map` stores:

-   unique keys
-   no sorted-order guarantee

Declaration:

``` cpp
unordered_map<int, string> ump;
```

Example:

``` cpp
ump[1] = "A";
ump[5] = "B";
ump[2] = "C";
```

The iteration order is not guaranteed to be:

``` text
1 2 5
```

### Complexity

Average-case:

``` text
insert   → O(1)
find     → O(1)
erase    → O(1)
count    → O(1)
```

Worst-case can be:

``` text
O(n)
```

### Map vs Unordered Map

  `map`                          `unordered_map`
  ------------------------------ ----------------------
  Unique keys                    Unique keys
  Keys sorted                    No sorting guarantee
  Usually `O(log n)`             Average `O(1)`
  Tree-based ordered structure   Hash-table based

------------------------------------------------------------------------

# 45. Container Comparison Cheat Sheet

  ------------------------------------------------------------------------
  Container       /     Duplicate   /      Ordered      /    Main Use
  ------------------ ----------------- ----------------- -----------------
  `vector`           Yes               Insertion order   Dynamic array

  `list`             Yes               Insertion order   Linked-list
                                                         operations

  `deque`            Yes               Insertion order   Both-end
                                                         operations

  `stack`            Yes               LIFO              Stack problems

  `queue`            Yes               FIFO              Queue problems

  `priority_queue`   Yes               Priority order    Heap / priority
                                                         problems

  `set`              No                Sorted            Unique sorted
                                                         values

  `multiset`         Yes               Sorted            Sorted duplicate
                                                         values

  `unordered_set`    No                No guaranteed     Fast average
                                       order             lookup

  `map`              Unique keys       Sorted by key     Key-value data

  `multimap`         Duplicate keys    Sorted by key     Multiple values
                                                         per key

  `unordered_map`    Unique keys       No guaranteed     Fast average
                                       order             key-value lookup
  ------------------------------------------------------------------------

------------------------------------------------------------------------

# 46. STL Algorithms

STL also provides ready-made algorithms.

Instead of manually implementing sorting algorithms such as:

-   Bubble Sort
-   Selection Sort
-   Insertion Sort

you can use:

``` cpp
sort(...)
```

------------------------------------------------------------------------

# 47. `sort()`

For an array:

``` cpp
int a[] = {5, 1, 3, 2};
int n = 4;

sort(a, a + n);
```

Result:

``` text
1 2 3 5
```

For a vector:

``` cpp
vector<int> v = {5, 1, 3, 2};

sort(v.begin(), v.end());
```

Result:

``` text
1 2 3 5
```

### Range rule

The range is:

``` cpp
[start, end)
```

Start is included.

End is excluded.

------------------------------------------------------------------------

# 48. Sort Only a Portion

Suppose:

``` cpp
vector<int> v = {5, 4, 3, 2, 1};
```

To sort only positions `1` through `3`:

``` cpp
sort(v.begin() + 1, v.begin() + 4);
```

The element at `v.begin() + 4` is excluded.

------------------------------------------------------------------------

# 49. Descending Sort

Use the built-in comparator:

``` cpp
greater<int>()
```

Example:

``` cpp
sort(v.begin(), v.end(), greater<int>());
```

Result:

``` text
5 4 3 2 1
```

Conceptually:

``` cpp
greater<int>()
```

tells `sort()` to arrange values in descending order.


Your summaries for `std::sort` are spot on!

Here is a full C++ program compiling all these sorting concepts together for quick reference:

---

### Complete Code Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <functional> // Required for std::greater

using namespace std;

// Helper function to print vectors cleanly
void printVector(const string& label, const vector<int>& v) {
    cout << label << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    // ---------------------------------------------------------
    // 47. Sorting Full Array & Full Vector
    // ---------------------------------------------------------
    int a[] = {5, 1, 3, 2};
    int n = 4;
    sort(a, a + n);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n\n";

    vector<int> v1 = {5, 1, 3, 2};
    sort(v1.begin(), v1.end());
    printVector("Sorted Full Vector", v1);
    cout << endl;

    // ---------------------------------------------------------
    // 48. Sorting Only a Portion [start, end)
    // ---------------------------------------------------------
    vector<int> v2 = {5, 4, 3, 2, 1};
    // Index positions: 0, 1, 2, 3, 4
    // Values:        {5, 4, 3, 2, 1}
    
    // Sorts elements at indices 1, 2, and 3 (excluding index 4)
    sort(v2.begin() + 1, v2.begin() + 4); 
    printVector("Portion Sorted (Indices 1 to 3)", v2);
    // Output: 5 2 3 4 1
    cout << endl;

    // ---------------------------------------------------------
    // 49. Descending Sort using greater<int>()
    // ---------------------------------------------------------
    vector<int> v3 = {1, 3, 2, 5, 4};
    sort(v3.begin(), v3.end(), greater<int>());
    printVector("Descending Sort", v3);

    return 0;
}

```

### Output

```text
Sorted Array: 1 2 3 5 

Sorted Full Vector: 1 2 3 5 

Portion Sorted (Indices 1 to 3): 5 2 3 4 1 

Descending Sort: 5 4 3 2 1 

```

---

### Summary Table for `std::sort`

| Target | Code | Time Complexity |
| --- | --- | --- |
| **Array (Ascending)** | `sort(a, a + n);` | $O(N \log N)$ |
| **Vector (Ascending)** | `sort(v.begin(), v.end());` | $O(N \log N)$ |
| **Sub-range (Ascending)** | `sort(v.begin() + L, v.begin() + R + 1);` *(for range $[L, R]$)* | $O(K \log K)$ *(where $K = R - L + 1$)* |
| **Vector (Descending)** | `sort(v.begin(), v.end(), greater<int>());` | $O(N \log N)$ |

> **Key Takeaway for DSA:**
> `std::sort()` in C++ uses **IntroSort** (a hybrid of QuickSort, HeapSort, and InsertionSort), guaranteeing worst-case performance of **$O(N \log N)$**.
------------------------------------------------------------------------

# 50. Custom Comparator

Sometimes normal ascending or descending sorting is not enough.

Example:

``` cpp
vector<pair<int, int>> v =
{
    {1, 2},
    {2, 1},
    {4, 1}
};
```

Requirement:

1.  Sort by the **second element in increasing order**.
2.  If the second elements are equal, sort by the **first element in
    decreasing order**.

Expected result:

``` text
{4, 1}
{2, 1}
{1, 2}
```

------------------------------------------------------------------------

# 51. Writing a Comparator

``` cpp
bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;

    if (p1.second > p2.second)
        return false;

    return p1.first > p2.first;
}
```

Use:

``` cpp
sort(v.begin(), v.end(), comparator);
```

------------------------------------------------------------------------

# 52. How to Think About a Comparator

This is the most important way to understand custom comparators.

Do **not** think about the entire array first.

Take only two elements:

``` text
p1
p2
```

Ask:

> Should `p1` come before `p2`?

Return:

``` text
true  → p1 should come before p2
false → p1 should not come before p2
```

For our requirement:

### Case 1 --- second values are different

If:

``` text
p1.second < p2.second
```

then `p1` should come first.

Return:

``` cpp
true;
```

If:

``` text
p1.second > p2.second
```

then `p1` should not come first.

Return:

``` cpp
false;
```

### Case 2 --- second values are equal

Now compare first values.

Requirement is decreasing order:

``` cpp
return p1.first > p2.first;
```

------------------------------------------------------------------------

# 53. Comparator Mental Model

Whenever a problem says:

> "Sort in my own way"

follow these steps:

### Step 1

Identify the data type.

Example:

``` cpp
pair<int, int>
```

### Step 2

Take two objects:

``` cpp
p1
p2
```

### Step 3

Ask:

> Should `p1` come before `p2`?

### Step 4

Return `true` if yes, otherwise `false`.

This approach makes custom sorting much easier.
Your mental model for custom comparators is **100% correct** and is the single best way to approach sorting logic in C++!

Taking just two elements `p1` and `p2` and asking *"Should `p1` come before `p2`?"* avoids getting confused by the full array.



---

### Complete Executable Code

```cpp
#include <iostream>
#include <vector>
#include <utility>   // For std::pair
#include <algorithm> // For std::sort

using namespace std;

// Step 1 & 2: Identify data type and accept two parameters
bool comparator(pair<int, int> p1, pair<int, int> p2) {
    // Case 1: If second elements are different, 
    // smaller second element comes first (increasing order)
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    // Case 2: If second elements are equal, 
    // larger first element comes first (decreasing order)
    return p1.first > p2.first;
}

int main() {
    vector<pair<int, int>> v = {
        {1, 2},
        {2, 1},
        {4, 1}
    };

    // Pass the function name as the 3rd argument
    sort(v.begin(), v.end(), comparator);

    // Print the sorted vector
    cout << "Sorted pairs:\n";
    for (auto p : v) {
        cout << "{" << p.first << ", " << p.second << "}\n";
    }

    return 0;
}

```

### Output

```text
Sorted pairs:
{4, 1}
{2, 1}
{1, 2}

```

---

### Pro-Tips & Common Gotchas for C++ Comparators

#### 1. Avoid Duplicate Logic (Shorter Version)

Instead of checking `p1.second < p2.second` and `p1.second > p2.second` separately, you can handle it like this:

```cpp
bool comparator(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second != p2.second) {
        return p1.second < p2.second; // Increasing by second
    }
    return p1.first > p2.first;      // Decreasing by first
}

```

#### 2. Pass by Reference (`const &`)

Notice the `const pair<int, int>&` above. Passing parameters by **const reference** prevents C++ from making unnecessary copies of objects during every comparison, making your code significantly faster.

#### 3. Strict Weak Ordering (Crucial Rule!)

Never return `true` when two elements are equal in value. Returning `true` for equal values causes undefined behavior (and can lead to runtime errors/segmentation faults) because C++ requires a **Strict Weak Ordering** relationship.

> **Example:**
> If `p1 == p2`, the comparator **must** return `false`.

------------------------------------------------------------------------

# 54. `__builtin_popcount()`

`__builtin_popcount()` counts the number of set bits (`1`s) in the
binary representation of an unsigned integer-type value.

Example:

``` text
7 = 111
```

There are 3 set bits.

``` cpp
cout << __builtin_popcount(7);
```

Output:

``` text
3
```

Another example:

``` text
6 = 110
```

Number of set bits:

``` text
2
```

``` cpp
cout << __builtin_popcount(6);
```

Output:

``` text
2
```

------------------------------------------------------------------------

# 55. `__builtin_popcountll()`

For `long long` values:

``` cpp
__builtin_popcountll(x)
```

Example:

``` cpp
long long x = 15;

cout << __builtin_popcountll(x);
```

Output:

``` text
4
```

because:

``` text
15 = 1111
```

------------------------------------------------------------------------

# 56. `next_permutation()`

`next_permutation()` generates the next lexicographically greater
permutation.

Example:

``` cpp
string s = "123";

do
{
    cout << s << endl;
}
while (next_permutation(s.begin(), s.end()));
```

Output:

``` text
123
132
213
231
312
321
```

There are:

``` text
3! = 6
```

permutations.

------------------------------------------------------------------------

# 57. Important Rule for All Permutations

If you want to generate **all** permutations using repeated
`next_permutation()`, start from the sorted sequence.

Correct:

``` cpp
string s = "123";
```

or:

``` cpp
sort(s.begin(), s.end());
```

Then:

``` cpp
do
{
    cout << s << endl;
}
while (next_permutation(s.begin(), s.end()));
```

Why?

`next_permutation()` moves forward from the current lexicographical
arrangement. If you start in the middle, it will not automatically
generate the permutations that come before it.

Example:

``` text
Start = 231

next:
312
321

then no next permutation
```

So starting with sorted order is important when the goal is to enumerate
every permutation.

------------------------------------------------------------------------

# 58. `max_element()`

`max_element()` returns an iterator to the maximum element in a range.

Example:

``` cpp
vector<int> v = {1, 7, 5, 6};

auto it = max_element(v.begin(), v.end());
```

`it` points to `7`.

To get the value:

``` cpp
cout << *it;
```

Output:

``` text
7
```

### Important

`max_element()` returns an **iterator**, not directly the value.

------------------------------------------------------------------------

# 59. `min_element()`

Similarly:

``` cpp
auto it = min_element(v.begin(), v.end());

cout << *it;
```

returns the minimum value.

Example:

``` text
1 7 5 6
```

Output:

``` text
1
```

------------------------------------------------------------------------

# 60. Most Important STL Algorithms for DSA

The lecture focuses on these commonly useful algorithms:

| STL Algorithm | Purpose |
| :--- | :--- |
| `sort()` | Sort a range |
| `greater<>` | Descending/custom ordering helper |
| `__builtin_popcount()` | Count set bits |
| `__builtin_popcountll()` | Count set bits in `long long` |
| `next_permutation()` | Generate next lexicographical permutation |
| `max_element()` | Find maximum element |
| `min_element()` | Find minimum element |

There are many more STL algorithms, but you can learn additional ones as needed while solving problems.

------------------------------------------------------------------------

# 61. Iterator Rules to Remember

This is one of the most important sections for DSA.

### `begin()`

Points to the first element.

``` cpp
v.begin()
```

### `end()`

Points just after the last element.

``` cpp
v.end()
```

### `rbegin()`

Points to the last element for reverse traversal.

``` cpp
v.rbegin()
```

### `rend()`

Points just before the first element in reverse traversal.

``` cpp
v.rend()
```

### Dereference

``` cpp
*it
```

gets the element referred to by iterator `it`.

------------------------------------------------------------------------

# 62. The `[start, end)` Rule

STL heavily uses half-open ranges:

``` text
[start, end)
```

Meaning:

``` text
start → included
end   → excluded
```

Examples:

``` cpp
sort(v.begin(), v.end());
v.erase(v.begin() + 1, v.begin() + 3);
```

For:

``` text
10 20 30 40
```

``` cpp
v.erase(v.begin() + 1, v.begin() + 3);
```

removes:

``` text
20 30
```

but not `40`.

### Memory trick

> **Start stays, End escapes.**

------------------------------------------------------------------------

# 63. Important STL Complexity Summary

  Container / Operation                      Complexity
  ---------------------------------- ------------------
  Vector random access `v[i]`                    `O(1)`
  Vector `push_back()`                 Amortized `O(1)`
  Vector `pop_back()`                            `O(1)`
  Vector insertion/erase in middle               `O(n)`
  Stack `push()`                                 `O(1)`
  Stack `pop()`                                  `O(1)`
  Stack `top()`                                  `O(1)`
  Queue `push()`                                 `O(1)`
  Queue `pop()`                                  `O(1)`
  Queue `front()`                                `O(1)`
  Queue `back()`                                 `O(1)`
  Priority queue `push()`                    `O(log n)`
  Priority queue `pop()`                     `O(log n)`
  Priority queue `top()`                         `O(1)`
  Set `insert()`                             `O(log n)`
  Set `find()`                               `O(log n)`
  Set `erase()`                              `O(log n)`
  Map `insert()`                             `O(log n)`
  Map `find()`                               `O(log n)`
  Map `erase()`                              `O(log n)`
  Unordered set average operations               `O(1)`
  Unordered map average operations               `O(1)`
  Unordered set/map worst case                   `O(n)`
  `max_element()`                                `O(n)`
  `min_element()`                                `O(n)`
  `sort()`                                 `O(n log n)`

> Complexity can depend on the specific operation and iterator/container
> type. The table above is the standard DSA-level summary.

------------------------------------------------------------------------

# 64. Quick Revision --- "What Should I Remember?"

## Pair

``` cpp
pair<int, int> p = {1, 2};

p.first;
p.second;
```

Remember:

> **Pair = two related values**

------------------------------------------------------------------------

## Vector

``` cpp
vector<int> v;

v.push_back(10);
v.pop_back();

v.size();
v.empty();

v.front();
v.back();

v.begin();
v.end();

v.insert(...);
v.erase(...);
v.clear();
```

Remember:

> **Vector = dynamic array**

------------------------------------------------------------------------

## List

``` cpp
list<int> ls;

ls.push_front(10);
ls.push_back(20);

ls.pop_front();
ls.pop_back();
```

Remember:

> **List = doubly linked list + efficient insertion/removal at known
> positions**

------------------------------------------------------------------------

## Deque

``` cpp
deque<int> dq;

dq.push_front(1);
dq.push_back(2);

dq.pop_front();
dq.pop_back();
```

Remember:

> **Deque = insertion/removal from both ends**

------------------------------------------------------------------------

## Stack

``` cpp
stack<int> st;

st.push(10);
st.top();
st.pop();
```

Remember:

> **Stack = LIFO**

------------------------------------------------------------------------

## Queue

``` cpp
queue<int> q;

q.push(10);
q.front();
q.back();
q.pop();
```

Remember:

> **Queue = FIFO**

------------------------------------------------------------------------

## Priority Queue

``` cpp
priority_queue<int> pq;
```

Remember:

> **Default = maximum element at top**

Min-heap:

``` cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

------------------------------------------------------------------------

## Set

``` cpp
set<int> st;
```

Remember:

> **Set = sorted + unique**

Important:

``` cpp
insert()
find()
count()
erase()
lower_bound()
upper_bound()
```

------------------------------------------------------------------------

## Multiset

``` cpp
multiset<int> ms;
```

Remember:

> **Multiset = sorted + duplicates allowed**

------------------------------------------------------------------------

## Unordered Set

``` cpp
unordered_set<int> us;
```

Remember:

> **Unique + no sorted-order guarantee + average O(1) lookup**

------------------------------------------------------------------------

## Map

``` cpp
map<int, int> mp;
```

Remember:

> **Unique keys + sorted keys + key-value pairs**

------------------------------------------------------------------------

## Multimap

``` cpp
multimap<int, int> mp;
```

Remember:

> **Sorted keys + duplicate keys allowed**

------------------------------------------------------------------------

## Unordered Map

``` cpp
unordered_map<int, int> ump;
```

Remember:

> **Unique keys + no sorted-order guarantee + average O(1) lookup**

------------------------------------------------------------------------

# 65. Most Important Code Templates

## Vector traversal

``` cpp
for (auto x : v)
{
    cout << x << " ";
}
```

## Iterator traversal

``` cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

## Set existence

``` cpp
if (st.find(x) != st.end())
{
    cout << "Found";
}
```

## Map traversal

``` cpp
for (auto it : mp)
{
    cout << it.first << " " << it.second << endl;
}
```

## Sorting

``` cpp
sort(v.begin(), v.end());
```

## Descending sort

``` cpp
sort(v.begin(), v.end(), greater<int>());
```

## Maximum

``` cpp
int mx = *max_element(v.begin(), v.end());
```

## Minimum

``` cpp
int mn = *min_element(v.begin(), v.end());
```

## Set-bit count

``` cpp
int count = __builtin_popcount(x);
```

For `long long`:

``` cpp
int count = __builtin_popcountll(x);
```

## All permutations

``` cpp
sort(s.begin(), s.end());

do
{
    cout << s << endl;
}
while (next_permutation(s.begin(), s.end()));
```

------------------------------------------------------------------------

# 66. Final Mental Map

Think about STL like this:

``` text
C++ STL
│
├── Containers
│   │
│   ├── Sequence
│   │   ├── vector
│   │   ├── list
│   │   └── deque
│   │
│   ├── Container Adapters
│   │   ├── stack
│   │   ├── queue
│   │   └── priority_queue
│   │
│   └── Associative / Unordered
│       ├── set
│       ├── multiset
│       ├── unordered_set
│       ├── map
│       ├── multimap
│       └── unordered_map
│
├── Utility
│   └── pair
│
├── Iterators
│   ├── begin()
│   ├── end()
│   ├── rbegin()
│   └── rend()
│
└── Algorithms
    ├── sort()
    ├── max_element()
    ├── min_element()
    ├── next_permutation()
    ├── __builtin_popcount()
    └── __builtin_popcountll()
```

------------------------------------------------------------------------

# 67. Final Revision Checklist

Before moving forward with DSA, make sure you can explain and code these
without looking at notes:

-   [ ] What is STL?
-   [ ] Why is STL useful in DSA?
-   [ ] What is a pair?
-   [ ] How to access `first` and `second`?
-   [ ] What is nested pair?
-   [ ] What is a vector?
-   [ ] Difference between array and vector?
-   [ ] `push_back()` vs `emplace_back()`
-   [ ] Vector initialization
-   [ ] `size()`, `empty()`, `clear()`
-   [ ] `front()` and `back()`
-   [ ] `begin()` and `end()`
-   [ ] `rbegin()` and `rend()`
-   [ ] Iterator dereferencing using `*`
-   [ ] `auto`
-   [ ] Vector `insert()` and `erase()`
-   [ ] List and vector difference
-   [ ] Deque
-   [ ] Stack and LIFO
-   [ ] Queue and FIFO
-   [ ] Priority queue
-   [ ] Max heap vs min heap
-   [ ] Set = sorted + unique
-   [ ] Multiset = sorted + duplicates
-   [ ] Unordered set
-   [ ] Map = unique sorted keys + values
-   [ ] Multimap
-   [ ] Unordered map
-   [ ] `find()`
-   [ ] `count()`
-   [ ] `lower_bound()` and `upper_bound()`
-   [ ] `[start, end)` range rule
-   [ ] `sort()`
-   [ ] Descending sort
-   [ ] Custom comparator
-   [ ] How to reason about a comparator using two objects
-   [ ] `__builtin_popcount()`
-   [ ] `__builtin_popcountll()`
-   [ ] `next_permutation()`
-   [ ] `max_element()`
-   [ ] `min_element()`
-   [ ] Basic STL time complexities

------------------------------------------------------------------------

# 68. One-Page Memory Summary

``` text
PAIR
→ two values
→ first / second

VECTOR
→ dynamic array
→ push_back / emplace_back
→ insert / erase
→ front / back
→ begin / end

LIST
→ doubly linked list
→ push_front / push_back
→ pop_front / pop_back

DEQUE
→ double-ended
→ push/pop from both ends

STACK
→ LIFO
→ push / pop / top

QUEUE
→ FIFO
→ push / pop / front / back

PRIORITY QUEUE
→ default max heap
→ top = largest
→ min heap with greater<>

SET
→ sorted + unique

MULTISET
→ sorted + duplicates

UNORDERED SET
→ unique + no sorted order
→ average O(1)

MAP
→ key → value
→ unique sorted keys

MULTIMAP
→ sorted keys + duplicate keys

UNORDERED MAP
→ unique keys + no sorted order
→ average O(1)

ITERATORS
→ begin = first
→ end = after last
→ rbegin = last
→ rend = before first
→ *it = value

ALGORITHMS
→ sort
→ max_element
→ min_element
→ next_permutation
→ __builtin_popcount
→ __builtin_popcountll

RANGE
→ [start, end)
→ start included
→ end excluded

CUSTOM SORT
→ compare two objects
→ true = first object should come before second
```

------------------------------------------------------------------------

## Important Study Advice

Do not try to memorize every STL function at once.

For DSA, first become comfortable with:

``` text
pair
vector
iterator
stack
queue
priority_queue
set
map
unordered_set
unordered_map
sort
custom comparator
next_permutation
max_element
min_element
```

Then learn additional STL functions naturally while solving problems.

The goal is not only to remember syntax. You should understand **which
container fits which problem** and the **time complexity of the
operations you use**.
