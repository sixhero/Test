#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<string> DigitalTwin = {"零","一","二","三","四","五","六","七","八","九"};
const vector<string> NumRank = {"","十","百","千","万"};

string SmallToBigNum(int index)
{
    string bigNum;
    string numStr = to_string(index);
    for (int i = 0; i < numStr.length(); i++)
    {
        if(numStr.at(i) == '0')
        {
            if(i+1>=numStr.length())
            {
                continue;
            }
            else
            {
                if(numStr.at(i+1) == '0')
                {
                    continue;
                }
                else
                {
                    bigNum += DigitalTwin[numStr.at(i) - '0'];
                    continue;
                }
            }
        }
        bigNum += DigitalTwin[numStr.at(i) - '0'];
        bigNum += NumRank[numStr.length() -1 - i];
    }
    if(bigNum.find("一十") == 0)
    {
        bigNum = bigNum.substr(3);
    }

    return bigNum;
}

int main(int argc,char ** argv)
{
    cout<<SmallToBigNum(atoi(argv[1]));
    return 0;
}