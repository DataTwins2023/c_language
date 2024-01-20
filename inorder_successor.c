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

struct node* search_target(struct node* root, int target){
    if(target == root -> data)
    {
        return root;
    }
    else
    {
        if(target > root -> data)
        {
            search_target(root->right, target);
        }
        else
        {
            search_target(root->left, target);
        }
    }
}

void get_suc(struct node* root, int target){
    /* find the max value of the tree*/
    struct node* max_node = root;
    while(max_node -> right)
    {
        max_node = max_node -> right;
    }
    /* search for target */
    struct node* target_node = search_target(root, target);
    if(target_node -> right)
    {
        printf("%d\n", target_node->right->data);
    }
    else
    {
        /* if node has no right child, but it's the max node of the tree, it has no successor */
        if(target_node -> data == max_node -> data)
        {
            printf("%s\n", "it's max of the tree, no successor");
        }
        /* other node that has no right child */
        else
        {
            struct node* root_left_max = root -> left;
            while(root_left_max -> right)
            {
                root_left_max = root_left_max -> right;
            }
            if(root_left_max -> data == target)
            {
                printf("%d\n", root -> data);
            }
            else
            {
                if(root_left_max -> data > target)
                {
                    get_suc(root -> left, target);
                }
                else
                {
                    get_suc(root -> right, target);
                }
            }
        }
    }
}


int main()
{
    struct node l2_left  = {2, NULL, NULL};
    struct node l1_left  = {3, NULL, &l2_left};
    struct node l2_right = {7, NULL, NULL};
    struct node l1_right = {6, &l2_right, NULL};
    struct node root     = {5, &l1_right, &l1_left};
    
    get_suc(&root, 3);
    return 0;
}
