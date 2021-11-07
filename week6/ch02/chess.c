#include "three_chess.h"

void menu() {
	printf("****************\n");
	printf("****1.play******\n");
	printf("****0.exit******\n");
	printf("****************\n");
}

void init_board(char arr[][COLS], int x, int y) { //传数组时一般要把数组的下标也传进来
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			arr[i][j] = ' ';//将二维数组初始化为空格
		}
	}
}

void print_board(char arr[][COLS], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		printf("%c |%c |%c\n", arr[i][0], arr[i][1], arr[i][2]);

		if (i < 2) { //一共打印三行棋盘，则在打印第三行时不打印下边的横线
			printf("--|--|--\n");
		}
	}
}


void player_move(char arr[][COLS]) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入你要下的坐标>");
		scanf("%d %d", &x, &y);
		x--;//数组元素的下标是从0开始，所以需要减一
		y--;

		if (arr[x][y] == ' ') { //如果这个下标下的元素为空格，则将p赋给这个元素
			arr[x][y] = 'p';
			break;//跳出循环
		} else {
			printf("你输入的下标已被占，请重新输入\n>");
			continue;//跳出本次循环
		}

	}
}


int check_full(char arr[][COLS], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (arr[i][j] == ' ') { //判断数组中有没有空格，如果出现一次空格，就已经可以证明数组没满
				return 0;
			}
		}
	}
	return 1;//如果程序可以执行到这里，说明数组已经满了，则返回0
}

void computer_move(char arr[][COLS]) {
	srand((unsigned int)time(NULL));//为了每次产生不同的随机数
	while (1) {
		int x = rand() % 3; //产生一个小于3的数
		int y = rand() % 3;
		if (check_full(arr, ROWS, COLS) == 0) { //判断棋盘是否已经满了
			if (arr[x][y] == ' ') { //判断这个元素是否为空
				arr[x][y] = 'c';//如果为空，则赋c给这个元素
				break;//跳出这层循环
			} else {
				continue;//继续执行下一次的循环
			}
		}

	}
}



char check_win(char arr[][COLS], int x, int y) {
	int i = 0;
	if (check_full(arr, ROWS, COLS) == 1) { //如果棋盘满了，则返回q
		return 'q';
	}
	for (i = 0; i < x; i++) {
		if ((arr[i][0] == arr[i][1]) && arr[i][1] == arr[i][2]) {
			return arr[i][0];//返回三个元素中的任一个元素
		}
	}

	for (i = 0; i < y; i++) {
		if ((arr[0][i] == arr[1][i]) && arr[1][i] == arr[2][i]) {
			return arr[1][i];
		}
	}

	if ((arr[0][0] == arr[1][1]) && arr[1][1] == arr[2][2]) {
		return arr[0][0];
	}

	if ((arr[0][2] == arr[1][1]) && arr[1][1] == arr[2][0]) {
		return arr[1][1];
	}

	return ' ';//如果没有判断出谁赢并且棋盘还没满，则继续进行游戏
}



#include "three_chess.h"

void game() { //游戏开始
	char ret = 0;
	char arr[ROWS][COLS];
	init_board(arr, ROWS, COLS);//初始化棋盘
	print_board(arr, ROWS, COLS);//打印棋盘
	do {
		player_move(arr);//玩家先走
		print_board(arr, ROWS, COLS); //打印出棋盘
		if (check_win(arr, ROWS, COLS) != ' ') { //如果棋盘不为空的话，就跳出循环
			break;
		}
		printf("电脑下：\n");
		computer_move(arr);//否则电脑下棋
		print_board(arr, ROWS, COLS); //把电脑下过后的棋盘打印出来
		ret = check_win(arr, ROWS, COLS);//将判断输赢后的返回值保存起来
	} while (ret == ' '); //如果棋盘没有满，同时也没有判断出输赢的话，继续执行循环，否则跳出循环

	if (check_win(arr, ROWS, COLS) == 'p') { //如果判断输赢的返回值为玩家下的字符则就能判断出玩家赢
		printf("玩家赢\n");
	} else if (check_win(arr, ROWS, COLS) == 'c') //如果判断输赢的返回值为c,则可以判断电脑赢

	{
		printf("电脑赢\n");

	} else {
		if (check_win(arr, ROWS, COLS) == 'q') //如果棋盘下满了，即就是返回值为q的时候，则可以判断为平局
			printf("平局\n");
	}

}




int main() {
	int choose = 0;
	do {
		menu();
		printf("请选择>");
		scanf("%d", &choose);
		switch (choose) {
			case 0:
				exit(1);
			case 1:
				game();
		}

	} while (choose);
}