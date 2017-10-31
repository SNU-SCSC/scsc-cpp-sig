C++ 시그 6강: 입출력 / Operator Overloading / 기타 ㅁㄴㅇㄹ
SCSC 장필식
---

# 클래스에 입출력 함수를 만들어보자

```cpp
struct StudentInfo {
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read(std::istream& os);
    std::ostream& write(std::ostream& os);
    double grade() const;
};
```
---

# stream?

어떠한 데이터의 인풋이나 아웃풋을 받고 싶을 때 (콘솔창 입출력, 파일 입출력, 등등)을 받을 때, C++에서는 **stream** 이라는 개념을 자주 쓴다.

데이터의 흐름을 stream으로 표현함으로써 우리는 데이터 인풋이 콘솔창에서 오는건지 파일에서 오는건지 신경을 쓰지 않아도 된다!

---

# stream의 종류

![](std-io-complete-inheritance.svg)

---

# 대표적인 예: std::cin, std::cout

std::cin은 std::istream 타입을 가지고 있으며,
std::cout은 std::ostream 타입을 가지고 있다.

이 두 오브젝트는 <iostream> 헤더에서 글로벌 변수로 제공하고 있다.

---

# read/write 함수를 사용하여 입력/출력하기

std::cin

---

