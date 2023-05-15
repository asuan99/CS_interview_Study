# 데이터베이스 캐싱(Caching)이란 무엇이고 어떻게 동작하나요?

- 자료조사

  ### Cache

  Cache는 데이터나 값을 저장하는 임시 저장소로, 데이터를 더 빠르고 효율적으로 액세스할 수 있게 해준다.

  - 원본 데이터 접근보다 빠르다.
  - 같은 데이터를 반복적으로 접근하는 상황에서 사용하기에 알맞다.
  - 잘 변하지 않는 데이터일수록 더 효율적이다.
    ![Server_DB](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Server_DB.png)

  ***

  ### 추상적인 웹 서비스 구조(클라이언트 - 웹 서버 - DB)

  - 클라이언트가 웹 서버에 접속하고 요청을 보내면 웹 서버가 DB에 데이터를 읽거나 쓰기 작업을 요청한다.
  - DB도 사실 내부용 캐시가 있지만 캐시 용량이 Memory 사이즈보다 커지면 당연히 Disk를 사용해야 한다.
  - 쿼리 결과를 내부적 캐시에 담고 있는데 여러가지 요청을 처리하다 보면 기존에 있던 캐시를 날리고 디스크에서 새로 읽어야 하는 순간이 온다. 그래서 디스크에 접근할 때마다 속도가 굉장히 느려질 수 있다.
    ![Client_Server_DB](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Client_Server_DB.png)

  ***

  ### Cache 구조 및 전략

  Redis로 캐시로 사용할 때 어떻게 배치할 것이냐는 캐싱 전략이 필요하다. 이에 따라 성능에 영향을 끼치기 때문에 상황(데이터 유형, 데이터 액세스 패턴)에 맞게 적절한 전략을 사용해줘야 한다.

  - 시스템이 많이 작성하는데 덜 자주 읽습니까? (ex. 시간 기반 로그)
  - 데이터를 한번 쓰고 여러 번 읽습니까? (ex. 사용자 프로필)
  - 반환되는 데이터는 항상 고유합니까? (ex. 검색어)

  ***

  ### 캐시 활용 전략

  - Look aside Cache
    ![Look_Aside_Cache](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Look_Aside_Cache.png)

    - 순서
      - Cache에서 데이터가 있는지 체크한다.
      - Cache에 Data가 있으면 Cache hit! -> Data를 Application에 return 한다.
        - Cache에서 Data를 못 찾는 경우 Cache miss -> Application은 DB에 쿼리를 날려서 데이터를 읽고 Application에 Data를 반환한 뒤 Cache에 Data를 저장한다.
    - 특징

      - 읽기에 상당히 적합하다.
      - 반복적인 호출에 적합하다.
      - 캐시 시스템 자체에 대한 장애 대비 구성이 가능하다.
        - ex) Cache DB인 Redis가 죽더라도 DB에서 데이터를 가져올 수 있다.
        - Redis와 같은 Cache에 Connection이 상당히 많았다면 Redis가 죽고 난 뒤 DB에 일시적으로 Connection이 상당히 발생하므로 DB에 부하가 올 수 있다.
      - 정합성 문제 발생
        - Cache Store 와 Data Store 가 가지고 있는 데이터가 서로 다를 수 있다.
        - 초기 조회 시 무조건 Data Store를 호출해야 하므로 단건 호출 빈도가 높은 서비스에 부적합하다.
      - 읽기가 많은 경우 상당히 적합하다.
        <aside>
        💡 초기에 데이터가 DB에만 저장되어 있어 처음에 cache miss가 많아지기 때문에 성능 저하의 가능성이 있다.

        미리 DB에서 캐시로 데이터를 넣어주는 작업이 필요하고 이를 Cache Warming이라고 한다.

        </aside>

  - Read Through
    ![Read_Through](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Read_Through.png)
    - 순서
      - 캐시는 데이터베이스와 인라인으로 배치되며 Cache Miss가 있는 경우 DB에서 Miss된 데이터를 로드하고 Cache를 채우고 Application으로 반환.
      - Cache-aside, Read-through 전략은 처음 Read 하는 경우에만 data load를 lazy 하게 진행함.
    - 특징
      - 읽기가 많은 워크 로드에 적합하다.
      - Read Through 방식은 Cache Aside 방식과 비슷하지만 차이점이 존재한다.
        - 차이점
          - cache-aside에서는, application은 데이터베이스에서 데이터를 가져오고 캐시를 채우는 역할을 함.read-through에서는 위에 로직을 라이브러리가 지원하거나 stand alone 형식의 cache provider가 지원해 줌.
          - cache-aside와는 다르게, read-through에서 DB에서 직접 Cache를 채우기 때문에 cache의 데이터 모델은 DB의 데이터 모델과 다를 수가 없다.
      - Read-Through는 동일한 데이터가 여러번 요청될 때 읽기가 많은 워크 로드에 적합함
  - Write Back
    ![Write_Back](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Write_Back.png)

    - log를 DB에 넣어야 하는 경우에 cache에 몰아 넣어 놓고 한번에 배치 작업으로 DB에 저장하는 로직과 같이 Cache에 데이터를 몰아두고 DB에 한번에 배치작업으로 write 한다.
    - 특징
      - Queue의 역할을 한다.
      - DB에 대한 전체 쓰기를 줄일 수 있기 때문에 비용을 감소할 수 있다.
      - Data 정합성이 확보된다
      - 단 캐시가 장애가 났을 경우 Data가 유실될 수 있다.
      - 불필요한 리소스가 저장된다.
      - Write Back 패턴의 경우 Cache Store가 데이터 저장소 역할을 하면서 동시에 Data Store에 Write 부하를 줄이기 위한 Queue의 역할도 한다.
        - Database의 부하를 경감 시킬 수 있는 장점이 있다.
        - 대체로 쓰기 작업이 많은 경우 적용을 권장한다.
    - Write Back 패턴의 장점
      - 데이터베이스의 일시적인 다운타임을 허용하거나 장애에 대응할 수 있다.
      - Cache와 Date Store 간 데이터 정합성 유지하기 유용하다.
      - 쓰기 성능을 향상시키고 쓰기 작업량이 많은 워크 로드에 적합하다.
        - read-throught와 결합하면 최근 업데이트되고 엑스스된 데이터를 항상 캐시에 사용할 수 있는 혼합 워크 로드에 적합하다.
    - Write Back 패턴의 단점

      - Cache Store에서 Data Store로 데이터를 전송하기 전에 장애 발생 시 데이터 분실 발생 위험이 있을 수 있음
      - 자주 사용되지 않는 데이터가 저장되어 리소스 낭비, Write 작업에 부하 발생할 수 있음 \*\*\*\*TTL을 꼭 사용하여 사용되지 않은 데이터를 삭제해야 한다
        <aside>
        💡 **TTL 이란?**

        타임 투 리브(Time to live, TTL)는 컴퓨터나 네트워크에서 데이터의 유효 기간을 나타내기 위한 방법이다.

        TTL은 계수기나 타임스탬프의 형태로 데이터에 포함되며, 정해진 유효기간이 지나면 데이터는 폐기된다.

        컴퓨터 네트워크에서 TTL은 패킷의 무한 순환을 방지하는 역할을 한다.

        컴퓨터 애플리케이션에서 TTL은 캐시의 성능이나 프라이버시 수준을 향상시키는 데에 사용되기도 한다

        </aside>

  - Write Through
    ![Write_Through](https://github.com/JungMunGyu/CS_interview_Study/blob/main/database/img/Write_Through.png)
    - Application 이 Data를 쓰거나 값을 update 하려고 할 때
      - 응용프로그램은 Data를 Cache에 직접 쓴다.
      - Cache는 DB에 Data를 update 한다.
      - 쓰기가 완료되면 Cache와 Database 모두 동일한 값을 가지며 Cache는 항상 일관성을 유지한다.
    - 특징
      - 항상 Cache와 DB가 동기화되어 있어 DB 작성할 때마다 Cache에 Data를 추가한다.
      - Cache와 Back up DB에 업데이트를 같이 하여 데이터 일관성을 유지할 수 있어서 안정적이다.
      - 데이터 유실이 절대로 발생하면 안 되는 상황에 적합하다.
      - 기억장치에 데이터를 기록할 때 cpu 대기시간이 필요하기 때문에 성능이 떨어진다.
      - 사실상 Cache가 자체적으로 많은 작업을 수행하지 않는다.
      - Wrtie Through 패턴은 Cache Store에도 반영하고 Data Store에도 동시에 반영하는 방식
        - Write Back은 일정 시간을 두고 나중에 한꺼번에 저장한다.
        - 그래서 항상 동기화가 되어 있어 항상 최신 정보를 가지고 있다는 장점이 있다.
      - 저장할 때마다 2단계 과정을 거쳐 치기 때문에 **상대적으로 느리며** 무조건 일단 Cache Store에 저장하기 때문에 캐시에 넣은 데이터를 저장만 하고 사용하지 않을 가능성이 있어서 리소스 낭비 가능성이 있다.
        - 이 역시 이를 해결하기 위해 TTL을 꼭 사용하여 사용되지 않는 데이터를 반드시 삭제해야 한다.

- 답안
  > DB에 데이터를 읽거나 쓰기 작업을 요청할 때 쓰기에 비해 읽기가 많은 데이터가 있다. 이러한 데이터에 대한 접근을 할 때 데이터베이스에서 캐시를 사용하는 것을 데이터베이스 캐싱이라고 한다. 올바르게 수행되면 캐시는 응답 시간을 줄이고 데이터베이스의 부하를 줄이며 비용 절감에 효과적이다. 캐시를 활용하는 몇 가지 전략이 있으며 올바른 것을 선택하면 좋은 효과를 볼 수 있다. 캐싱 전략에는 Look aside Cache, Read Through, Write Back, Write Through등이 있다.
- reference
  [[Cache] cash 말고! DB cache 활용 전략!](https://velog.io/@vino661/Database-Cache-활용-전략)
  [[Database] 캐싱과 캐싱 전략에 대해 알아보자](https://loosie.tistory.com/800)
