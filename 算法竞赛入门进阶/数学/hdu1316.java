import java.util.Scanner;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigInteger[] f = new BigInteger[500];
        f[1] = new BigInteger("1");
        f[2] = new BigInteger("2");
        for(int i=3;i<f.length;i++)
            f[i] = f[i-1].add(f[i-2]);
        while(in.hasNext()){
            int ans = 0;
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0)
                break;
            for(int i=1;i<f.length;i++){
                if(f[i].compareTo(a) >=0 && f[i].compareTo(b)<=0)
                    ans++;
                if(f[i].compareTo(b) == 1)
                    break;
            }
            System.out.println(ans);
            ans = 0;
        }
    }
}