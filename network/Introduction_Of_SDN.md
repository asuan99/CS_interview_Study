# SDN에 대해 설명하시오

## 답안

> SDN은 Software-Defined Networking의 약자로 네트워크 장비 가령 Router의 Control Plane와 Data Plane을 분리하여 Control Plane은 중앙 서버가 제어하고 Data Plane은 기존처럼 장비가 담당하도록 한다. Control Plane을 중앙 서버가 제어함으로써 각각의 네트워크 장비를 수동으로 관리할 필요 없이 중앙에서 관리하므로 유지 보수 비용이 줄어들고 네트워크 상황에 맞는 빠른 대응이 가능해지며, 라우팅의 경로 또한 유연하게 적용 가능하다.
> 

---

## 자료 조사

### Network Layer

IP 주소를 이용하여 패킷의 전달 경로를  결정하는 역할을 함
대표적인 장비로 Router가 있으며,  기능적으로 Control Plane과  Data Plane로 나누어 볼 수 있다.

- Control Plane : Routing관련 알고리즘. Router 간의 상호작용을 통해 패킷의 최적 전달 경로를 결정
- Data Plane : Fowarding관련 알고리즘. Routing알고리즘을 통해 만들어진 Forwarding Table을 참조하여 목적지에 맞는 포트로 패킷을 전달

### SDN

소프트웨어 정의 네트워킹(Software-Defined Networking)

핵심 : 네트워크 장비(Router)의 Control Plane과 Data Plane의 분리하여 Control Plane을 별도의 컴퓨팅 서버로 분리, 네트워크 장비는 Data Plane만 담당하도록 함

→ Router의 Control Plane을 중앙에서 제어하거나 관리하여 장비별 관리에 따른 리소스 낭비를 최소화하고 트래픽에 따른 제어를 효과적으로 처리할 수 있음

- 장점
    - 각각의 네트워크 장비를 수동으로 관리할 필요 없이 중앙에서 하므로 유지비용이 감소
    - Control Palne과 Data Plane의 분리를 통해 효율적으로 관리 가능
    - 중앙 제어를 통해 네트워크 상황에 따른 빠른 대응 가능
    - 네트워크 상황에 따른 라우팅 루트의 변화를 유연하게 적용 가능

---

## 꼬리 질문

---

## Ref

---

[[Network] SDN(Software Defined Network) 이란?](https://suyeon96.tistory.com/48)

[SDN 개념 기존네트워크와 차이점 장단점 비교](https://techblogpedia.com/sdn-%EA%B0%9C%EB%85%90-%EA%B8%B0%EC%A1%B4%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC%EC%99%80-%EC%B0%A8%EC%9D%B4%EC%A0%90-%EC%9E%A5%EB%8B%A8%EC%A0%90-%EB%B9%84%EA%B5%90/)

영남대학교 [컴퓨터 네트워크 및 실습(박영덕)] 강의
