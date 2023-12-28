#include <stdio.h>

struct node {
    int data;
    struct node* left_son;
    struct node* right_son;
};

void insert(int x, struct node* root){
    // 建立new node
    struct node insert_node = {x, NULL, NULL};
    if(root -> data > x){
        // 新建一個temp是為了之後讓temp的pointer可以指向新插入的node
        struct node* temp = root -> left_son;
        if(temp == NULL){
            root -> left_son = &insert_node;
        }
        else{
            insert(x, temp);
        }
    }
    else if(root -> data < x){
        // 新建一個temp是為了之後讓temp的pointer可以指向新插入的node
        struct node* temp = root -> right_son;
        if(temp == NULL){
            root -> right_son = &insert_node;
        }
        else{
            insert(x, temp);
        }
    }
};// 插入x
int main()
{
    struct node n_1  = {1, NULL, NULL}; 
    struct node n_2  = {3, NULL, NULL}; 
    struct node root = {2, &n_1, &n_2};
    insert(10, &root);
    // print 10
    printf("%d\n", (n_2.right_son->data));
    return 0;
}
