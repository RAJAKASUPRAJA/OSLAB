package oslab;
import java.util.Scanner;
public class Priority {
	

	    public static void main(String[] args) {
	        int[] p = new int[20];
	        int[] bt = new int[20];
	        int[] pri = new int[20];
	        int[] wt = new int[20];
	        int[] tat = new int[20];
	        int i, k, n, temp;
	        float wtavg, tatavg;

	        Scanner scanner = new Scanner(System.in);
	        System.out.print("Enter the number of processes --- ");
	        n = scanner.nextInt();

	        for (i = 0; i < n; i++) {
	            p[i] = i;
	            System.out.print("Enter the Burst Time & Priority of Process " + i + " --- ");
	            bt[i] = scanner.nextInt();
	            pri[i] = scanner.nextInt();
	        }

	        for (i = 0; i < n; i++) {
	            for (k = i + 1; k < n; k++) {
	                if (pri[i] > pri[k]) {
	                    temp = p[i];
	                    p[i] = p[k];
	                    p[k] = temp;
	                    temp = bt[i];
	                    bt[i] = bt[k];
	                    bt[k] = temp;
	                    temp = pri[i];
	                    pri[i] = pri[k];
	                    pri[k] = temp;
	                }
	            }
	        }

	        wtavg = wt[0] = 0;
	        tatavg = tat[0] = bt[0];

	        for (i = 1; i < n; i++) {
	            wt[i] = wt[i - 1] + bt[i - 1];
	            tat[i] = tat[i - 1] + bt[i];
	            wtavg += wt[i];
	            tatavg += tat[i];
	        }

	        System.out.println("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	        for (i = 0; i < n; i++) {
	            System.out.printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ", p[i], pri[i], bt[i], wt[i], tat[i]);
	        }
	        System.out.printf("\nAverage Waiting Time is --- %f", wtavg / n);
	        System.out.printf("\nAverage Turnaround Time is --- %f", tatavg / n);

	        scanner.close();
	    }
	}
