#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main()
{
int a,b,**arr,*arr2,i,j,n,m;
setlocale(LC_ALL,"RUS");
printf("1-Считаем, что двумерный массив размера m на n преобразуется в одномерный массив размера m* n\nпутем последовательной записи строк. (m и n заданы) \nРеализовать такое преобразование «туда» и «обратно».\n");
printf("2-Заполнить двумерный массив размером n x m так по примеру\n");
printf("|Для выхода введите 0|\n\n");
int p=-1;
while (p!=0)
{
    printf("Выберите задание:");
    scanf("%d",&p);
    switch(p)
    {
    case 1:
        printf("Введите число строк:\n\t");
        scanf("%d",&a);
        printf("Введите число столбцов:\n\t");
        scanf("%d",&b);
        arr = (int**)malloc(a * sizeof(int*));
        for (i = 0; i < a; i++)
		{
			arr[i] = (int*)malloc(b * sizeof(int));
		}

		printf("Введите элементы массива\n");
        for (i = 0; i < a; i++)
        {
			for (j = 0; j < b; j++)
			{
			    printf("\t");
				scanf("%d", &arr[i][j]);
			}
		}
		printf("Начальный массив:");
        for (i = 0; i < a; i++ )
        {
			printf("\n");
			for (j = 0; j < b; j++)
            {
				printf("%d\t ", arr[i][j]);
			}
		}
		printf("\n");

		arr2 = (int*)malloc((a * b) * sizeof(int));
		for ( i = 0; i < a; i ++ )
        {
            {
                for ( j = 0; j < b; j ++ )
                {
                    arr2[i*b+j] = arr[i][j];
                }
            }
		}
		printf("\nОтвет a[i][j]->b[i*j]:\n");

		for (i = 0; i < a * b; i++)
        {
			printf("%d\t", arr2[i]);
		}
		printf("\n");

		for (i = 0; i < a; i++)
        {
			for (j = 0; j < b; j++)
            {
				arr[i][j] = 0;

			}
		}
		printf("\n");
		printf("Ответ b[i*j]->a[i][j]:");
		for (i = 0; i < a * b; i++){
			arr[i / b][i % b] = arr2[i];

		}

		for (i = 0; i < a; i++)
        {
			printf("\n");
				for (j = 0; j < b; j++)
				{
					printf("%d\t", arr[i][j]);
				}
		}
		printf("\n\n");
        break;
    case 2:

	printf("Введите размер:\n");
	scanf("%d %d", &n, &m);

	int** mas;
	mas = (int**)malloc(n * sizeof(int*));
	for (int q = 0; q < n; q++) {
		mas[q] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < m; j++)
        {
			mas[i][j] = j + 1 - i;
			if (mas[i][j] <= 0)
            {
				mas[i][j] = 2 - mas[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
    {
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
			mas[i][j] = 0;
		}
	}
	printf("\n\n");


	int sum = 1;

	if (n % 2 == 1 && m % 2 == 1) {
		mas[n / 2][m / 2] = n * m;

	}

	int krug;
	if (n > m) {
		krug = n / 2;
	}
	else{
		krug = m / 2;
	}
	for (int i = 0; i < krug; i++) {
		for (int j = i; j < (m - i); j++) {
			mas[i][j] = sum;
			sum++;
		}
		for (int j = 1; j < (n - i - i); j++) {
			mas[(j + i)][m- i -1] = sum;
			sum++;
		}
		for (int j = m-2 - i; j >= i; j--) {
			mas[n - i - 1][(j)] = sum;
			sum++;
		}
		for (int j = ((n - i) - 2); j > i; j--) {
			mas[j][i] = sum;
			sum++;
		}
	}


	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
		}
	}
	printf("\n");
	break;

		}
	}






return 0;
}

