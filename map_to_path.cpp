#include "data_struct.h"

int init_map(const std::string filePath,std::vector<buiding> &node,Matrix &graph)
{
    std::ifstream file(filePath);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        exit(1);
    }

    std::string line;
    node.push_back({0});
    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        //读取结点
        if(line.length() <= MAX_NODE_CODE)
        {
            int index_x;
            int index_y;
            int tp;
            std::string nm;
            iss >> index_x >> index_y >> tp>>nm;

            node.push_back({index_x,index_y,tp,nm});
        }
        //读取边
        if(line.length()>=MIN_EDGE_CODE)
        {
            int x;
            int y;
            int node1;
            int node2;
            int buiding_code;
            int length;
            int ratio;
            int size;
            

            iss>> x >> y >> buiding_code >>length >> ratio >>size;
            graph[x][y].road_code=buiding_code;
            graph[x][y].distance=length;
            graph[x][y].crowding=ratio;

            for(int i=1;i<=size;i++)
            {
                float v;
                iss>>v;
                graph[x][y].velocity.push_back(v);
            }

        }
    }

    // 关闭文件
    file.close();
    return 0;
}

// BFS 查找路径函数
/* std::vector<int> bfsPath(const Matrix& graph, int start, int end) {
    std::queue<int> q;
    std::vector<bool> visited(N, false);
    std::unordered_map<int, int> parent;  // 存储路径
    std::vector<int> path;

    // 初始化
    q.push(start);
    visited[start] = true;
    parent[start] = -1;  // 起始节点没有父节点

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 如果到达终点
        if (current == end) {
            // 回溯构造路径
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        // 遍历所有相邻节点
        for (int i = 0; i < N; ++i) {
            if (graph[current][i] && !visited[i]) {  // 检查是否有边且未被访问
                visited[i] = true;
                q.push(i);
                parent[i] = current;
            }
        }
    }

    return path; // 如果找不到路径则返回空
}
 */
Walk bfs(const std::vector<buiding> buiding_data,Matrix graph,int start,int end)
{
    Walk path;
    std::queue<int> q;
    std::vector<bool> visited(MAX_NODE_CODE, false);
    std::unordered_map<int, int> parent;
    
    // 初始化
    q.push(start);
    visited[start] = true;
    parent[start] = -1;  // 起始节点没有父节点

    path.push_back(buiding_data[start]);
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 如果到达终点
        if (current == end) {
            // 回溯构造路径
            while (current != -1) {
                path.push_back(buiding_data[current]);
                current = parent[current];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        // 遍历所有相邻节点
        for (int i = 0; i < MAX_NODE_CODE; ++i) {
            if ((!graph[current][i].empty()) && !visited[i]) {  // 检查是否有边且未被访问
                visited[i] = true;
                q.push(i);
                parent[i] = current;
            }
        }
    }
    path.push_back(buiding_data[end]);
    
    return path;
}

Walk generate_path(const std::vector<buiding> buiding_data,const Matrix graph)
{

    //选择控制
    std::cout<<"下面是图中所有游览地点"<<std::endl;
    for (buiding x : buiding_data) 
    {
        if(x.type==1)
            std::cout << x.name << "\n";
    }
    std::cout<<"请选择您要游览的起始点和终点"<<std::endl;
    std::string start;
    std::string end;
    int num_s=0;
    int num_e=0;
    std::cin>>start>>end;

    //遍历确认选择结点行数
    int i=0;
    for(auto x : buiding_data)
    {
        if(x.name==start)
            num_s=i;
        if(x.name==end)
            num_e=i;
        i++;
    }

    std::cout<<"您要游览的起点为"<<start<<" "<<"终点为"<<end<<std::endl;
    std::cout<<"正在为您生成游览路线..."<<std::endl;
  
    //查参数选址
    auto path=bfs(buiding_data,graph,num_s,num_e);

    return path;
}

int print_path(const std::vector<buiding> buiding_data,const Matrix graph,const Walk path)
{
    //打印路径
    std::cout<<"生成路径如下：";
    for (auto node : path) {
        std::cout << node.name << "->";
    }
    std::cout << std::endl;

    return 0;
}

int main()
{

    std::string filePath = "data.txt";
    std::vector<buiding> buiding_data;//每一个结点的数据
    Matrix graph={0};

    init_map(filePath,buiding_data,graph);
    auto path = generate_path(buiding_data,graph);
     if (!path.empty()) {
        print_path(buiding_data,graph,path);
    } else {
        std::cout << "No path found."<< std::endl;
    }

    return 0;


}