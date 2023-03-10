## 질문 1 : 해시 collision에 대해 설명하고, 해결 방법을 1가지 이상 말해주세요.

- 자료조사
    - Collision이란?
        - A,B 두가지 key가 있을 때 해시 값을 얻었는데 값이 똑같이 나온 경우
        - 해시함수로 해시를 만드는 과정에서 서로 다른 key가 같은 해시로 변경되면 같은 공간에 2개의 value가 저장되므로 key-value가 1:1로 매핑되어야 하는 해시 테이블의 특성에 위배
    - 해결법
        1. Chaning
            1. 저장소(Bucket)에서 충돌리 일어나면 기존 값과 새로운 값을 연결리스트로 연결하는 방법이다.

            ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7ca52444-e339-4afe-8dac-ae77af7b1ab7/Untitled.png)

            - 장점
                - 미리 충돌을 대비해서 공간을 많이 잡아놓을 필요가 없다. 충돌이 나면 그때 공간을 만들어서 연결만 해주면 된다.
            - 단점
                - 같은 hash에 자료들이 많이 연결되면 검색 시 효율이 낮아진다.

        2. 개방주소법
            1. 충돌이 일어나면 비어있는 hash에 데이터를 저장하는 방법이다.
            2. 개방주소법의 해시 테이블은 hash와 value가 1:1관계를 유지한다.
                1. 즉 충돌 발생 시 해시함수로 얻은 주소가 아닌 다른 주소 공간에 데이터를 저장한다.
        - 충돌이 발생할 경우 비어있는 hash를 찾아 저장하는 방법이 개방주소법이
        다. 이때, 비어있는 hash를 찾아가는 방법은 여러가지가 있다.
        ex) 선형 프로빙, 이차식 프로빙, 이중 해시
- 답안
해시 함수를 통해 얻은 해시값이 겹치는 경우 같은 키에 value가 두가지가 맵핑될 수 있다 이러한 경우를 collision이라고 하고, 그 해결법으로 대표적으로 Chaning기법와 개방주소법이 있다. Chaning기법은 저장소에서 Collision이 일어나면 기존 값과 새로운 값을 연결리스트로 연결하여 저장하는 방법이다 이렇게 저장하면 키값이 같다라도 연결리스트로 저장하여 여러가지 value를 저장할 수 있게 된다 개방주소법은 collision이 발생했을 때 비어있는 hash에 데이터를 저장하는 방법이다 이 기법은 key와 value의 1:1관계가 유지되어야 할 때 사용한다. 

-reference
[[자료구조] Hash의 개념 및 설명](https://go-coding.tistory.com/30)

[[자료구조] - 해시(Hash) 란?](https://choidr.tistory.com/entry/Hash-란)

## 질문 2 : AVL트리의 특징과 AVL트리가 이진탐색트리의 단점을 극복할 수 있는 이유를 설명해주세요.

- 자료조사
    - AVL트리의 특징
        - 이진 탐색 트리의 속성을 가진다
        - 왼쪽, 오른쪽 서브 트리의 높이 차이가 최대 1이다
        - 높이 차이가 1보다 커지면 회전을 통해 균형을 맞춰 높이 차이를 줄인다
        - 삽입, 검색, 삭제의 시간 복잡도가 O(logN)이다 ( N:노드의 개수 )
    - 이진탐색트리의 단점

        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/be505d64-068c-4768-ad34-925d55ecb494/Untitled.png)

        위 그림처럼 오름차순이나 내림차순으로 데이터가 들어왔을 경우 이진탐색 트리는 한쪽으로 노드가 쏠릴 수 있다. 이런 경우 특정 값을 검색하거나 찾기위해 O(N)의 시간이 필요하다.

        - 즉 데이터의 양이 많아질 수록 시간이 많이 오래걸릴 수 있다.
    - 이진탐색트리의 단점을 극복하기 위해 나온 AVL트리

        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c8ae0f64-3aba-4aa1-a26c-192f8c867841/Untitled.png)

        위 그림처럼 AVL트리로 재구성하게 되면 이진탐색트리의 단점을 해결할 수 있다. AVL트리는 이진탐색트리의 속성을 가지면서 리프노드의 높이차가 최대1이기 때문에 특정 값을 찾기위한 시간 복잡도가 O(log N)이기 때문에 이진탐색트리에 비해 빠르다.

