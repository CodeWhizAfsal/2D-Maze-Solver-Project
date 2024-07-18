#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 150 // row
#define MAX_COLS 150 // col

char maze[MAX_ROWS][MAX_COLS];

int startRow, startCol, endRow, endCol;

int rows = 0, cols = 0;

struct node {

  int dest;
  struct node *next;

};

struct AdjList {

  struct node *head;

};

struct Graph {

  int V;
  struct AdjList *array;

};

struct node *newnode(int dest) {

  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  newNode->dest = dest;
  newNode->next = NULL;

  return newNode;

}

struct Graph *createGraph(int V) {

  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

  for (int i = 0; i < V; i++) {
    graph->array[i].head = NULL;
  }

  return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {

  struct node *newNode = newnode(dest);

  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  newNode = newnode(src);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;

}

void printMaze() {

  printf("Maze:\n");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }

}

void readMazeFromFile(char *filename) {

  FILE *file;
  file = fopen(filename, "r");

  if (file == NULL) {

    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);

  }

  char ch;

  while ((ch = fgetc(file)) != EOF) {

    if (ch == '\n') {

      rows++;
      cols = 0;
    } 
    else {

      maze[rows][cols] = ch;
      if (ch == 'S') {

        startRow = rows;
        startCol = cols;

      } 
      else if (ch == 'E') {

        endRow = rows;
        endCol = cols;

      }

      cols++;

    }

  }

  rows++;
  fclose(file);

}

void breadthFirstSearch(struct Graph *graph, int startVertex) {

  int *queue = (int *)malloc(rows * cols * sizeof(int));
  int front = 0, rear = 0;

  queue[rear++] = startVertex;

  while (front != rear) {

    int currentVertex = queue[front++];
    int currentRow = currentVertex / cols;
    int currentCol = currentVertex % cols;

    if (currentRow == endRow && currentCol == endCol) {

      printf("Path found!\n");
      printMaze();
      free(queue);
      return;

    }

    struct node *temp = graph->array[currentVertex].head;

    while (temp) {

      int adjVertex = temp->dest;
      int adjRow = adjVertex / cols;
      int adjCol = adjVertex % cols;

      maze[adjRow][adjCol] = '.';

      temp = temp->next;

    }

  }

  printf("Path not found!\n");
  printMaze();
  free(queue);

}

int main() {

  char filename[100];
  printf("Enter the filename to open \n");
  scanf("%s", filename);

  readMazeFromFile(filename);

  struct Graph *graph = createGraph(rows * cols);

  for (int i = 0; i < rows; i++) {

    for (int j = 0; j < cols; j++) {

      if (maze[i][j] != '#') {

        if (i > 0 && maze[i - 1][j] != '#') {

          addEdge(graph, i * cols + j, (i - 1) * cols + j);

        }

        if (i < rows - 1 && maze[i + 1][j] != '#') {

          addEdge(graph, i * cols + j, (i + 1) * cols + j);

        }

        if (j > 0 && maze[i][j - 1] != '#') {

          addEdge(graph, i * cols + j, i * cols + (j - 1));

        }

        if (j < cols - 1 && maze[i][j + 1] != '#') {

          addEdge(graph, i * cols + j, i * cols + (j + 1));

        }

      }

    }
    
  }

  breadthFirstSearch(graph, startRow * cols + startCol);

  return 0;
}
