#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char name[10];
    float weight;
    struct Node* next;  
}Node;
int count(Node *l){
    int i=0;
    while (l!=NULL){i++;l=l->next;}
    return i;
};
float sum(Node *l){
    float s=0;
    while (l!=NULL){s+=l->weight;l=l->next;}
    return s;
};
float moy(Node *l){
    if (count(l)==0){return 0.0;}
    return sum(l)/count(l);
};
void affiche(Node *l){
    int i=0;
    Node * p = l;
    while (p!=NULL){printf("Le Nom n°%d est: %-10s de %.2f poids\n",i,p->name,p->weight);
        p=p->next;i++;
    }
};
Node * create_empty(){
    Node * p = malloc(sizeof(Node));
    p->next=NULL;
    return p;
};
void lire_nom(char a[10]) {
    printf("Donner le nom : ");
    scanf("%9s", a);
};
void lire_poid(float* r) {
    printf("Donner le poid : ");
    scanf("%f", r);
};
Node * create_special(char a[10],float r){
    Node * temp=create_empty();
    strcpy(temp->name,a);
    temp->weight=r;
    return temp;
};
Node * create_node(){
    char nom[10];
    float poids;
    lire_nom(nom);
    lire_poid(&poids);
    return create_special(nom,poids);
};
Node * create_node_if(Node *l){
    char nom[10];
    float poids,m;
    m=moy(l);
    lire_nom(nom);
    lire_poid(&poids);
    while(poids<=m){lire_poid(&poids);}
    return create_special(nom,poids);
};
Node * append(Node *l){
    Node * ptr=l;
    if (ptr==NULL){return create_node();}
    while(ptr->next!=NULL){ptr=ptr->next;}
    ptr->next=create_node();
    return l;
};
Node * insert(Node *l){
    Node * ptr=create_node();
    if (l==NULL){return ptr;}
    ptr->next=l;
    l=ptr;
    return l;
};
Node * create_list(Node *l){
    if (l==NULL){
    l=create_node();}
    Node * ptr=l;
    int complete=1;
    while (1){
        printf("Carry On ? (1:YES, 0:NO) : ");
        scanf("%d",&complete);
        if (complete==0){return l;}
        ptr->next=create_node_if(l);
        ptr=ptr->next;
    }return l;
    
};
Node * create_copy(Node *l){
    return create_special(l->name,l->weight);
};
Node * create_inverse(Node *l){
    if (l != NULL) {
        Node *p = l;
        Node *start = create_copy(p);
        Node *ptr;
        p = p->next;
        while (p != NULL) {ptr = create_copy(p);
        ptr->next=start;start=ptr;p=p->next;}
        return start;  
    }
    return NULL;
}
void flip(Node * a, Node * b){
    char temp1[10];
    float temp2;
    strcpy(temp1,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp1);
    temp2=a->weight;
    a->weight=b->weight;
    b->weight=temp2;
}
Node* bubble_sort(Node *l){
    if(l==NULL){return NULL;}
    Node * ptr=l;
    int swaps=1;
    int u=count(l);
    while (swaps!=0){
        ptr=l;
        swaps=0;
        for(int i=0;i<u-1;i++){
            if (ptr->weight>ptr->next->weight)
            {flip(ptr,ptr->next);swaps++;}
            ptr=ptr->next;
        }}
        u--;
    return l;
    }
int main() {
    Node *list = NULL;
    list = create_list(list);
    printf("Original list:\n");
    affiche(list);
    printf("\nSum of weights: %.2f\n", sum(list));
    printf("Average weight: %.2f\n", moy(list));
    list = bubble_sort(list);
    printf("\nSorted list:\n");
    affiche(list);
    Node *reversedList = create_inverse(list);
    printf("\nReversed list:\n");
    affiche(reversedList);

    return 0;
}
