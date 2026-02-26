# AStarAlgorithm Project

The A Star Algorithm (A* Algorithm) is a pathfinding and graph traversal algorithm used to find the shortest path between a start node and a goal node. It is commonly used by Google Maps and in many tower defense games.

## Week 1

### Initial Research

To begin the project, I started by looking at the GeeksforGeeks link that Michelle linked on moodle.
- https://www.geeksforgeeks.org/dsa/a-search-algorithm/<br>

This gave me some information on what the A* algorithm is and what it is used for. It outlined how the A* algorithm has 'brains' compared to other traversal techniques. There was also an explanation given which described in more technical detail how the A* algorithm works. Here is a summary of this:<br>

The A* Search Algorithm is used to find the shortest path between a starting cell and a target cell on a grid that may contain obstacles. At each step, A* selects the next cell based on a value called: 
- **`f = g + h`**<br>

Where:
- **`g`** is the actual cost from the starting cell to the current cell.
- **`h`** is the estimated cost from the current cell to the target (this estimate is called a heuristic).<br>

The algorithm always chooses the cell with the lowest **`f`** value. By combining the distance already travelled (**`g`**) with an estimate of the remaining distance (**`h`**), A* efficiently guides the search toward the goal while still guaranteeing the shortest path.<br>

In simple terms, A* works by choosing the path that appears shortest overall based on both actual progress and an intelligent estimate of what remains.

### Initial Code
To start coding, I created an OO (Object Oriented) C++ project which consisted of `main.cpp`, `AStarAlgorithm.cpp`, and `AStarAlgorithm.h`. I did this to follow the brief and to avoid using monolithic code and create a more modular project. In my header file, I included a header guard to avoid multiple `#include`s of my header file, which could cause redefinition errors. Including a header guard also just follows good modern C++ coding practices.<br>

In my header file, within my header guard, I created a class called `AStarAlgorithm`. I will use this class to hold `public` and `private` member functions. I will use `private` for data to ensure data protection. I created a `void AStarGrid();` function declaration and in my `AStarAlgorithm.cpp` file, I will have the function definition.

<p align="center">
<img width="290" height="410" alt="AStarAlgorithm h-Initial-code" src="assests/images/AStarAlgorithm.h-Initial-code.png" />
</p>

In `AStarAlgorithm.cpp`, I `#include "AStarAlgorithm.h"` to have access to the class and methods. In `AStarGrid`, I create a 2-d vector which creates a grid made up of `1`'s and `0`'s, `1` being a blocked node and `0` being an unblocked node. I use vectors as they are the preferred method for storing a range of elements. Vectors are preferred over arrays as vectors can be resized but both are preferred over C arrays to avoid memory bugs. As outlined in the `C++ Core Guidelines`, vectors should be used by default unless you have a reason to use a different container<br>
- **SL.con.1: Prefer using STL array or vector instead of a C array**
- **SL.con.2: Prefer using STL vector by default unless you have a reason to use a different container**<br>

I print out the grid with blocked nodes being represented by `#` and unblocked nodes being represented by `.`<br>

<p align="center">
<img alt="AStarAlgorithm.cpp-Initial-code" src="assests/images/Astar.cpp-initial-code.png" /> <img alt="AStarAlgorithm.cpp-Initial-grid" src="assests/images/Astar.cpp-initial-grid.png" />
</p>

Then in my `main.cpp`, I create an object of class `AStarAlgorithm` and call the `AStarGrid` method to actually display it. In week 2, I will be looking at UML diagrams and how I can design my code before I start developing.

---

## Week 2
### Initial UML Diagram Research
In week 2, I focused on the design and structure of my A* Algorithm project using UML Class Diagrams. UML class diagrams are used to show the structure of a system. It shows classes, attributes, methods, and relationships. This makes it easier to communicate how the program works. To understand the layout of UML class diagrams, I looked at GeeksforGeeks and visual paradigm:
- https://www.geeksforgeeks.org/system-design/unified-modeling-language-uml-class-diagrams/
- https://www.visual-paradigm.com/guide/uml-unified-modeling-language/uml-aggregation-vs-composition/<br>

This explained that a class diagram typically shows:
- a class as a rectangle with name/attribute/method compartments.
- the relationship between classes<br>

