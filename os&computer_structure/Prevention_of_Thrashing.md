# 스레싱을 방지하기 위해서는 어떻게 해야하는가?

---

- 자료조사
    
    ## 가상 메모리
    
    컴퓨터는 애플리케이션이 실행될 때, 프로그램을 실행하기 위한 모든 데이터를 메모리에 적재하지 않는다.
    
    프로세스가 실행될 때 메모리에 해당 프로세스 전체가 올라가지 않더라도 실행이 가능하다.
    
    이 점을 바탕으로 **가상 메모리** 개념이 나왔다.
    
    컴퓨터는 애플리케이션이 실행될 때 실행에 필요한 일부분만 메모리에 올리고 나머지는 디스크에 남게된다.
    
    모든 데이터를 메모리에 올리지 않기 때문에, 더 많은 프로그램을 동시에 실행할 수 있다.
    
    가상 메모리는 실제 메모리보다 많이 보이게 하는 기술이다.
    
    ## 페이지 폴트(Page Fault)
    
    Q. CPU가 가상 메모리로부터 어떠한 데이터를 요청했을 때, 가상 메모리에 해당 데이터가 적재되어 있지 않다면?
    
    A. 해당 데이터를 프로그램이 저장되어 있는 디스크에서 가상 메모리로 가져온다.
    
    가져온 데이터는 어디에 어떻게 저장하는가
    
    ⇒ 만약 빈 프레임이 있다면? 가져온 데이터를 빈 프레임에 저장한다.
    
    ⇒ 만약 빈 프레임이 없다면? 현재 사용되고 있지 않는 프레임을 찾아서 그걸을 비워버리고 저장한다.
    
    ## 스레싱(Thrashing)
    
    가상 메모리에 페이지 폴트가 발생하여 디스크로부터 데이터를 가져오는 과정동안
    
    CPU는 일을 하지 않고 쉬고 있다.
    
    즉, 잦은 페이지 폴트는 CPU 이용률을 저하시킨다.
    
    운영체제는 CPU 이용률이 낮아지면, CPU 이용률을 높이고자 메모리에 올라가는 프로세스 수(다중 프로그래밍 정도)를 늘린다.
    
    <img width="717" alt="Graph_of_Thrashing" src="https://user-images.githubusercontent.com/99192837/229368835-f9a3efc7-d723-4771-87bb-4fc2a5233119.png">
    
    프로세스를 실행시키기 위해 할당된 페이지 수가 부족하여 페이지 폴트 발생
    
    → 페이지 폴트가 나면서 CPU 이용률이 저하
    
    → CPU 이용률이 저하되어 CPU 이용률을 높이고자 다중 프로그래밍 정도를 높임
    
    → 실행시켜야 할 프로세스가 많아짐에 따라 페이지 폴트가 발생
    
    (악순환)
    
    페이지 폴트가 많이 발생하면 디스크 입출력이 덩달아 잦아진다.
    
    이때 마치 CPU가 동작하지 않는 것처럼 보이게 되는데 이러한 상태를 스레싱이라고 한다.
    
    ## 스레싱 방지 알고리즘1 - 워킹셋 알고리즘
    
    프로세스가 일정 시간 동안 집중적으로 특정 주소 영역을 참조하는 경향이 있는데 이를 지역성 집합이라고 한다. 워킹셋 알고리즘은 지역성 집합이 메모리에 동시에 올라갈 수 있도록 보장하는 메모리 관리 알고리즘이다.
    
    워킹셋? 한꺼번에 메모리에 올라가야 하는 페이지들의 집합
    
    워킹셋 알고리즘? 워킹셋을 구성하는 페이지가 한꺼번에 올라갈 수 있을 메모리 공간이 있을 때만 동작한다. 메모리 공간이 부족하다면 기존 메모리에 있는 페이지를 디스크로 스왑아웃 시켜 공간을 확보한다.
    
    ## 스레싱 방지 알고리즘2 - 페이지 부재 빈도 알고리즘
    
    프로세스의 페이지 부재율을 주기적으로 조사하고 이 값에 그건해서 각 프로세스에 할당할 메모리 양을 동적으로 조정하는 알고리즘이다.
    
    시스템이 미리 정해 놓은 페이지 부재율을 상한값을 넘거가거나, 하한값 이하로 떨어지게 되면 운영체제가 메모리에 올라가 있는 프로세스의 수를 조절한다.
    
- 추가질문
    
    Q. 페이지 부재 빈도 알고리즘에서, 페이지 부재율이 하한값 이하로 떨어지는 경우는 왜 고려하나요?
    
    A. 페이지 부재율이 하한값 이하로 떨어지면 프로세스에게 필요 이상의 많은 프레임이 할당된 것으로 간주하여 할당된 프레임 수를 줄이는 것입니다. CPU 이용률 관점에서, 어느 정도의 페이지 폴트는 받아드리고 동시에 실행하는 프로세스의 수를 늘리는 것이 더 큰 이득입니다.
    
    Q. 페이지 폴트가 발생하여 데이터를 가져올 때 빈 프레임이 없는 경우 현재 사용되고 있지 않는 프레임을 찾아 비운다고 하였는데, 어떤 방식으로 현재 사용되고 있지 않는 프레임이라고 판단하나요?
    
    A. 현재 사용되고 있는 않는 프레임을 찾아서 페이지를 교체하는 것을 페이지 교체라고 합니다. 페이지 교체를 위한 페이지 교체 알고리즘은 대표적으로 FIFO, OPT, LRU, LFU, MFU가 있습니다.
    
    - FIFO(First In First Out): 가장 먼저 메모리에 올라온 페이지를 가장 먼저 내보내는 알고리즘
    - OPT(Optimal Page Replacement): 앞으로 가장 오랫동안 사용되지 않을 페이지를 교체하는 알고리즘 (구현 목적이 아닌 연구 목적의 알고리즘)
    - LRU(Least Recently Used): 가장 오랫동안 사용되지 않은 페이지를 교체하는 알고리즘
    - LFU(Least Frequently Used): 참조 횟수가 가장 적은 페이지를 교체하는 알고리즘
    - MFU(Most Frequently Used): 참조 횟수가 가장 많은 페이지를 교체하는 알고리즘
    
- 답안
    
    스레싱이란 프로세스가 자주 사용하는 페이지가 메모리에 적재되지 못해 페이지 폴트가 발생하고, 이에 따라 CPU 이용률이 급격히 떨어지는 현상입니다. 스레싱을 방지하기 위해서는 지역성을 활용한 워킹셋 알고리즘을 사용하여 페이지 폴트를 줄이거나, 페이지 부재 빈도 알고리즘을 사용하여 다중 프로그래밍 정도를 줄여 페이지 폴트를 줄일 수 있습니다.
    
- Reference
    
    [[운영체제] 가상 메모리(Virtual Memory System)](https://ahnanne.tistory.com/15)
    
    [스레싱(thrashing)이란 무엇인가](https://straw961030.tistory.com/155)
    
    [[OS] 스레싱(thrashing)](https://zangzangs.tistory.com/144)
    
    [[운영체제OS]8. 가상메모리(페이징, 페이지 교체, 스레싱)](https://yiyj1030.tistory.com/80)
    
    [[운영체제] 페이지 교체 알고리즘 (FIFO/OPT/LRU/LFU/MFU)](https://code-lab1.tistory.com/60)
