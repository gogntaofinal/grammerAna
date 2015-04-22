#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char formula[200];//产生式
}grammarElement;

grammarElement  gramOldSet[200];//原始文法的产生式集
char ele[200]; //产生式个体 
char terSymbol[200];//终结符号
char non_ter[200];//非终结符号
char allSymbol[400];//所有符号
char firstSET[100][100];//各产生式右部的FIRST集
char followSET[100][100];//各产生式左部的FOLLOW集
int M[200][200];//分析表
int pro_num ;   //产生式的数量 

void initana(){
     memset(terSymbol, 0, sizeof(terSymbol));
     memset(non_ter, 0, sizeof(non_ter));
     memset(allSymbol, 0, sizeof(allSymbol));
     memset(firstSET, 0, sizeof(firstSET));
     memset(followSET, 0, sizeof(followSET));
     memset(M, 0, sizeof(M));
     memset(gramOldSet, 0, sizeof(gramOldSet));
}
 
int prod(){
     int i = 0, j = 0;
     while(scanf("%s", ele) != EOF){
         strcpy(gramOldSet[i++].formula, ele);
     }
     for(j = 0; j < i; ++j){
         printf("%s\n", gramOldSet[j].formula);
     }
     return i;
}

/*

该函数是用来统计终结符和非终结符的，暂时先手动写出
已知的终结符，方便处理， 以后在考虑具体实现
 
int getAllSymbol(){
    int i = 0; //用于表示终结符的输入
    int j = 0; //用于表示非终结符的输入
    int k = 0; //总控指针
    int l = 0; // 用于表示所有符号的输入 
    for(k = 0; k < pro_num; ++k){
         strcpy(ele,  gramOldSet[k].formula);
         for(l = 0; l < strlen(ele); ++l) {
             
         }
    }
}
*/

int isTer(){
    int i = 0, len = strlen(terSymbol);
    int tag;
    for(i = 0; i < len; ++i){
    
    } 
}
int findFirst(){
    
}

int main(){
    
    freopen("product.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    initana();
    strcpy(terSymbol, "ABEFT");
    strcpy(non_ter, "$*i()");
    pro_num = prod();
    
    
    return 0;
}