There are also certain notations that are used to represent the access level attributes and methods
- `+` for public (visible to all classes)
- `-` for private (visible only within the class)
- `#` for protected (visible to subclasses)
- `~` for package or default visibility (visible to classes in the same package)<br>

The main notations I will use are `+` and `-`.

### Initial UML Class Diagram
<p align="center">
<img width="290" height="410" alt="Initial UML Class Diagram" src="assests/images/UML-1.png" />
</p>

This was the initial UML class diagram I had for my week 1 code. It is obvious from the image that I needed to spend some time developing my project design. I want to have methods that check the validity of my grid, check if a cell is in bounds, and checks if a cell is blocked. I will add them as private methods. I also want a variable that will hold the current coordinates of the cell the algorithm is in. I will use a struct for this to hold the row and column coordinates. An example use of a struct on C.2 C++ Core guidelines shows it being used when members can vary independently.
- **C.2: Use class if the class has an invariant; use struct if the data members can vary independently**<br>

<p align="center">
<img width="400" height="600" alt="C++ ISO C.2" src="assests/images/C.2-struct1.png" />
</p>

I also know I will want a method to use the manhattan distance calculation. This is a heuristic calculation used to approximate `h`. It is described as:

>the sum of absolute values of differences in the goal’s x and y coordinates and the current cell’s x and y coordinates respectively

on the GeeksfoGeeks reference <a href="https://www.geeksforgeeks.org/dsa/a-search-algorithm/#:~:text=the%20sum%20of%20absolute%20values%20of%20differences%20in%20the%20goal%E2%80%99s%20x%20and%20y%20coordinates%20and%20the%20current%20cell%E2%80%99s%20x%20and%20y%20coordinates%20respectively">here.</a><br>

I also want a method that will complete the actual A* algorithm search of the grid. This is where I will do my grid validation checking, run my manhattan calculation, and find the best path from start to goal. By the end of week 2, This is what my UML Class Diagram looks like
<p align="center">
<img width="600" height="800" alt="UML Class Diagram" src="assests/images/UML-2.png" />
</p>

I'm sure this will develop over the weeks but it is a good starting point for now.

---

## Week 3
In week 3, I focused my work on creating grid and cell validation methods, the manhattan calculation, and creating the actual A* star search method which will do the actual calculation for finding the best route from start to goal

### Validation Methods
Before running A*, I added a small set of validation methods to make sure the grid and inputs are valid. This prevents crashes (like out-of-range indexing) and avoids wasting time running the algorithm on impossible setups.

<p align="center">
<img alt="IsValidGrid()" src="assests/images/IsValidGrid.png" />
</p>

**What it checks**<br>
The grid contains data:
- `grid` is not empty (has rows)
- `grid[0]` is not empty (has columns)

**Why it's used**<br>
A* relies on accessing `grid[0]` and `grid[r][c]`. If the grid is empty, those accesses would crash. It’s an early “sanity check” before doing anything else.

<p align="center">
<img alt="InBounds()" src="assests/images/InBounds.png" />
</p>

**What it checks**<br>
The Cell coordinator `p` is inside the grid:
- `0 <= p.r < grid.size()`
- `0 <= p.c < grid[0].size()`

**Why it’s used**<br>
It prevents out-of-bounds indexing when reading `grid[p.r][p.c]` and ensures the start/goal (and any checked positions) are valid locations on the grid. The `name` parameter (“Start”, “Goal”) makes error messages clearer.

<p align="center">
<img alt="IsNotBlocked()" src="assests/images/IsNotBlocked.png" />
</p>

**What it checks**<br>
If the cell at `p` is walkable.
- `grid[p.r][p.c] == 0` (cell is free).
- if it’s `1` (blocked), the method returns false.

**Why it's used**
- Stops A* running if the start or goal is on a wall.
- Makes the program more user-friendly (clear error instead of confusing results).

#### Why validation matters
- **Safety**: avoids crashes from invalid indexing.
- **Correctness**: ensures A* starts from a valid position and has a reachable target.
- **Cleaner algorithm code**: A* can assume inputs are valid and focus only on pathfinding logic.

