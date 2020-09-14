#include<iostream>
using namespace std;

//获取next数组（next数组为pmt整体右移一位获取的）
void getNext(char *p, int *next){
    //以自身分别为主串和子串进行模式匹配，i位置所在的next[i]值即为所匹配的最大公共前后缀的长度
    next[0] = -1;
    int i = 0,j = -1;
    while (i < strlen(p)){
       if (j == -1 || p[i] == p[j]){//j=-1时，主串与重子串第一个位置开始匹配。p[i] == p[j]时，主串与子串匹配成功，继续往下走
            ++i;
            ++j;
            next[i] = j;
       }else
            j = next[j] ;//当p[i]!=p[j]时，j回退至next[j]处继续匹配，若仍不匹配，继续回退，直到退至j=-1重新开始
    }
}

int KMP(char *t,char *p,int *next){
    getNext(p,next);
    int i = 0, j = 0;
    while (i < strlen(t) && j < strlen(p)){
        if (t[i] == p[j]){
            i++;
            j++;
        }else
            j = next[j];
    }
    if(j == strlen(p))
        return i-j;
    else
        return -1;
    
}
int main(){
    char *t="ababababca",*p="abababca";
    int next[8];
    int i = KMP(t,p,next);
    cout<<i<<endl;
}