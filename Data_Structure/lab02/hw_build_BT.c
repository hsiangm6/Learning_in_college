#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node { 
    int data; 
    struct node *left, *right; 
} Node;

// TO-DO: implement postorder traversal.
void postorder(Node* root){ 
	//write your code.
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
} 

int preindex = 0;// record index of preorder[]

// TO-DO: construct a binary tree from inoder and preorder traversal.
Node* build_binary_tree(int inorder[], int preorder[], int instart, int inend) 
{ 	
	if(instart>inend){
		return NULL;
	}
	
	Node *new_node;
	new_node = (Node* )malloc(sizeof(Node));
	if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = preorder[preindex];
	
	if(instart==inend){ //leaf node
		preindex++;
		return new_node;
	}
	// printf("instart = %d, inend = %d, preindex = %d, new_node->data = %d\n", instart, inend, preindex, new_node->data);

	for(int i=instart;i<=inend; i++){
		if(inorder[i]==preorder[preindex]){
			preindex++;
			new_node->left=build_binary_tree(inorder, preorder, instart, i-1);
			new_node->right=build_binary_tree(inorder, preorder, i+1, inend);
			break;
		}
	}
	return new_node;
}

int main()
{
	int tree1inorder[] = {1,2,3,4,5,6,7};
	int tree1preorder[] = {4,2,1,3,6,5,7};
	int len1 = sizeof(tree1inorder)/sizeof(tree1inorder[0]);
	Node *root1 =  build_binary_tree(tree1inorder, tree1preorder, 0, len1-1);
	printf("tree1 preorder traversal: 4, 2, 1, 3, 6, 5, 7 \n");
	printf("tree1 inorder traversal: 1, 2, 3, 4, 5, 6, 7 \n");
	printf("tree1 postorder traversal: ");
    postorder(root1);
    preindex = 0;	
    
    int tree2inorder[] = {5,9,3,8,4,7,6};
	int tree2preorder[] = {8,9,5,3,7,4,6};
	int len2 = sizeof(tree2inorder)/sizeof(tree2inorder[0]);
	Node *root2 =  build_binary_tree(tree2inorder, tree2preorder, 0, len2-1);
	printf("\n\ntree2 preorder traversal: 8, 9, 5, 3, 7, 4, 6 \n");
	printf("tree2 inorder traversal: 5, 9, 3, 8, 4, 7, 6 \n");
	printf("tree2 postorder traversal: ");
    postorder(root2);
    preindex = 0;
    free(root1);
	free(root2);
    return 0;
}
