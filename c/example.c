// [Visual Studio 2015] scanf()を使う
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include "cpgplot.h"

/* 関数の定義*/
double func(double x, double y);

/* オイラー法*/
void euler(double x, double y, double a, double b, int n, double(*f)(double, double));


int main(void) {
	int n;

	printf("分割数を入力してください--->");
	if (scanf_s("%d", &n) == 0) {
		printf("読み込みエラー\n");
		return 0;
	}

	/* pgplot を使った描画の初期設定*/
//	cpgopen("/CGW"); /* Linux の場合は"/xserv" */
//	cpgpap(8.0, 0.5); // グラフィック画面の横幅（インチ）と縦横比
//	cpgsch(2.0); // 文字の高さ
//	cpgenv(0., 1.0, 0., 5.0, 0, 0);
	/* 初期設定以上*/
//	cpgmove(0.0, 1.0); /* 最初のペンの位置*/

	euler(0.0, 1.0, 0.0, 1.0, n, func);


	// 終了時にEnter入力を要求する
	fflush(stdin);
	getchar();

	return 0;
}


/* オイラー法*/
void euler(double x, double y, double a, double b, int n, double(*f)(double, double)) {
	double h;
	int i;
	h = (b - a) / n; /* 刻み幅*/

	for (i = 0; i < n; i++) {
		y = y + h * (*f)(x, y);
		x += h;
		printf("x=%f \t y=%f \n", x, y);
//		cpgdraw(x, y); /* 前の位置から現在位置まで線を引く*/
	}
}


/* 関数の定義*/
double func(double x, double y) {
	return(x + y);
}
