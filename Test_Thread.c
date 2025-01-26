#include"types.h"
#include"user.h"
#include"stat.h"

Lock My_Lock;
void function1(void* arg1,void* arg2){
    int* X=(int*)arg2;
    printf(2,"Thread %d Finished with value =%d\n",(*X),2*(*X)+1);
    printf(0,"TEST func1 : %d\n", REQUEST(0));
    sleep(500);
    printf(0,"TEST func1 : %d\n", REQUEST(1));
    exit();
}
void function2(void* arg1,void* arg2){
    int* X=(int*)arg2;
    printf(2,"Thread %d Finished with value =%d\n",(*X),2*(*X)+1);
    printf(0,"TEST func2 : %d\n", REQUEST(1));
    sleep(500);
    printf(0,"TEST func2 : %d\n", REQUEST(0));
    exit();
}
int main(){
    int l=3;
    int* size=&l;
    int list[3];
    printf(0,"***This Program will calculate 2x+1 for 3 threads where x is the tid passed to thread as its 2nd arg***\n");
    Lock_Init(&My_Lock);
    int tid;
    
    
    list[0]=0+1;
    tid = thread_create(&function1,(void*)size,(void*)&list[0]);
    printf(0,"Tid1: %d\n", tid);
    
    list[1]=1+1;
    tid = thread_create(&function2,(void*)size,(void*)&list[1]);
    printf(0,"Tid2: %d\n", tid);
    
    
    for(int i=1;i<=2;i++){
        join(i);
    }
    exit();
}

//release