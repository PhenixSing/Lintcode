#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        make_heap(nums.begin(), nums.end(), less<int>());
        for(int i=0;i<n;i++){
        	
        	pop_heap(nums.begin(), nums.end()-i, less<int>());
		    //cout << data.back() << endl;//���7
		    //data.pop_back();
		    
        }
        return *(nums.end()-n);
}
int main(void)
{
	int a[5] = { 3,1,2,7,5 };
	//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��5������ҿ����䣩
	//vector<int> b(a, a+5);
	vector<int> data(a, a+5);
	cout << kthLargestElement(3,data);
    //����ѣ�����
    //make_heap(data, data+5, less<int>());
    //pop�Ѷ�Ԫ�أ�����Ԫ��
    //pop_heap(data.begin(), data.end(), less<int>());
    //for(int i=0;i<5;i++)cout << data[i] << endl;//���7
    //data.pop_back();
    //���������Ԫ��
    //data.push_back(4);
    //push_heap(data.begin(), data.end(), less<int>());//������
    
	return 0;
}
