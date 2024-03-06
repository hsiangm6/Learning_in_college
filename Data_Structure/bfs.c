#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000  // 節點數的最大值

// 結構體，表示一個圖中的節點
struct node {
    int val;  // 節點的值
    struct edge *edges;  // 指向相鄰邊的指針
    bool visited;  // 該節點是否已被訪問
};

// 結構體，表示一個圖中的邊
struct edge {
    int to;  // 邊指向的節點
    struct edge *next;  // 指向下一條邊的指針
};

// 創建一個節點，返回節點的指針
struct node *create_node(int val) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->edges = NULL;
    node->visited = false;
    return node;
}

// 創建一條邊，返回邊的指針
struct edge *create_edge(int to) {
    struct edge *edge = (struct edge *)malloc(sizeof(struct edge));
    edge->to = to;
    edge->next = NULL;
    return edge;
}

// 向無向圖中添加一條邊
void add_edge(struct node *nodes[], int from, int to) {
    // 添加一條邊，需要從from節點出發，指向to節點
    struct edge *edge1 = create_edge(to);
    edge1->next = nodes[from]->edges;
    nodes[from]->edges = edge1;

    // 然後再添加一條邊，從to節點出發，指向from節點
    struct edge *edge2 = create_edge(from);
    edge2->next = nodes[to]->edges;
    nodes[to]->edges = edge2;
}

// BFS算法實現
void bfs(struct node *nodes[], int n, int start) {
    int queue[MAX_N];  // 用陣列實現隊列，保存每個節點的編號
    int head = 0, tail = 0;  // head指向隊列頭，tail指向隊列尾
    queue[tail++] = start;  // 先把起始節點入隊
    nodes[start]->visited = true;  // 設置起始節點為已訪問

    while (head < tail) {  // 當隊列不為空時
        int curr = queue[head++];  // 取出隊列頭節點
        printf("%d ", nodes[curr]->val);  //
        // 遍歷該節點的所有相鄰節點
    struct edge *edge = nodes[curr]->edges;
    while (edge) {
        int next = edge->to;
        if (!nodes[next]->visited) {  // 如果相鄰節點還沒有被訪問過
            nodes[next]->visited = true;  // 設置為已訪問
            queue[tail++] = next;  // 入隊
        }
        edge = edge->next;  // 遍歷下一條邊
    }
}
}

// 主函數
int main() {
    int n = 5, m = 6; // 節點數和邊數
    struct node *nodes[5]; // 創建n個節點
    for (int i = 0; i < n; i++) {
        nodes[i] = create_node(i);
    }
    // 添加m條邊
    add_edge(nodes, 0, 1);
    add_edge(nodes, 0, 2);
    add_edge(nodes, 1, 3);
    add_edge(nodes, 1, 4);
    add_edge(nodes, 2, 4);
    add_edge(nodes, 3, 4);

    // 從節點0開始遍歷整個圖
    bfs(nodes, n, 0);

    return 0;
}

// 這個程式首先定義了兩個結構體，`node`表示圖中的一個節點，`edge`表示一條邊。然後定義了`create_node`和`create_edge`函數用於
//      創建節點和邊，`add_edge`函數用於向圖中添加一條無向邊。最後定義了`bfs`函數實現BFS算法。

// 在`bfs`函數中，我們首先創建一個隊列，並把起始節點入隊，然後進入一個while循環，該循環的條件是隊列不為空。
//      每次從隊列頭取出一個節點，然後遍歷該節點的所有相鄰節點，如果相鄰節點還沒有被訪問過，就把它入隊並設置為已訪問。重複這個過程，直到隊列為空為止。

// 在主函數中，我們首先創建了n個節點，然後向圖中添加m條邊。最後從節點0開始遍歷整個圖。
