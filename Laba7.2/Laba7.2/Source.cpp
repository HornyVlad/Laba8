#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <limits.h>
#include <queue>
#include <iostream>
using namespace std;

void BFS(int* dist, int** a, int size, int num)
{
	queue <int> q;
	int i, v;
	q.push(num);
	dist[num] = 0;
	while (!q.empty())
	{
		num = q.front();
		q.pop();
		for (i = 0; i < size; i++)
		{
			if (dist[i] > dist[num] + a[num][i] && a[num][i] != 0)
			{
				q.push(i);
				dist[i] = dist[num] + a[num][i];
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int i, j, size, ** a, * dist, ran, num, type, type2;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	for (i = 0; i < argc; i++) cout << argv[i] << endl;
	size = atoi(argv[1]);
	type = atoi(argv[2]);
	type2 = atoi(argv[3]);
	num = atoi(argv[3]);
	printf("Матрица смежности:\n");
	a = (int**)malloc(size * sizeof(int));
	dist = (int*)malloc(size * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		dist[i] = INT_MAX;
	}
	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = 0;
		}
	}

	switch (type)
	{
	case 1:
		for (i = 0; i < size; i++)
		{
			for (j = 1 + i; j < size; j++)
			{
				ran = rand() % 101;
				if (ran > 40) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				a[j][i] = a[i][j];
			}
		}
		break;
	case 2:
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				ran = rand() % 101;
				if (ran > 40) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		for (i = 0; i < size; i++)
		{
			j = i;
			a[i][j] = 0;
		}
	}
	switch (type2)
	{
	case 1:
	{
		switch (type)
		{
		case 1:
			for (i = 0; i < size; i++)
			{
				for (j = 1 + i; j < size; j++)
				{
					if (a[i][j] == 1) a[i][j] = rand() % 8;
				}
			}
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{
					a[j][i] = a[i][j];
				}
			}
			break;
		case 2:
			for (i = 0; i < size; i++)
			{
				for (j = 1 + i; j < size; j++)
				{
					if (a[i][j] == 1) a[i][j] = rand() % 8;
				}
			}
		}
		break;
	case 2:
	break;
	}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	BFS(dist, a, size, num);
	printf("\nРасстояния до вершин: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", dist[i]);
	}
}