#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Than
{
public:
	bool operator()(int val)//һԪν��
	{
		return val > 20;
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	vector<int>::iterator pos = find_if(v.begin(), v.end(), Than());
	if (pos != v.end())
	{
		cout << "�ҵ��˴���20������" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

class mysort
{
public:
	bool operator()(int v1, int v2)//��Ԫν��
	{
		return v1 > v2;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	sort(v.begin(),v.end(),mysort());
	//lambda���ʽ ��������  []����lanmda���ʽ��־
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
	cout << endl;
}
int main()
{
	test1();
	return 0;
}