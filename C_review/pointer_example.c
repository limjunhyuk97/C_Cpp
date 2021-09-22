#include <stdio.h>
#include <stdlib.h>

// Linked List 간단하게 구현
typedef int Data;

typedef struct Node{
    struct Node *next;
    struct Node *before;
    Data data;
}Node;

typedef struct Linked_List{
    Node *head;
    Node *tail;
}List;

void List_init(List *list){
    Node *Dummy = (Node *)malloc(sizeof(Node));
    Dummy->before = NULL; Dummy->next = NULL; Dummy->data = 0;
    list->tail = Dummy;
    list->head = Dummy;
}

void List_insert(List *list, Data data){
    Node *newNode = (Node *)malloc(sizeof(List));
    newNode->next = NULL; newNode->before = NULL; newNode->data = data;
    
    list->tail->next = newNode;
    newNode->before = list->tail;
    list->tail = newNode;
}

int *arr;

// change_arr 함수 정의
void change_arr(int *a, int size){
    a = (int *)malloc(sizeof(int) * size);
    for(int i=0; i<size; ++i){
        a[i] = i + 1;
    }
}

int main(void){
    
    // 기억할 것!.. 정리하고 보니 너무 당연한 얘기들이라 허무하군..
    // - 지역 변수는 함수 내에서만 존재한다
    // - malloc을 통해 할당한 메모리는 해제되지 않는 한 어딘가에 남아있다.
    // - 함수를 통해서 포인터 값을 전달하는 것은, 함수 내에서 사용될 지역변수에 포인터 값을 전달하는 것이다.
    //  - 여기서 지역 변수에 '다른 포인터 값(메모리 주소 값)을 할당'한다면, 당연히 함수 외부값에 대한 접근이 불가능해지는 것! (1. 상황)
    //  - 여기서 지역 변수를 '통한' 접근을 한다면, 함수 외부 값에 대한 접근이 가능해 질 것이다.
    
    // 1. 동작하지 않는다
    // - change_arr의 매개변수 a에 int형 포인터 arr의 값 즉, arr에 할당된 메모리 주소값이 전달된다. (빈 포인터이므로 0x00.. : NULL)
    // - change_arr함수가 실행되면 a에 동적할당된 새로운 주소가 할당된다.
    // - 동적할당된 컴퓨터의 메모리 공간 어딘가에서, a[i] = i+1 연산이 일어난다.
    // - change_arr함수가 종료되면, arr는 여전히 0x00.. 을 가리키고 있다.
    // - 또한, 동적할당된 메모리의 해제 작업이 이루어지지 않았기에 메모리 누수가 발생할 수 있다.
    change_arr(arr, 7);
    for(int i=0; i<7; ++i)
        printf("%d\n", arr[i]);
    
    // 2. 동작 한다
    // - list 변수가 만들어짐
    // - List_init을 통해서 list 함수의 초기화가 이루어짐
    // - List_insert을 통해서 list 포인터가 가리키는, list tail 포인터가 가리키는, next node에 대한 지칭을 변경할 수 있음
    List list;
    List_init(&list);
    List_insert(&list, 10);
    printf("%d\n", list.tail->data);
    
    
    return 0;
}

