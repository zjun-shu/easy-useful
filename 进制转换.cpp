#include<iostream>//�ʼ�  string[]     �ַ��������� 
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//������ 
char number[3][16]; //0 ������  1 ʮ����  2 ʮ������  3 ��д�� 
int Model; 
int Real_Value_10;
char numberr[12];

//���������� 
int fun_10_to_10(char number_10[]);//ʮ����תΪʮ������(����)
int fun_2_to_10(char number_2[]);//������תΪʮ������(����)
int fun_16_to_10(char number_16[]);//ʮ������תΪʮ������(����)
void fun_10_to_2(int value_10);//ʮ����תΪ��������(����) ���ض����Ƴ��� 
void fun_10_to_16(int value_10);//ʮ����תΪʮ��������(����) ���ض����Ƴ��� 

//������ʾ�� 
int main()
{ 
	cout<<"����������    0 \n ʮ��������   1\n ʮ���������� 2\n������";
	while(cin>>Model){
		if(Model>=0&&Model<=2) break;
			else cout<<"����������";	 
	}	
	cout<<"�뿪ʼ����    ��ʾ��Ctrl+c �˳�"<<endl;
	
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
		cout<<"ʮ���Ʊ�ʾΪ:      "<<Real_Value_10<<endl;
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
	cout<<"�����Ʊ�ʾΪ:      "; 
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
	cout<<"ʮ�����Ʊ�ʾΪ:    "; 
	for(int i =0;i<Length;i++)
		cout<<number_16[Length-1-i];	
	cout<<endl;
}
