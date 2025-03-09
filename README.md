# Gym Management System  
**C++ OOP Project**  

## Overview  
- **Purpose:** Manage gym equipment, clients, products, and branches via a console interface.  
- **Key Concepts:** Encapsulation, operator overloading, dynamic memory.  
- **Classes:** `Aparate`, `Clienti`, `Produse`, `Sala`.  

## Implementation  
### Class Structure  
| Class       | Key Methods                          |  
|-------------|--------------------------------------|  
| `Aparate`   | `operator++`, `operator+`, `operator[]` |  
| `Clienti`   | `operator<=`, `operator+`, `operator-` |  
| `Produse`   | `operator==`, `operator++`          |  
| `Sala`      | `operator<<`, `operator[]`          |  

### Features  
- Dynamic memory management for strings (`char*`).  
- CRUD operations for gym entities.  
- Overloaded operators for comparisons and arithmetic.  

---

### **Proiect 2: Supplement Store (Inheritance)**

```markdown
# Supplement Store (Inheritance)

**C++ OOP Project**

## Overview

-   **Purpose:** Model weight-loss/muscle-gain supplements using inheritance.
-   **Key Concepts:** Polymorphism, abstract classes, diamond inheritance.
-   **Classes:** `Produse`, `ProduseDeSlabit`, `ProduseMasaMusculara`, `Shake`.

## Implementation

### Class Hierarchy

Produse
├── ProduseDeSlabit
└── ProduseMasaMusculara
└── Shake (multi-inheritance)
```

### Features

-   Virtual methods (`citire`, `afisare`) from abstract class `IOinterface`.
-   Dynamic casting for product comparisons.
-   Quality index calculation via `indiceProdus()`.

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
