//GFG: https://www.geeksforgeeks.org/left-rotate-digits-of-node-values-of-all-levels-of-a-binary-tree-in-increasing-order/



/*
Question:
Given a binary tree where each level represents a floor of a multi storeyed building. 
Each node represents a house number. Number of nodes is the number of houses on that level. 
The task is to left rotate the digits of a house number, 
to have all the house numbers at a level arranged in increasing order.
                          256              256
                         /   \
                       537   189          537 918
                       /  \    \
                    438   365  167      384 536 716

*/

//My version:
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left,*right;

	TreeNode(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
};

int processValues(int val, int *prev){
    string s = to_string(val);
    vector<int>v;
    for(int i=0;i<s.size();i++){
       int x = stoi(s.substr(i,s.size())+s.substr(0,i));
       if(*prev<x){
           v.push_back(x);
       }
    }
    if(v.size()==0)return -1;
    sort(v.begin(),v.end());
    return v[0];
}
bool leftOrder(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        int size1 = q.size();
        int prev=INT_MIN;
        while(size1--){
        TreeNode* t = q.front();
        t->val = processValues(t->val,&prev);
        prev=t->val;
        if(t->val == -1)flag =true;
        q.pop();
        if(t->left!=NULL){
            q.push(t->left);
        }
        if(t->right!=NULL){
            q.push(t->right);
        }
        }
    }
    return flag;
}
int main()
{
    cout<<"Testcase 1:\n";
	TreeNode *root = new TreeNode(341);
	root->left = new TreeNode(241);
	root->right = new TreeNode(123);
    root->left->left = new TreeNode(324);
	root->left->right = new TreeNode(235);
	root->right->right = new TreeNode(161);
	bool flag = leftOrder(root);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<root->val<<"\n";
	cout<<root->left->val<<" ";
	cout<<root->right->val<<" ";
	cout<<root->left->left->val<<" ";
	cout<<root->left->right->val<<" ";
	cout<<root->right->right->val<<"\n";
	}	
	
	cout<<"Testcase 2:\n";
	TreeNode *node = new TreeNode(12);
	node->left = new TreeNode(89);
	node->right = new TreeNode(115);
	flag = leftOrder(node);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<node->val<<"\n";
	cout<<node->left->val<<" ";
	cout<<node->right->val<<" ";
	}
	
	cout<<"\n";
	cout<<"Testcase 3:\n";
	TreeNode *nodes = new TreeNode(12);
	nodes->left = new TreeNode(89);
	nodes->right = new TreeNode(15);
	flag = leftOrder(nodes);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<nodes->val<<"\n";
	cout<<nodes->left->val<<" ";
	cout<<nodes->right->val<<" ";
	}
}


//Optimized Version:

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left,*right;

	TreeNode(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
};

int processValues(int val, int *prev){
    string s = to_string(val);
    int mini = val;
    bool flag = true;
    for(int i=0;i<s.size();i++){
       int x = stoi(s.substr(i,s.size())+s.substr(0,i));
       if(*prev<=x && flag){
           mini = x; 
           flag = false;
       }
       if(*prev<=x)
         mini = min(mini,x);
    }
    if(mini>*prev)return mini;
    return -1;
}
bool leftOrder(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        int size1 = q.size();
        int prev=INT_MIN;
        while(size1--){
        TreeNode* t = q.front();
        t->val = processValues(t->val,&prev);
        prev=t->val;
        if(t->val == -1)flag =true;
        q.pop();
        if(t->left!=NULL){
            q.push(t->left);
        }
        if(t->right!=NULL){
            q.push(t->right);
        }
        }
    }
    return flag;
}
int main()
{
    cout<<"Testcase 1:\n";
	TreeNode *root = new TreeNode(341);
	root->left = new TreeNode(241);
	root->right = new TreeNode(123);
    root->left->left = new TreeNode(324);
	root->left->right = new TreeNode(235);
	root->right->right = new TreeNode(161);
	bool flag = leftOrder(root);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<root->val<<"\n";
	cout<<root->left->val<<" ";
	cout<<root->right->val<<" ";
	cout<<root->left->left->val<<" ";
	cout<<root->left->right->val<<" ";
	cout<<root->right->right->val<<"\n";
	}	
	
	cout<<"Testcase 2:\n";
	TreeNode *node = new TreeNode(12);
	node->left = new TreeNode(89);
	node->right = new TreeNode(115);
	flag = leftOrder(node);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<node->val<<"\n";
	cout<<node->left->val<<" ";
	cout<<node->right->val<<" ";
	}
	
	cout<<"\n";
	cout<<"Testcase 3:\n";
	TreeNode *nodes = new TreeNode(12);
	nodes->left = new TreeNode(89);
	nodes->right = new TreeNode(15);
	flag = leftOrder(nodes);
	if(flag)cout<<"-1"<<"\n";
	else{
	cout<<nodes->val<<"\n";
	cout<<nodes->left->val<<" ";
	cout<<nodes->right->val<<" ";
	}
}

/*
Output:
Testcase 1:
134
124 231 243 352 611
Testcase 2:
12
89 115 
Testcase 3:
-1
*/



