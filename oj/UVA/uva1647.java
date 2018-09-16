import java.math.*;
import java.util.*;
/*
 * 思路：
 * 数列是 0 1 1 3 5 11 21 43
 * 然后从第三项开始*2+1，*2-1，*2+1，*2-1，一直这么运算下去
 * 发现题解竟然是 a[i]=a[i-1]+2*a[i-2],这个更具通用性
 * 做法：
 * 递推要记住预处理，要不然有点浪费
 *
 */
public class Main {
	public static void main(String []args) {
		BigInteger []arr=new BigInteger[1010];
		arr[1]=BigInteger.valueOf(0);
		arr[2]=arr[3]=BigInteger.valueOf(1);
		for(int i=4;i<=1000;i++) {
			if(i%2==1)arr[i]=arr[i-1].multiply(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(1));
			else arr[i]=arr[i-1].multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1));
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()) {
			int n=cin.nextInt();
			System.out.println(arr[n]);
		}
	}

}
