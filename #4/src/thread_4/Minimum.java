package thread_4;

import java.util.concurrent.Callable;

class Minimum implements Callable<Double>
{
	private double [] tab;
	public Minimum(double[] tab) {
		this.tab=tab;
	}
	public Double call() {
		double max=Double.POSITIVE_INFINITY;
		for(double val:this.tab) {
			if(val<=max) {
				max=val;
			}
		}
		return new Double(max);
	}
}