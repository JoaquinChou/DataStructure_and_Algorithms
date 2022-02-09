#include <iostream>
#include <stack>
using namespace std;

template<class T>
class VertexNode;

template<class T>
class AOVGraph;

// 定义边表结点类
template<class T>
class EdgeNode {
friend class AOVGraph<T>;
private:
    // 1) 存储该顶点的下标
    int adjvex;
    // 2) 网图的权重
    int weight;
    // 3) 指向下一个邻接点
    EdgeNode *next;
};


// 定义顶点表结点类
template<class T>
class VertexNode {
friend class AOVGraph<T>;
private:
    // 1) 顶点入度
    int indegree;
    // 2) 顶点数据
    T data;
    // 3) 边表头指针
    EdgeNode<T> *first_edge;
};


template<class T>
class AOVGraph {
private:
    VertexNode<T> *adjList;
    // 当前的顶点数和边数
    int vertex_num;
    int edge_num;
    void createAOVGraph(VertexNode<T>* &adjList, T vertexes[], T edges[][2], int vertex_num, int edge_num);
    int getPosition(T vertexes[], T element, int vertex_num);
    void printAOVGraph(VertexNode<T>* adjList, int vertex_num);
    bool topologicalSort(VertexNode<T>* adjList, int vertex_num);

public:
    AOVGraph() {
        this->adjList = NULL;
    }
    void createAOVGraph(T vertexes[], T edges[][2], int vetexes_len, int edges_len) {
        return createAOVGraph(this->adjList, vertexes, edges, vetexes_len, edges_len);
    }
    void printAOVGraph() {
        return printAOVGraph(this->adjList, this->vertex_num);
    }
    bool topologicalSort() {
        return topologicalSort(this->adjList, this->vertex_num);
    } 

};

template<class T>
int AOVGraph<T>::getPosition(T vertexes[], T element, int vertex_num) {
        for(int i = 0; i < vertex_num; i++)
            if(vertexes[i] == element)
                return i;
        return -1;
    }


template<typename T>
void AOVGraph<T>::createAOVGraph(VertexNode<T>* &adjList, T vertexes[], T edges[][2], int vertex_num, int edge_num) {
    this->vertex_num = vertex_num;
    this->edge_num = edge_num;

    adjList = new VertexNode<T>[this->vertex_num];
    for (int i = 0; i < this->vertex_num; i++) {
        adjList[i].data = vertexes[i];
        adjList[i].first_edge = NULL;
        // 初始化每个入度都为0
        adjList[i].indegree = 0;
    }

    for (int k = 0; k <  this->edge_num; k++) {
        T v_i = edges[k][0];
        T v_j = edges[k][1];
        // 输入边(v_i, v_j)的顶点在数组中的序号
        int i = getPosition(vertexes, v_i,  this->vertex_num);
        int j = getPosition(vertexes, v_j,  this->vertex_num);

        // 生成边表结点
       EdgeNode<T> *edge_node = new EdgeNode<T>();
       edge_node->adjvex = j;
    //    入度数目增加1
       adjList[j].indegree++;
       edge_node->next = adjList[i].first_edge;
       adjList[i].first_edge = edge_node;
    }
}

template<typename T>
void AOVGraph<T>::printAOVGraph(VertexNode<T>* adjList, int vertex_num) {
    if (adjList == NULL)    cout << "输入图为空" << endl;
    else {

        EdgeNode<T> *edge_node;
        for (int i = 0; i < vertex_num; i++) {
            edge_node = adjList[i].first_edge;
            // cout << adjList[i].data << "的入度为" << adjList[i].indegree << "  ";
            //  printf("V%d", i);
            //  cout << adjList[i].data;
            while(edge_node != NULL) {
                // printf(" ->V%d(权:%d)",edge_node->adjvex, edge_node->weight);
                // cout << "->" << adjList[edge_node->adjvex].data;
                edge_node = edge_node->next;
            }
            cout << endl;
    }

    }
}

template<typename T>
bool AOVGraph<T>::topologicalSort(VertexNode<T>* adjList, int vertex_num) {
    EdgeNode<T> *edge_node;
    int ouput_cnt = 0;
    int get_top;
    stack<int> s;

    for (int i = 0; i < vertex_num; i++) {
        if (adjList[i].indegree == 0) {
            // 将入度为0的顶点入栈
            s.push(i);
        }
    }

    cout << "入度为0的顶点依次输出为" << endl;
    while (!s.empty()) {
        get_top = s.top();
        s.pop();
        // 打印入度为0的顶点
        cout << "->" << adjList[get_top].data;
        ouput_cnt++;
        for (edge_node = adjList[get_top].first_edge; edge_node; edge_node = edge_node->next) {
            // 将某个入度和删除顶点有关系的顶点入度-1
                int k = edge_node->adjvex;
                --adjList[k].indegree;
                if (adjList[k].indegree == 0) {
                    s.push(k);
                }
        }
    }

    cout << endl;
    // 小于顶点数，说明存在环
    if (ouput_cnt < vertex_num)   return false;
    return true;
}

void char_test(){
    AOVGraph<char> DGraph;
    char vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
            {'A', 'B'}, 
            {'B', 'C'}, 
            {'B', 'E'}, 
            {'B', 'F'}, 
            {'C', 'E'}, 
            {'D', 'C'}, 
            {'E', 'B'}, 
            {'E', 'D'}, 
            {'F', 'G'}}; 
    int vetexes_len = sizeof(vertexes) / sizeof(vertexes[0]);
    int edges_len = sizeof(edges) / sizeof(edges[0]);

    DGraph.createAOVGraph(vertexes, edges, vetexes_len, edges_len);
    DGraph.printAOVGraph();
    bool res = DGraph.topologicalSort();
      if (res) {
        cout << "路径不存在环路" << endl;
    }
    else {
        cout << "路径存在环路" << endl;
    }
}

void int_test() {
    AOVGraph<int> DGraph;
    int vertexes[] = {1, 2, 3, 4};
    int edges[][2] = {
        {2, 3},
        {1, 2},
        // {4, 2},
        {3, 4},
    };

    int vetexes_len = sizeof(vertexes) / sizeof(vertexes[0]);
    int edges_len = sizeof(edges) / sizeof(edges[0]);

    DGraph.createAOVGraph(vertexes, edges, vetexes_len, edges_len);
    DGraph.printAOVGraph();
    bool res = DGraph.topologicalSort();
    if (res) {
        cout << "路径不存在环路" << endl;
    }
    else {
        cout << "路径存在环路" << endl;
    }
}


int main() {

    char_test();
    int_test();
    return 0;
}