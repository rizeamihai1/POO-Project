---

### **Proiect 3: Supplement Store (STL & Templates)**

````markdown
# Supplement Store (STL & Templates)

**C++ OOP Project**

## Overview

-   **Purpose:** Manage supplements using STL containers and templates.
-   **Key Concepts:** Singleton pattern, STL (`vector`, `set`, `map`), exception handling.
-   **Classes:** `Produse`, `ProduseDeSlabit`, `Shake`, `meniu` (Singleton).

## Implementation

### Key Components

| Component               | Usage                             |
| ----------------------- | --------------------------------- |
| `vector<Produse*>`      | Stores heterogeneous products     |
| `set<int>`              | Tracks unique prices              |
| `map<string, Produse*>` | Maps product names to objects     |
| `Informatii<T>`         | Template class for I/O operations |

### Features

-   Singleton `meniu` for centralized control.
-   Template functions: `bubbleSort()`, `maxim()`.
-   6+ custom exceptions (e.g., invalid input, out-of-range).

## Compilation

```bash
g++ Grupa_YourName_Proiect3.cpp -o proiect3 && ./proiect3
```
````
