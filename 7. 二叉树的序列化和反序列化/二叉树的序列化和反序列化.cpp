#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<string>
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
string serialize(TreeNode * root) {
    // write your code here
    if(root==NULL) return "";
    string str;
    
    char* c_p=new char[20];
    sprintf(c_p,"%d",root->val);//to_string ps:dont use MinGW
	str+=c_p;
    //cout<<root->val;
	//TreeNode *t=root;
	queue<TreeNode *> pre_p;
	pre_p.push(root);
	//pre_p.push(t->left);
	//pre_p.push(t->right);
	for(;!pre_p.empty();){
		if(pre_p.front()->left!=NULL){
			str+=',';
			sprintf(c_p,"%d",pre_p.front()->left->val);//to_string
			str+=c_p;//cout<<','<<pre_p.front()->left->val;
			pre_p.push(pre_p.front()->left);
		}
		else str.append(",#");//cout<<",#";
		if(pre_p.front()->right!=NULL){
			str+=',';
			sprintf(c_p,"%d",pre_p.front()->right->val);//to_string
			str+=c_p;//cout<<','<<pre_p.front()->left->val;//cout<<','<<pre_p.front()->right->val;
			pre_p.push(pre_p.front()->right);
		}
		else str.append(",#");//cout<<",#";
		pre_p.pop();
	}
	for(int i=str.length()-1;i>=0&&(str[i]=='#'||str[i]==',');i--){
		str.erase(i);
	}
	return str;
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
void fan(TreeNode *t){
	
}
int main(void)
{
	//string s="3,9,2,#,#,1,7";
	string s="";//"12,2,#,3,#,4";
	TreeNode  *root = deserialize(s);
	//cout<<root->left->val;
	//cout<<root->right->val;
	//cout<<root->left->left->val;
	//cout<<root->right->right->val;
	cout<<serialize(root);

}
