import java.util.Scanner;
import java.util.Arrays;
/*
 * class Test{
	int a=0;
	String b="";
	Test(int a,String b){
		this.a=a;
		this.b=b;
	}
	void test1() {
		System.out.println("Hello");
	}
	void test2() {
		this.test1();
		System.out.println("Bye");
	}
}
public class suuuu {
	int a=5;
	int b=3;
	public int width() {
		return a*b;
	}
	public static class Test2{
		public int c=7;
	}
	public static void main(String[] args) {
		suuuu su= new suuuu();
		System.out.println(su.width());
		Test t=new Test(5,"Hello");
		System.out.println(t.a);
		t.test2();
		Test2 t2=new Test2();
		System.out.println(t2.c);
	}

}

 */
public class Main {
	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		int n;
        long h;
		n=s.nextInt();
		h=s.nextLong();
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		Arrays.sort(arr);
		long sum=0;
		for(int i=0;i<n;i++) {
			sum+=arr[i];
			if(sum>=h) {
				System.out.print(i+1);
				return;
			}
		}
		System.out.print(-1);
	}

}
