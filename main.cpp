#include "data_struct.h"

#include "map_to_path.cpp"
#include "diary_system.cpp"

int signin();

//用户注销，删除用户以及用户相关数据
int remove()
{

}

//登录用户，调取用户数据
int login()
{
    cout<<"是否未注册账号？（输入2注册账号）"<<endl;
    int x;cin>>x;
    if(x==2)
        signin();

    std::string name;
    std::string password;
    cout<<"昵称：";cin>>name;
    cout<<"密码：";cin>>password;

    static std::ifstream UserFile; // 创建一个输出文件流对象
    UserFile.open(name+".txt"); // 打开一个名为 "example.txt" 的文件，如果不存在则创建，如果存在则清空内容

    if (!UserFile) { // 检查文件是否成功打开
        std::cerr << "无法打开用户文件!" << std::endl;
        return 1; // 返回错误码
    }


    return 0;
}

//登出用户，释放处理用户数据
int logout()
{

}

//用户注册，创建用户数据
int signin()
{
    cout<<"是否已注册账号？（输入1登录账号）"<<endl;
    int x;cin>>x;
    if(x==1)
        login();

    std::string name;
    std::string password;
    std::string correct;
    std::string email;

    cout<<"昵称：";cin>>name;
    cout<<"密码：";cin>>password;
    cout<<"再次确认密码：";cin>>correct;
    cout<<"邮箱：";cin>>email;
    while(password!=correct)
    {
        cout<<"注册失败！请重新注册。"<<endl;
        cout<<"昵称：";cin>>name;
        cout<<"密码：";cin>>password;
        cout<<"再次确认密码：";cin>>correct;
        cout<<"邮箱：";cin>>email;
    }
    std::ofstream outFile; // 创建一个输出文件流对象
    outFile.open(name+".txt"); // 打开一个名为 "example.txt" 的文件，如果不存在则创建，如果存在则清空内容

    if (!outFile) { // 检查文件是否成功打开
        std::cerr << "无法打开文件!" << std::endl;
        return 1; // 返回错误码
    }

    // 写入数据到文件
    outFile << password<<endl;
    outFile << email<<endl;

    // 关闭文件
    outFile.close();

    return 0;
}

//首页控制
int Home()
{
    cout<<"欢迎来到Tourist游学系统，您将在这里完成一趟完美的游学旅程。"<<endl;
    cout<<"请选择操作模式：\n1. 登录模式\n2. 注册模式"<<endl;
    int x;cin>>x;

    switch (x)
    {
    case 1:
        login();
        break;
    
    case 2:
        {signin();cout<<"注册完毕，请登录。";login();}
        break;

    default:
        login();
        break;
    }
    
    return x;
}

int main()
{
//用户登录以及初始操作
    Home();

//选景部分
    /*此处写选择景点的函数*/



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