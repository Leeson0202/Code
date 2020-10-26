import java.util.Scanner;

public class myapp {
    public static void main(String[] args) {
        int a, b;
        myapp mp = new myapp();
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入a:");
        a = sc.nextInt();
        System.out.print("请输入b:");
        b = sc.nextInt();
        int max = mp.max(a, b);
        System.out.println("最大值为：" + max);

    }

    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }

    }
}