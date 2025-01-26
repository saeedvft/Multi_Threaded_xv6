#include"types.h"
#include"user.h"
#include"stat.h"

Lock My_Lock;
void function(void* arg1,void* arg2){
    int* X=(int*)arg2;
    Lock_Acquire(&My_Lock);
    printf(2,"Thread %d Finished with value =%d\n",(*X),2*(*X)+1);
    // int tid = gettid();
    // printf("TID:%d\n", tid);
    Lock_Release(&My_Lock);
    exit();
}
void no_wait(void* arg1,void* arg2){
    sleep(10);
    exit();
}
void one_sec(void* arg1,void* arg2){
    sleep(1000);
    exit();
}
void two_secs(void* arg1,void* arg2){
    sleep(2000);
    exit();
}
void three_secs(void* arg1,void* arg2){
    sleep(3000);
    exit();
}
int main(){
    // void* x=0;
    // printf(0,"TEST : NEW SYSCALLS %d %d %d\n", READ(4,4,4,x),WRITE(4,x,4,4),REQUEST(4)); //,RELEASE(4)   
    // int l=3;
    // int* size=&l;
    // int list[3];
    // printf(0,"***This Program will calculate 2x+1 for 3 threads where x is the tid passed to thread as its 2nd arg***\n");
    // Lock_Init(&My_Lock);
    // for(int i=0;i<3;i++){
    //     list[i]=i+1;
    //     thread_create(&function,(void*)size,(void*)&list[i]);
    // }
    int tid[6];
    tid[0] = thread_create(&no_wait, 0, 0);
    // printf("first is %d\n", tid);
    tid[1] = thread_create(&two_secs, 0, 0);
    // printf("second is%d\n", tid);
    sleep(1000);
    tid[2] = thread_create(&two_secs, 0, 0);
    // printf("third is%d\n", tid);
    sleep(1000);
    tid[3] = thread_create(&one_sec, 0, 0);
    // printf("fourth is%d\n", tid);
    tid[4] = thread_create(&one_sec, 0, 0);
    // printf("fifth is%d\n", tid);
    tid[5] = thread_create(&one_sec, 0, 0);
    // printf("sixth is%d\n", tid);
    for(int i=0;i<6;i++){
        wait();
    }
    for(int i=0;i<6;i++){
        printf(0, "i : %d is %d\n", i, tid[i]);
    }
    exit();
}