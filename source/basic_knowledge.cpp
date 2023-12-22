#include <iostream>
using namespace std;

class Line
{
	public:
		int getlength(void);
		Line(int len);	//�������Ĺ��캯��
		Line(const Line &obj);	//�������캯��
		~Line();	//��������
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



//�Ƚϳ���������
class Box1
{
	public:
		//���캯������
		Box1(double l = 2.0, double b = 2.0, double h = 2.0)
		{
			cout << "���ù��캯��" << endl;
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

//Box��Ա��������
void Box::setWidth(double wid)
{
	width = wid;
}

//printWidth�����κ���ĳ�Ա����
void printWidth(Box box)
{
	//��Ϊ�˺�����Box�����Ԫ���������Է��ʸ�����κγ�Ա
	cout << "Width of Box:" << box.width << endl;
}



//��Ա��������
Line::Line(int len)
{
	cout << "���ù��캯��" << endl;
	//Ϊָ������ڴ�
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line &obj)
{
	cout << "���ÿ������캯��Ϊptr�����ڴ�" << endl;
	ptr = new int;
	*ptr = *obj.ptr;	//����ֵs
}

Line::~Line(void)
{
	cout << "�ͷ��ڴ�" << endl;
	delete ptr;
}

int Line::getlength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line��С��" << obj.getlength() << endl;
}

//����������
// int main()
// {
	// Line line1(10);
	// Line line2 = line1;
	// display(line1);
	// display(line2);
	// return 0;
// }

//��Ԫ�������ǳ�Ա��������ԭ�Ϳ�������Ķ����г��֣�

// int main()
// {
	// Box box;
	// box.setWidth(10.0);
	// printWidth(box);//ʹ����Ԫ����������
	// return 0;
// }


//��������
//ʹ�������������ÿռ�����ȡʱ��Ľ�ʡ�����ڷ������������������е�ʱ��ű�������������������ڳ�������ڼ������
//����������ȡ�����ú�������䡣���ÿ�θ�������������֮����Ҫ���±������

int main()
{
	Box1 obj1(3.3, 1.2, 1.5);
	Box1 obj2(8.5, 6.0, 2.0);
	if (obj1.compare(obj2))
	{
		cout << "obj2�������obj1С" << endl;
	}
	else
	{
		cout << "obj2�������obj1�Ĵ�" << endl;
	}
	return 0;
}

