#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 文件路径
    std::string filePath = "data.txt";
    
    // 创建一个输入文件流对象
    std::ifstream file(filePath);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    std::string line;
    // 使用std::getline从文件中读取一行，直到文件结束
    while (std::getline(file, line)) {
        // 输出读取的行
        std::cout << line << std::endl;
    }

    // 关闭文件
    file.close();

    return 0;
}
