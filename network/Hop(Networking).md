# Hop(Networking)

Reference

[Wikipedia Hop(networking)](https://en.wikipedia.org/wiki/Hop_(networking))

- Hop Limit이 존재해야 하는 이유를 설명해주세요.
    
    Hop Limit이 존재하지 않고 계속해서 network device를 통해 전달된다면, network packet이 계속해서 네트워크 상에 머물게 되고, 이는 곧 전체 네트워크의 자원을 지속적으로 갉아먹기 때문에, Hop Limit을 통해 이를 제어해야 원활한 네트워크 응용이 가능합니다.
    

- Hop(Networking)
    - Hop
        
        패킷이 한 네트워크 세그먼트에서 다음으로 전달될 때 발생한다.
        
        데이터 패킷이 라우터를 통해 출발지에서 목적지 사이를 순회하는 것처럼 전달된다.
        
         hop count 는 데이터가 출발지에서 목적지로 전달되는 동안 통과한 네트워크 장치의 수를 의미한다.(라우팅 토폴로지에 따라 출발지/목적지를 포함할 수도 있고, 첫 홉은 hop 0 또는 hop 1 으로 세아린다)
        
        저장과 전달 그리고 각 홉 사이에서 발생하는 다른 레이턴시들로 인해 출발지와 목적지 사이에 hop이 많으면 실시간 성능이 떨어짐을 나타낸다.
        
        ---
        
        패킷이 전달될 때 지나가는 네트워크 디바이스라고 생각하면 됨
        
    - Hop Count
        
        유선 네트워크에서 hop count는 출발지와 목적지 사이에 데이터가 지나간 network 또는 network device의 수를 의미한다. 따라서, hop count는 두 호스트간의 거리를 대략적으로 측정할 수 있다. 1-origin hop count를 사용하는 라우팅 알고리즘(RIP)의 경우 n의 hop count는 n개 network가 출발 호스트를 목적 호스트로부터 분리한다는 걸 말한다. DHCP같은 다른 프로토콜은 hop을 메시지가 전달되는 횟수를 의미한다.  
        
        Internet Protocl (IP) 같은 layer 3 네트워크에서는 데이터 경로에 따라 각 라우터가 hop을 구성한다. 하지만 speed, load, reliabilty, 특정 홉의  latency에 대한 고려를 하지 않고 전체 카운트만 고려했기 때문에, 그 자체로 이런 메트릭이 최적의 네트워크 경로를 결정하는 데 유용하지는 않다. 그럼에도 불구하고 Routing Information Protocol(RIP) 같은 몇몇 라우팅 프로토콜은 hop count를 단일 측량으로 사용한다.
        
        라우터가 패킷을 받을 때 패킷의 Time To Live (TTL)을 점점 감소시킨다. 라우터는 TTL 값이 0인 패킷을 받으면 이를 무시한다. 이는 패킷이 영원히 네트워크를 돌아다녀서 라우팅 오류가 발생하는 걸 방지한다. 라우터는 hop count를 관리할 수 있지만, Ethernet hub와 bridge 같은 네트워크 장치들은 불가능하다.
        
        ---
        
        패킷이 전달될 때 지나가는 네트워크 디바이스의 수
        
    - Hop Limit
        
        IPv4에서 TTL로 알려지고 IPv6에서는 hop limit로 알려져 있는 이 영역은 패킷이 무시되기 전에 허용되는 홉 개수 제한을 말한다. 라우터는 IP 패킷을 그들이 전달하는 과정에서 수정하며 TTL 이나 hop limit fields를 줄여나간다. 라우터는 0이나 그 이하의 값을가진 패킷에 대해서 전달할 수 없다. 이는 패킷이 영원히 루프를 도는 걸 방지한다.   
        
    - Next Hop
        
        네트워크 장치를 구성할 때, hop이 다음 hop으로 참조할 수 있도록 한다. 다음 hop은 패킷이 경로를 따라 최종 목적지로 전달되도록 하는 다음 gatway를 말한다. routing table은 일반적으로 목적지 네트워크의 IP 주소와 최종 목적지 네트워크로 전달되는 다음 gateway의 IP 주소를 포함한다. next-hop 정보를 저장하기만 해도, next-hop routing 또는 next-hop forwaring은 routing table의 크기를 줄인다. 주어진 gateway는 목적지까지 전체 경로가 아니라, 경로를 따라 한 스텝 밖에 모른다. routing table에 리스트 업 돼있는 next hops이 gateway가 직접적으로 연결된 네트워크를 아는 주요한 단서가 된다.
        
    - Diagnostics
        
        traceroute 명령어는 한 router host에서 다른 router host로의 수를 측정하는 데 사용된다.  Hop count는 네트워크 상의 오류를 찾거나 routing이 실제로 연결됐는 지 파악하기에 용이하다.
        
    - Wireless ad hoc networking
        
        무선 애드 혹 네트워크에서 일반적으로 모든 참여 노드는 router처럼 동작한다. 이는 hop과 hop count라는 용어가 혼란을 일으킨다는 걸 말한다. 송신 노드는 간단하게 첫번째 hop으로 카운트하므로, hop을 라우터 순회와 노드에서 노드로의 이동으로 해석할 때 hop에 대해 같은 수를 나타낸다.  
        

- Advanced Topic
    - Single-hop routing
    
    - Multi-hop routing
        - wireless sensor networks
        - wireless mesh networks
        - Mobile ad hoc networks
        - Smart phone ad hoc networks
        - Mobile networks with stationary multi-hop relays