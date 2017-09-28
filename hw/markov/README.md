# HW 1: Poor man's machine learning

## Skeleton code

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <regex>

template<typename T>
auto selectRandom(const std::vector<T>& vec) {
    return std::next(vec.begin(), std::rand() % vec.size());
}

decltype(std::chrono::high_resolution_clock::now()) curTime;
std::chrono::duration<double> diffTime;

void timerStart() {
    curTime = std::chrono::high_resolution_clock::now();
}

void timerEnd() {
    auto prevTime = curTime;
    curTime = std::chrono::high_resolution_clock::now();
    diffTime = curTime - prevTime;
}

void printElapsedTime() {
    std::cout << "Elapsed: " << diffTime.count() << "s" << std::endl;
}

using std::cout; using std::cin; using std::endl;

using MarkovState = std::string;
using NextChars = std::vector<char>;
using MarkovMap = std::unordered_map<MarkovState, NextChars>;

void start(std::string inputText, int stateSize, int outputSize) {
    // Put your code in here...
}

int main() {
    std::srand(std::time(0));

    std::string filename;
    cout << "File name: ";
    cin >> filename;
    cout << endl;
    
    std::ifstream istream(filename);
    if (!istream) {
        cout << "Cannot read file!" << endl;
        return 1;
    }

    int stateSize;
    cout << "Markov chain length: ";
    cin >> stateSize;
    cout << endl;

    int outputSize;
    cout << "Output length: ";
    cin >> outputSize;
    cout << endl;

    std::stringstream buffer;
    buffer << istream.rdbuf();
    std::string originalText = buffer.str();
    cout << "Loaded original text." << endl;

    std::string text;
    std::stringstream wordStream(originalText);
    std::string word;
    while(wordStream) {
        wordStream >> word;
        text += word;
        text += " ";
    }
    cout << "Removed whitespace." << endl;

    start(text, stateSize, outputSize);

    return 0;
}
```

## 제공하는 함수들

``selectRandom``: std::vector에서 랜덤한 원소를 뽑아서 그것의 iterator를 리턴.

``timerStart/timerEnd/printElapsedTime``:  코드의 실행이 얼마나 걸리는지를 측정하기 위한 함수들.

### Timer 사용 예시

```cpp
timerStart();
int sum = 0;
for (int i = 1; i <= 100; ++i) {
    sum += i;
}
timerEnd();
cout << "Result of adding from 1 to 100: " << sum << endl;
printElapsedTime();
```

```text
Result of adding from 1 to 100: 5050
Elapsed: 1.591e-06s
```

## Input/Output

여기서 shakespeare.txt, 10, 1000는 입력값 (std::cin으로 받음)

```text
File name: shakespeare.txt

Markov chain length: 10

Output length: 1000

Loaded original text.

Removed whitespace.

Created markov chain.
Elapsed: 5.54617s

Selected random seed as: ake sick m
Elapsed: 0.252586s

Finished generating text: 
ake sick men play so nicely with the edge of husbandry in heaven forgive us all! VINCENTIO. Lucentio! O, he hath not the boy profited? BARDOLPH. Out, alas, sir, I am fortune's fool! Ben. Why dost thou urge God's dreadful Sagittary the raised search, And thank you princes fight in safeguard of your departure thence Freed and enfranchisement of the slaughter, lost. Exit SCENE II. The street should serve the Jew any longer conference. PAULINA. What is't, Laertes? You cannot speak. I will return no more; cease. Thou know'st it well. Go you and tell me sooner? Pox of your loss. Our hint of woe Is common; that ever I dress myself. Re-enter CLOWN AGUECHEEK. 'Tis not thy companions? Pray get you out. But to your wantonness. By my christendom). Mort. In faith, lady, your lady mourn! SECOND SOLDIER. A thousand marks in gold, or sums in sealed bag, two sealed bags of ducats I receiv'd you At fortune's steward; he can deliver up your men And meet him, madam; at a marriage with tears? An if thou want'st by f
Elapsed: 0.00123394s
```

## Text Files (폴더 내에 들어 있음)

- shakespeare.txt

- alice.txt

이 두개는 제공해 드립니다.
심심하면 다른것도 해보세용!
