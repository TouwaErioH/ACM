import java.math.*;
import java.util.*;
/*
 * ˼·��
 * ������ 0 1 1 3 5 11 21 43
 * Ȼ��ӵ����ʼ*2+1��*2-1��*2+1��*2-1��һֱ��ô������ȥ
 * ������⾹Ȼ�� a[i]=a[i-1]+2*a[i-2],�������ͨ����
 * ������
 * ����Ҫ��סԤ����Ҫ��Ȼ�е��˷�
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
