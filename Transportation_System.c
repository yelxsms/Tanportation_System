//简易交通咨询系统


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Windows.h"

#define INF 99999

typedef int Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vex[8];
	EdgeType arc[8][8];
}Graph;


typedef char Start;
typedef char End;


void menu()
{
	printf("城市：a b c d e f g h\n");
	printf("\n");
	printf("\n");
	printf("请输入需要查询的起点城市和终点城市(9999代表不可直达)\n");
}


int main()
{
	//menu();
	
	Graph G;

	G.vex[0] ='a' ; G.vex[1] = 'b'; G.vex[2] = 'c'; 
	G.vex[3] = 'd'; G.vex[4] = 'e'; G.vex[5] = 'f'; 
	G.vex[6] = 'g'; G.vex[7] = 'h'; 
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			G.arc[i][j] = INF;
		}
	}

	G.arc[0][1] = 70; G.arc[0][4] = 10; G.arc[0][5] = 60;
	G.arc[0][6] = 110; G.arc[1][2] = 20; G.arc[1][3] = 40;
	G.arc[1][6] = 10; G.arc[2][3] = 90; G.arc[2][4] = 30;
	G.arc[2][7] = 30; G.arc[3][7] = 150; G.arc[4][5] = 30;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			G.arc[j][i] = G.arc[i][j];
		}
	}
	
	printf("各个城市之间距离的邻接矩阵为：\n");
	
	char city[8] = { 'a','b','c','d','e','f','g','h' };
	for (int i = 0; i < 8; i++)
		printf("%c\t", city[i]);
	printf("\n");
	int count = 0;
	int count_3 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			printf("%d\t", G.arc[i][j]);
			count++;
			if (count % 8 == 0)
			{
				printf("%c ", city[count_3]);
				printf("\n");				
				count_3 = count_3 + 1;
				
			}
		}
	}
	

	int Patharc[20][20];
	int ShortPathTable[20][20];

	int v, w, k;
	for (v = 0; v < 8; ++v)
	{
		for (w = 0; w < 8; ++w)
		{
			ShortPathTable[v][w] = G.arc[v][w];
			Patharc[v][w] = w;
		}
	}
	for (k = 0; k < 8; ++k)
	{
		for (v = 0; v < 8; ++v)
		{
			for (w = 0; w < 8; ++w)
			{
				if (ShortPathTable[v][w] > ShortPathTable[v][k] + ShortPathTable[k][w])
				{
					ShortPathTable[v][w] = ShortPathTable[v][k] + ShortPathTable[k][w];
					Patharc[v][w] = Patharc[v][k];
				}				
			}
		}
	}
	for (int i = 0; i < 8; i++)
		ShortPathTable[i][i] = 0;
	printf("\n");
	
	
	
	menu();

	char start;
	char end;
	int numstart=0;
	int numend=0;
	scanf_s("%c", &start);
	scanf_s("%c", &end);
	for (int i = 0; i < 9; i++)
	{
		if (G.vex[i] == start)
			numstart = i;
		if (G.vex[i] == end)
			numend = i;
	}
	//printf("%c,%c\n", numstart, numend);
	printf("\n城市%c和城市%c之间的最短路径为：%d\n", start, end, ShortPathTable[numstart][numend]);



	printf("\n");
	printf("\n");
	Sleep(1000);
	printf("各个城市之间的最短路径为：\n");
	for (int i = 0; i < 8; i++)
		printf("%c\t", city[i]);
	printf("\n");
	int count_2 = 0;
	int count_4 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d\t", ShortPathTable[i][j]);
			count_2++;
			if (count_2 % 8 == 0)
			{
				printf("%c", city[count_4]);
				printf("\n");
				count_4++;
			}
		}
	}
}
