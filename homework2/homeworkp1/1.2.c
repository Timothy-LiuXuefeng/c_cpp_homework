//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef unsigned char UCHAR;
//static inline UCHAR rev(UCHAR x)	/*��ת*/
//{
//	x = (((x & 0x0f) << 4) | ((x & 0xf0) >> 4));	/*������λ��ת*/
//	x = (((x & 0x33) << 2) | ((x & 0xcc) >> 2));	/*������λ��ת*/
//	x = (((x & 0x55) << 1) | ((x & 0xaa) >> 1));	/*����һλ��ת*/
//	return x;
//}
//int main(int argc, char* argv[])	/*argv[1]�������ļ�����argv[2]������ļ���*/
//{
//	UCHAR form[256];	/*�洢��תֵ*/
//	UCHAR* buffer;
//	FILE* fin, * fout;
//	int max = 16;
//	size_t now;
//	if (argc != 3)
//	{
//		printf("Parameter input error!\n");
//		exit(-1);
//	}
//	for (register int i = 0; i < 256; ++i)
//	{
//		form[i] = rev((UCHAR)i);
//	}
//	if (!(fin = fopen(argv[1], "rb")))
//	{
//		printf("Cannot open the file %s!\n", argv[1]);
//		exit(-1);
//	}
//	if (!(fout = fopen(argv[2], "wb")))
//	{
//		printf("Cannot open the file %s!\n", argv[2]);
//		exit(-1);
//	}
//	for (int i = 0; i < 256; ++i)	/*��ʼ����ת��*/
//		form[i] = rev(i);
//	buffer = (UCHAR*)malloc(sizeof(UCHAR) * max);
//	if (!buffer)
//	{
//		printf("ERROR!");
//		exit(-1);
//	}
//	while (1)
//	{
//		now = fread(buffer, sizeof(UCHAR), max, fin);
//		for (int i = 0; i < now; ++i)
//			buffer[i] = form[buffer[i]];
//		fwrite(buffer, sizeof(UCHAR), now, fout);
//		if (now < max) break;	/*�����ļ�β*/
//		free(buffer);	/*����ÿ�ζ�����*/
//		max *= 2;
//		buffer = (UCHAR*)malloc(sizeof(UCHAR) * max);
//		if (!buffer)
//		{
//			printf("ERROR!");
//			exit(-1);
//		}
//	}
//	free(buffer);
//	fclose(fout);
//	fclose(fin);
//	return 0;
//}