- 답안
    - AVL트리는 다음과 같은 특징을 가진다.
        - 이진 탐색 트리의 속성을 가진다
        - 왼쪽, 오른쪽 서브 트리의 높이 차이가 최대 1이다
        - 높이 차이가 1보다 커지면 회전을 통해 균형을 맞춰 높이 차이를 줄인다
        - 삽입, 검색, 삭제의 시간 복잡도가 O(logN)이다 ( N:노드의 개수 )
    - 이진탐색트리는 들어오는 값에 따라 한쪽으로 쏠리는 현상이 발생할 수 있고 이렇게 되면 하나의 데이터를 찾기위해 많은 시간이 걸릴 수 있다. 하지만 AVL트리는 리프노드끼리의 차가 최대 1이기 때문에 한쪽으로 쏠리는 현상이 발생하지 않고 시간복잡도가 O(N)인 이진탐색트리에 비해 O(logN)으로 횔씬 빠른시간에 데이터를 찾을 수 있다.
- 코드
    - 삽입

    ```jsx
    struct node {
      int key;
      struct node *left, *right;
      int height;
    };

    int max(int a, int b) {
      return (a > b)? a : b;
    }

    struct node* newNode(int key) {
      struct node *temp = (struct *node)malloc(sizeof(struct node));

      temp->data = key;
      temp->left = NULL;
      temp->right = NULL;
      temp->height = 1;
      return temp;
    }

    struct node *leftRotate (struct node *z) {
      struct node *y = z->right;
      struct node *T2 = y->left;

    // left 회전 수행
      y->left = z;
      z->right = T2;

    // 노드 높이 갱신
      z->height = 1 + max(z->left->height, z->right->height);
      y->height = 1 + max(y->left->height, y->right->height);

    // 새로운 루트 노드 y를 반환  
      return y;
    }

    struct node *rightRotate (struct node *z) {
      struct node *y = z->left;
      struct node *T2 = y->right;

    // right 회전 수행
      y->right = z;
      z->left = T2;

    // 노드 높이 갱신
      z->height = 1 + max(z->left->height, z->right->height);
      y->height = 1 + max(y->left->height, y->right->height);

    // 새로운 루트 노드 y를 반환  
      return y;
    }

    // BF(BalanceFactor)값을 가져오는 함수.
    int getBalanceFactor(struct node *n) {
      if (n == NULL)
        return 0;
      return n->left->height - n->right->height;
    }

    // 트리의 높이 균형을 유지하는 함수.
    // 4가지 케이스를 가지고 rotate를 수행함.
    struct node* rebalance(struct node* root) {

      int bFactor = getBalanceFactor(root);

      // LL Case
      if (bFactor > 1 && key < node->left->key)
        return rightRotate(root);
      // RR Case
      if (bFactor < -1 && key > node->right->key)
        return leftRotate(root);
      // LR Case
      if (bFactor > 1 && key > node->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
      // RL Case
      if (bFactor < -1 && key < node->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }

      return root;
    }

    // 삽입 함수.
    struct node* insert(struct node* root, int key) {

    // 삽입 수행
      if (root == NULL)
        return newNode(key);
      if (key > root->data)
        root->right = insert(root->right, key);
      else if (key < root->data)
        root->left = insert(root->left, key);
      else
        return root;

    // 노드 높이 갱신
      root->height = 1 + max(node->left->height, node->right->height);

    // 노드 균형 유지  
      root = rebalance(root);

      return root;
    }
    ```

- reference

[[자료구조] AVL 트리(Tree)](https://yoongrammer.tistory.com/72)

[[자료구조] AVL 트리(Tree)](https://yoongrammer.tistory.com/72)