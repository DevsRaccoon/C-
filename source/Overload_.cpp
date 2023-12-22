#include <iostream>
using namespace std;

//Overload function or Overload operator
//Overload resolution


class Box
{
	public:
		double getVolume(void)
		{
			return length * height * breadth;
		}
		void setLength(double len)
		{
			length = len;
		}
		void setHeight(double hei)
		{
			height = hei;
		}
		void setBreadth(double bre)
		{
			breadth = bre;
		}
		
		//Overload + resolution
		Box operator+(const Box& b)
		{
			Box box;
			box.length = this->length + b.length;
			box.height = this->height + b.height;
			box.breadth = this->breadth + b.breadth;
			return box;
		}
	private:
		double height;
		double length;
		double breadth;
};


class PrintData
{
	public:
		void print(int i)
		{
			cout << "整数为：" << i << endl;
		}
		void print(double f)
		{
			cout << "浮点数为：" << f << endl;
		}
		void print(char c[])
		{
			cout << "字符串为：" << c << endl;
		}
};

int main()
{
	// PrintData pd;
	//输出整数
	// pd.print(5);
	//输出浮点数
	// pd.print(10.2);
	//输出字符串
	// char c[12] = "Hello World";
	// pd.print(c);
	// return 0;
	
	Box box1;
	Box box2;
	Box box3;
	double volume = 0.0; //Volume storaged in this variable
	
	// Box1 详述
	box1.setLength(6.0); 
	box1.setBreadth(7.0); 
	box1.setHeight(5.0);
	 
	// Box2 详述
	box2.setLength(12.0); 
	box2.setBreadth(13.0); 
	box2.setHeight(10.0);
	
	//Box1的体积
	volume = box1.getVolume();
	cout << "Volume of Box1: " << volume << endl;
	
	//Box2的体积
	volume = box2.getVolume();
	cout << "Volume of Box2: " << volume << endl;
	
	box3 = box1 + box2;
	
	//Box3的体积
	volume = box3.getVolume();
	cout << "Volume of Box3: " << volume << endl;
	
	return 0;
	
	
}

