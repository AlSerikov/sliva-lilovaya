#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el el_t;
struct el{
    int pload;
    el_t*next;
};
//* Добавляет елемент с нагрузкой pload,
// возвращает 0 в случае удачного завершения
// возвращает -1 в случае неудачи
int add_el(int pload);

//* Удаляет елемент на который указывает внутренний указатель
// возвращает
int del_el(void);

//Установка внутреннего указателя на найденный елемент
int find_el(int pload);

//Возвращает елемент на который указывает внутренний указатель
int get_el(int* pload);


int next_el(void);

// Обнуление текущий указатель curr в значение  NULL
int ress_el(void);

//просмотор элементов
int lookadd_el();

static el_t* top=NULL;
static el_t* curr=NULL;

int main(){
  add_el(1);
  add_el(11);
  add_el(12);
  add_el(13);
  add_el(14);
  add_el(15);
 lookadd_el;
  //del_el();
  //find_el();
  //get_el();
  //next_el();
  //ress_el();

}

int add_el(int pload){
    printf("Хотим добавить элемент %d curr: %p top: %p\n" ,pload,curr,top);
   if (top==NULL)
   {
       printf ("в списке ничего нет\n");
       top=malloc(sizeof(el_t));
       top->next=NULL;
       top->pload=pload;
       curr=top;
   }
   else // top!=NULL
   {
       for(curr=top; curr->next!=NULL; curr=curr->next){printf(".");}
       curr->next=malloc(sizeof (el_t));
       curr=curr->next;
       curr->next=NULL;
       curr->pload=pload;
   }

    return 0;
}

int lookadd_el(){

    for(curr=top; curr->next!=NULL; curr=curr->next)
    {
        printf("%d\n", pload);

    }

    return 0;
}


int del_el(void){
    printf("Хотим удалить элемент %d\n");
    return 0;
}

int find_el(int pload){
    printf("Хотим найти элемент %u\n" ,pload);
    return 0;
}

int get_el(int* pload){
    printf("Хотим вернуть элемент %d\n" ,pload);
    return 0;
}

int next_el(void){
    printf("Хотим перейти на следующий элемент %d\n");
    return 0;
}


int ress_el(void){
    el_t*curr=NULL;
    printf("Хотим обнулить текущий указатель на элемент %u\n");
    return 0;
}
