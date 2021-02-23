//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char *argv[]) /*argv[1]�������ļ�����argv[2]������ļ���*/
//{
//    char **s;
//    int size = 0, capacity = 4; /*�ַ�����Ŀ������*/
//    int range;                  /*������*/
//    FILE *fin, *fout;
//    if (argc != 3)
//    {
//        printf("Parameter input error!\n");
//        exit(-1);
//    }
//    s = (char **)malloc(sizeof(char *) * capacity); /*�����ַ�������*/
//    if (!s)
//    {
//        perror("ERROR!\n");
//        exit(-1);
//    }
//    for (int i = 0; i < capacity; ++i) /*����capacity���ַ����ռ�*/
//    {
//        if (!(s[i] = (char *)malloc(sizeof(char) * 82)))
//        {
//            perror("ERROR!\n");
//            exit(-1);
//        }
//    }
//    fin = fopen(argv[1], "r"); /*�����ļ�*/
//    if (!fin)
//    {
//        printf("Cannot open the file %s!\n", argv[1]);
//        exit(-1);
//    }
//    fout = fopen(argv[2], "w"); /*�����ļ�*/
//    if (!fout)
//    {
//        printf("Cannot open the file %s!\n", argv[2]);
//        exit(-1);
//    }
//    while (1)
//    {
//        if (!(fgets(s[size++], 82, fin)))
//            break;
//        if (size == capacity) /*�ﵽ���ֵ�����·����ڴ�*/
//        {
//            capacity *= 2;
//            s = (char **)realloc(s, capacity * sizeof(char*));
//            if (!s)
//            {
//                perror("ERROR!\n");
//                exit(-1);
//            }
//            for (int i = capacity / 2; i < capacity; ++i)
//            {
//                if (!(s[i] = (char *)malloc(sizeof(char) * 82)))
//                {
//                    perror("ERROR!\n");
//                    exit(-1);
//                }
//            }
//        }
//    }
//    --size;
//    range = strlen(s[size - 1]); /*�������һ���ַ���ĩβ�Ƿ��л��з�*/
//    if (s[size - 1][range - 1] != '\n')
//    {
//        s[size - 1][range] = '\n';
//        s[size - 1][range + 1] = '\0';
//    }
//    range = size - 1;
//    while (range > 0) /*�����ַ���*/
//    {
//        for (int i = 0; i < range; ++i)
//        {
//            if (strcmp(s[i], s[i + 1]) > 0)
//            {
//                char *tmp = s[i];
//                s[i] = s[i + 1];
//                s[i + 1] = tmp;
//            }
//        }
//        --range;
//    }
//    for (int i = 0; i < size; ++i) /*����ַ���*/
//        fprintf(fout, s[i]);
//    for (int i = capacity - 1; i >= 0; --i) /*�ͷ��ڴ�*/
//        free(s[i]);
//    free(s);
//    fclose(fout); /*�ر��ļ�*/
//    fclose(fin);
//    return 0;
//}
