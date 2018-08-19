#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        make_heap(nums.begin(), nums.end(), less<int>());
        for(int i=0;i<n;i++){
        	
        	pop_heap(nums.begin(), nums.end()-i, less<int>());
		    //cout << data.back() << endl;//输出7
		    //data.pop_back();
		    
        }
        return *(nums.end()-n);
}
int main(void)
{
	int a[5] = { 3,1,2,7,5 };
	//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
	//vector<int> b(a, a+5);
	vector<int> data(a, a+5);
	cout << kthLargestElement(3,data);
    //构造堆，最大堆
    //make_heap(data, data+5, less<int>());
    //pop堆顶元素，最大的元素
    //pop_heap(data.begin(), data.end(), less<int>());
    //for(int i=0;i<5;i++)cout << data[i] << endl;//输出7
    //data.pop_back();
    //往堆中添加元素
    //data.push_back(4);
    //push_heap(data.begin(), data.end(), less<int>());//调整堆
    
	return 0;
}
