import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- != 0) {
            BigInteger q = in.nextBigInteger();
            BigInteger P = in.nextBigInteger();
            BigInteger one = BigInteger.ONE;
            BigInteger two = BigInteger.valueOf(2);
            BigInteger three = BigInteger.valueOf(3);

            // ans = (q-1)*(q-2)/2;
            BigInteger ans = q.subtract(one).multiply(q.subtract(two)).divide(two);

            System.out.println(ans.mod(P));

        }
    }
}