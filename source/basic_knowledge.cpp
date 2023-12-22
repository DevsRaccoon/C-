#include <iostream>
using namespace std;

class Line
{
	public:
		int getlength(void);
		Line(int len);	//带参数的构造函数
		Line(const Line &obj);	//拷贝构造函数
		~Line();	//析构函数
	private:
		int *ptr;
};

class Box
{
	double width;
	public:
		double length;
		friend void printWidth(Box box);
		void setWidth(double wid);
};



//比较长方体的体积
class Box1
{
	public:
		//构造函数定义
		Box1(double l = 2.0, double b = 2.0, double h = 2.0)
		{
			cout << "调用构造函数" << endl;
			length = l;
			breadth = b;
			height = h;
		}
		double Volume()
		{
			return length * breadth * height;
		}
		int compare(Box1 box)
		{
			return this->Volume() > box.Volume();
		}
	private:
		double length;
		double breadth;
		double height;
};

//Box成员函数定义
void Box::setWidth(double wid)
{
	width = wid;
}

//printWidth不是任何类的成员函数
void printWidth(Box box)
{
	//因为此函数是Box类的友元，故它可以访问该类的任何成员
	cout << "Width of Box:" << box.width << endl;
}



//成员函数定义
Line::Line(int len)
{
	cout << "调用构造函数" << endl;
	//为指针分配内存
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line &obj)
{
	cout << "调用拷贝构造函数为ptr分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr;	//拷贝值s
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}

int Line::getlength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line大小：" << obj.getlength() << endl;
}

//程序主函数
// int main()
// {
	// Line line1(10);
	// Line line2 = line1;
	// display(line1);
	// display(line2);
	// return 0;
// }

//友元函数（非成员函数）（原型可能在类的定义中出现）

// int main()
// {
	// Box box;
	// box.setWidth(10.0);
	// printWidth(box);//使用友元函数输出宽度
	// return 0;
// }


//内联函数
//使用内联函数是用空间来换取时间的节省，对于非内联函数都是在运行的时候才被替代，而内联函数是在程序编译期间就是用
//函数副本来取代调用函数的语句。因此每次更改了内联函数之后都需要重新编译程序。

int main()
{
	Box1 obj1(3.3, 1.2, 1.5);
	Box1 obj2(8.5, 6.0, 2.0);
	if (obj1.compare(obj2))
	{
		cout << "obj2的体积比obj1小" << endl;
	}
	else
	{
		cout << "obj2的体积比obj1的大" << endl;
	}
	return 0;
}

