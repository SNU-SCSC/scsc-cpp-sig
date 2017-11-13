C++ 제 7강: Heap & Memory Management
SCSC 장필식
---

# Heap

동적인 크기의 데이터를 저장할 때 사용하는 메모리 공간

Stack하고는 별도로 운영되는, 신비의 메모리 공간

---

# new / delete

```cpp
// allocate a's value in heap (and set it to 1)
int* a = new int(1);

cout << "a is: " << *a << endl; // 1
*a = 2;
cout << "a is: " << *a << endl; // 2

// deallocate a's value from heap
delete a;

```

---

# Allocation in class

```cpp

```

---

# Constructor / Destructor

---

# Ex: Linked List

---

# Doubly Linked List

기존의 코드를 확장하여 앞뒤로 포인터가 존재하는 Doubly Linked List를 만들어라.
그리고 나서 다음 함수들을 구현해라.
- 뒤에 숫자를 집어넣는 ``void insertAtTail(int value)``
- 거꾸로 리스트를 프린트하는 ``void traverseBackwards()``

---

# 끄으읕

