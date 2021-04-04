import java.io.*;
import java.math.*;
import java.util.*;

public class Main{ 
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            BigDecimal ans = cin.nextBigDecimal();
            int n = cin.nextInt();
            String res = ans.pow(n).stripTrailingZeros().toPlainString();
            if(res.startsWith("0")){
                res = res.substring(1);
            }
            System.out.println(res);
        }
    }
}