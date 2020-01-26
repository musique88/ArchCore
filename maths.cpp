#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    float value = 0.0f;
    
    if(!strcmp(argv[1],"add"))
        value = stof(argv[2]) + stof(argv[3]);
    else if(!strcmp(argv[1], "sub"))
        value = stof(argv[2]) - stof(argv[3]);
    else if(!strcmp(argv[1], "mul"))    
        value = stof(argv[2]) * stof(argv[3]);
    else if(!strcmp(argv[1], "div"))    
        value = stof(argv[2]) / stof(argv[3]);
    else if(!strcmp(argv[1], "pow"))
    {
        value = stof(argv[2]);
        for(int i = 1; i < atoi(argv[3]); ++i)
            value *= stof(argv[2]);
    }
    cout << value << "\n";
    return 0;
}