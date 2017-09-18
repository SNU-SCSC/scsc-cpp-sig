# C++ 환경 세팅

---

# Text Editor vs IDE?

---

# Text Editor

말그대로 텍스트 편집이 주력인 프로그램들.

- vim
- emacs
- Sublime Text
- Atom
- Visual Studio Code

요즘 대부분의 텍스트 편집기는 플러그인을 통해 IDE 못지않은 기능을 낼 수 있다.

---

# IDE

프로그래밍 하는데 많은 편리한 기능들을 같이 제공하는 프로그램.

대표적으로 C++을 지원하는 IDE들:

- Visual Studio
- CLion
- KDevelop
- Eclipse
- QtCreator

---

# Windows

1. Visual Studio Community 2017 (추천)

2. MSYS/MINGW32 + CLion

3. WSL (Windows Subsystem for Linux) 세팅

아래로 갈수록 세팅방법이 리눅스랑 유사도가 크다.

---

# Windows - Visual Studio

1. https://www.visualstudio.com/downloads/로 가서 Visual Studio Commmunity 2017 다운.

2. 인스톨러에서 "Desktop development with C++"라는 항목을 꼭 체크! (디폴트로 설치해주지 않음)

3. 설치되기 까지 몇 분 (혹은 몇 시간) 기다리자. 실행되면 새로운 C++ 프로젝트를 만든 다음 잘 돌아가는지 체크해보기.

---

# Windows - MSYS/MINGW32 + CLion

Visual Studio에 대한 심한 알레르기가 있는 사람에게 추천.

1. http://www.msys2.org/ 에서 MSYS2를 설치한 다음 실행.

2. pacman -Syu를 통해 시스템 업데이트.

3. gcc 설치 (pacman -S gcc)

4. https://www.jetbrains.com/clion/ 에서 CLion IDE 다운/설치 (학교 이메일 계정으로 무료 사용 가능)

5. CLion에서 컴파일러를 알아서 잡아주지 않았다면 세팅에서 gcc 바이너리의 위치를 잡아주자.

6. 실행되면 새로운 C++ 프로젝트를 만든 다음 잘 돌아가는지 체크해보자.

---

# Windows - WSL (Windows Subsystem for Linux)

리눅스와 유사한 환경을 쓰고 싶은 사람들에게 추천.

들어본 적이 없으면 그냥 Visual Studio 설치 바람.

Ubuntu 설치 후는 Linux 파트랑 거의 동일.

https://msdn.microsoft.com/en-us/commandline/wsl/install_guide

---

# Mac

1. XCode (가장 무난)

2. CLion 등 다른 IDE 설치/

---

# Mac - XCode

XCode를 App Store에서 깔면 된다.

---

# Mac - CLion

CLion을 깔기 전에 gcc 혹은 clang 컴파일러를 설치해야 한다.

1. 터미널에서 xcode-select --install를 친 다음에 Command Line Developer Tools 설치. 그럼 XCode를 깔지 않고도 clang 컴파일러가 설치되어 있을 것이다.

2. brew 라는 패키지 매니저를 통해 gcc 혹은 clang 설치.

---

# Linux

1. 자신의 패키지 매니저로 (apt, pacman 등등)으로 gcc 설치

2. CLion/KDevelop 등 원하는 IDE 설치

3. 혹은 IDE 없이 개발할거면....
```
g++ -o main main.cpp
./main
```

--- 

# 끄으읕







