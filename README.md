# Pool-Project
For studying the memory pool, object pool


Memory Pool이란?
----------------
고정된 메모리 사이즈를 할당해주어, malloc이나 new와 유사한 메모리 할당을 가능하게 해준다. 잦은 malloc이나 new는 system call로 인한 overhead가 생기며, 메모리 단편화가 일어날 수 있다.
Memory pool은 malloc이나 new의 이런 잠재적 단점을 어느정도 예방할 수 있다.

Memory Pool을 사용한 것과 사용하지 않은 것끼리의 Performance 비교
--------------------------------------------------------
performance는 memory 할당/해제를 10번씩 한 것을 한번의 iteration이라고 가정할 때, iteration을 MAX_LOOP_NUMBE번 반복하는데 걸린 시간을 기준으로 측정

![line-graph](https://user-images.githubusercontent.com/38073072/194109218-49c03d08-dbbe-4eff-ab59-3c07937772e6.png)


Object Pool이란?
----------------
프로그램에서 사용될 오브젝트 개수를 예측해서 미리 container에 할당해서 담아두고, 프로그래머가 필요할 때 마다 컨테이너에서 꺼내줌. 메모리 풀과 같이 잦은 new/malloc & delete/free로 오버헤드로 인한 성능저하를 어느 정도 개선할 수 있다.

Object Pool을 사용한 것과 사용하지 않은 것끼리의 Performance 비교
--------------------------------------------------------
performance는 memory pool과 같은 방식으로 측정  
loop 1번 iteration 할 때 마다 20개의 오브젝트를 할당및 해제

![line-graph (1)](https://user-images.githubusercontent.com/38073072/126066702-cc8b2c66-b231-415d-992f-a526b13589e3.png)



Reference
* Git: https://github.com/SnowFleur/2020-Pool-Patterns
