#include <stdio.h>
#include <stdlib.h>
int graph[7][7];
int point_DFSed[7];
int array_store_BFSed[7] = {-1, -1, -1, -1, -1, -1, -1};
int BFS_count;
int queue_count;
void funtion_clear_BFS()
{
    for (int i = 0; i < 7; i++)
    {
        array_store_BFSed[i] = -1;
    }
    BFS_count = 0;
    queue_count = 0;
}
void function_print_graph()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void function_creat_graph()
{
    printf("input the start point(0-6):\n");
    int start_point;
    scanf("%d", &start_point);
    printf("input the end point(0-6):\n");
    getchar();
    int end_number;
    scanf("%d", &end_number);
    getchar();
    graph[start_point][end_number] = 1;
}
void funcion_DFS(int point)
{
    printf("%d", point);
    point_DFSed[point] = 1;
    for (int i = 0; i < 7; i++) //try every possible point
    {
        if (i == point)
        {
            continue;
        }
        if (point_DFSed[i] == 0 && graph[point][i] != 0)
        {
            point_DFSed[i] = 1;
            funcion_DFS(i);
        }
    }
}
void function_clear_DFSed()
{
    for (int i = 0; i < 7; i++)
    {
        point_DFSed[i] = 0;
    }
}

void function_BFS(int start_point)
{
    if (BFS_count > 6)
    {
        return;
    }
    {
        int flag = 0;
        for (int j = 0; j < 7; j++)
        {
            if (array_store_BFSed[j] == start_point)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            array_store_BFSed[BFS_count++] = start_point;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (graph[start_point][i] != 0)
        {
            int flag = 0;
            for (int j = 0; j < 7; j++)
            {
                if (array_store_BFSed[j] == i)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                array_store_BFSed[BFS_count++] = i;
            }
        }
    }
    if (BFS_count < 7)
    {
        function_BFS(array_store_BFSed[++queue_count]);
    }
}
void function_auto()
{
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[0][3] = 1;
    graph[3][0] = 1;

    graph[1][4] = 1;
    graph[4][1] = 1;

    graph[1][5] = 1;
    graph[5][1] = 1;

    graph[1][6] = 1;
    graph[6][1] = 1;

    graph[2][6] = 1;
    graph[6][2] = 1;

    graph[4][5] = 1;
    graph[5][4] = 1;
}
int main()
{
    int option;
    while (option != 4)
    {
        system("clear");
        printf("BFS and DFS\n");
        printf("you have four options:\n");
        printf("1.creat a graph\n");
        printf("2.DFS\n");
        printf("3.BFS\n");
        printf("4.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("creat a 7*7 graph\n");
            //??????????????????????????????????????????
            function_auto(); //????????????????????????????????????,?????????????????????
            // function_creat_graph();
            printf("press to continue\n");
            getchar();
            break;

        case 2:
            printf("enter a number to start 0-6\n");
            int a;
            scanf("%d", &a);
            getchar();
            function_clear_DFSed();
            funcion_DFS(a);
            printf("\npress to continue\n");
            getchar();
            break;
        case 3:
            printf("enter a number to start 0-6\n");
            int b;
            scanf("%d", &b);
            getchar();
            funtion_clear_BFS();
            function_BFS(b);
            for (int i = 0; i < 7; i++)
            {
                printf("%d", array_store_BFSed[i]);
            }

            printf("\npress to continue\n");
            getchar();
            break;
        case 4:
            option = 4;
            break;
        }
    }

    return 0;
}