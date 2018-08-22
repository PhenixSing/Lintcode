#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<string>
#include <list>
using namespace std;
class TreeNode {
	public:
	    int val;
	    TreeNode *left, *right;
	    TreeNode(int val) {
	        this->val = val;
	        this->left = this->right = NULL;
	    }
};
void mid_tree(TreeNode *root,vector<int> &v,int k1,int k2){
	if(root==NULL){
		return;
	}
	if(root->val>k1){
		mid_tree(root->left,v,k1,k2);
		
	}
	if(root->val<=k2&&root->val>=k1)v.push_back(root->val);
	if(root->val<k2)mid_tree(root->right,v,k1,k2);
}

vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
    vector<int> v;
	mid_tree(root,v,k1,k2);
	return v;
}
TreeNode * deserialize(string &data) {
    // write your code here
    //string s=data;
    if(data.length()<1) return NULL;
    string s_int;
    s_int = data.substr(data.find_first_of(',')+1);
    
	TreeNode *root=new TreeNode(atoi(data.substr(0,data.find_first_of(',')).c_str()));
	TreeNode *pre=root;
	queue<TreeNode *> pre_p;
	int i=0;
	for(;s_int.find_first_of(',')!=-1;i++){
		if(i%2==0){
			if(s_int[0]=='#')pre->left=NULL;
			else {
				pre->left=new TreeNode(atoi(s_int.substr(0,s_int.find_first_of(',')).c_str()));
				
				//cout<<pre->left->val<<' '<<pre->left<<' ';
				pre_p.push(pre->left);
			}
			s_int = s_int.substr(s_int.find_first_of(',')+1);
		}
		else{
			if(s_int[0]=='#')pre->right=NULL;
			else {
				pre->right=new TreeNode(atoi(s_int.substr(0,s_int.find_first_of(',')).c_str()));
				
				//cout<<pre->right->val<<' '<<pre->right<<' ';
				pre_p.push(pre->right);
			}
			s_int = s_int.substr(s_int.find_first_of(',')+1);
			if(!pre_p.empty()){
				pre=pre_p.front();
				//cout<<pre<<' ';
				pre_p.pop();
			}
		}
	}
	if(i%2==0){
		if(s_int[0]=='#')pre->left=NULL;
		else {
			pre->left=new TreeNode(atoi(s_int.c_str()));
			
			//cout<<pre->left->val<<' '<<pre->left<<' ';
			pre_p.push(pre->left);
		}
	}
	else{
		if(s_int[0]=='#')pre->right=NULL;
		else {
			pre->right=new TreeNode(atoi(s_int.c_str()));
			
			//cout<<pre->right->val<<' '<<pre->right<<' ';
			pre_p.push(pre->right);
		}
	}
    return root;
}
int main(void)
{
	string s="20,8,22,#,#,21,29";
	//string s="12,2,#,3,#,4";
	TreeNode  *root = deserialize(s);
	//cout<<root->left->val;
	//cout<<root->right->val;
	//cout<<root->left->left->val;
	//cout<<root->right->right->val;
	
	for(int i=0;i<4;i++)cout<<searchRange(root, 8, 29)[i];
	return 0;
}
