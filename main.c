#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct el el_t;
struct el{
    int pload;
    el_t*next;
};
//* добовавляем элемент с нагрузкой pload, возвращает 0 при успехе, -1 при неудаче.
int add_el(int pload);

//* удаляет элемент на который указывает внтренний укозатель, возвращает 0 при успехе, -1 при неудаче.
int del_el(void);

//установка укозателя на найденный элемен
int find_el(int pload);

//возврашщает элемент на который указывает внтренний укозатель, возвращает 0 при успехе, -1 при неудаче.
int get_el(int* pload);

//Хотим перейти на следующий элемент
int next_el(void);

// Обнуление текущий указатель curr в значение  NULL
int ress_el(void);

//показать все элементы
int look_add_el();

//Сравнение двух значений pload
int pload_cmp(int pload1, int pload2);

//Сравнение через указатель    pload_cmp2(curr->pload, curr->next->pload, curr); почемуто работает только так ????
int pload_cmp2(int pload_currcmp, int pload_curr, int currcmp);

// Сохранение curr для сравнения
int curr_save();

static el_t *top=NULL;
static el_t *curr=NULL;

int main(){

    add_el(1);
    add_el(11);
    add_el(11);
    add_el(11);
    add_el(12);
    add_el(13);
    look_add_el();
    find_el(11);
    curr_save();
    next_el();
    pload_cmp2(curr->pload, curr->next->pload, curr);
    add_el(4);
    add_el(5);
    add_el(6);
    add_el(6);
    add_el(7);
    add_el(8);
    find_el(6);
    look_add_el();
    curr_save();
    next_el();
    next_el();
    pload_cmp2(curr->pload, curr->next->pload, curr);
    // pload_cmp(4,5);
   // pload_cmp(4,4);

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
          for(curr=top; curr->next!=NULL; curr=curr->next);
          curr->next=malloc(sizeof (el_t));
          curr=curr->next;
          curr->next=NULL;
          curr->pload=pload;
      }
    return 0;
}

int look_add_el(void) {
   printf("Элементы в списке:\n");
   for(el_t* trans=top;trans!=NULL;  trans=trans->next)
       printf("%d:  %p\n", trans->pload, trans);

   return 0;}

int pload_cmp(int pload1, int pload2){
    if(pload1 == pload2){
        printf("Значения pload %d равны друг другу\n");
        return 0;
    } else {
        printf("Значения pload %d и %d не равны\n", pload1, pload2);
        return -1;
    }
}

int curr_save()
{
   int currcmp;
    if(curr==NULL)
    {
        printf("нечего сохронять \n");
        return 0;
    }
    else
    {
      currcmp=curr;
      printf("сохранено значение:, curr %p\n", curr );
      return 0;
    }
 }

int pload_cmp2(int pload_currcmp, int pload_curr, int currcmp)
{
    if (currcmp == NULL)
    {
        printf("Нет сохраненного указателя для сравнения\n");
        return -1;
    }
    if (curr == NULL)
    {
        printf("Указатель отсутствует\n");
        return -2;
    }
    else
    {
        if (pload_currcmp == pload_curr)
        {
            printf("Значения нагрузки равны\n");
            return 0;
        }
        else
        {
            printf("Значения нагрузки не равны\n");
            return -1;
        }
    }
}
int del_el(void){
    printf("Хотим удалить элемент %d\n");
    return 0;
}

int find_el(int pload) {
   printf("Хотим найти элемент %d\n", pload);
   if (top == NULL) {
       printf("Список пуст, поиск невозможен\n");
       return -1;
   }

   for (curr = top; curr != NULL; curr = curr->next) {
       if (curr->pload == pload) {
           printf("Элемент найден:указвтель %p  нагрузка %d \n", curr, pload);
           return 0;
       }
   }

   printf("Элемент не найден\n");
   return -1;
}

int get_el(int* pload){
    printf("Хотим вернуть элемент %d\n" ,pload);
    return 0;
}

int next_el(void){
    if(curr->next==NULL)
    {
       printf("некуда переходить");
        return -1;
    }
    else {
        curr=curr->next;
    printf("перешли на следующий элемент curr:%p, \n",curr);
    return 0;
    }
}


int ress_el(void){
    el_t*curr=NULL;
    printf("Хотим обнулить текущий указатель на элемент %u\n");
    return 0;
}
