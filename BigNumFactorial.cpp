#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string mutiple(string a, string b);
int stringElenmentToInteger(char c);
string resultprocessing(string* d);
bool isNotZero(string e);

int main()
{
    int a = 1;
    string Multiplicand = "1";
    cout<<mutiple(mutiple("39916810","12"),"13");
    return 0;
}

string mutiple(string a, string b)
{
    string FinalResult="";
    string result[2] = {""};
    if(b.length()<3)
    {
        int carryout = 0;
        int carryin = 0;
        for(int i = a.length()-1; i>-1; i--)
        {
            int buffer = 0;
            char cbuffer = '\0';
            buffer = stringElenmentToInteger(a[i])*stringElenmentToInteger(b[1]);
            if(buffer > 9)
            {
                carryout = buffer/10;
                buffer = buffer%10;
            }
            if(carryin+buffer<10)
            {
                //carryout = 0;
                cbuffer = carryin + buffer + '0';
            }
            else
            {
                carryout = carryout+1;
                cbuffer = (carryin + buffer -10)+'0';
            }
            carryin = carryout;
            carryout = 0;
            result[0] = cbuffer +result[0];
        }
        if(carryin != 0)
        {
            char overflow = carryin+'0';
            result[0] = overflow + result[0];
            carryin = 0;
        }
        //carryin = 0;
        for(int i = a.length()-1; i>-1; i--)
        {
            int buffer = 0;
            char cbuffer = '\0';
            buffer = stringElenmentToInteger(a[i])*stringElenmentToInteger(b[0]);
            if(buffer > 9)
            {
                carryout = buffer/10;
                buffer = buffer%10;
            }
            if(carryin+buffer<10)
            {
                //carryout = 0;
                cbuffer = carryin + buffer + '0';
            }
            else
            {
                carryout =  carryout+1;
                cbuffer = (carryin + buffer -10)+'0';
            }
            carryin = carryout;
            carryout = 0;
            result[1] = cbuffer +result[1];
        }
        if(carryin != 0)
        {
            char overflow = carryin+'0';
            result[1] = overflow + result[1];
            carryin = 0;
        }
        //carryin = 0;
        //cout << result[0] <<" " <<result[1]<<endl;
        return resultprocessing(result);
    }
}


int stringElenmentToInteger(char c)
{
    if(c=='0')
    {
        return 0;
    }
    if(c=='1')
    {
        return 1;
    }
    if(c=='2')
    {
        return 2;
    }
    if(c=='3')
    {
        return 3;
    }
    if(c=='4')
    {
        return 4;
    }
    if(c=='5')
    {
        return 5;
    }
    if(c=='6')
    {
        return 6;
    }
    if(c=='7')
    {
        return 7;
    }
    if(c=='8')
    {
        return 8;
    }
    if(c=='9')
    {
        return 9;
    }
}

string resultprocessing(string* d)
{
    string FinalResult="";
    //cout<< "?"<<isNotZero(d[0])<<endl;
    if(isNotZero(d[0])){d[1] = d[1]+'0';}
    //d[1] = d[1]+'0';
    int lengthOfD1 = d[1].length();
    int lengthOfD0 = d[0].length();
    int carryin = 0;
    int carryout = 0;
    for(int i= 0;i<d[1].length();i++)
    {

        int buffer = 0;
        char cbuffer= '\0';
        if(i<lengthOfD0)
        {
            buffer = stringElenmentToInteger(d[1][lengthOfD1-1-i]) +  stringElenmentToInteger(d[0][lengthOfD0-1-i]);
            if(buffer>9)
            {
                carryout = buffer/10;
                buffer = buffer%10;
            }
            if(carryin+buffer<10)
            {
                //carryout = 0;
                cbuffer = carryin + buffer + '0';
            }
            else
            {
                carryout = carryout+1;
                cbuffer = (carryin + buffer -10)+'0';
            }
            carryin = carryout;
            carryout = 0;
            FinalResult =  cbuffer + FinalResult;
        }
        else
        {

            buffer = stringElenmentToInteger(d[1][lengthOfD1-1-i]);
            if(carryin+buffer<10)
            {
                //carryout = 0;
                cbuffer = carryin + buffer + '0';
            }
            else
            {
                carryout = 1;
                cbuffer = (carryin + buffer -10)+'0';
            }
            carryin = carryout;
            carryout = 0;
            FinalResult = cbuffer + FinalResult;
            if(carryin != 0)
            {
                char overflow = carryin + '0';
                FinalResult = overflow + FinalResult;
                carryin = 0;
            }

        }
    }
    return FinalResult;
}

bool isNotZero(string e)
{
    int lengthOfE = e.length();
    for(int i = 0; i<lengthOfE;i++)
    {
        //cout<<e[i]<<endl;
        if(e[i] != '0')
        {
            return 1;
        }
    }
    return 0;
}

