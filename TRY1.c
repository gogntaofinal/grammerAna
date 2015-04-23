/**
 ==========================================================
 求first集的算法思想：
 ==========================================================
 如果产生式右部第一个字符为终结符，则将其计入左部first集
 如果产生式右部第一个字符为非终结符
 ->求该非终结符的first集
 ->将该非终结符的非$first集计入左部的first集
	->若存在$，则将指向产生式的指针右移
	->若不存在$，则停止遍历该产生式，进入下一个产生式
	->若已经到达产生式的最右部的非终结符，则将$加入左部的first集
 处理数组中重复的first集中的终结符
 ===========================================================
 */

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

int isTer(char ch){
    int i = 0, len = strlen(terSymbol);
    for(i = 0; i < len; ++i){
        if(ch == terSymbol[i]){
            return 1;
        }
    }
    return 0;
}

int isNoTer(char ch){
    int i = 0, len = strlen(non_ter);
    for(i = 0; i < len; ++i){
        if(ch == non_ter){
            return i;
        }
    }
    return -1;
}

int findFirst(char target){
    int i = 0;      //用来标记全体产生式的遍历
    int j = 0;      //用来标记打个产生式的遍历
    int lens = 0;   //用来记录整个产生式的长度
    int lenf = 0;   //用来记录first集的长度
    int tag = 0, tag1 = 0;    //用来表示是否存在$
    int seti = isNoTer(target);   //用来标示是哪个非终结符的first集
    int k = 0;      //用来表示first集的遍历
    for(i = 0; i < pro_num; ++i){
        strcpy(ele, terSymbol[i].formula);
        lens = strlen(ele);
        if(ele[0] == target){
            for(j = 3; j < lens; ++j){
                if(isTer(ele[j])){
                    firstSET[seti][strlen[firstSET[seti]]] = ele[j];
                    break;
                }
                else{
                    findFIRST(ele[j]);
                    lenf = strlen(firstSET[isNoTer(ele[j])]);
                    for(k = 0; k < lenf; ++k){
                        if(firstSET[isNoTer(ele[j])][k] == '$'){
                            tag1 ++;
                        }else{
                            firstSET[seti][strlen[firstSET[seti]]] = firstSET[isNoTer(ele[j])][k];
                        }
                    }
                    if(tag1 == 0){
                        break;
                    }else{
                        tag += tag1;
                        tag1 = 0;
                    }
                }
            }
            if(tag == lens - 3){
                firstSET[seti][strlen[firstSET[seti]]] = '$';
            }
        }
    }
    return 0;
}

int main(){
    
//    freopen("product.txt", "r", stdin);
//    freopen("output.txt", "a", stdout);
    initana();
    strcpy(terSymbol, "ABEFT");
    strcpy(non_ter, "$*i()");
    pro_num = prod();
    
    
    return 0;
}
