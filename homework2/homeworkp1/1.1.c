//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning(disable:4996)
//int main(int argc, char* argv[])	/*argv[1]�������ļ�����argv[2]������ļ���*/
//{
//	char** s;
//	int Num = 0, max = 4;	/*�ַ�����Ŀ������*/
//	int range;	/*������*/
//	FILE* fin, *fout;
//	if (argc != 3)
//	{
//		printf("Parameter input error!\n");
//		exit(-1);
//	}
//	s = (char**)malloc(sizeof(char*) * max);	/*�����ַ�������*/
//	if (!s)
//	{
//		printf("ERROR!\n");
//		exit(-1);
//	}
//	for (int i = 0; i < max; ++i)		/*����max���ַ����ռ�*/
//	{
//		if (!(s[i] = (char*)malloc(sizeof(char) * 82)))
//		{
//			printf("ERROR!\n");
//			exit(-1);
//		}
//	}
//	fin = fopen(argv[1], "r");	/*�����ļ�*/
//	if (!fin)
//	{
//		printf("Cannot open the file %s!\n", argv[1]);
//		exit(-1);
//	}
//	fout = fopen(argv[2], "w");	/*�����ļ�*/
//	if (!fout)
//	{
//		printf("Cannot open the file %s!\n", argv[2]);
//		exit(-1);
//	}
//	while (1)
//	{
//		if (!(fgets(s[Num++], 82, fin))) break;
//		if (Num == max)		/*�ﵽ���ֵ�����·����ڴ�*/
//		{
//			int oldMax = max;
//			char** tmp = (char**)malloc(sizeof(char*) * max * 2);
//			if (!tmp)
//			{
//				printf("ERROR!\n");
//				exit(-1);
//			}
//			max *= 2;	/*������2*/
//			for (int i = 0; i < max; ++i)
//			{
//				if (!(tmp[i] = (char*)malloc(sizeof(char) * 82)))
//				{
//					printf("ERROR!\n");
//					exit(-1);
//				}
//			}
//			for (int i = 0; i < Num; ++i)	/*�����ַ���*/
//				strcpy(tmp[i], s[i]);
//			for (int i = oldMax - 1; i >= 0; --i)	/*�ͷ�ԭ�ڴ�*/
//				free(s[i]);
//			free(s);
//			s = tmp;
//		}
//	}
//	--Num;
//	range = strlen(s[Num - 1]);	/*�������һ���ַ���ĩβ�Ƿ��л��з�*/
//	if (s[Num - 1][range - 1] != '\n')
//	{
//		s[Num - 1][range] = '\n';
//		s[Num - 1][range + 1] = '\0';
//	}
//	range = Num - 1;
//	while (range > 0)	/*�����ַ���*/
//	{
//		for (int i = 0; i < range; ++i)
//		{
//			if (strcmp(s[i], s[i + 1]) > 0)
//			{
//				char* tmp = s[i];
//				s[i] = s[i + 1];
//				s[i + 1] = tmp;
//			}
//		}
//		--range;
//	}
//	for (int i = 0; i < Num; ++i)	/*����ַ���*/
//		fprintf(fout, s[i]);
//	for (int i = max - 1; i >= 0; --i)	/*�ͷ��ڴ�*/
//		free(s[i]);
//	free(s);
//	fclose(fout);	/*�ر��ļ�*/
//	fclose(fin);
//	return 0;
//}
