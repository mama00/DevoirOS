package thread_4; 
import java.util.Scanner;
import java.util.concurrent.*;

public class Main {

	public static void main(String[] args) {
		double[] tab_values=get_values();
		ExecutorService pool=Executors.newFixedThreadPool(3);
		Future<Double> result_maximum = pool.submit(new Maximum(tab_values));
		Future<Double> result_minimum = pool.submit(new Minimum(tab_values));
		Future<Double> result_average = pool.submit(new Average(tab_values));


		try {
			System.out.println("Max = " + result_maximum.get());
			System.out.println("Min = " + result_minimum.get());
			System.out.println("Average = " + result_average.get());
		} 
		catch (InterruptedException | ExecutionException ie) {}
	}
	
	public static double[] get_values() {
		Scanner in = new Scanner(System.in);
		int i=0;
		System.out.println("Entrer les valeurs");
		String value=in.nextLine();
		double[] tab_values=new double[value.split(" ").length];
		for(String vv: value.split(" ")) {
			tab_values[i]=Double.parseDouble(vv);
			i++;
		}
		return tab_values;
	}

}
