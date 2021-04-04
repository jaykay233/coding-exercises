import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.*;

public class Main {
	public static BigInteger Factorial(int n) {
		BigInteger res = BigInteger.ONE;
		for(int i = 1; i <= n; i++)
			res = res.multiply(BigInteger.valueOf(i));
		return res;
	}
	
	public static BigInteger Combination(int n, int m) {
		return Factorial(n).divide(Factorial(m).multiply(Factorial(n-m)));
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n, m;
		BigInteger ans, tmp;
		while(input.hasNext()) {
			n = input.nextInt();
			m = n / 2;
			ans = BigInteger.ONE;
			for(int i = 1; i <= m; i++)
				ans = ans.add(Combination(n-i, i));
			System.out.println(ans);
		}
	}
}