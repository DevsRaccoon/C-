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
			cout << "����Ϊ��" << i << endl;
		}
		void print(double f)
		{
			cout << "������Ϊ��" << f << endl;
		}
		void print(char c[])
		{
			cout << "�ַ���Ϊ��" << c << endl;
		}
};

int main()
{
	// PrintData pd;
	//�������
	// pd.print(5);
	//���������
	// pd.print(10.2);
	//����ַ���
	// char c[12] = "Hello World";
	// pd.print(c);
	// return 0;
	
	Box box1;
	Box box2;
	Box box3;
	double volume = 0.0; //Volume storaged in this variable
	
	// Box1 ����
	box1.setLength(6.0); 
	box1.setBreadth(7.0); 
	box1.setHeight(5.0);
	 
	// Box2 ����
	box2.setLength(12.0); 
	box2.setBreadth(13.0); 
	box2.setHeight(10.0);
	
	//Box1�����
	volume = box1.getVolume();
	cout << "Volume of Box1: " << volume << endl;
	
	//Box2�����
	volume = box2.getVolume();
	cout << "Volume of Box2: " << volume << endl;
	
	box3 = box1 + box2;
	
	//Box3�����
	volume = box3.getVolume();
	cout << "Volume of Box3: " << volume << endl;
	
	return 0;
	
	
}

