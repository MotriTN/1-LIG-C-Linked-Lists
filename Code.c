#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char name[10];
    float weight;
    struct Node * next;
}Node;
void affiche(Node *l){
    Node * ptr=l;
    int i=1;
    while(ptr!=NULL){
        printf("Nom n°%d: %-10s",i,ptr->name);
        printf("Poid n°%d: %.2f\n",i,ptr->weight);
        i++;
        ptr=ptr->next;
    }
}
Node * create_empty(){
    Node * p=malloc(sizeof(Node));
    p->next=NULL;
    return p;
}
Node * create_node(){
    Node * ptr=create_empty();
    printf("Donner le nom : ");
    scanf("%9s",ptr->name);
    printf("Donner le poid : ");
    scanf("%f",&ptr->weight);
    return ptr;
}
Node * insert(Node *l){
    Node * k = create_node();
    k->next=l;
    return k;
}
Node * append(Node *l){
Node *p=create_node();
if (l==NULL){l=p;return p;}
Node *ptr=l;
while(ptr->next!=NULL){
    ptr=ptr->next;
} ptr->next=p;
return l;

}
Node * create_list(){
    Node *head=NULL;
    head=append(head);
    int complete;
    while (1){
        printf("Carry On ? (type 0 to escape): ");scanf("%d",&complete);
        if (complete==0){break;}
        head=append(head);    }
    return head;
}
Node * delete_first(Node *l){
    if (l!=NULL){
        Node * ptr;
        ptr=l;
        l=l->next;
        free(ptr);
    }
    return l;
}
void freeing(Node *l){
    while (l!=NULL){
        l=delete_first(l);
    }
}
Node * reverse(Node *l){
    if (l==NULL){return NULL;}
    Node * ptr=l;
    Node * start=create_empty();
    Node * f;
    if (ptr!=NULL){
    strcpy(start->name, ptr->name);
    start->weight=ptr->weight;
    ptr=ptr->next;
    while(ptr!=NULL){
    f=create_empty();
    strcpy(f->name,ptr->name);
    f->weight=ptr->weight;
    f->next=start;
    start=f;
    ptr=ptr->next;
    }
    return start;
}}
void flip(Node * a,Node * b){
    char temp1[10];
    float temp2;
    strcpy(temp1,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp1);
    temp2=a->weight;
    a->weight=b->weight;
    b->weight=temp2;
}
Node * bubble_sort(Node *l){
    Node * ptr=l;
    if (ptr==NULL){return NULL;}
    int swaps;
    do{swaps=0;ptr=l;
    while (ptr->next!=NULL){
        if (ptr->weight>ptr->next->weight){flip(ptr,ptr->next);swaps++;}
        ptr=ptr->next;
    }
    }while(swaps!=0);
    return l;}
int main(){
    Node *j = NULL;
    Node * l=NULL;
    l=create_list();
    printf("\n------\n");
    printf("normal: \n");
    affiche(l);
    l=bubble_sort(l);
    printf("\n------\n");
    printf("bubble sorted: \n");
    affiche(l);
    j=reverse(l);
    printf("\n------\n");
    printf("bubble sorted and inversed: \n");
    affiche(j);
    freeing(l);
    freeing(j);
    return 0;
};
