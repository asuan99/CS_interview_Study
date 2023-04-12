# 1. 파이프라인과 슈퍼스칼라의 차이점은 무엇인가요?

- 자료조사
    - 파이프라인
        
        CPU 명령어 처리를 단계적으로 분할하고, 각 단계를 병렬로 처리함으로써 CPU의 처리 속도를 높이는 기술
        
        - 예시
            
            ![그림1](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/pipeline_ex1.png)
            
            Single-cycle예시
            
            ![그림2](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/pipeline_ex2.png)
            
            PipeLine 예시
            
            ![그림3](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/5cycle_set.png)
            
            - 명령어 5 Cycle 구조
                1. fetch : 명령어 메모리에서 명령어를 가져옵니다.
                2. decode : 명령어를 해석하여 필요한 레지스터와 메모리 주소를 찾습니다.
                3. execute : 명령어를 실행합니다.
                4. memory access : 명령어에서 필요한 데이터를 메모리에서 가져오거나 메모리에 쓰기를 합니다.
                5. write back : 결과를 레지스터나 메모리에 씁니다.
            
            ![그림4](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/single_vs_pipeline.png)
            
            1번째 : single : 800ps / pipeline : 1000ps
            
            2번째 : single 1600ps / pipeline : 1200ps
            
            1,000,000 번째?
            
            single : 800 * 1,000,000ps
            
            pipeline : 1000 + 200 * 999,999ps
            
            - 꼬리질문
                
                위 사진에서 Reg의 위치가 다르다 이유는??
                
                - 답변
                    
                    ![그림5](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/structual_hazard_ex.png)
                    
                    **structual hazard**를 막기위해서 write는 앞에 read는 뒤에 실행한다.
                    
    - 슈퍼 스칼라
        
        CPU 내에 여러 파이프라인 유닛을 두어 명령어를 동시에 실행하는 기술이다. 
        
        - 예시
            
            ![그림6](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/superscalar.png)
            
            2-WAY 슈퍼스칼라 예시
            
            N-WAY의 경우 이론적으로 N배의 처리속도가 가능하지만 실질적으로는 명령어 **캐시의 제약, 명령어 사이의 의존성, 분기문** 등의 문제로 N배보다 적은 처리속도를 보여준다.
            
- 답안
    
    파이프라인과 슈퍼스칼라 모두 병렬 처리를 통해 CPU의 처리 속도를 높이는 병렬처리 방법이지만, 파이프라인은 명령어를 처리하는 각 단계를 병렬로 처리하는 반면, 슈퍼 스칼라는 한번에 여러 개의 명령어를 병렬로 처리한다.
    
- Reference
    
    [위키백과 슈퍼스칼라](https://ko.wikipedia.org/wiki/%EC%8A%88%ED%8D%BC%EC%8A%A4%EC%B9%BC%EB%9D%BC)
    
    곽종욱 교수님 컴퓨터구조 4강
    
- 추가 질문
    - 원호 : 파이프라인과 슈퍼스칼라의 명령어 구조가 같나요??
        
        파이프라인(Pipeline)과 슈퍼스칼라(Superscalar)는 모두 컴퓨터의 프로세서 설계 기술 중 하나로, 명령어의 실행을 빠르게 처리하기 위한 기술입니다. 그러나 파이프라인과 슈퍼스칼라는 서로 다른 구조와 동작 방식을 가지고 있으며, 명령어 구조도 다릅니다.
        
        파이프라인은 명령어를 실행하는 과정을 여러 단계로 나누어 각 단계를 병렬적으로 처리하도록 설계된 구조입니다. 예를 들어, 명령어를 메모리에서 읽어오는 단계, 연산을 수행하는 단계, 결과를 저장하는 단계 등으로 나누어 처리합니다. 이러한 단계를 파이프라인 스테이지라고 하며, 각 스테이지는 이전 스테이지의 결과를 받아 처리합니다.
        
        반면에 슈퍼스칼라는 여러 개의 기능 유닛(Function Unit)을 가지고 있어서, 동일한 명령어를 병렬로 처리할 수 있습니다. 이를 위해 명령어를 분석하여 동일한 유형의 명령어는 동일한 기능 유닛에서 처리하도록 설계되었습니다.
        
        따라서, 파이프라인과 슈퍼스칼라는 명령어의 실행을 빠르게 처리하기 위한 공통된 목적을 가지고 있지만, 명령어 구조와 처리 방식은 다릅니다.
        
    - 병준 : 유닛 별 클락을 다르게 주면
        
        서로의 의존성 확인을 위한 처리단계가 늘어나서 성능이 오히려 저하될 수 있기 때문