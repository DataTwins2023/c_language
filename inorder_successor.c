#include <stdio.h>
#include <stdlib.h> // 添加此头文件以使用 malloc 函数

struct node {
    int data;
    struct node* right;
    struct node* left;
};

void get_info(struct node* b){
    printf("%d\n",b->data);
    printf("%d\n",b->right->data);
    printf("%d\n",b->left->data);
}

void inorder(struct node* n){
    if(n){
        inorder(n -> left);
        printf("%d\n", n->data);
        inorder(n -> right);
    }
}

void get_suc_leaf(struct node* root, int target){
    struct node* root_l  = root -> left;
    if(root_l -> right){ 
        root_l = root_l -> right;
    };// 找左子max
    if(root_l -> data == target){
        printf("%d\n", root -> data);
    }
    else{
        if(root_l -> data > target){
            get_suc_leaf(root -> left, target);
        }
        else if(root_l -> data < target){
            get_suc_leaf(root -> right, target);
        }
    }
}

void get_suc_nonleaf(struct node* c){
    c = c -> right;
    if(c -> left){ // c有right_son
        c = c -> left;
    }
    printf("%d\n", c -> data);
}


int main()
{
    struct node l2_left  = {2, NULL, NULL};
    struct node l1_left  = {3, NULL, &l2_left};
    struct node l2_right = {7, NULL, NULL};
    struct node l1_right = {6, &l2_right, NULL};
    struct node root     = {5, &l1_right, &l1_left};
    
    get_suc_leaf(&root, 2);
    return 0;
}
