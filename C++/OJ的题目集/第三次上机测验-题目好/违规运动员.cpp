#include <iostream>
using namespace std;
/*
题目描述：

学校举办迷你马拉松，为了保证运动公平，每位选手佩戴的手环中有一个RFID标签
在经过传感器时，计算机会将记录传感器id、选手的号码及经过传感器的时间（时间采用24小时格式：HH MM SS）
本次运动一共有3个传感器，分别在在出发点、中间点和终点，对应的传感器id分别为0，1，2。
分析传感器的数据，输出有多少运动员违规。
违规的判断：（1）如果某个运动员完成某个半程的时间少于半小时，则判他可能利用了某种交通工具违规；
（2）缺少中间点或终点的传感器数据。

输入说明：首先输入运动员的人数，接着输入若干行传感器数据，每行传感器数据：传感器id 运动员编号 HH MM SS，

最后一行输入3结束。

默认在出发点所有运动员均有数据上传。

Sample

input:

5 
0 100 08 00 00
0 122 08 00 00
0 132 08 00 00
0 142 08 00 01
0 152 08 00 02

1 132 08 50 46
1 152 08 49 59
1 142 08 51 10
1 122 08 52 00

2 152 09 19 58
2 142 09 34 02
2 100 09 34 05
2 122 09 35 35
2 132 09 36 00
3

output:
2 

struct ath
{
	int name;//第一遍输入了之后之后也得让他输入，只是在相同的基础上再输入一遍而已啦 
	int count;//得先把所有人的count给成0的**初始化**，如果输入的姓名找到了他，就count++ 
	int hour[3];//如果没有被cin赋值的话，是会被计算机给上随机值的，不一定是0，可能是其他奇奇怪怪的数呢****
	//所以遇到没有完全输入的情况，应该直接break或者goto出来，下次只能调用到有数据的地方呢** 
	int min[3];
	int sec[3];
};
 */
 
 /*
 
3
0 100 08 00 00
0 122 08 00 00
0 152 08 00 02
1 152 08 49 59
1 122 08 52 00
2 152 09 19 58
2 100 09 34 05
2 122 09 35 35
3
 */ 
/*
思路的选择：
1、题目的类别。一个人有好多个性质：过的节点的次数、他的编号信息、他的每个节点的时间信息
			》》像这样每个人集成度很高的，都是在描述同一个人的信息的题目，果断结构 
和水果那题一样，一定要选择结构 


*/
/*
//【错误】 
/*
①变量定义的名字不够特异性，思路不清，给他用混了*****
who这个名字就不好，应该起成name1》》这个人的名字肯定不会混成下表啦**
i在放进循环前，要清楚他后面还会不会起到作用***。
如果后面起到作用最好就不用i了，可以用out这个名字，提醒自己外边还会用的 



②【错误2】n重复命名 
尽量不要使用n这个名字，如果可以 使用second这个不会出错的情况，就别用n啦***

③Debug：Program received signal SIGSEGV,Segmentation fault.【调试的时候报错】 
1、指针未初始化
2、数组未被初始化+数组下标越界+数组元素不存在等【大概率是咱们数组下标用错啦，越界了***】
3、定义在main函数中的二维数组过大 
 
 
针对可能导致SIGSEGV的四种原因可分别采用以下的解决方法：
1、指针、数组未初始化>>>初始化指针、数组
2、数组下标越界、数组元素不存在>>>检查数组下标，禁止数组越界，给不存在的数组元素赋值
3、使用printf输出变量时变量格式控制不合理>>>规范输出变量格式(%d%s%d)
4、在main函数中定义了过大的二维数组>>>将数组的定义移至main函数之前

另外，经过尝试之后，还发现main函数中定义的最大二维数组为[720][720]。
所以也就意味着，
如果要定义比这更大的二维数组就要在main函数外面定义啦！！
*/
*/
struct ath
{
	int name;
	int count;//得先把所有人的count给成0的**初始化**
	int hour[3];
	int min[3];
	int sec[3];
};

int main() 
{
	//step1：给所有运动员赋值成1*
	int n;
	cin >> n;
	//得创建一个ath类型的数组啦，没法直接定义n个ath类型的结构
	ath a[n];
	//区分。链表的时候p->content和(*p).content=a;一样的***指针特殊采用->的呢
	for(int i=0;i<n;i++)
		a[i].count=0;
	//必须先赋值成0***》》不然之后第二次没有成绩，第三次有成绩了，认为他过了三次** 
	//先输入第一轮，记住他们的名字
	for(int i=0;i<n;i++)
	{
		cin >> a[i].count;
		cin >>	a[i].name;
		cin >> a[i].hour[0]>> a[i].min[0]>> a[i].sec[0];
	} 
	int in;
	cin >> in;
	while(in!=3)
	{
		//满足输入条件，开始找是那个人过了这个点了** 
		int who;
		cin >> who;
		int i;
		for(i=0;i<n;i++)
		{
			if(a[i].name==who)
				break;
		} 
		//现在是a[i]这个人过这个点了，他的名字是who***
		a[i].count=a[i].count+1;
		int x=a[i].count;
		cin >> a[i].hour[x] >>a[i].min[x]>>a[i].sec[x];
		//在输入一个in，看看是不是循环结束了** 
		cin >> in;
	} 
	//问题出现在，a[i].count有问题，输出不出来 
//		cout << a[2].count=0<<" "<< a[2].hour[1]=0;

	//全部输入完毕，先看看有几个count不是2，不是2不看他且计数器+1
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].count==2)//三个点都过了 ,看看时间合理吗 
		{
			//开始计算每一个人经过的秒数
			int m;//前两个点之间的秒数差
			m=(a[i].hour[1]-a[i].hour[0])*3600+(a[i].min[1]-a[i].min[0])*60+a[i].sec[1]-a[i].sec[0];
			int n1;
			n1= (a[i].hour[2]-a[i].hour[1])*3600+(a[i].min[2]-a[1].min[1])*60+a[i].sec[2]-a[i].sec[1];
			if(m>=1800&&n1>=1800)
				;
			else
				sum++;
			
		}
		else//有其中几个点没有过！直接加1，不再算他们几个节点之间的时间了** 
			sum++;
	 } 
	 cout << sum;
	return 0;
}
