import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		BigInteger[] arr=new BigInteger [10005];
		arr[0]=arr[1]=arr[2]=new BigInteger(0+"");
		arr[3]=new BigInteger(4+"");
		arr[4]=new BigInteger(7+"");
		for(int i=5;i<=10000;i++)
			arr[i]=arr[i-1].add(arr[i-2]);//这个地方一开始写成了arr[i]=arr[i].add(arr[i-1]).add(arr[i-2]),RE了
		Scanner in=new Scanner(System.in);
		while(in.hasNextInt())//EOF结尾输入用hasNext()
		{
			int n=in.nextInt();
			System.out.println(arr[n]);
		}
	}
}