### Initial Research and Understanding of Manhattan Calculation
<p align="center">
<img width="500" height="700" alt="UML Class Diagram" src="assests/images/manhattan-template.jpg" />
</p>

In my A* implementation, I use the **Manhattan distance** as the heuristic function h(n). The heuristic estimates how far a node is from the goal. The A* formula is **`f(n) = g(n) + h(n)`**
- **`g(n)`** = cost from start to current node
- **`h(n)`** = estimated cost from current node to goal
- **`f(n)`** = total estimated cost of the path

The Manhattan distance is what I use for **`h(n)`**.

### Manhattan Implementation
<p align="center">
<img alt="Manhattan" src="assests/images/Manhattan.png" />
</p>

The above method calculates the Manhattan distance between two points on a grid. If `a` is the current node and `b` is the goal node, Then the function returns the total number of horizontal and vertical steps required to move from `a` to `b`.
- **`std::abs(a.r - b.r)`** calculates the vertical distance (difference in rows).
- **`std::abs(a.c - b.c)`** calculates the horizontal distance (difference in columns).

They are added because, in a 4-direction grid, you can only move up, down, left, or right. You can’t move diagonally, so moving horizontally doesn’t reduce the vertical distance, and moving vertically doesn’t reduce the horizontal distance. To get to the goal, you have to complete all of the horizontal moves and all of the vertical moves. Since each move costs 1, the total distance is just the number of horizontal steps plus the number of vertical steps. The absolute value ensures the result is always positive. This is fine as we only care about the distance, not the direction.

### A\* Search Method

`AStarSearch()` is the method that actually runs the A\* pathfinding algorithm on my grid. It returns a path as a `std::vector<Cell>` from the start cell to the goal cell, or an empty vector if no path exists. Below I'll step through each section of the method and explain what it does and why it's there.

#### Step 1: Early Validation

<p align="center">
<img alt="Validation Checking" src="assests/images/validation-checking.png" />
</p>

The first thing `AStarSearch()` does is run the three validation checks before any algorithm logic starts. If the grid is empty, if start/goal are outside the grid, or if start/goal are walls, the method returns an empty vector immediately. This keeps A\* focused purely on searching — it should never have to guard against invalid data mid-loop.

#### Step 2: Grid Size and Flattening Setup

<p align="center">
<img alt="Grid Size & Flattening" src="assests/images/grid-size.png" />
</p>

Here I read the grid dimensions and calculate the total number of cells. The reason I store `total` is that all of the A\* state arrays (`bestG`, `parent`, `closed`) are 1D vectors of size `total`. Working with 1D arrays is simpler and more cache-friendly than nested 2D structures.

#### Step 3: Two Lambdas: Mapping 2D to 1D

```cpp
auto toIndex = [cols](const Cell& p) { return p.r * cols + p.c; };
auto toCell  = [cols](int idx)       { return Cell{ idx / cols, idx % cols }; };
```

These two lambdas convert between a 2D cell coordinate and a flat 1D index. `toIndex` turns `(r, c)` into a single integer, and `toCell` turns it back. For example on a 4-column grid: `(2, 3)` becomes `2 * 4 + 3 = 11`, and `11` maps back to `(11 / 4, 11 % 4) = (2, 3)`. This means I can use simple array indexing like `bestG[idx]` everywhere rather than `bestG[r][c]`, which keeps the code cleaner and the data contiguous in memory.

**Start and Goals Indices**
<p align="center">
<img alt="Start & Goal indices" src="assests/images/start_goal-index.png" />
</p>

Here we are using the lambdas to convert start and goal to the flattened index form so the algorithm can use them for arrays and queue items.

#### Step 4: Core A\* Data Structures

<p align="center">
<img alt="Data Structs" src="assests/images/data-structs.png" />
</p>

These three vectors are the core state of the algorithm:

* **`bestG`** stores the best (lowest) known cost to reach each node from the start. It starts as `INF` (meaning unreached) and gets updated whenever a shorter path is found
* **`parent`** stores the index of the previous node on the best known path to each node. It starts as `-1` (no parent) and is used at the end to reconstruct the path by walking backwards
* **`closed`** tracks which nodes have been fully processed and expanded. Once a node is closed, we know we already have the optimal cost to reach it and don't need to revisit it

