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

In my header file, within my header guard, I created a class called `AStarAlgorithm`. I will use this class to hold `public` and `private` member functions. I will use `private` for data to ensure data protection. I created a `void AStarGrid();` function declaration and in my `AStarAlgorithm.cpp` file, I will have the function definition.<br><br>

<p align="center">
<img width="290" height="410" alt="AStarAlgorithm h-Initial-code" src="assests/images/AStarAlgorithm.h-Initial-code.png" />
</p><br><br>

In `AStarAlgorithm.cpp`, I `#include "AStarAlgorithm.h"` to have access to the class and methods. In `AStarGrid`, I create a 2-d vector which creates a grid made up of `1`'s and `0`'s, `1` being a blocked node and `0` being an unblocked node. I use vectors as they are the preferred method for storing a range of elements. Vectors are preferred over arrays as vectors can be resized but both are preferred over C arrays to avoid memory bugs. As outlined in the `C++ Core Guidelines`, vectors should be used by default unless you have a reason to use a different container<br>
- **SL.con.1: Prefer using STL array or vector instead of a C array**
- **SL.con.2: Prefer using STL vector by default unless you have a reason to use a different container**<br>

I print out the grid with blocked nodes being represented by `#` and unblocked nodes being represented by `.`<br><br>

<p align="center">
<img alt="AStarAlgorithm.cpp-Initial-code" src="assests/images/Astar.cpp-initial-code.png" /> <img alt="AStarAlgorithm.cpp-Initial-grid" src="assests/images/Astar.cpp-initial-grid.png" />
</p><br><br>

Then in my `main.cpp`, I create an object of class `AStarAlgorithm` and call the `AStarGrid` method to actually display it. In week 2, I will be looking at UML diagrams and how I can design my code before I start developing.


## Week 2
- Show research of UML diagrams (Lecture slides and links)
- Show UML diagrams to design my software

## Initial UML Diagram Research
In week 2, I focused on the design and structure of my A* Algorithm project using UML Class Diagrams. UML class diagrams are used to show the structure of a system. It shows classes, attributes, methods, and relationships. This makes it easier to communicate how the program works. To understand the layout of UML class diagrams, I look at GeeksforGeeks:
- https://www.geeksforgeeks.org/system-design/unified-modeling-language-uml-class-diagrams/<br>

This explained that a class diagram typically shows:
- a class as a rectangle with name/attribute/method compartments.
- the relationship between classes<br>

There are also certain notations that are used to represent the access level attributes and methods
- `+` for public (visible to all classes)
- `-` for private (visible only within the class)
- `#` for protected (visible to subclasses)
- `~` for package or default visibility (visible to classes in the same package)<br>

The main notations I will use are `+` and `-`.

## Initial UML Class Diagram
<p align="center">
<img width="290" height="410" alt="AStarAlgorithm h-Initial-code" src="assests/images/UML-1.png" />
</p><br><br>

This was the initial UML class diagram I had for my week 1 code. It is obvious from the image that I needed to spend some time developing my project design. I want to have methods that check the validity of my grid, check if a cell is in bounds, and checks if a cell is blocked. I will add them as private methods. I also want a variable that will hold the current coordinates of the cell the algorithm is in. I will use a struct for this to hold the row and column coordinates. An example use of a struct on C.2 C++ Core guidelines shows it being used when members can vary independently.
- **C.2: Use class if the class has an invariant; use struct if the data members can vary independently**<br>

<p align="center">
<img width="400" height="600" alt="AStarAlgorithm h-Initial-code" src="assests/images/C.2-struct1.png" />
</p><br><br>

## Week 3

## Week 4

## Week 5

## Week 6
