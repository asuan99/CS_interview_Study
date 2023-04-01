### 2. 빅오(Big-O)란 무엇인가요?
- 답변
        
        알고리즘 최악의 실행 시간을 표기해주는 표기법 입니다.
        
        최소한 보장되는 성능을 표기하기 때문에 가장 일반적으로 사용됩니다.
        
- 빅오
        
  빅오(Big O)는 알고리즘의 시간 복잡도(Time Complexity)를 표기하는 표기법 중 하나입니다.
        
  알고리즘의 입력 크기(n)에 대한 함수로서, 알고리즘의 수행 시간이 어떻게 증가하는지를 나타냅니다.
        
  빅오 표기법은 알고리즘의 최악의 수행 시간(최대 시간 복잡도)을 나타내며, 점근적 상한(Asymptotic Upper Bound)을 표기합니다.
        
  이는 입력 크기가 충분히 클 때 알고리즘의 실행 시간이 얼마나 증가하는지를 나타내며, 최악의 경우에 대한 예측을 제공합니다.
        
    - 종류
        1. O(1)
            
            상수 시간 알고리즘
            
            입력 크기에 관계 없이 일정한 시간이 소요됨
            
        2. O(log n)
            
            로그 시간 알고리즘
            
            입력 크기가 2배씩 증가할 때마다 1번의 연산이 수행됨
            
        3. O(n)
            
            선형 시간 알고리즘
            
            입력 크기에 비례하여 시간이 증가함
            
        4. O(n log n)
            
            로그 선형 시간 알고리즘
            
            입력 크기가 2배씩 증가할 때마다 n번의 연산이 수행됨
            
        5. O(n^2)
            
            이차 시간 알고리즘
            
            입력 크기의 제곱에 비례하여 시간이 증가함
            
        6. O(n^3)
            
            삼차 시간 알고리즘
            
            입력 크기의 세제곱에 비례하여 시간이 증가함
            
        7. O(2^n)
            
            지수 시간 알고리즘
            
            입력 크기에 대하여 2의 n제곱에 비례하여 시간이 증가함