# C++ - default/zero initialization
SCSC 장필식
---

# Reference

http://en.cppreference.com/w/cpp/language/type
https://isocpp.org/wiki/faq
https://en.wikipedia.org/wiki/C%2B%2B_classes

---

# C++ type system

- Fundamental types
- Compound types
    - POD
    - non-POD
    - Aggregate

---

# Fundamental (Primitive) types

void, int, float, double, bool, ...

---

# default vs zero initialization

```cpp
// default initialization
// value of a is indeterminate
int a;

// zero initialization
// value of a is 0
int a = int();
int a = {};
int a{};
```

---

# default initialization rules

http://en.cppreference.com/w/cpp/language/default_initialization

Use of an indeterminate value obtained by default-initializing a non-class variable of any type is undefeined behavior

```cpp
int f(bool b)
{
    int x;               // OK: the value of x is indeterminate
    int y = x;           // undefined behavior
    unsigned char c;     // OK: the value of c is indeterminate
    unsigned char d = c; // OK: the value of d is indeterminate
    int e = d;           // undefined behavior
    return b ? d : 0;    // undefined behavior if b is true
}
```

---

# zero initialization rules

http://en.cppreference.com/w/cpp/language/zero_initialization

- For every named variable with static or thread-local storage duration that is not subject to constant initialization, before any other initialization.
- As part of value-initialization sequence for non-class types and for members of value-initialized class types that have no constructors, including value initialization of elements of aggregates for which no initializers are provided.

---

# effects of zero initialization

- If T is a scalar type, the object's initial value is the integral constant zero explicitly converted to T.
- If T is an non-union class type, all base classes and non-static data members are zero-initialized, and all padding is initialized to zero bits. The constructors, if any, are ignored.
- ...

---

# compound types

- reference types
- pointer types
- pointer to member types
- array types
- function types
- enumeration types
- **class types**

---

# default/zero initialization of class types

Default initialization happens

- When we define nonstatic variables (§ 2.2.1, p. 43) or arrays (§3.5.1, p. 114) at block scope without initializers
- When a class that itself has members of class type uses the synthesized default constructor (§ 7.1.4, p. 262)
- When members of class type are not explicitly initialized in a constructor
initializer list (§ 7.1.4, p. 265)

Value initialization happens

- During array initialization when we provide fewer initializers than the size of the array (§ 3.5.1, p. 114)
- When we define a local static object without an initializer (§ 6.1.1, p. 205)
- When we explicitly request value initialization by writing an expressions of the form T() where T is the name of a type (The vector constructor that takes a single argument to specify the vector’s size (§ 3.3.1, p. 98) uses an argument of this kind to value initialize its element initializer.)

---

# default constructor



---

# Example

```cpp
class NoDefault {
public:
    NoDefault(const std::string&);
    // additional members follow, but no other constructors
};
struct A {  // my_mem is public by default; see § 7.2 (p. 268)
    NoDefault my_mem;
};
A a;       //  error: cannot synthesize a constructor for A
struct B {
    B() {} //  error: no initializer for b_member
    NoDefault b_member;
}
```

---

# 

