#include <iostream>
#include <string>


using namespace std;

string mutiple(string a, string b);
int stringElenmentToInteger(char c);
string resultprocessing(string* d);
bool isNotZero(string e);
string changeIntTo(int f);

int main()
{
    int a = 1;
    string Multiplicand = "1";
    while(a<100)
    {
        string temp = changeIntTo(a);
        Multiplicand = mutiple(Multiplicand,temp);
        a++;
        cout << a-1 << "   " << Multiplicand << endl;
    }
    //cout<<mutiple("8320987112741390144276341183223364380754172606361245952449277696409600000000","61");
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
        //cout << result[0] << endl <<result[1]<<endl;
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
            //cout<<FinalResult<<endl;
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
            /*if(carryin != 0)
            {
                cout << carryin <<endl;
                char overflow = carryin + '0';
                FinalResult = overflow + FinalResult;
                carryin = 0;
            }*/

        }
    }
    if(carryin != 0)
    {
        //cout<< carryin <<endl;
        char overflow = carryin + '0';
        FinalResult = overflow + FinalResult;
        carryin = 0;
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

string changeIntTo(int f)
{
    string changedResult = "";
    int x = f;
    int numberOfDigits = 0;
    do
    {
        ++numberOfDigits;
        x /= 10;
    }while(x);
    int temp_1 = 0; //store the digit to identify
    int temp_2 = 0; //divided by ten after each loop
    temp_2 = f;
    while(numberOfDigits>0)
    {
        temp_1 = temp_2%10;
        switch(temp_1)
        {
        case 9:
            changedResult = "9" + changedResult;
            break;
        case 8:
            changedResult = "8" + changedResult;
            break;
        case 7:
            changedResult = "7" + changedResult;
            break;
        case 6:
            changedResult = "6" + changedResult;
            break;
        case 5:
            changedResult = "5" + changedResult;
            break;
        case 4:
            changedResult = "4" + changedResult;
            break;
        case 3:
            changedResult = "3" + changedResult;
            break;
        case 2:
            changedResult = "2" + changedResult;
            break;
        case 1:
            changedResult = "1" + changedResult;
            break;
        case 0:
            changedResult = "0" + changedResult;
            break;
        default:
            cout<<"Not a integer"<<endl;
            return "-1";

        }
        temp_2 = temp_2/10;
        numberOfDigits--;
    }
    return changedResult;

    /*if(f==1){return "1";}
    if(f==2){return "2";}
    if(f==3){return "3";}
    if(f==4){return "4";}
    if(f==5){return "5";}
    if(f==6){return "6";}
    if(f==7){return "7";}
    if(f==8){return "8";}
    if(f==9){return "9";}
    if(f==10){return "10";}
    if(f==11){return "11";}
    if(f==12){return "12";}
    if(f==13){return "13";}
    if(f==14){return "14";}
    if(f==15){return "15";}
    if(f==16){return "16";}
    if(f==17){return "17";}
    if(f==18){return "18";}
    if(f==19){return "19";}
    if(f==20){return "20";}
    if(f==21){return "21";}
    if(f==22){return "22";}
    if(f==23){return "23";}
    if(f==24){return "24";}
    if(f==25){return "25";}
    if(f==26){return "26";}
    if(f==27){return "27";}
    if(f==28){return "28";}
    if(f==29){return "29";}
    if(f==30){return "30";}
    if(f==31){return "31";}
    if(f==32){return "32";}
    if(f==33){return "33";}
    if(f==34){return "34";}
    if(f==35){return "35";}
    if(f==36){return "36";}
    if(f==37){return "37";}
    if(f==38){return "38";}
    if(f==39){return "39";}*/
}
