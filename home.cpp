#include"data_struct.h"

int signin();

//用户注销，删除用户以及用户相关数据
int remove()
{

}

//登录用户，调取用户数据
std::string login()
{
    cout<<"是否未注册账号？（输入2注册账号）"<<endl;
    int x;cin>>x;
    if(x==2)
        signin();

    static std::string current_name;
    std::string password;
    cout<<"昵称：";cin>>current_name;
    cout<<"密码：";cin>>password;

    std::string filename = current_name+".txt";
    fs::path filePath = fs::current_path()/filename;
    if(fs::exists(filePath))
    {   
        std::ifstream user_file(filePath);

        if (!user_file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        exit(1);
        }
        
        std::string line;
        std::istringstream iss(line);
        std::getline(user_file, line);
        if(line==password)
            cout<<"登录成功!"<<endl;
        else
        {
            cout<<"密码错误，请重新登录。"<<endl;
            exit(1);
        }
        
   

    }
    else
    {
        cout<<"用户不存在"<<endl;
    }

    return current_name;
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
std::string Home()
{
    cout<<"欢迎来到Tourist游学系统，您将在这里完成一趟完美的游学旅程。"<<endl;
    cout<<"请选择操作模式：\n1. 登录模式\n2. 注册模式"<<endl;
    int x;cin>>x;
    std::string name;
    switch (x)
    {
    case 1:
        name=login();
        break;
    
    case 2:
        {signin();cout<<"注册完毕，请登录。"<<endl;name=login();}
        break;

    default:
        name=login();
        break;
    }
    
    return name;
}
