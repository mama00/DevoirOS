package thread_4;

import java.util.concurrent.Callable;

class Maximum implements Callable<Double>
{
	private double [] tab;
	public Maximum(double[] tab) {
		this.tab=tab;
	}
	public Double call() {
		double max=0;
		for(double val:this.tab) {
			if(val>=max) {
				max=val;
			}
		}
		return new Double(max);
	}
}