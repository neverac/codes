import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger[][] c = new BigInteger[310][310];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i <= 300; ++i) {
            c[i][0] = BigInteger.valueOf(1);
            c[i][i] = BigInteger.valueOf(1);
            for (int j = 1; j < i; ++j)
                c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
        }
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt(), k = in.nextInt(), d = in.nextInt();
            System.out.println(c[n][k].toString(d));
        }
    }


}