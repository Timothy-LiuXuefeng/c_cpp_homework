//#include <iostream>
//#include <string>
//using namespace std;
//class Ball
//{
//public:
//	enum Color	//Ball���ڵ�ö������
//	{
//		Red,
//		Yellow,
//		Blue,
//		White,
//		Black
//	};
//	Ball(Color color) :_color(color) {}	//��ʼ��_color
//	string GetColor()	//�õ���ɫ�ַ���
//	{
//		switch (_color)
//		{
//		case Red:
//			return static_cast<string>("��"); //ת��Ϊstring����
//		case Yellow:
//			return static_cast<string>("��");
//		case Blue:
//			return static_cast<string>("��");
//		case White:
//			return static_cast<string>("��");
//		case Black:
//			return static_cast<string>("��");
//		default:
//			cout << "No such Color!" << endl;
//			return static_cast<string>("No such Color!");
//		}
//	}
//private:
//	Color _color;
//};
//int main()
//{
//	Ball ball[5] = { Ball::Red, Ball::Yellow, Ball::Blue, Ball::White, Ball::Black };
//	int sum = 0;
//	for(int i = 0; i < 3; ++i)
//		for(int j = i + 1; j < 4; ++j)
//			for (int k = j + 1; k < 5; ++k)
//			{
//				++sum;
//				cout << ball[i].GetColor() << ", " << ball[j].GetColor() << ", " << ball[k].GetColor() << endl;
//			}
//	cout << "��ȡ�����ǣ�" << sum;
//	return 0;
//}
