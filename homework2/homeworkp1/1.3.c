#include <stdio.h>
#include <string.h>
//#include <stdint.h>
#include <stdlib.h>
#pragma warning(disable:4996)
char input[20000] = { 0 };
char output[20000];
char number[10][3] = { "��", "һ", "��", "��", "��" , "��" , "��" , "��" , "��" , "��" };
char loword[4][3] = { "��", "ʮ", "��", "ǧ" };
char highword[13][3] = { "��", "��", "��", "��", "��", "��", "��", "�", "��", "��", "��", "��", "��" };
#define MAX_NUM 52
inline long changeToNum(char* p)	//��˫�ֽ��ַ�ת����ANSI��ֵ
{
	return (unsigned char)p[0] * 0x100L + (unsigned char)p[1];
}
int main()
{
	char zero[] = "��";
	char nine[] = "��";
	char* p = input, * q, * tmptr;
	int outlen = 0, pN;
	int zeroN, nineN, tmp, tmp1, tmp2;
	int tmp3, zeronum, tmp4;
	//char outputzero = 0; //�ղ��Ƿ������'��'
	zeroN = changeToNum(zero);
	nineN = changeToNum(nine);
	printf("������һ�Σ������ո񡢻س���Tab�����������Ļ���\n\n");
	scanf("%s", input);
	while (*p)
	{
		if (*p == '-' && ((*(p + 1) >= '0' && *(p + 1) <= '9') || (changeToNum(p + 1) >= zeroN && changeToNum(p + 1) <= nineN)))
		{
			strncpy(&output[outlen], "��", 2);
			outlen += 2;
			++p;
		}
		if (((*p) >> 7) & 1)	//���λΪ1
		{


			/*����ȫ��*/

			pN = changeToNum(p);
			if (pN >= zeroN && pN <= nineN)
			{
				if (pN == zeroN)	//����ͷ��0
				{
					p += 2;
					while (changeToNum(p) == zeroN) { p += 2; }	//ȥ����ͷ�Ķ���㣬ֻ����һ��
					p -= 2;
					if (changeToNum(p + 2) < zeroN || changeToNum(p + 2) > nineN) //������������
					{
						strncpy(&output[outlen], "��", 2);
						outlen += 2;
						p += 2;
						goto dot1;
					}
					p += 2;
				}
				if (changeToNum(p) == zeroN + 1 && (changeToNum(p + 4) < zeroN || changeToNum(p + 4) > nineN))  //10�Ƚ����⣬��Ϊ��1������
				{
					if (changeToNum(p + 2) >= zeroN && changeToNum(p + 2) <= nineN)
					{
						strncpy(&output[outlen], "ʮ", 2);
						outlen += 2;
						if (changeToNum(p + 2) != zeroN)
						{
							strncpy(&output[outlen], number[changeToNum(p + 2) - zeroN], 2);
							outlen += 2;
						}
						p += 4;
						goto dot1;
					}
				}

				q = p + 2;
				while (changeToNum(q) >= zeroN && changeToNum(q) <= nineN)
				{
					q += 2;
				}
				tmp = (q - p) / 2;
				if (tmp > MAX_NUM)
				{
					perror("\n��λ��������������֣�\n");
					exit(-1);
				}
				tmp -= 1;
				tmp1 = tmp / 4;
				tmp2 = tmp % 4;
				if (tmp2 == 1 && changeToNum(p) == zeroN + 1 && changeToNum(p + 2) >= zeroN && changeToNum(p + 2) <= nineN)	//ʮ��ʮ�ڵ����⣬1����
				{
					strncpy(&output[outlen], "ʮ", 2);
					outlen += 2;
					if (changeToNum(p + 2) != zeroN)
					{
						strncpy(&output[outlen], number[changeToNum(p + 2) - zeroN], 2);
						outlen += 2;
					}
					strncpy(&output[outlen], highword[tmp1], 2);
					outlen += 2;
					tmp2 = 3;
					--tmp1;
				}
				while (tmp1 >= 0)
				{

					//����0

					if (changeToNum(&p[(tmp - 4 * tmp1 - tmp2) * 2]) == zeroN)
					{
						tmp3 = tmp - 4 * tmp1 - tmp2 + 1;
						zeronum = 1;
						while (changeToNum(&p[tmp3 * 2]) == zeroN && tmp2 - zeronum >= 0)
						{
							++zeronum;
							++tmp3;
						}
						if (zeronum == 4)	//��λ����0
						{
							tmp4 = 0;
							while (changeToNum(&p[(tmp3 + tmp4) * 2]) == zeroN)
							{
								++tmp4;
							}
							if (tmp4 == tmp1 * 4) //0��������λ��ֱ���ж�С����
							{
								p = q;
								goto dot1;
							}
							//if (!outputzero)	//�ո�û�����'��'�����'��'
							{
								strncpy(&output[outlen], number[0], 2);
								outlen += 2;
								//outputzero = 1;
							}
							tmp1 -= tmp4 / 4 + 1;		//��ת�����㴦
							tmp2 = 3 - tmp4 % 4;
							continue;
						}
						if (zeronum == tmp2 + 1)	/*0������ÿ��4λĩβ*/
						{
							if (tmp1 > 0)	//��Ҫ����߼�������λ
							{
								strncpy(&output[outlen], highword[tmp1], 2);
								outlen += 2;
								//outputzero = 0;
							}
							--tmp1;
							tmp2 = 3;
							continue;
						}
						//if (!outputzero)	//�ո�û�����'��'
						{

							strncpy(&output[outlen], number[0], 2);
							outlen += 2;
							//outputzero = 1;
						}
						tmp2 -= zeronum;
						continue;
					}


					//����


					//����
					strncpy(&output[outlen], number[changeToNum(p + (tmp - 4 * tmp1 - tmp2) * 2) - zeroN], 2);
					outlen += 2;
					//outputzero = 0;
					if (tmp2 != 0)	//���Ǹ�λ
					{		//λ
						strncpy(&output[outlen], loword[tmp2], 2);
						outlen += 2;
					}
					--tmp2;
					if (tmp2 == -1)
					{
						if (tmp1 != 0)
						{
							strncpy(&output[outlen], highword[tmp1], 2);
							outlen += 2;
						}
						--tmp1;
						tmp2 = 3;
					}
				}
				p = q;

			dot1:

				//����С����
				if (*p == '.')
				{
					++p;
					if (changeToNum(p) >= zeroN && changeToNum(p) <= nineN)
					{
						strncpy(&output[outlen], "��", 2);
						outlen += 2;
						strncpy(&output[outlen], number[changeToNum(p) - zeroN], 2);
						outlen += 2;
						p += 2;
					}
					while (changeToNum(p) >= zeroN && changeToNum(p) <= nineN)
					{
						strncpy(&output[outlen], number[changeToNum(p) - zeroN], 2);
						outlen += 2;
						p += 2;
					}
				}
			}
			else
			{
				output[outlen++] = *(p++);
				output[outlen++] = *(p++);
				//outputzero = 0;
			}

			//int pN = changeToNum(p);
			//if (pN >= zeroN && pN <= nineN)
			//{
			//	/*ת�����ַ���*/
			//	/*�����������*/
			//	/*�޸�p*/
			//}
			//else
			//{
				
			//}
		}
		else
		{
		
			/*if (*p == '-' && *(p + 1) >= '0' && *(p + 1) <= '9')
			{
				strncpy(&output[outlen], "��", 2);
				outlen += 2;
				++p;
			}*/
			
			if (*p >= '0' && *p <= '9')
			{
				if (*p == '0')	//����ͷ��0
				{
					++p;
					while (*p == '0') { ++p; }	//ȥ����ͷ�Ķ���㣬ֻ����һ��
					--p;
					if (*(p + 1) < '0' || *(p + 1) > '9') //������������
					{
						strncpy(&output[outlen], "��", 2);
						outlen += 2;
						++p;
						goto dot;
					}
					++p;
				}
				if (*p == '1' && (*(p + 2) < '0' || *(p + 2) > '9'))  //10�Ƚ����⣬��Ϊ��1������
				{
					if (*(p + 1) >= '0' && *(p + 1) <= '9')
					{
						strncpy(&output[outlen], "ʮ", 2);
						outlen += 2;
						if (*(p + 1) != '0')
						{
							strncpy(&output[outlen], number[*(p + 1) - '0'], 2);
							outlen += 2;
						}
						p += 2;
						goto dot;
					}
				}
				
				q = p + 1;
				while (*q >= '0' && *q <= '9')
				{
					++q;
				}
				tmp = q - p;
				if (tmp > MAX_NUM)
				{
					perror("\n��λ��������������֣�\n");
					exit(-1);
				}
				--tmp;
				tmp1 = tmp / 4;
				tmp2 = tmp % 4;
				if (tmp2 == 1 && *p == '1' && *(p + 1) >= '0' && *(p + 1) <= '9')	//ʮ��ʮ�ڵ����⣬1����
				{
					strncpy(&output[outlen], "ʮ", 2);
					outlen += 2;
					if (*(p + 1) != '0')
					{
						strncpy(&output[outlen], number[*(p + 1) - '0'], 2);
						outlen += 2;
					}
					strncpy(&output[outlen], highword[tmp1], 2);
					outlen += 2;
					tmp2 = 3;
					--tmp1;
				}
				while (tmp1 >= 0)
				{

					//����0

					if (p[tmp - 4 * tmp1 - tmp2] == '0')	
					{
						tmp3 = tmp - 4 * tmp1 - tmp2 + 1;
						zeronum = 1;
						while (p[tmp3] == '0' && tmp2 - zeronum >= 0)
						{
							++zeronum;
							++tmp3;
						}
						if (zeronum == 4)	//��λ����0
						{
							tmp4 = 0;
							while (p[tmp3 + tmp4] == '0') ++tmp4;
							if (tmp4 == tmp1 * 4) //0��������λ��ֱ���ж�С����
							{
								p = q;
								goto dot;
							}
							//if (!outputzero)	//�ո�û�����'��'�����'��'
							{
								strncpy(&output[outlen], number[0], 2);
								outlen += 2;
								//outputzero = 1;
							}
							tmp1 -= tmp4 / 4 + 1;		//��ת�����㴦
							tmp2 = 3 - tmp4 % 4;
							continue;
						}
						if (zeronum == tmp2 + 1)	/*0������ÿ��4λĩβ*/
						{
							if (tmp1 > 0)	//��Ҫ����߼�������λ
							{
								strncpy(&output[outlen], highword[tmp1], 2);
								outlen += 2;
								//outputzero = 0;
							}
							--tmp1;
							tmp2 = 3;
							continue;
						}
						//if (!outputzero)	//�ո�û�����'��'
						{
							
							strncpy(&output[outlen], number[0], 2);
							outlen += 2;
							//outputzero = 1;
						}
						tmp2 -= zeronum;
						continue;
					}


					//����


					//����
					strncpy(&output[outlen], number[p[tmp - 4 * tmp1 - tmp2] - '0'], 2);
					outlen += 2;
					//outputzero = 0;
					if(tmp2 != 0)	//���Ǹ�λ
					{		//λ
						strncpy(&output[outlen], loword[tmp2], 2);
						outlen += 2;
					}
					--tmp2;
					if (tmp2 == -1)
					{
						if (tmp1 != 0)
						{
							strncpy(&output[outlen], highword[tmp1], 2);
							outlen += 2;
						}
						--tmp1;
						tmp2 = 3;
					}
				}
				p = q;

			dot:

				//����С����
				if (*p == '.')
				{
					++p;
					if (*p >= '0' && *p <= '9')
					{
						strncpy(&output[outlen], "��", 2);
						outlen += 2;
						strncpy(&output[outlen], number[*p - '0'], 2);
						outlen += 2;
						++p;
					}
					while (*p >= '0' && *p <= '9')
					{
						strncpy(&output[outlen], number[*p - '0'], 2);
						outlen += 2;
						++p;
					}
				}
			}
			else
			{
				output[outlen++] = *(p++);
				//outputzero = 0;
			}
		}
	}
	output[outlen++] = '\0';
	printf("\n\n%s\n", output);
	printf("\n���������Խ�������\n");
	while (getchar() != '\n');
	scanf("%c", input);
	return 0;
}
