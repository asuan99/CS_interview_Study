# 2주차(자료구조/알고리즘)

# 1. Sorting중에 제일 효율적인 Sorting은 무엇이라고 생각합니까?

## 자료조사

### bubble 정렬

![bubble.gif](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/fd5c3ff3-2670-4f79-997c-64c4b9fb9db7/bubble.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064717Z&X-Amz-Expires=86400&X-Amz-Signature=d15e1c1d76bde09db0bb5527edccd3c9d42e09b2f500507c01cff98175c5290e&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22bubble.gif%22&x-id=GetObject)

만약 배열에 n개의 요소가 있을 경우 1번째 원소 vs 2번째 원소를 비교하고 2번째 원소 vs 3번째 원소를 비교하고, ... n-1번째 원소 vs n번째 요소를 비교하면 1회전 비교가 끝난다.

간단한 알고리즘이지만, 시간복잡도가 최고, 평균, 최악 모두 O$(n^2)$이다.

### insert 정렬

![insert-min.gif](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/3bcc26aa-fbc8-47eb-a51b-2046da0eb25c/insert-min.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064729Z&X-Amz-Expires=86400&X-Amz-Signature=95106cc50b9b9c108fab9d2638e242b5e1c469752aff4c2d242398dc2873717d&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22insert-min.gif%22&x-id=GetObject)

삽입 정렬이란 정렬을 진행할 원소의 index보다 낮은 곳에 있는 원소들을 탐색하며 알맞은 위치에 삽입해주는 정렬 알고리즘이다. 동작 방식은 두 번째 index부터 시작한다.

최적의 경우 시간복잡도가 O(n)이다. 평균, 최악의 경우는 O$(n^2)$이다.

### Selection 정렬

![selection.gif](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/edacfa4a-8418-4f82-9525-e743113de052/selection.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064742Z&X-Amz-Expires=86400&X-Amz-Signature=fd8d13e4de8596bf20c2427c22aa225537e1a0f6a33b2b580c35bde243c07140&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22selection.gif%22&x-id=GetObject)

시간복잡도가 모두 O$(n^2)$인 비효율적인 알고리즘이다. 첫 번째는 주어진 배열에서 최소값을 찾는다. 두 번째는 최소값을 맨 앞의 값과 바꾼다.

### Quick 정렬

![quick.gif](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/baff037d-4b3a-4761-b39f-40e00fb4013c/quick.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064758Z&X-Amz-Expires=86400&X-Amz-Signature=bbae97dffe64c00c1a4b1e19d65ce43abdeac4bacc332c84cfa8dbe14720f031&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22quick.gif%22&x-id=GetObject)

퀵 정렬의 동작방식은 다음과 같다. 가령 예를 들어 배열 [5, 6, 1, 4, 2, 3, 7]이 있고, 피봇을 임의로 4를 선택했다 가정하자. 이후 4를 기준으로 작은 것은 왼쪽으로 큰 것은 오른쪽으로 보내 [1, 2, 3] < 4 < [5, 6, 7]를 생성한다. 다시 왼쪽에서부터 임의의 피봇 2를 설정하여 [1] < 2 < [3]을 생성하고 오른쪽에선 임의의 피봇 6를 설정하여 [5] < 6 < [7]로 나눈다. 이를 피봇선택이라고 한다.

시간복잡도는 최적, 평균의 경우 O$(nlog_2n)$이고 최악의 경우 O$(n^2)$이다.

### Merge 정렬

![merge.gif](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/03f3be47-f4f9-42bd-ba1a-240e30e3bb54/merge.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064813Z&X-Amz-Expires=86400&X-Amz-Signature=4108d2503980d8079066814854b9d6ca5671e6a02b747de4d07af9908b800c06&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22merge.gif%22&x-id=GetObject)

퀵 정렬과 같이 피봇선택 알고리즘을 사용한다. 피봇 선택 이후 피봇 기준으로 대소를 비교하는 반면, 병합 정렬은 배열을 원소가 하나만 남을 때 까지 계속 이분할 한 다음, 대소관계를 고려하여 다시 재배열 하며 원래 크기의 배열로 병합한다. 예를 들어 배열 [6, 5, 1, 4, 3, 2, 8, 7]이 있을 때, 첫 번째로 [6, 5, 1, 4]와 [3, 2, 8, 7]로 분리한다. 두 번째로 [6, 5], [1, 4], [3, 2], [8, 7]로 나눈다. 세 번째로 [6], [5], [1], [4], [3], [2], [8], [7]로 나눈다. 이렇게 모든 원소가 분리되면 대소 관계를 고려하여 병합 과정을 거친다. 첫 번째로 [5, 6], [1, 4], [2, 3], [7, 8]이 되며, 두 번째는 [1, 4, 5, 6], [2, 3, 7, 8]이 된다. 마지막으로 하나의 배열로 병합되면서 [1, 2, 3, 4, 5, 6, 7, 8]와 같이 정렬이 완료되면서 알고리즘이 종료된다. 시간복잡도는 모두 $nlog_2n$이다.

### Heap 정렬

힙 정렬이란 완전 이진 트리를 기반으로 하는 정렬 알고리즘이다. 힙의 분류는 크게 최대 힙과 최소 힙 두 가지로 나뉜다. 최대 힙은 내림차순 정렬에 사용하며, 최소 힙은 오름차순 정렬에 사용한다.

![heap.png](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/0363b7d6-ff1f-4345-be7d-0c84bf570198/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064826Z&X-Amz-Expires=86400&X-Amz-Signature=627d8f6ab32bd7e364d77fc6aff0cf0597d119ec1d63b5df10fdceb2b8ae1d06&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject)

시간복잡도는 모두 O($nlog_2n$)이다.

![O(n).png](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/31262607-5799-4349-8b19-e21ed7f99eae/O%28n%29.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230310%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230310T064839Z&X-Amz-Expires=86400&X-Amz-Signature=3d3fb80a7b11a14252d10de417d77e7f578c4bc36305c472fb6b484b858109fc&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22O%28n%29.png%22&x-id=GetObject)

## 답변

최선의 경우(정렬되어있는 경우)에는 삽입정렬이 제일 빠르지만 대부분의 경우에는 퀵 정렬을 많이 사용한다. 하지만 최악의 경우를 생각할 때는 힙정렬이나 병합정렬도 나쁘지 않은 정렬방법이다.

### ref

[[자료구조] 기본 정렬 알고리즘 총 정리](https://roytravel.tistory.com/328)

[https://github.com/gyoogle/tech-interview-for-developer/tree/master/Algorithm](https://github.com/gyoogle/tech-interview-for-developer/tree/master/Algorithm)