#### Step 5: The Open Node and Priority Queue

<p align="center">
<img alt="Open Node and Priority Queue" src="assests/images/OpenNode-priority_queue.png" />
</p>

`OpenNode` is what gets stored in the priority queue. It holds the total estimated cost `f = g + h`, the actual cost so far `g`, and the flattened cell index. The comparator `CompareBySmallestF` makes `std::priority_queue` behave as a **min-heap** by returning `a.f > b.f`. This means the node with the lowest `f` is always at the top and is popped first, which is exactly what A\* requires.

#### Step 6: Initialising the Search

<p align="center">
<img alt="Initial Search" src="assests/images/init_search.png" />
</p>

The search starts by setting the start node's `g` cost to `0` and pushing it into the open queue with `f = 0 + h = Manhattan(start, goal)`. This is the only node we know anything about at the start, so it's the first candidate to be expanded.

#### Step 7: 4-Direction Movement Vectors

<p align="center">
<img alt="4-direction movement" src="assests/images/4dir-movement.png" />
</p>

These two arrays represent the four directions: up, down, left, right. By looping `k` from 0 to 3 and applying `dr[k]` and `dc[k]` to the current cell, I generate all four neighbours cleanly without repeating code four times.

#### Step 8: Path Reconstruction Lambda

<p align="center">
<img alt="Path reconstruction" src="assests/images/path-reconstruct.png" />
</p>

A\* doesn't store the full path while it searches, it only stores "where I came from" at each node. When the goal is reached, this lambda walks backwards through the `parent` array from goal to start, building up a vector of cells, then reverses it to get the correct start to goal order. This is memory-efficient because we don't maintain a growing path list throughout the search.

#### Step 9: The Main Loop

<p align="center">
<img alt="Main Loop" src="assests/images/AStar-while-loop.png" />
</p>

The main `while` loop runs as long as there are nodes to explore. On each iteration it pops the node with the lowest `f` value from the priority queue.

**Skipping stale entries:**

```cpp
if (current.g != bestG[current.idx]) { continue; }
```

Because `std::priority_queue` has no way to update the priority of an existing entry (no "decrease-key" operation), when a better path to a node is found I push a new, improved entry and leave the old one in the queue. This check detects those old entries if the `g` value on the popped node doesn't match the best known `g` for that cell, it's a stale duplicate and gets skipped.

**Early exit on reaching the goal:**

```cpp
if (current.idx == goalIndex) {
    return reconstructPath(goalIndex);
}
```

As soon as the goal node is popped from the queue, the path found is guaranteed to be optimal with an admissible heuristic like Manhattan distance, the first time you pop a node its cost is the shortest. So we immediately reconstruct and return the path.

**Closed set check:**

```cpp
if (closed[current.idx]) { continue; }
closed[current.idx] = true;
```

If the node has already been fully expanded, skip it. Otherwise mark it as closed so it won't be expanded again.

#### Step 10: Expanding Neighbours

<p align="center">
<img alt="Neighbours" src="assests/images/dir_for-loop.png" />
</p>

For each of the four neighbours of the current cell, the algorithm applies a series of filters before considering it:

1. **Bounds check**: silently skip any cell outside the grid boundaries. This is done inline rather than calling `InBounds()` to avoid printing an error message for every out-of-bounds neighbour during the search loop
2. **Wall check**: skip cells where `grid[r][c] != 0`
3. **Closed check**: skip cells that are already fully processed

If the neighbour passes all three, the algorithm computes the **tentative g-cost**:

```cpp
const int tentativeG = bestG[current.idx] + kMoveCost;
if (tentativeG >= bestG[nIdx]) { continue; }
```

This is the "relaxation" step, the same idea used in Dijkstra's algorithm. If going through the current node would cost *at least* as much as the best route already known to reach the neighbour, there's no point updating anything. But if it's an improvement:

```cpp
parent[nIdx] = current.idx;
bestG[nIdx]  = tentativeG;
const int f  = tentativeG + Manhattan(neighbour, goal);
open.push(OpenNode{ f, tentativeG, nIdx });
```

The parent is updated, the best g-cost is updated, and the neighbour is pushed into the open queue with its new `f` value.

#### Step 11: No Path Found
```cpp
return {}; // no path
```

