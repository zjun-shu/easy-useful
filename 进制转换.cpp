#include<iostream>//笔记  string[]     字符串处理函数 
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//变量： 
char number[3][16]; //0 二进制  1 十进制  2 十六进制  3 待写入 
int Model; 
int Real_Value_10;
char numberr[12];

//函数声明： 
int fun_10_to_10(char number_10[]);//十进制转为十进制数(函数)
int fun_2_to_10(char number_2[]);//二进制转为十进制数(函数)
int fun_16_to_10(char number_16[]);//十六进制转为十进制数(函数)
void fun_10_to_2(int value_10);//十进制转为二进制数(函数) 返回二进制长度 
void fun_10_to_16(int value_10);//十进制转为十六进制数(函数) 返回二进制长度 

//函数表示： 
int main()
{ 
	cout<<"二进制输入    0 \n 十进制输入   1\n 十六进制输入 2\n请输入";
	while(cin>>Model){
		if(Model>=0&&Model<=2) break;
			else cout<<"请重新输入";	 
	}	
	cout<<"请开始输入    提示：Ctrl+c 退出"<<endl;
	
	while(~scanf("%s",number[Model])!=0){
		//cout<<fun_10_to_10(number[Model])<<endl;
		if(Model == 0) {
			Real_Value_10 = fun_2_to_10(number[Model]);
		}
			else if(Model == 1) {
				Real_Value_10 = fun_10_to_10(number[Model]);
			}
				else {
					Real_Value_10 = fun_16_to_10(number[Model]);
				}
		cout<<"十进制表示为:      "<<Real_Value_10<<endl;
		fun_10_to_2(Real_Value_10);
		fun_10_to_16(Real_Value_10);
		
	} 
}
int fun_10_to_10(char number_10[]){
	int value_10 = 0;
	int Length = strlen(number_10);
	for(int i =0;i<Length;i++){
		value_10 += (number_10[i] - '0')*(pow(10,Length-1-i));	
	}
	return value_10;
}

int fun_2_to_10(char number_2[]){
	int value_10 = 0;
	int Length = strlen(number_2);
	for(int i =0;i<Length;i++){
		value_10 += (number_2[i] - '0')*(pow(2,Length-1-i));	
	}
	return value_10;
}

int fun_16_to_10(char number_16[]){
	int value_10 = 0;
	int Length = strlen(number_16);
	for(int i =0;i<Length;i++){
		if(number_16[i]>='0'&&number_16[i]<='9')
			value_10 += (number_16[i] - '0')*(pow(16,Length-1-i));
		else	
			value_10 += (number_16[i] - 'A'+10)*(pow(16,Length-1-i));	
	}
	return value_10;
}
void fun_10_to_2(int value_10){
	char number_2[16];
	int Length = 0;	
	while(value_10 != 0){
		number_2[Length]=value_10%2+48;
		value_10=value_10/2;
		//cout<<number_2[Length]<<endl;
		Length++;		
	} 
	cout<<"二进制表示为:      "; 
	for(int i =0;i<Length;i++)
		cout<<number_2[Length-1-i];	
	cout<<endl;
}
void fun_10_to_16(int value_10){
	int Length = 0;	
	char number_16[16]; 
	while(value_10 != 0){
		int temp = value_10%16;
		number_16[Length]=(temp<=9)?(temp+'0'):(temp-10+'A');
		value_10=value_10/16;
		Length++;		
	} 
	cout<<"十六进制表示为:    "; 
	for(int i =0;i<Length;i++)
		cout<<number_16[Length-1-i];	
	cout<<endl;
}
