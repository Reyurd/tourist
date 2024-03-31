#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "data_struct.h"

int init_map(const std::string filePath,std::vector<buiding> &node,std::vector<std::vector<road>> &graph)
{
    std::ifstream file(filePath);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        exit(1);
    }

    std::string line;
    
    while (std::getline(file, line)) 
    {

        //读取结点

        //读取边
        
    }



    // 关闭文件
    file.close();

}

std::vector<std::pair<int,int>> generate_path(const std::vector<buiding> buiding_data,const std::vector<std::vector<road>> graph)
{
    //选择控制

    //查参数选址

}

int print_path(const std::vector<buiding> buiding_data,const std::vector<std::vector<road>> graph,const std::vector<std::pair<int,int>> path)
{
    //根据路径查找
}

int main()
{

    std::string filePath = "data.txt";
    std::vector<buiding> buiding_data;//每一个结点的数据
    std::vector<std::vector<road>> graph;

    init_map(filePath,buiding_data,graph);
    std::vector<std::pair<int,int>> path = generate_path(buiding_data,graph);
    print_path(buiding_data,graph,path);

    return 0;


}