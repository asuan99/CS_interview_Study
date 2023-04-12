# 2. 파이프라인 도중 발생하는 해저드에는 무엇이 있습니까?

- 자료조사
    - Data Hazard
        
        다음 명령어가 이전 명령어로부터 데이터를 읽어와야 하는데, 이전 명령어가 아직 실행을 완료하지 않은 상태라서 데이터가 준비되지 않은 경우 발생
        
        - 예시
            
            ![그림1](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/data_hazard_ex.png)
            
            **→ 빨강색의 경우 hazard**
            
            - 해결법
                - stalling 기법
                    
                    ![그림2](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/data_hazard_stalling.png)
                    
                    데이터를 사용하는 명령어를 실행하는 단계를 대기시켜 데이터가 준비될 때까지 기다리는 방법입니다. 이 방법은 해결 방법이 간단하지만, 파이프라인의 성능을 저하시키는 단점이 있습니다.
                    
                - Forwarding 기법
                    
                    ![그림3](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/data_hazard_forwarding.png)
                    
                    이전 명령어에서 계산된 결과를 레지스터를 통해 바로 다음 명령어에게 전달하여 데이터 해저드를 해결하는 방법입니다. 이를 위해서는 ALU(산술논리연산장치)에서 계산된 값을 따로 보관해야 하며, 이를 위해 추가적인 회로가 필요합니다.
                    
            
    - Control Hazard
        
        
        프로그램 실행 도중 분기(branch)나 점프(jump)와 같은 제어 흐름 변경 명령어가 발생하여, 다음 명령어를 정확히 예측할 수 없는 상황에서 발생하는 문제를 말합니다. 즉, 파이프라인에서 다음 명령어를 가져오는 과정에서 명령어의 흐름을 예측할 수 없어서, 올바른 명령어를 가져오지 못하는 문제를 의미합니다.
        
        - 해결방법
            - Flushing 기법
                
                ![그림4](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/control_hazard_flushing.png)
                
            - Move branch decision hardware
                
                ![그림5](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/control_hazard_early_decision.png)
                
                MEM 단계에서 branch가 결정되던 기존의 datapath와는 달리 ID 단계에서 결정이 일어나서 1 cycle만 손해를 보게된다.
                
            - Prediction
                
                예측을 통하여 conditional branch가 taken 될지, 아니면 untaken 될 지 예측합니다.기본적인 **default 값은 untaken** 될 것이라 예측합니다. 만약 prediction이 틀린다면 pipeline stall이 발생하게 됩니다.
                
                - Static
                    
                    **Static은 branch의 일반적인 행동을 기반으로 예측합니다.**
                    
                    loop 같은 경우에는 항상 branch가 taken 된다고 가정합니다.
                    
                    만약 100번 loop 한다고 가정하면, 99번은 맞추고 1번은 틀리게 됩니다.
                    
                - Dynamic
                    
                    앞의 상황에 따라 뒤의 상황을 예측
                    
                    **branch prediction buffer** 는 IF 단계에 있으며, 해당 buffer는 branch가 최근에 taken 되었는지 아닌지에 대한 bit 정보를 저장하고 있습니다.
                    
                    **1-bit predictor**
                    
                    ![그림6](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/1bit_prediction.png)
                    
                    **2-bit predictor**
                    
                    ![그림7](https://github.com/HmDol/CS_interview_Study/blob/main/os%26computer_structure/img/2bit_prediction.png)
                    
                    일반적으로 1bit predictor 보다 2bit predictor이 25% 성공확률 향상이 있다.
                    
- 답안
    
    데이터 해저드와 제어 해저드가 대표적입니다. 데이터 해저드는 이전 명령어의 결과를 미리 받지 못해 생기는 해저드로 Forwarding 기법으로 해결 가능하며, 제어 해저드는 분기문의 예측이 불가하여 생기는 해저드로 Dynanic prediction기법을 이용해 성능저하를 최소화 할 수 있습니다.
    
- Reference
    
    곽종욱 교수님 컴구 4강
    
    [티스토리 Control Hazard](https://hi-guten-tag.tistory.com/267)