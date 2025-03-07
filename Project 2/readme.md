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

## Compilation

```bash
g++ Grupa_YourName_Proiect2.cpp -o proiect2 && ./proiect2
```
