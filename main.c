#include <stdio.h>
#include <stdlib.h>

// Struktur untuk simpul dalam graf
struct Node {
    int id;
    struct Node* next;
};

// Struktur untuk daftar simpul yang terhubung ke simpul utama
struct AdjList {
    struct Node* head;
};

// Struktur untuk graf itu sendiri
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Fungsi untuk membuat simpul baru
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk membuat graf dengan jumlah simpul tertentu
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));

    for (int i = 0; i < vertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

// Fungsi untuk menambah tepi dalam graf
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Tambahkan kembali tepi dari dest ke src (graf tak berarah)
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Fungsi untuk mencetak graf
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* pCrawl = graph->array[v].head;
        printf("\n Vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->id);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Fungsi untuk membebaskan memori dari graf (menyebabkan memory leak)
void freeGraph(struct Graph* graph) {
    // Kesalahan: hanya membebaskan array simpul, tidak membebaskan setiap node
    free(graph->array);
    free(graph);
}

// Fungsi untuk membebaskan memori dari graf (dioptimalkan)
// void freeGraph(struct Graph* graph) {
//     for (int v = 0; v < graph->numVertices; v++) {
//         struct Node* temp = graph->array[v].head;
//         while (temp) {
//             struct Node* next = temp->next;
//             free(temp);
//             temp = next;
//         }
//     }
//     free(graph->array);
//     free(graph);
// }

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    // Memori tidak dibebaskan sepenuhnya di sini
    freeGraph(graph);

    return 0;
}
