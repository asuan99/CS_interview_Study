## 질문 2 : TCP와 UDP의 특징과 차이

- 자료조사
  - 패킷들이 전송되는 과정에서 막힘없이 전송되면 좋겠지만, 실제 환경에서는 여러가지 요인들로 인해 지연이 발생한다.

### Packet Delay의 종류 4가지
  1. Processing Delay
  2. Queueing Delay
  3. Transmission Delay
  4. Propagation Delay

### Processing Delay

  - Processing 과정은 라우터 내에서 패킷이 진행하는 과정이다.
  - 패킷 내 데이터의 **에러체크**와 **어디로 나갈지 결정**한다.
      - 이 과정에서 발생하는 Delay
  - 매우 짧은 시간동안만 발생하며, 라우터 내의 하드웨어 성능에 따라 좌지우지되므로 가변적이지 않다.
  - 해결법 : 성능 좋은 하드웨어 쓰기 → 비쌈

---

### Queueing Delay

  - 라우터로 패킷들이 한번에 많이 들어올 경우, 라우터는 패킷들을 queue 형태로 보관하여 차례대로 처리한다.
  - 전송을 위해 output link의 queue에서 기다리면서 발생하는 지연을 Queueing delay라 한다.
  - Queueing delay는 라우터의 **congestion(혼란) 정도가 결정**하며, 상황에 따라 가변적이라 예측이 어렵다는 특징이 있다.
  - 해결법 : 현재까지 마땅한 해결방법이 없음

---

### Transmission Delay

  - queue를 빠져나가 라우터의 output link를 통해 빠져나가기 전까지 발생하는 delay이다. 즉, **전송하려는 패킷을 output link로 밀어내는데 걸리는 시간**이다.
  - Time to send bits into link = L/R
      - L : packet length(bits)
      - R : link bandwidth(bps)
  - 해결법 : 패킷이 전송되는 link의 성능에 따라 갈리며, 품질이 좋은 link를 사용할 경우 Transmission delay가 줄어든다.

---

### Propagation Delay

  - 실제 link를 타고 데이터가 전송될 때 발생하는 delay이다.
  - Propagation delay는 거리와 link의 매체가 결정하는 delay로, 다른 delay에 비해 매우 짧은 시간이 걸린다. 특히나 요즘같이 광통신을 하는 경우에는 거의 없다고 봐도 될 정도로 짧다.
  - Propagation delay = (distance) / (Propagation speed) 로 계산한다.
      - distance : length of physical link
      - Propagation speed : in medium(~2x108 m/sec)

 - 답안
    - 패킷이 전송되는데 발생하는 delay는 Processing delay, Queueing delay, Transmission delay, Propagation delay 가 있다. Processing delay는 에러체크와 어떤 경로로 패킷이 나가야하는지 정하는 Processing 과정에서 생기는 Delay이다. 더 성능이 좋은 하드웨어를 쓴다면 어느정도 시간을 줄일 수 있다. Queueing delay는 큐에서 패킷의 전송을 위해 output link의 큐에서 기다리면서 발생하는 Delay이다. Queueing delay는 현재까지 마땅한 해결책이 없다. Transmission Delay는 큐를 빠져나가 라우터의 output link를 통해 빠져나가기 전까지 발생하는 delay이다. 성능좋은 link를 사용할 경우 delay를 줄일 수 있다. 마지막으로 Propagation delay는 실제 link를 타고 데이터가 전송될 때 발생하는 delay이다. 광통신을 사용하는 경우에는 delay가 거의 없다고 봐도 될 정도로 짧다.
    
    

- reference
    - [패킷의 지연과 손실](https://ddongwon.tistory.com/70)
    - [2022 네트워크 강의자료]20220307_Background.pdf