#include <iostream>
using namespace std;
int main()
{
	int a=10000, i, b[3], c[3]; //a：上界  i：指标  b：分子  c：分母
	int j, k, l, m; //循环用变量
	bool result = true;
	cout << "please input index:" << endl;
	cin	>> i  ;
	cout << "I=" << i << endl;
	for (j = i * i + 2 * i + 3; j < a; j++)  //到达上界后退出
	{ 
		result = true;
		for (k = 1; k <= j; k++)  //对第一个数的分母枚举
		{
			result = true;
			c[0] = i * k + 1;
			for (l = 1; l <= k; l++)  //对第二个数的分母枚举
			{
				result = true;
				c[1] = i * l + 1;
				for (b[0] = 1; b[0] < c[0]; b[0]++)  //对第一个数的分子枚举
				{
					result = true;
					for (b[1] = 1; b[1] < c[1]; b[1]++)  //对第二个数的分子枚举
					{
						result = false;
						b[2] = 2 * c[0] * c[1] - b[0] * c[1] - b[1] * c[0];
						c[2] = c[0] * c[1];
						for (m = 1; m <= j; m++)  //只要存在m满足条件即可
						{
							if (b[2] > c[2])  //第三个数大于1 无需讨论
							{
								result = true;
								break;
							}
							//考虑第三个数为1的特殊情况
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
						if (result == false)  //不存在m 回到第一个循环处
						{
							cout << "j=" << j << endl;
							cout << "b1=" << b[0] << "/" << c[0] << endl;
							cout << "b2=" << b[1] << "/" << c[1] << endl;
							cout << "b3=" << b[2] << "/" << c[2] << endl;       //debug
							break;
						}
					}
					if (result == false)  //不存在m 回到第一个循环处
					{
						break;
					}
				}
				if (result == false)  //不存在m 回到第一个循环处
				{
					break;
				}
			}
			if (result == false)  //不存在m 回到第一个循环处
			{
				break;
			}
		}
		if (result == true)  //如果全部成功 则结束
		{
			cout << j <<endl;
			break;
		}
	}
	cout << "complete" << endl;
	system("pause");
	return 0;
} 