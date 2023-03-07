# Hash, HashMap, HashTable

# HashMap과 HashTable의 차이점은 무엇인가요?

- 해쉬(Hash)
    - 해쉬(Hash)란 단방향 암호화 기법인 해시함수를 이용하여 생성된 고정된 길이의 비트열
    - 변경전 원래 데이터의 값: Key, 변경 후 데이터의 값: value로 키와 값으로 변환되는 과정을 해싱(Hashing)이라고 함
    - 해싱 과정에서 value가 중복되는 경우를 해시충돌(Hash Collision) 이라고 함
- 해시맵(HashMap), 해시테이블(Hashtable)
    - 해시함수를 사용하여 Key를 해시값으로 매핑하고, 해시값을 인덱스 혹은 주소로 하여 데이터의 값(value)를 key와 함께 저장하는 자료구조
        
        ![Hash](https://user-images.githubusercontent.com/111514410/222893577-494ce29c-ab99-42e1-b502-06ceda660f31.png)

    
- HashMap
    - Key와 value에 null 허용
    - 동기화를 보장x
    - thread-safe하지 않기 때문에 싱글 쓰레드 환경에서 사용하는게 좋음
    - 데이터 탐색 속도가 빠르지만 신뢰성과 안정성이 떨어짐
    
    ```java
    public V get(Object key) {
    	Node<K,V> e;
    	return (e = getNode(hash(key), key)) == null ? null : e.value;
    }
    ```
    
- HashTable
    - Key와 value에 null을 허용하지 않음
    - 동기화를 보장
    - thread-safe 하기 때문에, 멀티 쓰레드 환경에서 사용할 수 있음
    - 메소드를 보면 synchronized 키워드가 있는데 이것을 통해 쓰레드간 동기화 락을 걸어 데이터 무결성을 보장
    - 탐색 속도가 매우 느림
    
    ```java
    public synchronized V get(Object key) {
    	Entry<?,?> tab[] = table;
    	int hash = key.hashCode();
    	int index = (hash & 0x7FFFFFFF) % tab.length;
    	for (Entry<?,?> e = tab[index] ; e != null; e = e.next) {
    		if ((e.hash == hash) && e.key.equals(key)) {
    				return (V)e.value;
    		}
    	}
    	return null;
    }
    ```
    
- 답안
    
    Hashmap은 key와 value에 null을 허용하지만 HashTable은 허용하지 않는다는 차이점도 있지만 가장 큰 차이는 Thread-safe라고 할 수 있다. Hashtable의 모든 data 변경 메소드는 synchronized로 선언되어 있어 data의 무결성을 보장해주는 반면 HashMap의 경우 Thread-safe하지 않기 때문에 멀티 스레드 환경에서 동시에 data를 조작할 경우 data가 깨질 수 있다.
    
- 참고
    
    [[자료구조] Hash, HashMap, HashTable](https://velog.io/@kwj2435/자료구조-Hash-HashMap-HashTable)
    
    [자바 해시 테이블( Hashtable), 해시 맵(HashMap) 구조와 원리](https://nhj12311.tistory.com/512)
    
    [HashMap vs HashTable vs ConcurrentHashMap](https://tecoble.techcourse.co.kr/post/2021-11-26-hashmap-hashtable-concurrenthashmap/)
