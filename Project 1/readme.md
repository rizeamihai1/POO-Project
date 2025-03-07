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

## Compilation  
```bash  
g++ Grupa_YourName_Proiect1.cpp -o proiect1 && ./proiect1  