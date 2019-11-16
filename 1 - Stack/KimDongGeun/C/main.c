//
//  main.c
//  test
//
//  Created by 김동근 on 2019/11/16.
//  Copyright © 2019 KimDongGeun. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode *nextNode;
}ListNode;

ListNode *createNode(int value, ListNode *link){
    ListNode *new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node==NULL) printf("에러");
    new_node->value = value;
    new_node->nextNode = link;
    return(new_node);
}

void insert_node(ListNode **phead, ListNode *new_node){
    if(*phead == NULL){
        new_node->nextNode = NULL;
        *phead = new_node;
    }
    else {
        new_node->nextNode = *phead;
        *phead = new_node;
    }
}

void display(ListNode *phead){
    ListNode *p = phead;
    while (p!=NULL) {
        printf("%d-> ",p->value);
        p=p->nextNode;
    }
}

//A -> B -> C
//(**phead) =A값의주소
//*phead =
//*phead -> Node1개
//


int pop(ListNode **phead){
    ListNode *node;
    int data;
    node = *phead; // *(phead는 스택의 주소값) 주소값이 가리키는 struct
    
    data = (*phead)->value;
    
    data = (*phead)->value;
    *phead = (*phead)->nextNode;
    
    free(node); //free(*pointer) -> *pointer 주소값을 해제
    return data;
}

int peek(ListNode **phead){
    return (*phead)->value;
}

int main(int argc, const char * argv[]) {
    ListNode *list1 = NULL;
    insert_node(&list1,  createNode(10, NULL));
    insert_node(&list1,  createNode(20, NULL));
    insert_node(&list1,  createNode(30, NULL));
    display(list1);
    printf("\n 값 : %d", pop(&list1));
    printf("\n 값 : %d", peek(&list1));
    printf("\n 값 : %d", pop(&list1));
    printf("\n 값 : %d", peek(&list1));
    printf("\n 값 : %d\n", pop(&list1));
    return 0;
}
