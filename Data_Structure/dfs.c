#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 節點結構體
struct node {
    int vertex;            // 節點值
    struct node* next;     // 下一個節點指針
};

// 圖形結構體
struct Graph {
    int numVertices;                       // 節點數量
    struct node* adjLists[MAX_VERTICES];   // 鄰接表陣列
    bool visited[MAX_VERTICES];            // 訪問標記陣列
};

// 創建新節點
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // 分配節點內存
    newNode->vertex = v;                                              // 設置節點值
    newNode->next = NULL;                                             // 初始化下一個節點指針
    return newNode;
}

// 創建新圖形
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // 分配圖形內存
    graph->numVertices = vertices;                                     // 設置節點數量
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;                                     // 初始化鄰接表
        graph->visited[i] = false;                                     // 初始化訪問標記陣列
    }
    return graph;
}

// 添加無向邊
void addEdge(struct Graph* graph, int src, int dest) { // 指向 Graph 結構的指針 graph，以及兩個整數 src 和 dest，分別表示邊的起點和終點
    struct node* newNode = createNode(dest);                    // 創建新節點，設置節點值為目標節點
    newNode->next = graph->adjLists[src];                       // 將新節點插入源節點的鄰接表中
    graph->adjLists[src] = newNode;
    newNode = createNode(src);                                  // 創建新節點，設置節點值為源節點
    newNode->next = graph->adjLists[dest];                      // 將新節點插入目標節點的鄰接表中
    graph->adjLists[dest] = newNode;
}

// 使用 DFS 遍歷圖形
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = true;                                 // 設置當前節點訪問標記為 true
    printf("Visited vertex: %d\n", vertex);                        // 輸出訪問的節點值
    struct node* adjList = graph->adjLists[vertex];                // 取得當前節點的鄰接表
    while (adjList != NULL) { // 遍歷當前節點的所有相鄰節點
        int adjVertex = adjList->vertex;
        if (!graph->visited[adjVertex]) { // 如果相鄰節點未訪問，遞歸訪問之
            DFS(graph, adjVertex);
        }
        adjList = adjList->next; // 移動到下一個相鄰節點
    }
}

int main() {
    struct Graph* graph = createGraph(4); // 創建包含 4 個節點的圖形
    addEdge(graph, 0, 1); // 添加邊
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printf("DFS traversal starting from vertex 2:\n");
    DFS(graph, 2);  // 從節點 2 開始使用 DFS 遍歷圖形

    return 0;
}