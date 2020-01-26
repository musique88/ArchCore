#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   
    ifstream powerNow("/sys/class/power_supply/BAT0/charge_now"); 
    ifstream powerMax("/sys/class/power_supply/BAT0/charge_full");
    ifstream powerStatus("/sys/class/power_supply/BAT0/status");
        
    string powerNowS;
    string powerMaxS;
    string powerStatusS;
    
    getline(powerNow, powerNowS);
    getline(powerMax, powerMaxS);
    getline(powerStatus,powerStatusS);
    
    cout << powerNowS << " / " << powerMaxS << " ( " << 
    to_string((stof(powerNowS) / stof(powerMaxS)) * 100).substr(0,2) << 
    "\% ) : " << powerStatusS << endl;
    
    return 0;
}