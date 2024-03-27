#pragma once
#include<string>
#include<vector>
#include<unordered_map>

std::unordered_map<std::string,float> list;//辅助查询

typedef struct node
{
    struct location
    {
        int x;
        int y;
        /* float x;
        float y; */
    };

    int type;
    //std::string type;
}buiding;

typedef struct edge
{
    int num;
    int distance;
    float crowding;
    std::vector<float> velocity;
    /* std::string name;
    float distance;
    float crowding;
    std::vector<float> velocity;速度，可用list辅助查询 
    */
}road;

void List()
{
    list["步行"]=100.0;
    list["自行车"]=200.0;
    list["汽车"]=400.0;
    list["船"]=200.0;
};