If the queue empties without ever reaching the goal, it means no valid path exists between the start and goal on this grid. The method returns an empty vector, which `AStarGrid()` then handles by printing "No path found."

### Why This Approach Is Good But Bad Coding Practice

The `AStarSearch()` method above works correctly. It finds the optimal path, handles edge cases, and produces the right output. Getting a working implementation of A\* is genuinely non-trivial, and having it all in one place makes it easy to read through from top to bottom and understand the full flow. For a first working version, this approach is perfectly reasonable.

However, from a software engineering standpoint, cramming validation, data structure definitions, helper lambdas, and the algorithm all into a single method is a poor coding practice. Below are the main issues with this approach, referenced against the C++ Core Guidelines and C++23 standards.

#### 1. It Violates the Single Responsibility Principle

The method does too many things: it validates inputs, defines types (`OpenNode`, `CompareBySmallestF`), defines helper functions (`toIndex`, `toCell`, `reconstructPath`), and runs the algorithm. The **C++ Core Guidelines** are clear on this:

> **C.2: Use class if the class has an invariant; use struct if the data members can vary independently**

More broadly, each unit of code should have **one reason to change**. If I need to change how the path is printed, I should not have to open the same file as the algorithm. If I want to test validation in isolation, I cannot. It is buried inside `AStarSearch()`.

#### 2. Local `struct` Definitions Hide Reusable Types

`OpenNode` and `CompareBySmallestF` are defined as local structs inside the function body:

```cpp
struct OpenNode { int f; int g; int idx; };
struct CompareBySmallestF { ... };
```

This means they are invisible outside of `AStarSearch()`. If I wanted to write a unit test for the priority queue ordering, or reuse `OpenNode` in a different search variant, I could not. Types that carry meaningful responsibility should be at an appropriate scope, at minimum class scope, and ideally in their own header if they are genuinely reusable. This follows:

> **I.1: Make interfaces explicit**: types used at the boundary of a function should be visible to callers

#### 3. `const char*` Instead of `std::string_view`

The validation methods use `const char*` for the `name` parameter:

```cpp
bool InBounds(const std::vector<std::vector>& grid, Cell p, const char* name) const;
```

C++17 introduced `std::string_view` as the correct way to pass read-only string data. It accepts string literals, `std::string`, and other string types without copying, and carries length information (unlike a raw pointer). Using `const char*` is a C-style habit that C++ has had a better answer for since 2017:

> **SL.str.2: Use `std::string_view` or `gsl::string_span` to refer to character sequences**

#### 4. The Repeated Complex Type `std::vector<std::vector<int>>`

The raw type `std::vector<std::vector<int>>` is written out in full in every function signature:

```cpp
std::vector AStarSearch(const std::vector<std::vector>& grid, Cell start, Cell goal);
bool IsValidGrid(const std::vector<std::vector>& grid) const;
bool InBounds(const std::vector<std::vector>& grid, Cell p, const char* name) const;
```

This is noisy, hard to read, and fragile. If the grid representation ever changes, every single signature needs to be updated manually. A type alias solves this immediately:

```cpp
using Grid = std::vector<std::vector>;
```

This follows:

> **T.1: Use aliases to express semantic intent and avoid repeating complex types**

All of these issues are exactly what motivated the refactor in week 4. Getting the algorithm working first was the right move,  but once it worked, taking the time to improve the structure made the code genuinely better: easier to test, easier to extend, and much more closely aligned with what modern C++ should look like.

---

## Week 4
In week 4, I focused on refactoring the entire project to follow strong Object-Oriented (OO) design principles and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). Up to this point, all of the logic (validation, printing, and pathfinding) lived inside a single `AStarAlgorithm` class. While functional, this violated the **Single Responsibility Principle (SRP)**, which states that a class should have one, and only one, reason to change. The goal of week 4 was to split that monolithic class into focused, modular components that are easier to maintain, test, and extend.

### Why Refactor?
The original design had one class doing everything: validating the grid, printing output, and running the algorithm. This creates a problem. If I want to change how the grid is printed, I have to open the same file as the algorithm. If I want to test validation in isolation, I cannot. The C++ Core Guidelines directly address this:

