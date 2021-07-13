# Pool-Project
For studying the memory pool, object pool


Memory Pool이란?
----------------
고정된 메모리 사이즈를 할당해주어, malloc이나 new와 유사한 메모리 할당을 가능하게 해준다. 잦은 malloc이나 new는 system call로 인한 overhead가 생기며, 메모리 단편화가 일어날 수 있다.
Memory pool은 malloc이나 new의 이런 잠재적 단점을 어느정도 예방할 수 있다.

Memory Pool을 사용한 것과 사용하지 않은 것끼리의 Performance 비교
--------------------------------------------------------
performance는 memory 할당/해제를 MAX_LOOP_NUMBE만큼 반복하는데 걸린 시간을 기준으로 측정

![line-graph](https://user-images.githubusercontent.com/38073072/125497378-46dcabbb-f439-401e-b2e7-9799a74921f6.png)


Object Pool이란?
----------------
(Update 예정)



Reference
* Git: https://github.com/SnowFleur/2020-Pool-Patterns
