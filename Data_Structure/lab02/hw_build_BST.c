#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
    int data; 
    struct node *left, *right; 
} Node;

// TO-DO: implement inorder traversal.
void inorder(Node* root){ 
	//write your code. 
	if(root){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
} 

// TO-DO: count the number of non-leaf in a binary search tree.
int countnonleaf(Node* node){
	//write your code.  
	if(node && (node->left || node->right)){
		return 1+countnonleaf(node->left)+countnonleaf(node->right);
	}
	else{
		return 0;
	}
}

// TO-DO: count the number of leaf in a binary search tree.
int countleaf(Node* node){
	//write your code.
	if(node && (!node->left && !node->right)){
		return 1;
	}
	else{
		return 0+countleaf(node->left)+countleaf(node->right);
	}
}

// TO-DO: calculate the height of the binary search tree.
int height(Node* node){
    //write your code.
	if(node==NULL){
		return 0;
	}
	int left_height=height(node->left);
	int right_height=height(node->right);
	if(left_height>right_height){
		return left_height+1;
	}else{
		return right_height+1;
	}

}

// TO-DO: check if this tree is a binary search tree.
int is_BST(Node* node)  {  
	//write your code.  
	if(node==NULL){
		return 1;
	}
	if(node->left!=NULL && node->data < node->left->data){
		return 0;
	}
	if(node->right!=NULL && node->data > node->right->data){
		return 0;
	}
	if(!is_BST(node->left) || !is_BST(node->right)){ //if having error, returning 0
		return 0;
	}
	return 1;
}

// TO-DO: insert a node in a binary search tree.
Node* insert(Node* node, int data){ 
    //if the tree is empty, create a new node and make it the root
	if(node == NULL){
		Node *new_node;
		new_node=(Node*)malloc(sizeof(Node));
		new_node->data=data;
		new_node->left=NULL;
		new_node->right=NULL;
		return new_node;
	}
	if(data < node->data){
		node->left=insert(node->left, data);
	}
	else{
		node->right=insert(node->right, data);
	}
	return node;
	

	
} 

int main(){
    int insert_data[] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	Node* root = NULL; 
	int i;
    root = insert(root, insert_data[0]);
	int len = sizeof(insert_data)/sizeof(insert_data[0]); 
    for(i=1;i<len;i++){
    	insert(root, insert_data[i]);
	}
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
	printf("\nroot data: %d\n",root->data);
	printf("the number of leaves: %d\n",countleaf(root));
	printf("the number of non-leaves: %d\n",countnonleaf(root));
	printf("height: %d\n\n",height(root));
		
	root->data = 20;
	printf("Modify Binary Search Tree(BST): \n");
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
	free(root);
    return 0; 
}
