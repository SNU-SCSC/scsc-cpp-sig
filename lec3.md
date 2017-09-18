# C++ 3강: Stack / Heap
SCSC 장필식

---

# 변수는 어디에 저장이 되는가?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    cout << a << b << c << endl;
}
```

---

# 레지스터 / 캐시 / 메모리

자주 사용되는 변수는 보통 레지스터에 저장이 되고,
나머지는 메모리라는 공간에 저장이 된다.

하지만 메모리와 CPU를 왔다갔다 하는데 시간이 많이 걸리므로, 캐시(cache) 라는 것을 통해 변수들을 미리 기억해놓는다.

![center](/home/lasagnaphil/scsc/cpp-sig/mem_hierarchy.gif)

---

# 메모리의 구조

![center](/home/lasagnaphil/scsc/cpp-sig/stack_heap.gif)

---

# 