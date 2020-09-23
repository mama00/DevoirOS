package thread_4;

import java.util.concurrent.Callable;

public class Average implements Callable<Double>
{
	private double [] tab;
	public Average(double[] tab) {
		this.tab=tab;
	}
	public Double call() {
		double sum=0;
		for(double val:this.tab) {
			sum+=val;
			}
		
		return new Double(sum/this.tab.length);
	}
}