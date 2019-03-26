/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool bstHelper(Node* root, int min, int max){
        if (root == nullptr){
            return true;
        }
        else if (root->data <= min || root->data >= max){
            return false;
        }
        else {
            return bstHelper(root->left, min, root->data) && bstHelper(root->right, root->data, max); 
        }
    }
        
	bool checkBST(Node* root) {
        return bstHelper(root, 0, 10000); //as per the contraints
	}