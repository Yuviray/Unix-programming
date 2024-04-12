//Name:Yuvanesh Rajamani
//Course Number/Name: CS4350 Uniz System Programming
//Assignment Number: 7
//Due Date: 4/28/23
#include <stdio.h>
#include <pthread.h>

int Total = 0;
pthread_mutex_t mutex;

void *print_thread_1(void *ptr);
void *print_thread_2(void *ptr);
void *print_thread_3(void *ptr);
void *print_thread_4(void *ptr);
void *print_thread_5(void *ptr);
void *print_thread_6(void *ptr);
void *print_thread_7(void *ptr);
void *print_thread_8(void *ptr);
void *print_thread_9(void *ptr);
void *print_thread_10(void *ptr);
void *print_thread_11(void *ptr);
void *print_thread_12(void *ptr);

int main() {
    printf("Welcome to Yuvanesh Rajamani’s Thread App\n"
           "This program will do the following:\n"
           "Accepts an integer number X from the user and then uses\n"
           "twelve synchronized threads in order to do some math\n"
           "operations:\n\n");
    pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10,thread11,thread12;
    int num;
    int sum= 78;

    // Accept input from user
    printf("Enter an Integer > 0 --- >     ");
    scanf("%d", &num);

    // Check if the number is greater than 0
    if (num > 0) {
        printf("\nSum of Numbers Between 1 and 12 = %d\n\n",sum);
        pthread_mutex_init(&mutex, NULL);

        pthread_create(&thread1, NULL, print_thread_1,
                               (void*) &num);
        pthread_create(&thread2, NULL, print_thread_2,
                               (void*) &num);
        pthread_create(&thread3, NULL, print_thread_3,
                       (void*) &num);
        pthread_create(&thread4, NULL, print_thread_4,
                       (void*) &num);
        pthread_create(&thread5, NULL, print_thread_5,
                       (void*) &num);
        pthread_create(&thread6, NULL, print_thread_6,
                       (void*) &num);
        pthread_create(&thread7, NULL, print_thread_7,
                       (void*) &num);
        pthread_create(&thread8, NULL, print_thread_8,
                       (void*) &num);
        pthread_create(&thread9, NULL, print_thread_9,
                       (void*) &num);
        pthread_create(&thread10, NULL, print_thread_10,
                       (void*) &num);
        pthread_create(&thread11, NULL, print_thread_11,
                       (void*) &num);
        pthread_create(&thread12, NULL, print_thread_12,
                       (void*) &num);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
        pthread_join(thread4, NULL);
        pthread_join(thread5, NULL);
        pthread_join(thread6, NULL);
        pthread_join(thread7, NULL);
        pthread_join(thread8, NULL);
        pthread_join(thread9, NULL);
        pthread_join(thread10, NULL);
        pthread_join(thread11, NULL);
        pthread_join(thread12, NULL);
        pthread_mutex_destroy(&mutex);
        printf("\n\nTotal Result from All Threads =  %d\n", Total);

        if (Total==sum){
            printf("\nSum and the total are the same");
        }
        else{
            printf("\nSum and the total are not the same");
        }

    } else {
        printf("**** Number must be greater than 0 ***");
    }

    printf("\n\nProgram by Yuvanesh Rajamani\n4 – 28 - 2023");

    return 0;
}

void *print_thread_1(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result1;
    pthread_mutex_lock(&mutex);
    result1 = *x / *x;
    printf("Result of the 1st Thread =    %d\n", result1);
    Total += result1;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_2(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result2;
    pthread_mutex_lock(&mutex);
    result2 = (*x + *x) / *x;
    printf("Result of the 2nd Thread =    %d\n", result2);
    Total += result2;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_3(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result3;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }

    result3 = (int)sqrt;
    printf("Result of the 3nd Thread =    %d\n", result3);
    Total += result3;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
void *print_thread_4(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result4;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }
    double sqrt_x = sqrt;
    result4 = sqrt_x  + (*x / *x);
    printf("Result of the 4th Thread =    %d\n", result4);
    Total += result4;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_5(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result5;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }
    double sqrt_x = sqrt;
    int factorial = 1;
    int i = 1;
    for (i; i <= sqrt_x; i++) {
        factorial *= i;
    }
    result5 = factorial - (*x / *x);
    printf("Result of the 5th Thread =    %d\n", result5);
    Total += result5;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_6(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result6;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }

    result6 = *x - (int)(*x / sqrt) ;
    printf("Result of the 6th Thread =    %d\n", result6);
    Total += result6;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_7(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result7;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }
    result7 = (*x / *x) + *x - (int)sqrt;
    printf("Result of the 7th Thread =    %d\n", result7);
    Total += result7;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_8(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result8;
    pthread_mutex_lock(&mutex);
    result8 = *x - (*x / *x);
    printf("Result of the 8th Thread =    %d\n", result8);
    Total += result8;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_9(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result9;
    pthread_mutex_lock(&mutex);
    result9 = *x;
    printf("Result of the 9th Thread =    %d\n", result9);
    Total += result9;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_10(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result10;
    pthread_mutex_lock(&mutex);
    result10 = (*x / *x) + *x;
    printf("Result of the 10th Thread =   %d\n", result10);
    Total += result10;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *print_thread_11(void *ptr) {
    int *x;
    x = (int *) ptr;
    int result11;
    pthread_mutex_lock(&mutex);
    result11 = ((*x * *x) +(*x+ *x)) / *x;
    printf("Result of the 11th Thread =   %d\n", result11);
    Total += result11;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
void *print_thread_12(void *ptr) {
    float temp, sqrt;
    int *x;
    x = (int *) ptr;
    int result12;
    pthread_mutex_lock(&mutex);
    sqrt = *x / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *x/temp + temp) / 2;
    }
    result12 = (*x / sqrt) + *x;

    printf("Result of the 12th Thread =   %d\n", result12);
    Total += result12;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
