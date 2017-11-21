# HW 2: Particle Simulation

## 빌드

만약 CLion을 쓴다면 그냥 폴더를 열면 자동으로 import가 될 것이다.
돌려보기 전에 SFML을 미리 깔아오도록 하자.

## 프로그램 설명

이 프로그램의 입자들은 다음과 같은 규칙을 따른다.

- 1ms 동안 ``emitAmount (default: 5)``만큼 입자가 생성된다.
- 입자의 수명은 ``particleLifetimeMin`` ~ ``particleLifetimeMax``초의 수명을 가진다.
- 입자의 수명이 다 되면 시뮬레이션에서 사라지게 된다.

위에서 사용되는 변수들, 그리고 그 이외의 세팅들은 Constants.h에서 바꿀 수 있다. 컴퓨터 성능에 따라 기본 설정이 잘 안 돌아갈 수도 있으니 여러가지 경우에 대해서 시험해 보는것이 좋다.

## 과제

스켈레톤 코드에서 아주 간단하게 ``std::vector``로 구현을 해 놓은 VectorParticleManager가 있다. 눈치가 빠른 사람들은 이것이 매우 비효율적인 것을 알 수 있다. 우리의 목표는 최대한 효율적으로 돌아가는 ParticleManager를 만드는 것이다.

키보드의 1을 누르면 VectorParticleManager를 실행시킬 수 있고, 2를 누르면 BetterParticleManager를 실행시킬 수 있다. 코드는 BetterParticleManager의 TODO 부분을 채우면 된다.

성능은 프로그램을 실행할때 화면에 나오는 텍스트를 판단할 수 있다.

왼쪽에는 한 프레임당 얼마나 많은 시간이 걸리는지를 알려준다. 다만 화면에 입자들을 그리는 시간도 포함되어 있어서, 그래픽 카드 성능에 따라 많이 바뀔 수 있는 수치다.

오른쪽에는 한 프레임당 (렌더링을 제외한) ParticleManager가 한 프레임당 얼마나 많은 시간이 걸리는지를 알려준다. 이것이 우리가 중요시하는 수치이다.

현재 가지고 있는 노트북에서 다음과 같이 성능이 다음과 같이 나왔다.

- i7 6700HQ (Quad core), GTX 960M
- Update ms: About 11000ms (VectorParticleManager) -> 1100ms (BetterParticleManager)

참고로 임의의 개수의 입자들에 대해서 모두 작동할 수 있도록 구현해보자 (즉 입자의 개수를 제한해 놓기 없기)

## 힌트

Object Pooling을 검색해보라.