- **C.2: Use class if the class has an invariant; use struct if the data members can vary independently**
- **I.1: Make interfaces explicit**: callers should know exactly what a function needs and returns
- **P.1: Express ideas directly in code**: the structure of the code itself should communicate its purpose

The refactor expanded my project to **7 files** across 4 focused classes, each with a single clear job.

### `Cell.h`: The Cell Struct
`Cell.h` defines a simple struct that holds a row (`r`) and column (`c`) coordinate. Previously, `Cell` lived inside `AStarAlgorithm.h`, which meant any file that only needed a coordinate type had to include the entire algorithm header. By moving it to its own file, it can be included anywhere independently.

```cpp
struct Cell
{
    int r = 0;
    int c = 0;
};
```

Using a `struct` here is a deliberate choice guided by the C++ Core Guidelines:

- **C.1: Make related data into structs**: `r` and `c` are naturally related, they always travel together as a coordinate pair
- **C.8: Use struct for passive data (no invariants, all public)**: `Cell` has no behaviour or enforced constraints, it is purely data
- **P.1: Express ideas directly**: the type is named `Cell` because it *is* a cell, not an index or a raw pair of integers

### `Grid.h`: The Grid Type Alias
`Grid.h` introduces a single type alias:

```cpp
using Grid = std::vector<std::vector>;
```

Before this change, `std::vector<std::vector<int>>` was written out in full across every function signature in every file. This is noisy, fragile, and hard to change. If I later want to switch the grid representation to a flat 1D vector or a span, I would have had to update every signature manually. Now I only update one line.

This follows:

- **T.1: Use type aliases to express semantic intent**: `Grid` communicates *what* it is, not *how* it is stored
- **SL.con.1: Prefer using STL array or vector instead of a C array**
- **SL.con.2: Prefer using STL vector by default unless you have a reason to use a different container**

### `GridValidator`: Input Validation
`GridValidator.h` and `GridValidator.cpp` contain all grid and cell validation logic. This replaces the three validation methods that previously lived inside `AStarAlgorithm`. The class exposes four methods:

* `IsValidGrid()`: checks the grid has at least one row and one column
* `InBounds()`: checks that a `Cell` coordinate lies within the grid dimensions
* `IsNotBlocked()`: checks that a `Cell` is not a wall (`grid[r][c] == 0`)
* `ValidateCell()`: a convenience method that runs all three checks in sequence

A key improvement here is the change from `const char*` to `std::string_view` for the `name` parameter used in error messages. The C++ Core Guidelines recommend:

- **SL.str.2: Use `std::string_view` or `gsl::string_span` to refer to character sequences**: `std::string_view` is a lightweight, non-owning view of any string. It accepts string literals, `std::string`, and other string types without copying, making it more flexible and efficient than `const char*`

### `GridPrinter`: Display Logic
`GridPrinter.h` and `GridPrinter.cpp` contain all display logic. The class exposes three methods:

- `PrintGrid()`: renders the grid using `.` for open cells and `#` for walls
- `PrintPathCoordinates()`: prints each cell's `(row, col)` coordinate along the found path
- `PrintGridWithPath()`: a new method that overlays `*` on the grid to visually show the route

The most interesting method is `PrintGridWithPath()`. It builds an `std::unordered_set<int>` of flattened path indices before iterating over the grid:

```cpp
std::unordered_set pathSet;
pathSet.reserve(path.size());
for (const auto& p : path)
{
    pathSet.insert(p.r * cols + p.c);
}
```

Using a set here is deliberate. A naive approach would check if each grid cell appears in the path vector using a linear search, which is O(n) per cell and O(rows x cols x pathLength) in total. The `unordered_set` gives O(1) average lookup per cell, making the whole operation O(rows x cols) regardless of path length. The `contains()` method used here was introduced in **C++20** as a cleaner alternative to `find() != end()`.

Separating printing from the algorithm means I could later swap `GridPrinter` for a GUI renderer or a file writer without touching a single line of `AStarSearch`.

### `AStarSearch`: Pure Pathfinding
`AStarSearch.h` and `AStarSearch.cpp` contain only the pathfinding algorithm. The class has one public method, `Search()`, and two private helpers, `Manhattan()` and `ReconstructPath()`.

**`OpenNode` is now at class scope:**

