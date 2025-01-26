#include"types.h"
#include"user.h"
#include"stat.h"

Lock My_Lock;
void function1(void* arg1,void* arg2){
    int* X=(int*)arg2;
    // Lock_Acquire(&My_Lock);
    printf(2,"Thread %d Finished with value =%d\n",(*X),2*(*X)+1);
    printf(0,"TEST func1 : %d\n", REQUEST(0));
    sleep(500);
    // printf(0,"TEST func1 : %d\n", REQUEST(1));
    // int tid = gettid();
    // printf("TID:%d\n", tid);
    // Lock_Release(&My_Lock);
    exit();
}
void function2(void* arg1,void* arg2){
    int* X=(int*)arg2;
    // Lock_Acquire(&My_Lock);
    printf(2,"Thread %d Finished with value =%d\n",(*X),2*(*X)+1);
    printf(0,"TEST func2 : %d\n", REQUEST(1));
    sleep(500);
    // printf(0,"TEST func2 : %d\n", REQUEST(0));
    // Lock_Release(&My_Lock);
    exit();
}
int main(){
    // void* x=0;
    // printf(0,"TEST : NEW SYSCALLS %d %d %d\n", READ(4,4,4,x),WRITE(4,x,4,4),REQUEST(4)); //,RELEASE(4)   
    int l=3;
    int* size=&l;
    int list[3];
    printf(0,"***This Program will calculate 2x+1 for 3 threads where x is the tid passed to thread as its 2nd arg***\n");
    Lock_Init(&My_Lock);
    // for(int i=0;i<3;i++){
        
    // }
    int tid;
    
    
    list[0]=0+1;
    tid = thread_create(&function1,(void*)size,(void*)&list[0]);
    
    list[1]=1+1;
    tid = thread_create(&function2,(void*)size,(void*)&list[1]);
    
    printf(0,"Tid1: %d\n", tid);
    printf(0,"Tid2: %d\n", tid);
    
    for(int i=1;i<=2;i++){
        join(i);
    }
    exit();
}

//release