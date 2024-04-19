#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrCalculate.h"
/*****************计算器相关*******************/
uint8_t strput(StrStack_t * st,char strin)//将字符存入字符栈中
{
    if(st->Top_Point == 15 - 1)
    {return -1;}

    st->strque[st->Top_Point++] = strin;
    return 0;
}

uint8_t strdel(StrStack_t * st)//从字符栈中删除字符
{
    if(st->Top_Point == 0)
    {return -1;}

    st->strque[--st->Top_Point] = NULL;
    return 0;
}

uint8_t strstack_isEmpty(StrStack_t* st)//判断字符栈是否为空
{
    if(st->Top_Point == 0)
    {return 1;}

    return 0;
}

void strclear(StrStack_t* sq)//清空字符栈
{
    while(!strstack_isEmpty(sq))
    {
        strdel(sq);
    }
}

uint8_t NumStackPut(NumStack_t * st, float in)//将数字存入数字栈中
{
   if(st->Top_Point == CAL_DEPTH - 1)
	{return -1;}

	st->data[st->Top_Point++] = in;
	return 0;
}

uint8_t NumStackDel(NumStack_t * st)//从数字栈中删除数字
{
    if(st->Top_Point == 0)
	{return -1;}
    st->data[st->Top_Point--] = 0;
	return 0;
}

uint8_t NumStack_isEmpty(NumStack_t* st)//判断数字栈是否为空
{
	if(st->Top_Point == 0)
	{return 1;}

	return 0;
}

void NumStackClear(NumStack_t* st)//清空数字栈
{
	while(!NumStack_isEmpty(st))
	{
		NumStackDel(st);
	}
}

uint8_t SymStackPut(SymStack_t * st, char in)//将运算符存入运算符栈中
{
	if(st->Top_Point == CAL_DEPTH - 1)
	{return -1;}

	st->data[st->Top_Point++] = in;
	return 0;
}

uint8_t SymStackDel(SymStack_t * st)//从运算符栈中删除运算符
{
  if(st->Top_Point == 0)
	{return -1;}
    st->data[st->Top_Point--] = 0;
	return 0;
}

uint8_t SymStack_isEmpty(SymStack_t* st)//判断运算符栈是否为空
{
	if(st->Top_Point == 0)
	{return 1;}

	return 0;
}

void SymStackClear(SymStack_t* st)//清空运算符栈
{
	while(!SymStack_isEmpty(st))
	{
		SymStackDel(st);
	}
}

uint8_t SymisHighPriority(char top, char present)//判断两个运算符的优先级
{
    //乘除的优先级最大
    if(top == '*' || top == '/')
    {
        return 1;
    }
    else if(top == '+')
    {
        if(present == '-')
        {return 1;}
        else
        {return 0;}
    }
    else if(top == '-')
    {
        if(present == '+')
        {return 1;}
        else
        {return 0;}
    }
}

void CalculateOne(NumStack_t * numstack, SymStack_t * symstack)//从数字栈和运算符栈中取出两个数字和一个运算符进行计算，并将结果存回数字栈中
{
    caldata_t temp;
    temp.datatype = NUMBER_TYPE;
    temp.symbol = NULL;
    //计算数字栈中的顶部两数,结果存到temp中
    if(symstack->data[symstack->Top_Point-1] == '+')
        temp.number = (numstack->data[numstack->Top_Point-2]) + (numstack->data[numstack->Top_Point-1]);
    
    else if(symstack->data[symstack->Top_Point-1] == '-')
        temp.number = (numstack->data[numstack->Top_Point-2]) - (numstack->data[numstack->Top_Point-1]);
    
    else if(symstack->data[symstack->Top_Point-1] == '*')
        temp.number = (numstack->data[numstack->Top_Point-2]) * (numstack->data[numstack->Top_Point-1]);
    
    else if(symstack->data[symstack->Top_Point-1] == '/')
        temp.number = (numstack->data[numstack->Top_Point-2]) / (numstack->data[numstack->Top_Point-1]);
    
    //运算前两数出栈,运算结果数入栈
    NumStackDel(numstack);
    NumStackDel(numstack);
    NumStackPut(numstack,temp.number);
    SymStackDel(symstack);
    
}

