# 고정 길이의 해시값이 임의 길이의 해시값보다 좋은 이유

- **자료 조사**
    
    ![hash operation](https://user-images.githubusercontent.com/44726494/222752691-97d1b3ec-30d3-4b85-829c-331c91a52399.png)

    - **해시 함수 (Hash Function)**
        
        해시 함수는 데이터의 효율적인 관리를 목적으로 임의의 길이의 key 혹은 데이터를 **고정된 길이의 데이터**로 매핑해주는 역할을 하는 함수이다.
        
        좋은 해시 함수는 두 개의 기본 속성을 만족합니다.
        
        1) 계산이 매우 빠르다.
        
        2) 출력 값의 중복을 최소화한다.
        
        해시 함수는 다음 세 가지 특성을 가져야 합니다.
        
        1. 역상 저항성
            - 해시 값이 주어졌을 때, 그 해시 값을 생성하는 입력값을 알아내는 것이 불가능하다는 특성
            - **참고**
                
                ![Preimage_resistance](https://user-images.githubusercontent.com/44726494/222752719-6682f7f1-b37a-464f-b450-bbc51a288a06.png)

        2. 제2 역상 저항성
            - 어떤 입력 값과 동일한 해시 값 (결과 값)을 가지는 다른 입력 값을 찾을 수 없어야 한다는 특성
            - **참고**
                ![2nd_preimage_resistance](https://user-images.githubusercontent.com/44726494/222752750-ffcc608a-d1ee-4064-b593-beb70b841be8.png)

        3. 충돌 저항성
            
            해시 값이 동일한 입력 값 두 개를 찾을 수 없다는 특성이다.
            
            - **참고**
                ![Collision_esistance](https://user-images.githubusercontent.com/44726494/222752782-fe4db9b5-cd75-46db-922b-4a05336ca2c2.png)

    - **해시 (Hash)**
        
        다양한 길이를 가진 데이터를 고정된 길이를 가진 데이터로 매핑한 값
        
    - **해시 테이블 (Hash Table)**
        
        해싱을 통해 변환된 해시값을 주소 또는 색인 삼아 데이터를 key와 함께 저장하는 자료 구조
        
- **답안**
    
    고정 길이의 해시값은 두 개의 동일한 입력 값에 대해 항상 동일한 해시값을 반환해 데이터 일관성을 유지해주고 입력값의 크기와 관계없이 동일한 크기의 해시값을 반환해주어 저장 공간을 절약하는 데 도움을 주기 때문에 고정 길이의 해시값이 임의 길이 해시값 보다 다양한 측면에서 더 좋다고 말할 수 있습니다.
    
- **참고 자료**
    - [wikipedia hash_function](https://stackoverflow.com/questions/29599047/why-is-hash-output-fixed-in-length)
    - [stack overflow](https://stackoverflow.com/questions/29599047/why-is-hash-output-fixed-in-length)
    - [인크립션: 실용주의 암호화](https://thebook.io/006879/ch07/01_06/)
