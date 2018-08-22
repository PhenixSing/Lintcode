#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include <list>
using namespace std;
class MinStack {
public:
	stack<int> a;
	stack<int> b;
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        a.push(number);
        b.push((min()>number)?number:min());
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int c=a.top();
        a.pop();
        b.pop();
        return c;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        if(b.empty())return 2147483647;
        return b.top();
    }
};
int main(void)
{
	MinStack a;
	a.push(1);
	cout<<a.pop();
	a.push(2);
	a.push(3);
	cout<<a.min();
	a.push(1);
	cout<<a.min();
	return 0;
}
