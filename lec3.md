C++ 시그 3주차
SCSC 장필식
---

# 오늘 하게 될 것

간단한 C++ 코드를 작성할 수 있을 만한 거의 모든 것.

---

# 기본적인 자료구조

```cpp
std::array<int, 5>
std::vector<int>
std::list<int>
std::map<std::string, int>
std::unordered_map<std::string, int>
std::set<int>
```

---

# Array

고정된 갯수의 값들을 순서대로 저장하는 자료구조.

\<array\> 헤더파일에 들어있음

```cpp
// STL에 있는 어레이 (C++11 이상)
std::array<int, 5> arr = {1, 2, 3, 4, 5};
// C 어레이
int[5] arr;
```

사실 std::array도 안을 파고들면 C array로 구현이 되어있지만, std::array는 보다 편리한 기능들을 많이 제공한다.

---

# 꺽쇠꺽쇠는 무엇인가요?

C++의 template라는 기능을 통해 여러 "종류"의 오브젝트를 만들 수 있다.
타입 뿐만 아니라 값도 집어넣을 수 있다!

```cpp
std::array<int, 5> arr1; // 5개의 int가 들어있는 어레이
std::array<int, 10> arr2; // 10개의 int가 들어있는 어레이
std::array<std::string, 3> arr3; // 3개의 string이 들어있는 어레이
```

추후에 템플릿을 선언하는 방법을 배울 것입니다. 

---

# Array: 사용법

```cpp
#include <iostream>
#include <array>

using std::cout; using std::endl;

int main() {
    // initialize an array
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    // set element 0 to 3
    arr[0] = 3;

    // C-style for loop
    for (int i = 0; i < arr.size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // C++11-style foreach loop
    for (auto n : arr) {
        cout << n < " ";
    }
    cout << endl;
}
```

---

# initialization

어레이를 다음과 같이 생성시킬 수 있다.

default initialization: 기본값으로 모두 초기화

```cpp
std::array<int, 3> arr1; // {0, 0, 0}
```

initializer list 사용
```cpp
std::array<int, 3> arr2 = {2, 3, 5}; 
```

---

# foreach loop

- auto는 타입을 알아서 유추해주는 기능을 한다.
- 어레이의 원소들이 충분히 작을 때는 (int, float, double과 같은 primitive type): value로 받자
- 어레이의 원소들이 좀 클때는: reference 혹은 const reference로 받자

```cpp
int main() {
    std::string result = "";
    std::array<std::string, 3> strings = { ... };
    for (const auto& str : strings) {
        result += str;
        result += " ";
    }
}
```

---

# 고차원 어레이

```cpp
std::array<std::array<int, 3>, 3> mat = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}

cout << mat[1][1] << endl;

for (auto& rows : mat) {
    for (auto n : rows) {
        cout << n << endl;
    }
}
```

---

# using declaration

좀 복잡한 타입은 using를 통해 간추릴 수 있다.

```cpp
using Row = std::array<int, 3>;
using Matrix = std::array<Row, 3>;

int main() {
    Matrix mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
}
```

---

# Vector

여러 개의 값을 순서대로 저장하는 자료구조. 크기를 마음대로 조정할 수 있다.
\<vector\> 헤더파일에 들어있음

```cpp
#include <iostream>
#include <vector>

using std::cout; using std::endl;

int main() {
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(5);
    vec.push_back(8);
    for (auto n : vec) {
        cout << n << endl;
    }
    cout << vec[2] << endl;

    int last = vec.pop_back();
    int secondToLast = vec.pop_back();
    cout << last << ", " << secondToLast << endl;
}
```

---

# Vector

```cpp
int main() {
    
}
```

---

# List

Vector하고 같은 기능을 제공하지만, 내부 구현이 다르다.

```cpp

```

---

# std::vector vs. std::list

vector/list의 원소 개수가 n이라고 가정했을 때: 

|                     |std::vector| std::list |
|    :-:              |    :-:    |    :-:    |
|Random access (v[i]) |  $$O(1)$$ |  $$O(n)$$ |
|Iteration (for(..))  |  $$O(n)$$ |  $$O(n)$$ (하지만 훨씬 느림) |
|Insert/Delete at end |  $$O(1)$$ |  $$O(1)$$ |
|Insert/Delete at middle | $$O(n)$$ | $$O(1)$$ |
|메모리 사용 | 빈 자리가 많을 수 있음 | 꽉꽉 다 채우지만, 포인터에 의한 공간 소모 생김 |

---

# Map

---

# std::map vs std::unordered_map

map/unordered_map의 원소 개수가 n이라고 가정했을 때:

|                     |   std::unordered_map   |   std::map   |
|:-:                  |:-:           |:-:                     |
|Ordered              | X            | O                      |
|Insert/Delete entry  | 보통 $$O(1)$$| $$O(\log(n))$$         |
|Get value from key (m[k])| 보통 $$O(1)$$ | $$O(\log(n))$$    |
|메모리 사용| 빈 자리가 많을 수 있음 | 꽉꽉 다 채움           |

---

# Set

여러개의 값들을 순서 없이 모아놓은 자료구조. (중복 허용 X)
\<set\> 헤더파일에 들어있다.
가끔씩 쓰게 될 수도 있으므로 소개.

```cpp
std::set<int> numbers = {1, 5, 23, 7, 3, 2};
numbers.insert(4);
auto foundNum = numbers.find(3);
if (foundNum != numbers.end()) {
    cout << "found!" << endl;
}
```

---

# 간단한 알고리즘 문제

$a^2 + b^2 = c^2$를 만족하는 자연수 a, b, c를 찾으시오. (단 a, b, c는 100보다 작다.)

---

# 자료구조와 알고리즘 

정성스례 짠 알고리즘. (이것보다 훨씬 효율적인 방법이 있다.)

```cpp
#include <vector>
#include <algorithm>

int main() {
    
}
```

---

# <algorithm> 등장

도와줘 스피드왜건!

```cpp
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::tuple<int, int, int>> numbers = 
}
```

---





