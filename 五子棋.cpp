#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char tab[16][16];

void init() {
    for (int i = 0;i < 16;i++) {
        for (int j = 0;j < 16;j++) {
            tab[i][j] = ' ';
        }
    }
}

void putrow() {
    cout << "       ";
    for (int i = 0;i < 16;i++) {
        if (i < 10) {
            std::cout << "   " << i;
        }
        else {
            std::cout << "  " << i;
        }
    }
    std::cout << "\n";
}

void putline() {
    cout << "       ";
    for (int i = 0;i < 16;i++) {
        std::cout << "   -";
    }
    std::cout << "\n";
}

void putout() {
    putrow();
    for (int i = 0;i < 16;i++) {
        putline();
        if (i < 10) {
            std::cout << "第" << i << "行:  | ";
        }
        else {
            std::cout << "第" << i << "行: | ";
        }
        for (int j = 0;j < 16;j++) {
            std::cout << tab[i][j] << " | ";
        }
        std::cout << "\n";
    }
    putline();
}

void simulate_human() {

}

int value(int i) {
    if (i == 5) {
        return 1000;
    }
    if (i) {
        return 0;
    }
}

int evaluate(int rival) {//rival ==0:电脑自己,@    rival==1:对手,×
    int sum = 0;
    if (rival == 0) {
        //横方向
        for (int i = 0;i < 16;i++) {
            for (int j = 0;j < 16;j++) {
                if (tab[i][j] == '@') {
                    int count=0;//连子数目
                    int dead = -1;//-1代表没有封锁，活子；1代表有封锁
                    if (tab[i][j-1] == '×' && j > 0) {//左封锁
                        dead = 1;
                    }
                    while (tab[i][j]!='×' && j < 16) {
                        if (tab[i][j] == '@') {
                            count++;
                        }
                        j++;
                        if (tab[i][j + 1] == '×') {//右封锁
                            dead = 1;
                        }
                        if (tab[i][j]!=' ' && tab[i][j+1]==' ') {
                            break;
                        }
                    }//一个连续的组扫描完
                    if (count == 2) {
                        if (dead == -1) {
                            sum += 2;
                        }
                        else {
                            sum += 1;
                        }
                    }
                    if (count == 3 || count == 4) {
                        sum += (count - 1) * (count-dead);
                    }
                    if (count == 5) {
                        sum += 1000;
                    }
                }
            }//行扫描完
        }
    }
    return sum;
}

int machine(int rival,int level){//rival ==0:电脑自己    rival==1:模拟的对手
    if (level < 15) {
        return 0;
    }
}

void human() {
    putout();
    int a, b;
    int c;
    cout << "Input your position: Row and Con\n";
    cin >> a >> b;
    cout << "1 确认，2 重选，3退出\n";
    cin >> c;
    if (c == 1) {
        tab[a][b] = '*';
        int i = machine(0,0);
    }
    else if (c == 2) {
        human();
    }
    else if (c==3) {

    }
    else {
        cout << "Wrong Input,Try Again\n";
        human();
    }
}

void start() {
    init();
    cout << "选择：1 后手 or 2 先手\n";
    int a;
    cin >> a;
    if (a == 1) {
        int i = machine(0,0);
    }
    else if (a==2) {
        human();
    }
    else {
        cout << "不正确的输入，请重试\n";
        start();
    }
}

int main(){
    cout << "× 人，@ 机\n";
    start();
    //putout();
    return 0;
}