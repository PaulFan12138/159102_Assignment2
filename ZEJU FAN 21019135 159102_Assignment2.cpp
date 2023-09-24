//ZEJU FAN 21019135
//159102 Assignment 2
//2023/09/25
//Problem: When the first digit is "4", the value of PC is not output

//github Link:
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//global variables
int memory[256];
int reg[16];
int pc , ir;

//declare variables
int MasseyNum;
int FirstNum,SecondNum,ThirdNum,FourthNum;

//Declare a file input stream object 'file' for reading data from a file
ifstream file;

//Limit the output to four digits, and use "0" to make up for less than four digits.
void Output_four_digits()
{
    cout.width(4);
    cout.fill('0');
}

//Read the machine code from the file and write it into the memory, and output the value and memory address of each machine code according to the format.
void OutputNum()
{
    int i = 0;
    while (file >> hex >> memory[i])
    {
        cout << "Memory[0" << i << "] = ";
        Output_four_digits();
        cout << hex << uppercase << memory[i] << endl;
        i++;
        if (i >= 256)
        {
            break;
        }
    }
    //update the Massey Num
    //i is mean the number of input data
    MasseyNum = i;
    cout << endl;
}


void GetEveryPostionNumber(int Massycode)
{
    //Extract the first, second, third and fourth digits in the input string
    FirstNum = Massycode >> 12;
    SecondNum = (Massycode & 0X0f00) >> 8;
    ThirdNum = (Massycode & 0x00f0) >> 4;
    FourthNum = Massycode & 0X000f;
}

//Output the status information during program execution on the console
//ChangedPostion: Indicates the position where the register has changed
//ChangedValue: Indicates the value of the register after changes at the corresponding position.
//LocaleChangedPostion: Indicates the location where the memory location has changed
//LocaleChangedValue: Indicates the value after the memory changes at the corresponding location.
void Output(int ChangedPostion,int ChangedValue,int LocaleChangedPostion,int LocaleChangedValue,int choice)
{
    //If choice is greater than 0, it means the register has changed
    //For example: 1RXY Load register R with the value XY.
    if(choice > 0)
    {
        cout<<"Register R";
        //hex :Hexadecimal output
        //uppercase:Uppercase output
        cout<<hex<<uppercase<<ChangedPostion<<" = ";
        Output_four_digits();
        cout<<hex<<uppercase<<ChangedValue<<"    "<<endl;
    }
    //If choice is less than or equal to 0, it means that the memory has changed
    //For example: 4RXY Store the number in register R in the memory location at address XY.
    else
    {
        cout<<"Memory[";
        cout<<hex<<uppercase<<LocaleChangedPostion<<"] = ";
        Output_four_digits();
        cout<<hex<<uppercase<<LocaleChangedValue<<"    "<<endl;
    }
}
int main(){
    //String type variable FileName is declared to store the file name or file path entered by the user.
    string FileName;

    cout<<"Enter the file name of the MASSEY machine code: ";
    //cin : read the input file name and assign to FileName
    //Reference website:https://www.geeksforgeeks.org/cin-in-c/
    cin>>FileName;
    cout<<endl;
    //open the text file
    //Reference website:http://www.java2s.com/ref/cpp/cpp-ifstream-file-open-mode.html
    file.open(FileName.c_str(),ios::in);

    //If the file is not opened normally, output "File Open Wrong"
    if(!file.is_open()){
        cout<<"File Open Was Wrong!"<<endl;
        return 0;
    }else{
        //If the file is opened successfully, run the function "OutputNum"
        OutputNum();
    }

    
    //When MasseyNum is not equal to "E000", output the PC value
    for(int i = 0; i < MasseyNum ; i++)
    {   
    pc = i ;
    if( ir != 0xE000 ){
    cout<<"PC: 0"<<pc<<"  ";
    }
        
        labs:

        ir = memory[i];  
        //E000 Halt
        if(ir == 0xE000)
        {
            cout<<"IR: "<<ir;
            cout<<"  ";
            cout<<"Program halts";
        }
        else
        {
            
            cout<<"IR:  "<<ir<<"    ";
        }
        
        //Extract four numbers from the given machine instructions
        GetEveryPostionNumber(ir);
        //Determine the meaning of the command by the first digit
        switch (FirstNum)
        {
            case 1:
                reg[SecondNum] = ThirdNum * 16 + FourthNum;
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 2:
                reg[ThirdNum] = reg[FourthNum];
                Output(ThirdNum,reg[ThirdNum],0,0,1);
                break;
            case 3:
                reg[SecondNum] = memory[ThirdNum * 16 + FourthNum];
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 4:
                memory[ThirdNum * 16 + FourthNum] = reg[SecondNum];
                Output(0,0,(ThirdNum *16 + FourthNum),memory[ThirdNum * 16 + FourthNum],-1);
                break;
            case 5:
                
            case 6:
                reg[SecondNum] = reg[ThirdNum] + reg[FourthNum];
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 7:
                reg[ThirdNum] = -1 * reg[ThirdNum];
                Output(ThirdNum,reg[ThirdNum],0,0,1);
                break;
            case 8:
                reg[SecondNum] = reg[SecondNum] >> FourthNum;
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 9:
                reg[SecondNum] = reg[SecondNum] << FourthNum;
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 10:
                reg[SecondNum] = reg[ThirdNum] & reg[FourthNum];
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 11:
                reg[SecondNum] = reg[ThirdNum] | reg[FourthNum];
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 12:
                reg[SecondNum] = reg[ThirdNum] ^ reg[FourthNum];
                Output(SecondNum,reg[SecondNum],0,0,1);
                break;
            case 13:
            
                //Jump to the instruction at address XY if the value in register R is equal to the value in register R0.
                if(reg[SecondNum] == reg[0])
                {
                    cout<<"TRUE – jump to location 07 "<< endl;
                    i = ThirdNum * 16 + FourthNum;
                
                    goto labs;
                }
                else
                {
                    cout<<"             ";
                }
                break;
            case 14:
                return 0;
        }
        
    
    }
}
