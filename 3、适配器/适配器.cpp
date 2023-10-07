#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//函数对象适配器
class prin1t:public binary_function<int,int,void>
{
public:
	void operator()(int val, int start)const
	{
		cout << "val: "<<val<<"start:  "<<start<<"总和: "<<val + start << endl;
	}
};
void test()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值: " << endl;
	int num;
	cin >> num;
	//1、利用bind2nd进行绑定
	//2、继承public binary_function<int,int,void>
	//3、加const
	for_each(v.begin(), v.end(),bind2nd(prin1t(),num));
}
//取反适配器
class than :public unary_function<int,bool>{
public:
	bool operator()(int val)const
	{
		return val > 5;
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	//1、not1取反
	//2、继承unary_function<int,bool>
	//3、加const
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(than()));
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (pos != v.end())//一元取反
	{
		cout << "找到了小于于5的值为：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	cout << endl;
}
//函数指针适配器
void print(int val, int start)
{
	cout << val + start << " ";
}
void test2()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	//将函数指针 适配成函数对象
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print),1000));
	cout << endl;
}
//成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->mname = name;
		this->mage = age;
	}
	void print2()
	{
		cout << "姓名： " << this->mname << " 年龄： " << this->mage << endl;
	}
	string mname;
	int mage;
};

void test3()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//利用mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::print2));

}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}