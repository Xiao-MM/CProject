#include <iostream>
#define maxP 10
#define maxS 10
using namespace std;
int Available[maxS];
int Max[maxP][maxS];
int Allocation[maxP][maxS];
int Need[maxP][maxS];
int Request[maxS];
int Finish[maxP];
int path[maxP] = { 0 };
int PNum, RNum;
void outPath() {
    cout << "系统安全序列是:\n";
    //存的是序列号 + 1
    cout << "P" << path[0] - 1;
    for (int i = 1; path[i] != 0; i++) {
        cout << "->P" << path[i] - 1;
    }
    for (int i = 0; i < PNum; i++) path[i] = 0;
    cout << endl;
}
int BankSafe() {
    int i, j, l = 0;
    //系统可以分配的的资源数量
    int Work[maxS];
    for (i = 0; i < RNum; i++) Work[i] = Available[i];
    for (i = 0; i < PNum; i++) Finish[i] = 0;
    for (i = 0; i < PNum; i++) {
        //如果该编号的进程已经在安全队列（成功分配），则跳过该进程，继续验证下一个进程
        if (Finish[i] == 1)
            continue;
        else {
            for (j = 0; j < RNum; j++) {
                if (Need[i][j] > Work[j])
                    break;
            }
            //证明这一个进程需要的资源都可以被满足
            if (j == RNum) {
                //将该进程置为安全标志
                Finish[i] = 1;
                for (int k = 0; k < RNum; k++)
                    //将该进程已分配资源的数量归还
                    Work[k] += Allocation[i][k];
                //将该进程放入路径数组
                path[l++] = i + 1;
                //每次都将重新循环，会跳过已成功分配的进程
                i = -1;
            }
            //本次分配失败，尝试下一个进程
            else continue;
        }
        //所有进程均已成功分配资源
        if (l == PNum) {
            return 1;
        }
    }
    return 0;
}
void input(int PNum, int RNum) {
    cout << "输入每个进程最多所需的各类资源数:\n";
    for (int i = 0; i < PNum; i++) {
        cout << "P" << i << " : ";
        for (int j = 0; j < RNum; j++)
            cin >> Max[i][j];
    }
    cout << "输入每个进程已经分配的各类资源数:\n";
    for (int i = 0; i < PNum; i++) {
        cout << "P" << i << " : ";
        for (int j = 0; j < RNum; j++) {
            cin >> Allocation[i][j];
            Need[i][j] = Max[i][j] - Allocation[i][j];
            if (Need[i][j] < 0) {
                cout << "你输入的进程P" << i << "所拥有的第" << j + 1 << "个资源错误，请重新输入:\n";
                j--;
                continue;
            }
        }
    }
    cout << "请输入各个资源现有的数目:\n";
    for (int i = 0; i < RNum; i++)
        cin >> Available[i];
}
int requestP() {
    int Pi;
    cout << "输入要申请资源的进程号(0-4)：";
    cin >> Pi;
    cout << "输入进程所请求的各资源的数量:";
    for (int i = 0; i < RNum; i++)
        cin >> Request[i];
    for (int i = 0; i < RNum; i++) {
        if (Request[i] > Need[Pi][i]) {
            cout << "所请求资源数超过进程的需求量！\n";
            return 1;
        }
        if (Request[i] > Available[i]) {
            cout << "所请求资源数超过系统所有的资源数！\n";
            return 1;
        }
    }
    for (int i = 0; i < RNum; i++) {
        Available[i] -= Request[i];
        Allocation[Pi][i] += Request[i];
        Need[Pi][i] -= Request[i];
    }
    if (BankSafe()) {
        cout << "系统安全!\n";
        outPath();
        cout << "同意分配请求!\n";
    }
    else {
        for (int i = 0; i < RNum; i++) {
            Available[i] += Request[i];
            Allocation[Pi][i] -= Request[i];
            Need[Pi][i] += Request[i];
        }
        cout << "请求后,系统不安全,你的请求被拒!\n";
    }
    return 0;
}
void outDATA() {
    int i, j;
    cout << "\n系统可用的资源数为 :";
    for (j = 0; j < RNum; j++)
        cout << " " << Available[j];
    cout << endl << "各进程还需要的资源量:" << endl;
    for (i = 0; i < PNum; i++) {
        cout << "进程 P" << i << " :";
        for (j = 0; j < RNum; j++)
            cout << " " << Need[i][j];
        cout << endl;
    }
    cout << endl << "各进程已经得到的资源量:" << endl;
    for (i = 0; i < PNum; i++) {
        cout << "进程 P" << i << " :";
        for (j = 0; j < RNum; j++)
            cout << " " << Allocation[i][j];
        cout << endl;
    }
    cout << endl;
}
int main() {
    cout << "输入进程的数目:";
    cin >> PNum;
    cout << "输入资源的种类:";
    cin >> RNum;
    input(PNum, RNum);
    if (BankSafe()) {
        cout << "当前系统安全!\n";
        outPath();
    }
    else {
        cout << "当前系统不安全!\n";
        return 0;
    }
    while (1) {
        requestP();
        outDATA();
        char chose;
        cout << "是否再次请求分配？是请按Y/y，否请按N/n:\n";
        while (1) {
            cin >> chose;
            if (chose == 'Y' || chose == 'y' || chose == 'N' || chose == 'n')
                break;
            else {
                cout << "请按要求重新输入:\n";
                continue;
            }
        }
        if (chose == 'Y' || chose == 'y')
            continue;
        else break;
    }
    return 0;
}