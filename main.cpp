#include "data_struct.h"
#include"home.cpp"
#include "map_to_path.cpp"
#include "diary_system.cpp"

int main()
{
//用户登录以及初始操作
    std::string current_name=Home();

//选景部分
    /*此处写选择景点的函数*/
    cout<<current_name<<endl;


//导航部分
    //调整寻路算法并添加多点目标的算法以及不同路径策略的算法
    std::string filePath = "data.txt";
    std::vector<buiding> buiding_data;//每一个结点的数据
    Matrix graph={0};

    //生成路径
    init_map(filePath,buiding_data,graph);
    auto path = generate_path(buiding_data,graph);

    //打印路径
     if (!path.empty()) {
        print_path(buiding_data,graph,path);
    } else {
        std::cout << "No path found."<< std::endl;
    }

//场所查询



//日记系统



    return 0;


}