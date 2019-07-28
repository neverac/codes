import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int t;t=cin.nextInt();
        while(t-->0) {
        	BigInteger a,b;
        	int c;
        	a = cin.nextBigInteger(); b = cin.nextBigInteger(); c = cin.nextInt();
        	if (b.compareTo(a.subtract(b))>0){
        		b=a.subtract(b);
        	}
        	BigInteger sum1=BigInteger.ONE,sum2=BigInteger.ONE;
        	while(true) {
        		sum1=sum1.multiply(a);
        		sum2=sum2.multiply(b);
        		a=a.subtract(BigInteger.ONE);
        		b=b.subtract(BigInteger.ONE);
        		if(b.compareTo(BigInteger.ZERO)==0)break;
        	}
        	BigInteger sum=sum1.divide(sum2);
        	String er=new BigInteger(sum.toString(),10).toString(c);
        	System.out.println(er);
        }
    }
}