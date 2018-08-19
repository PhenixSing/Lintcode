#include<iostream>
#include<vector> 
using namespace std;

int qiu(int n){
	
}
int main(void)
{
	int n;
	cin>>n;
	vector<int> a;
	a.push_back(1);
	//cout<<a[0];
	int c[3]={0,0,0},b[3] = {2,3,5},next=1,index;
	for(int i=1;i<n;){
		next=a[c[0]]*b[0];
		index=0;
		if(next>a[c[1]]*b[1]){
			next = a[c[1]]*b[1];
			index=1;
		}
		if(next>a[c[2]]*b[2]){
			next = a[c[2]]*b[2];
			index=2;
		}
		
		if(next>a.back()){
			a.push_back(next);//cout<<next<<' ';
			i++;
		}
		c[index]  ++;
	}
	
	cout<<next;
	
    return 0;
}
