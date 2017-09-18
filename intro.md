# C++ Intro
---------------

# 신비한 C++

```cpp
// 무엇이 맞을까?
int x(1);
int x = 1;
int x = int(1);
int x{1};
```
---

# 신비한 C++

```cpp
const int * Constant
int const * Constant
int * const Constant
int const * const Constant
```

```cpp
// ???
class Klass {
    const int * const Method(const int * const &) const;
}
```

---

# 신비한 C++

```cpp
class Klass {
public:
    Klass();
}
```

---

# 신비한 C++

```cpp
// Before C++11 (rule of three)
class Klass {
public:
    Klass();

    ~Klass();
    Klass(const Klass& other);
    Klass& operator=(const Klass& other);
}
```

---

# 신비한 C++

```cpp
// After C++11 (rule of five)
class Klass {
public:
    Klass();

    ~Klass();
    Klass(const Klass& other);
    Klass& operator=(const Klass& other);
    Klass(Klass&& other);
    Klass&& operator=(Klass&& other);
}
```

---

# 신비한 C++

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> lst;
    lst.insert(10);
    return 0;
}
```

---

# 신비한 C++

![error-messages center 80%](/home/lasagnaphil/scsc/cpp-sig/stl-error-messages.png)

---

# Syllabus

C++ 실용적으로 쓰기
1. 변수, 제어문, 반복문, string, vector, array (Chap. 1~5)
2. 레퍼런스, 포인터, 함수, const (Chap. 2, 6)
3. 클래스 만들기 (Chap. 7)
4. STL 살펴보기 (vector/list/map, iterators, lambda expressions) (Chap. 9-10)

C++ 메모리 관리
5. stack/heap, malloc/free, new/delete, RAII (Chap. 12)
6. shared_ptr, unique_ptr (Chap. 13)

C++ 클래스 심화
7. Copy/Move control (Chap. 13)
8. Inheritance/Polymorphism (Chap. 15)
9. Templates (Chap. 16)


