#include <iostream>
using namespace std;
int main()
{
	int a=10000, i, b[3], c[3]; //a���Ͻ�  i��ָ��  b������  c����ĸ
	int j, k, l, m; //ѭ���ñ���
	bool result = true;
	cout << "please input index:" << endl;
	cin	>> i  ;
	cout << "I=" << i << endl;
	for (j = i * i + 2 * i + 3; j < a; j++)  //�����Ͻ���˳�
	{ 
		result = true;
		for (k = 1; k <= j; k++)  //�Ե�һ�����ķ�ĸö��
		{
			result = true;
			c[0] = i * k + 1;
			for (l = 1; l <= k; l++)  //�Եڶ������ķ�ĸö��
			{
				result = true;
				c[1] = i * l + 1;
				for (b[0] = 1; b[0] < c[0]; b[0]++)  //�Ե�һ�����ķ���ö��
				{
					result = true;
					for (b[1] = 1; b[1] < c[1]; b[1]++)  //�Եڶ������ķ���ö��
					{
						result = false;
						b[2] = 2 * c[0] * c[1] - b[0] * c[1] - b[1] * c[0];
						c[2] = c[0] * c[1];
						for (m = 1; m <= j; m++)  //ֻҪ����m������������
						{
							if (b[2] > c[2])  //������������1 ��������
							{
								result = true;
								break;
							}
							//���ǵ�������Ϊ1���������
							if ((b[2] < c[2] && ((m * i + 1) * b[0]) / c[0] + ((m * i + 1) * b[1]) / c[1] + ((m * i + 1) * b[2]) / c[2] <= 2 * m * i) || (b[2] == c[2] && ((m * i + 1) * b[0]) / c[0] + ((m * i + 1) * b[1]) / c[1] + m * i  <= 2 * m * i))
							{
								result = true;
								break;
							}
						}
						//debug
//						for (m = i * i + 2 * i + 3; m <= i * i + 2 * i + 3; m++)
//						{
//							if ((b[2] < c[2] && ((m * i + 1) * b[0]) / c[0] + ((m * i + 1) * b[1]) / c[1] + ((m * i + 1) * b[2]) / c[2] <= 2 * m * i) || (b[2] == c[2] && ((m * i + 1) * b[0]) / c[0] + ((m * i + 1) * b[1]) / c[1] + m * i <= 2 * m * i))
//							{
//								result = true;
//								break;
//							}
//						}
						//debug
						if (result == false)  //������m �ص���һ��ѭ����
						{
							cout << "j=" << j << endl;
							cout << "b1=" << b[0] << "/" << c[0] << endl;
							cout << "b2=" << b[1] << "/" << c[1] << endl;
							cout << "b3=" << b[2] << "/" << c[2] << endl;       //debug
							break;
						}
					}
					if (result == false)  //������m �ص���һ��ѭ����
					{
						break;
					}
				}
				if (result == false)  //������m �ص���һ��ѭ����
				{
					break;
				}
			}
			if (result == false)  //������m �ص���һ��ѭ����
			{
				break;
			}
		}
		if (result == true)  //���ȫ���ɹ� �����
		{
			cout << j <<endl;
			break;
		}
	}
	cout << "complete" << endl;
	system("pause");
	return 0;
} 