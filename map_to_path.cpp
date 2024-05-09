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

//后续修改寻路算法
bool dfs(const std::vector<buiding> buiding_data, Matrix graph, int current, int destination, Walk& path, std::vector<bool>& visited) {
    // 将当前节点标记为已访问
    visited[current] = true;
    path.push_back(buiding_data[current]);

    // 检查当前节点是否是目的地
    if (current == destination) {
        return true;
    }

    // 遍历所有可能的连接节点
    for (int i = 0; i < MAX_NODE_CODE; ++i) {
        if (!graph[current][i].empty() && !visited[i]) {  // 检查边的存在并且节点未被访问
            if (dfs(buiding_data,graph, i, destination, path, visited)) {
                return true;
            }
        }
    }

    // 如果从当前节点开始没有找到路径，则回溯
    path.pop_back();
    visited[current] = false;
    return false;
}

Walk generate_path(const std::vector<buiding> buiding_data,Matrix graph)
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
    Walk path;
    std::vector<bool> visited(MAX_NODE_CODE, false);
    dfs(buiding_data,graph,num_s,num_e,path,visited);

    return path;
}

int print_path(const std::vector<buiding> buiding_data,const Matrix graph,const Walk path)
{
    //打印路径
    std::cout<<"生成路径如下：";
    for (auto node : path) {
        std::cout << node.name << " ";
    }
    std::cout << std::endl;

    return 0;
}