import java.util.Scanner;

public class DiffEq {

	interface Func {
		// 修飾子を省略すると public になる
		double func(double x, double y);
	}

	public static void main(String[] args) {
		int n;

		System.out.print("分割数を入力してください--->");
		n = (new Scanner(System.in)).nextInt();

		// 一見呼び出しの形が同じだが、
		// Cのほうは関数を関数ポインタで与えている。
		// Javaバージョンでは関数を実装するインターフェースで与える。
		euler(0.0, 1.0, 0.0, 1.0, n, func);
		return;
	}

	/* オイラー法 */
	public static void euler(double x, double y, double a, double b, int n, Func f) {

		double h;
		int i;
		h = (b - a) / n; /* 刻み幅 */

		for (i = 0; i < n; i++) {
			y = y + h * f.func(x, y);
			x += h;
			System.out.printf("x=%f\t y=%f\n", x, y);
		}
	}

	static Func func = new Func() {
		/* 関数の定義 */
		public double func(double x, double y) {
			return (x + y);
		}
	};
}