```cpp
struct OpenNode
{
    int f = 0;
    int g = 0;
    int idx = 0;

    bool operator>(const OpenNode& other) const noexcept { return f > other.f; }
};
```

Previously, `OpenNode` was a local struct inside the `AStarSearch` function body, making it invisible to tests and unable to be reused. Moving it to header scope solves both problems. The `operator>` overload enables the use of `std::greater<OpenNode>` as the priority queue comparator, which is more idiomatic than a separate comparator struct and requires no extra code.

**Preconditions use `assert` instead of repeated guard clauses:**

```cpp
assert(!grid.empty() && !grid[0].empty() && "Search called with empty grid");
assert(grid[start.r][start.c] == 0 && "Start cell is blocked");
assert(grid[goal.r][goal.c]  == 0  && "Goal cell is blocked");
```

Because `AStarAlgorithm::Run()` already validates all inputs before calling `Search()`, repeating full `if`/`return` guards inside `Search()` is redundant. The `assert`s document the *preconditions*, which is the contract between the caller and `Search()`, without adding runtime overhead in release builds (asserts compile away with `NDEBUG`). This aligns with:

- **P.5: Prefer compile-time checking to run-time checking**: express constraints as early as possible
- **I.6: Prefer `Expects()` for expressing preconditions**: `assert` is the practical equivalent when the GSL is not available

`ReconstructPath()` now uses `std::ranges::reverse()` from **C++20** instead of the iterator-based `std::reverse()`:

```cpp
std::ranges::reverse(path);
```

The ranges algorithms are the modern C++20/23 replacement for the iterator-pair STL algorithms. They accept containers directly rather than requiring explicit `begin()`/`end()` calls, which makes the code cleaner and more readable.

All methods on `AStarSearch` are marked `const` because none of them modify any member state. This follows:

- **Con.2: By default, make member functions `const`**: a method that does not need to mutate state should declare that fact explicitly, both as documentation and to allow calling on `const` objects

### `AStarAlgorithm`: The Orchestrator / Facade
`AStarAlgorithm` is now a thin **facade** that wires the three subsystems together. It owns instances of `GridValidator`, `GridPrinter`, and `AStarSearch` as private members, and exposes a single public method:

```cpp
std::vector Run(const Grid& grid, Cell start, Cell goal) const;
```

The critical change here is that `Run()` **takes parameters** rather than hardcoding the grid and cells inside the method body. This makes `AStarAlgorithm` genuinely reusable, the same object can be used to solve different grids without modification. `main.cpp` demonstrates this by running three different scenarios through the same `aStar` object.

This follows the **Open/Closed Principle (OCP)**: the class is open for extension (you can pass any grid) but closed for modification (you do not need to edit the class to try a new scenario).

The `Run()` method itself is intentionally short, it only coordinates:

```cpp
if (!m_validator.IsValidGrid(grid)) return {};
if (!m_validator.ValidateCell(grid, start, "Start")) return {};
if (!m_validator.ValidateCell(grid, goal,  "Goal"))  return {};

m_printer.PrintGrid(grid);
const auto path = m_search.Search(grid, start, goal);
m_printer.PrintPathCoordinates(path);
m_printer.PrintGridWithPath(grid, path);
```

Each line delegates to exactly one subsystem. `AStarAlgorithm` itself knows nothing about *how* validation, searching, or printing work, it only knows *in what order* to call them.

### Updated UML Class Diagram

### What was achieved in Week 4
- Refactored a single-class design into four focused classes following the **Single Responsibility Principle**
- Moved `Cell` into its own header so it has no dependency on algorithm code
- Introduced `using Grid = ...` to eliminate repeated complex type signatures across all files
- Replaced `const char*` with `std::string_view` in all validation interfaces (C++17)
- Added `PrintGridWithPath()` using `unordered_set` and the `contains()` member (C++20)
- Moved `OpenNode` to header scope with `operator>` for cleaner priority queue usage
- Replaced redundant validation guards inside `AStarSearch` with `assert` preconditions
- Used `std::ranges::reverse()` for idiomatic path reconstruction (C++20)
- Made `Run()` accept parameters instead of hardcoding the grid, making the class reusable

## Week 5

## Week 6
