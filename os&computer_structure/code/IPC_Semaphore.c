#include <stdio.h>
        #include <pthread.h>
        #include <semaphore.h>
        
        #define NUM_THREADS 5
        
        sem_t mutex; // 상호 배제를 위한 세마포어
        
        void *thread_func(void *arg) {
            int id = *((int *)arg);
        
            sem_wait(&mutex); // 세마포어를 획득하기 위한 대기
            printf("Thread %d has acquired the lock.\n", id);
            sleep(1);
            printf("Thread %d is releasing the lock.\n", id);
            sem_post(&mutex); // 세마포어를 해제함
        
            pthread_exit(NULL);
        }
        
        int main() {
            pthread_t threads[NUM_THREADS];
            int ids[NUM_THREADS];
            int i;
        
            sem_init(&mutex, 0, 1); // 세마포어를 초기화함
        
            for (i = 0; i < NUM_THREADS; i++) {
                ids[i] = i;
                pthread_create(&threads[i], NULL, thread_func, &ids[i]); // 새 스레드를 생성
            }
        
            for (i = 0; i < NUM_THREADS; i++) {
                pthread_join(threads[i], NULL); // 스레드가 종료될 때까지 대기
            }
        
            sem_destroy(&mutex); // 세마포어를 해제함
        
            return 0;
        }