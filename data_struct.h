#pragma once
#include<string>
#include<vector>
#include<list>
#include<unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<array>
#include<queue>
#include<algorithm>


#define MAX_NODE_CODE 10
#define MIN_EDGE_CODE 19
const int MAX_ROWS = MAX_NODE_CODE+1;
const int MAX_COLS = MAX_NODE_CODE+1;

typedef struct node
{
    
    int x;
    int y;
    /* float x;
    float y; */
    int type;
    std::string name;


}buiding;

typedef struct edge
{
    int road_code;
    int distance;
    float crowding;
    std::vector<float> velocity;
    /* std::string name;
    float distance;
    float crowding;
    std::vector<float> velocity;速度，可用list辅助查询 
    */


   int empty()
   {
        if(road_code==0)
            return 1;
        else
            return 0;
   }

}road;

using namespace std;
using Matrix = std::array<std::array<road,MAX_COLS>,MAX_ROWS>;
using Walk = std::vector<buiding>;




/* std::unordered_map<std::string,float> list;//辅助查询
void List()
{
    list["步行"]=100.0;
    list["自行车"]=200.0;
    list["汽车"]=400.0;
    list["船"]=200.0;
}; */
