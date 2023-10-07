#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>
#include<ctime>
using namespace std;
class Speaker
{
public:
	string mname;
	int mscore[3];
};
void createspeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameseed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0;i < nameseed.size();i++)
	{
		string name = "选手";
		name += nameseed[i];
		Speaker sp;
		sp.mname = name;
		for (int j = 0;j < 3;j++)
		{
			sp.mscore[j] = 0;
		}
		v.push_back(i + 100);
		m.insert(make_pair(i + 100, sp));
	}
}
void random(vector<int> v)
{
	random_shuffle(v.begin(), v.end());
}
void speechcontest(int index, vector<int>& v1, vector<int>& v2, map<int, Speaker>& m)
{
	multimap<int, int, greater<int>> groupmap;
	int num = 0;
	for (vector<int>::iterator it = v1.begin();it != v1.end(); it++)
	{
		num++;
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 40 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = accumulate(d.begin(), d.end(), 0);
		int avg = sum / d.size();
		m[*it].mscore[index - 1] = avg;
		groupmap.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupmap.begin(); mit != groupmap.end(), count < 3;mit++, count++)
			{
				v2.push_back(mit->second);
			}
			groupmap.clear();
		}
	}
}

void print(int index, map<int, Speaker>& m, vector<int>& v)
{
	cout << "第" << index  << "轮晋级名单" << endl;
	for (map<int, Speaker>::iterator it = m.begin();it != m.end();it++)
	{
		if (0 == it->second.mscore[index - 1])continue;
		cout << "选手编号为: " << it->first << "姓名为： " << it->second.mname << "分数为：" << it->second.mscore[index - 1] << endl;
	}
	cout << "晋级选手编号为：" << endl;
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		sort(v.begin(), v.end());
		cout <<"晋级选手编号为：" <<*it<<"选手姓名："<<m[*it].mname <<"选手成绩为： "<<m[*it].mscore[index-1] << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<int>v1;
	map<int, Speaker>m;
	createspeaker(v1, m);
	random(v1);
	vector<int>v2;
	speechcontest(1, v1, v2,m);
	print(1, m, v2);


	random(v2);
	vector<int>v3;
	speechcontest(2, v2, v3, m);
	print(2, m, v3);

	random(v3);
	vector<int>v4;
	speechcontest(3, v3, v4, m);
	print(3, m, v4);

	return 0;
}