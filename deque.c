#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>  
#define MAZE_SIZE 100
#define MAX_DEQUE_SIZE 100
struct Node
{
    int x;
    int y;
};
int Distance(struct Node pos, struct Node endPos)
{
    int dif_x = abs(endPos.x - pos.x);
    int dif_y = abs(endPos.y - pos.y);
    return dif_x + dif_y;
}
int IsEmpty(int front, int rear)
{
    if( front == -1)
                return 1;
        else
                return 0;
}

int IsFull(int front, int rear)
{
    if ( (front==0 && rear==MAX_DEQUE_SIZE-1) || (front==rear+1) )
                return 1;
        else
                return 0;
}

void add_First(struct Node x, struct Node deque[], int *front, int *rear)
{
    if (IsFull(*front, *rear))
    {
        printf("Overflow\n");
    }
    else
    {
        if (IsEmpty(*front, *rear))
        {
            *front = *rear = 0;
        }
        else if (*front == 0)
        {
            *front = MAX_DEQUE_SIZE - 1;
        }
        else
        {
            (*front)--;
        }
        deque[*front] = x;
    }
}

void add_last(struct Node item, struct Node deque[], int *front, int *rear)
{
    if (IsFull(*front, *rear))
    {
        printf("Overflow\n");
    }
    else
    {
        if (IsEmpty(*front, *rear))
        {
            *front = *rear = 0;
        }
        else if (*rear == MAX_DEQUE_SIZE - 1)
        {
            *rear = 0;
        }
        else
        {
            (*rear)++;
        }
        deque[*rear] = item;
    }
}

void remove_first(int *front, int *rear)
{
    if (IsEmpty(*front, *rear))
    {
        printf("Underflow\n");
    }
    else
    {
        if (*front == MAX_DEQUE_SIZE - 1)
        {
            *front = 0;
        }
        else if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else
        {
            (*front)++;
        }
    }
}
int SolveMaze(char maze[MAZE_SIZE][MAZE_SIZE], struct Node start, struct Node end,
              struct Node deque[MAX_DEQUE_SIZE], int *front, int *rear)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int solved = 0;
    while (!IsEmpty(*front, *rear))
    {
        struct Node currentPos = deque[*front];
        if (maze[currentPos.x][currentPos.y] == ' ')
        {
            maze[currentPos.x][currentPos.y] = '.';
        }
        else if (maze[currentPos.x][currentPos.y] == 'E')
        {
            solved = 1;
            break;
        }
        remove_first(front, rear);
        int dist = Distance(currentPos, end);
        struct Node neighbour;
        for (int i = 0; i < 4; i++)
        {
            int newX = currentPos.x + dx[i];
            int newY = currentPos.y + dy[i];
            char element = maze[newX][newY];
            if (element == ' ' || element == 'E')
            {
                neighbour.x = newX;
                neighbour.y = newY;
                if (Distance(neighbour, end) < dist)
                {
                    add_First(neighbour, deque, front, rear);
                }
                else
                {
                    add_last(neighbour, deque, front, rear);
                }
            }
        }
    }
    return solved;
}
int main()
{
    struct Node deque[MAX_DEQUE_SIZE];
    struct Node start;
    struct Node end;
    int front = -1, rear = -1;
    char maze[MAZE_SIZE][MAZE_SIZE];
    char filename[10];
    
    printf("maze file name? ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    char ch;
    int m=0;
    int row = 0, col = 0;
    while (!feof(file))
    {
        ch = fgetc(file);
        if (ch == '\n')
        {
            row++;
            col = 0;
        }
        else
        {
            maze[row][col] = ch;
            if (ch == 'S')
            {
                start.x = row;
                start.y = col;
            }
            if (ch == 'E')
            {
                end.x = row;
                end.y = col;
            }
            col++;
            m=max(col,m);
            
        }
    }
    fclose(file);
    add_First(start, deque, &front, &rear);

    if (SolveMaze(maze, start, end, deque, &front, &rear) == 1)
    {
        printf("Here is your Solved Maze:\n");
        for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <=m-1; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    
    }
    else
    {
        printf("No path found:\n");
    }
    
}
