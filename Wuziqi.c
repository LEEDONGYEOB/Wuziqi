#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int n=1;//全局函数
int t=1;
void ShowMap(int map[15][15],int* isblack,int win_or_not,int num){//打印棋盘  二维数组的第一个数是纵轴，第二个数是横轴
    int i,j;
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    printf("   ");
    for(i=0;i<9;i++){printf("%d  ",arr[i]);}
    for(i=9;i<15;i++){printf("%d ",arr[i]);}
    printf("\n");
    for(i=0;i<9;i++){
		printf("%d  ",arr[i]);
		for(j=0;j<15;j++)
		{            
            if(map[i][j]==0){
                if(i==0&&j==0){printf("┌  ");}
                else if(i==0&&j==14){printf("┐");}
                else if(i==14&&j==0){printf("└  ");}
                else if(i==14&&j==14){printf("┘");}
                else if(i==0){printf("┬  ");}//i=0，0<j<14的情况
                else if(i==14){printf("┴  ");}//i=14,<0j<14的情况
                else if(j==0){printf("├  ");}//0<i<14,j=0的情况
                else if(j==14){printf("┤");}//0<i<14,j=14的情况
                else {printf("┼  ");}
            }
            else if(map[i][j]==1){printf("● ");}//黑棋
            else{printf("○ ");}//白旗
		}
		printf("\n");
	}
    for(i=9;i<15;i++){
		printf("%d ",arr[i]);
		for(j=0;j<15;j++)
		{
            if(map[i][j]==0){
                if(i==0&&j==0){printf("┌  ");}
                else if(i==0&&j==14){printf("┐");}
                else if(i==14&&j==0){printf("└  ");}
                else if(i==14&&j==14){printf("┘");}
                else if(i==0){printf("┬  ");}//i=0，0<j<14的情况
                else if(i==14){printf("┴  ");}//i=14,<0j<14的情况
                else if(j==0){printf("├  ");}//0<i<14,j=0的情况
                else if(j==14){printf("┤");}//0<i<14,j=14的情况
                else {printf("┼  ");}
            }
            else if(map[i][j]==1){printf("● ");}//黑棋
            else{printf("○ ");}//白旗
		}
		printf("\n");
	}
    if(t==1||win_or_not==1||win_or_not==2||num==225){return;}//第一次下棋时说明谁先手，以及防止打印胜利的时候出现'请输入坐标'
    else if(*isblack==1){printf("请输入黑棋坐标:");}
    else {printf("请输入白棋坐标:");}
}
void Press_Error_Y_N_O(char* press){//递归函数吧 输入字符不为YNO的情况
     if(n==1){
        printf("\n请重新输入:");
        n++;
    }
    *press=getch();
    if(*press=='y'||*press=='Y'||*press=='n'||*press=='N'||*press=='o'||*press=='O'){
        n=1;
        return;
    }
    else{Press_Error_Y_N_O(press);}
}
void Press_Error_Y_N(char* press){//递归函数吧 输入字符不为YN的情况
    if(n==1){
        printf("\n请重新输入:");
        n++;
    }
    *press=getch();
    if(*press=='y'||*press=='Y'||*press=='n'||*press=='N'){
        n=1;
        return;
    }
    else{Press_Error_Y_N(press);}
}
int Win_or_not(int map[15][15],int x,int y){//判断胜负
    int i,j;
    int temp=map[y][x];
    for(j=x-4,i=y;j<=x;j++){//i纵轴,j横轴,x横轴 y纵轴
        if(j>=0&&j<=10&&temp==map[i][j]&&temp==map[i][j+1]&&temp==map[i][j+2]&&temp==map[i][j+3]&&temp==map[i][j+4])
        { return map[y][x];}
    }//水平方向遍历
    for(i=y-4,j=x;i<=y;i++){//i纵轴,j横轴,x横轴 y纵轴
        if(i>=0&&i<=10&&temp==map[i][j]&&temp==map[i+1][j]&&temp==map[i+2][j]&&temp==map[i+3][j]&&temp==map[i+4][j])
        { return map[y][x];}
    }//竖直方向遍历
    for(j=x-4,i=y-4;j<=x,i<=y;j++,i++){//i纵轴,j横轴,x横轴 y纵轴
        if(j>=0&&j<=10&&i>=0&&i<=10&&temp==map[i][j]&&temp==map[i+1][j+1]&&temp==map[i+2][j+2]&&temp==map[i+3][j+3]&&temp==map[i+4][j+4])
        { return map[y][x];}
    }//左下至右上方向遍历
    for(j=x-4,i=y+4;j<=x,i>=1;j++,i--){//i纵轴,j横轴,x横轴 y纵轴
        if(j>=0&&j<=10&&i>=0&&i<=10&&temp==map[i][j]&&temp==map[i-1][j+1]&&temp==map[i-2][j+2]&&temp==map[i-3][j+3]&&temp==map[i-4][j+4])
        { return map[y][x];}
    }//左上至右下方向遍历
    return 0;
}
void SetPoint(int map[15][15],int* isblack,int* win_or_not){//每下一个棋set一次
    int f,s;
    scanf("%d %d",&f,&s);
    int x=f-1;//x横轴 y纵轴
    int y=s-1;
    if(x<0||y<0||x>14||y>14){
        printf("输入的点位不在棋盘内，请重新输入:");
        SetPoint(map,isblack,win_or_not);
    }
    else if(map[y][x]!=0){
        printf("当前位置已有棋子，请重新输入:");
        SetPoint(map,isblack,win_or_not);
    }
    else if(*isblack==1){
        *isblack=2;
        map[y][x]=1;//黑棋下子的位置的二维数组值为1
    }
    else{
        *isblack=1;
        map[y][x]=2;//黑棋下子的位置的二维数组值为1
    }
    *win_or_not=Win_or_not(map,x,y);
}
void PlayGame(){
    int map[15][15]={0};//全部初始化为0
    int a=1;//黑棋先手
    int* isblack=&a;//通过*isblack的值确定为黑棋白旗
    int num=0;//记录下的棋子个数
    ShowMap(map,isblack,0,num);
    if(t==1){
        t++;
        printf("黑棋先手，请输入黑棋坐标:");
    };
    while(1)//循环下棋直到一方胜利或者平局
    {
        int b=0;
        int* win_or_not=&b;
        SetPoint(map,isblack,win_or_not);
        system("cls");
        num++;
        ShowMap(map,isblack,*win_or_not,num);
        if(*win_or_not==1){
            printf("黑棋WIn!\n"); 
            break;
        }
        if(*win_or_not==2){
            printf("白棋WIN!\n");
            break;
        }
        if(num==225){
            printf("平局");
            break;
        }    
    }
    printf("是否再次进行一次游戏?(x或y)或者输入o，可以查看游戏介绍以及游戏操作说明\n");
    printf("请输入(y/n/o):");
    t=1;
}
void Introduction(){
    printf("五子棋 （两人对弈的策略型棋类游戏）\n"
           "五子棋是全国智力运动会竞技项目之一，是一种两人对弈的纯策略型棋类游戏。\n"
           "五子棋的棋具与围棋通用，是一种传统的棋种，有两种玩法。\n"
           "一种是双方分别使用黑白两色的棋子，下在棋盘直线与横线的交叉点上，先形成五子连线者获胜。\n"
           "还有一种是自己形成五子连线就替换对方任意一枚棋子。被替换的棋子可以和对方交换棋子。最后以先出完所有棋子的一方为胜。\n"
           "五子棋容易上手，老少皆宜，而且趣味横生，引人入胜：它不仅能增强思维能力，提高智力，而且富含哲理，有助于修身养性。\n"
           "本游戏是按照第一种五子棋的思路制作。\n");
    printf("五子棋操作方式\n"
            "五子棋阵的上面一行为横坐标，左侧为纵坐标，请通过输入横坐标 空格 纵坐标后点击回车的形式来下棋\n");
    printf("是否进行一次游戏？(y或n)请输入:");
    char* press;
    char temp=getch();
    press=&temp;
    if(*press=='n'||*press=='N'){exit(0);}
    else if(*press=='y'||*press=='Y'){
        system("cls");
        PlayGame();
    }
    else{//若输入值不为Y或N的时候
        Press_Error_Y_N(press);//直到输入Y或N才结束
        if(*press=='n'||*press=='N'){exit(0);}
        if(*press=='y'||*press=='Y'){
            system("cls");
            PlayGame();
        }
    }
}	
void RePlayGame(){//判断是否再次进行游戏
   
    while(1)
    {       
        char* press;
        char temp=getch();
        press=&temp;
        if(*press=='n'||*press=='N'){exit(0);}
        else if(*press=='o'||*press=='O'){
            system("cls");
            printf("五子棋 （两人对弈的策略型棋类游戏）\n"
                   "五子棋是全国智力运动会竞技项目之一，是一种两人对弈的纯策略型棋类游戏。\n"
                   "五子棋的棋具与围棋通用，是一种传统的棋种，有两种玩法。\n"
                   "一种是双方分别使用黑白两色的棋子，下在棋盘直线与横线的交叉点上，先形成五子连线者获胜。\n"
                   "还有一种是自己形成五子连线就替换对方任意一枚棋子。被替换的棋子可以和对方交换棋子。最后以先出完所有棋子的一方为胜。\n"
                   "五子棋容易上手，老少皆宜，而且趣味横生，引人入胜：它不仅能增强思维能力，提高智力，而且富含哲理，有助于修身养性。\n");
            printf("五子棋操作方式\n"
                   "五子棋阵的上面一行为横坐标，左侧为纵坐标，请通过输入横坐标 空格 纵坐标后回车的形式来下棋\n"
                   "输入o，可以查看游戏介绍以及游戏操作说明。");
            printf("是否再次进行一次游戏？\n");
            printf("请输入(y/n):");
        }
        else if(*press=='y'||*press=='Y'){
            system("cls");
            PlayGame();
        }
        else{
            Press_Error_Y_N_O(press);
            if(*press=='n'||*press=='N'){exit(0);}
            else if(*press=='o'||*press=='O'){
                system("cls");
                printf("五子棋 （两人对弈的策略型棋类游戏）\n"
                "五子棋是全国智力运动会竞技项目之一，是一种两人对弈的纯策略型棋类游戏。\n"
                "五子棋的棋具与围棋通用，是一种传统的棋种，有两种玩法。\n"
                "一种是双方分别使用黑白两色的棋子，下在棋盘直线与横线的交叉点上，先形成五子连线者获胜。\n"
                "还有一种是自己形成五子连线就替换对方任意一枚棋子。被替换的棋子可以和对方交换棋子。最后以先出完所有棋子的一方为胜。\n"
                "五子棋容易上手，老少皆宜，而且趣味横生，引人入胜：它不仅能增强思维能力，提高智力，而且富含哲理，有助于修身养性。\n");
                printf("五子棋操作方式\n"
                "五子棋阵的上面一行为横坐标，左侧为纵坐标，请通过输入横坐标 空格 纵坐标后回车的形式来下棋\n"
                "输入o，可以查看游戏介绍以及游戏操作说明。");
                printf("是否再次进行一次游戏？\n");
                printf("请输入(y/n):");
            }
            else if(*press=='y'||*press=='Y'){PlayGame();}
        }
    }
}
int main()
{
    system("color 70");//(stdlib.h下的函数)改变控制台背影和前景的颜色
    Introduction();
    RePlayGame();
    return 0;
}