#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
    
}
int main(void)
{
	int a[5] = { 3,1,2,7,5 };
	//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��5������ҿ����䣩
	//vector<int> b(a, a+5);
	vector<int> data(a, a+5);
	cout << kthLargestElement(3,data);
	
	
	for(int i = 0;i<5;i++)
	for(;;){
		if(data[1]<data[2]){
	    	if(data[0]<data[2]){
	    		int e=data[0];
	    		data[0]=data[2];
	    		data[2]=e;
	    	}
	    }
	    else{
	    	if(data[0]<data[1]){
	    		int e=data[0];
	    		data[0]=data[1];
	    		data[1]=e;
	    	}
	    }
	}
    if(data[1]<data[2]){
    	if(data[0]<data[2]){
    		int e=data[0];
    		data[0]=data[2];
    		data[2]=e;
    	}
    }
    else{
    	if(data[0]<data[1]){
    		int e=data[0];
    		data[0]=data[1];
    		data[1]=e;
    	}
    }
    
	return 0;
}
