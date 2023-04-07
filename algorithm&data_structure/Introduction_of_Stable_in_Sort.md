# Stable sort에 대해 설명하시오

## 답안

> Stablesort는 중복된 값을 가진 데이터들이 포함된 리스트를 정렬 시키더라도 중복된 값에 대한 상대적인 위치가 유지되도록 하는 정렬로 Insertion sort, Merge sort, Counting sort등이 있다. 정렬을 하여도 요소의 상대적인 순서를 유지해야 하는 경우에 사용하며, 아닌 경우에는 Unstable sort가 성능이나 메모리 사용에 대해서 유리하므로 Unstable sort사용이 권장된다.
> 

---

## 자료 조사

- Stablesort
    
    > 중복된 값을 가진 데이터들이 포함된 리스트를 정렬 시키더라도 중복된 값에 대한 상대적인 위치가 동일할 경우 해당 정렬 알고리즘은 Stablesort로 볼 수 있다.
    > 

![카드를 번호 순으로 정렬한다고 하였을 때 “5”라는 같은 수를 가진 문양이 다른 카드 2개가 존재한다. 이 카드들이 정렬이 끝났을 때  “하트5”가 “5”카드중의 처음, “스페이드5”가 “5”카드의 두 번째라는 상대적인 위치가  유지 된다면 해당 정렬 알고리즘은 Stablesort로 볼 수 있고, 반대의 경우Unstablesort 있다.  ](https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/Sorting_stability_playing_cards.svg/440px-Sorting_stability_playing_cards.svg.png)

카드를 번호 순으로 정렬한다고 하였을 때 “5”라는 같은 수를 가진 문양이 다른 카드 2개가 존재한다. 이 카드들이 정렬이 끝났을 때  “하트5”가 “5”카드중의 처음, “스페이드5”가 “5”카드의 두 번째라는 상대적인 위치가  유지 된다면 해당 정렬 알고리즘은 Stablesort로 볼 수 있고, 반대의 경우Unstablesort 있다.  

- 대표적인 Stable sort
    - Insertion sort
    - Merge sort
    - Bubble sort
    - Counting sort
    - Radix sort
- 사용 이유
    
    > 정렬을 하여도 요소의 상대적인 순서를 유지해야 하는 경우에 사용함 가령 학생 데이터에 대해 이름 순으로 정렬된 배열을 학년을 기준으로 나누기 위해 Unstable sort알고리즘으로 학년 기준으로 정렬한다면 학년 별로 나눠진 데이터에 대해서 다시 이름 순으로 정렬을 진행하여야 한다. 그러나 Stable sort를 사용한다면 이름 순에 대한 상대적인 순서가 유지되기 때문에 나눠진 데이터에 대해서 이름 순을 보장할 수 있다.
    > 
- 단점
    
    > 대체적으로 Unstable sort보다 속도가 느리거나 추가적인 메모리를 사용해야 한다는 단점이 있다. 특수한 경우에서 사용할 수 있는 Counting sort나 Radix sort를 제외 했을 때   Unstable한 Quciksort보다 느리며, 그나마 빠른 Mergesort의 경우 Quicksort보다 살짝 더 느리며, 더 많은 메모리를 사용한다.  따라서 요소의 상대적인 순서를 유지해야 하는 경우가 아니라면 Unstablesort사용이 더욱 유리하다.
    > 

---

## 참고 자료

---


스택오버플로우 : [What is stability in sorting algorithms and why is it important?](https://stackoverflow.com/questions/1517793/what-is-stability-in-sorting-algorithms-and-why-is-it-important)

Wikipidia : [정렬 알고리즘](https://ko.wikipedia.org/wiki/정렬_알고리즘)