uint8_t NumSymSeparate(char * str, uint8_t strlen, NumStack_t * NumStack, SymStack_t * SymStack)//将输入的字符串按照数字和运算符分割，同时将数字存入数字栈，运算符存入运算符栈
{
		NumStackClear(NumStack);
		SymStackClear(SymStack);
    caldata_t temp,temp_pre;
    char NumBehindPoint_Flag = 0;//数字是否在小数点后,后多少位
    temp.datatype = NUMBER_TYPE;
    temp.number = 0;
    temp.symbol = NULL;
    temp_pre = temp;
    temp_pre.datatype = SYMBOL_TYPE;
    if(str[0]>'9' || str[0]<'0')
        return 1;//erro
		int i;
    for(i=0;i<strlen;i++)
    {
        if(str[i]=='.')
        {
            temp.datatype = POINT_TYPE;
            if(temp_pre.datatype == NUMBER_TYPE)
            {} 
            else
            {return 2;}
            temp_pre = temp;
        }
        if(str[i]<='9' && str[i]>='0') 
        {
            //溢出报错
            if(NumStack->Top_Point>CAL_DEPTH || SymStack->Top_Point>CAL_DEPTH)
            {return 3;}
            //读取当前的字符到temp中
            temp.datatype = NUMBER_TYPE;
            temp.number = (str[i] - '0');
            temp.symbol = NULL;
            //如果为连续数字,需要进行进位,将数字栈顶读出进位，再加上现在位，再入栈
            if(temp_pre.datatype == NUMBER_TYPE)
            {
                if(!NumBehindPoint_Flag)
                {temp.number += NumStack->data[NumStack->Top_Point-1] * 10;}
                else
                {
                    NumBehindPoint_Flag += 1;
                    char i = NumBehindPoint_Flag;
                    while(i--)
                    {temp.number /= 10;}  
                    temp.number += NumStack->data[NumStack->Top_Point-1];   
                }
                NumStackDel(NumStack);
                NumStackPut(NumStack,temp.number);
            }
            //当前数字刚好是小数点后一位
            else if(temp_pre.datatype == POINT_TYPE)
            {
                NumBehindPoint_Flag = 1;
                temp.number /= 10;
                temp.number += NumStack->data[NumStack->Top_Point-1];
                NumStackDel(NumStack);
                NumStackPut(NumStack,temp.number);
            }
            //前一位不是数字或小数点,现在读取的这一位是数字，直接入栈 
            else
            {
                NumStackPut(NumStack,temp.number);
            }
            temp_pre = temp;
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') 
        {
            //溢出报错
            if(NumStack->Top_Point>CAL_DEPTH || SymStack->Top_Point>CAL_DEPTH)
            {return 4;}
            //读取当前的字符到temp中
            temp.datatype = SYMBOL_TYPE;
            temp.symbol = str[i];
            temp.number = 0;
            NumBehindPoint_Flag = 0;//小数点计算已经结束
            //重复输入了运算符号
            if(temp_pre.datatype == SYMBOL_TYPE)
            {
                return 5 ;//erro
            } 
            else
            {
                if((!SymStack_isEmpty(SymStack)) && SymisHighPriority(SymStack->data[SymStack->Top_Point-1],temp.symbol))
                {
                    CalculateOne(NumStack, SymStack);
                    SymStackPut(SymStack,temp.symbol);
                }
                else
                {
                    //符号压入符号栈
                    SymStackPut(SymStack,temp.symbol);
                }
                temp_pre = temp;
            }
        }
    }
    return 0;
} 

uint8_t StrCalculate(char * str,NumStack_t * NumStack, SymStack_t * SymStack)//对输入的字符串进行计算，最终得出结果
{
    if(NumSymSeparate(str,strlen(str),NumStack,SymStack))
    {
        //erro, clear all
        NumStackClear(NumStack);
        SymStackClear(SymStack);
        return -1;
    }
    else
    {
        while(!SymStack_isEmpty(SymStack))
        {
            CalculateOne(NumStack,SymStack);
        }
    }
    return 0;
}

uint8_t isIntNumber(float number)//判断一个浮点数是否为整数
{
	if(number == (int)number)
	{return 1;}
	return 0;
}


