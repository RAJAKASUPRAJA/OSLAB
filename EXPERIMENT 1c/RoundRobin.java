package oslab;
import java.util.Scanner;
public class RoundRobin {
	    public static void main(String[] args) {
	        int i, j, n, t, max;
	        int[] bu = new int[10];
	        int[] wa = new int[10];
	        int[] tat = new int[10];
	        int[] ct = new int[10];
	        float awt = 0, att = 0, temp = 0;

	        Scanner scanner = new Scanner(System.in);
	        System.out.print("Enter the number of processes: ");
	        n = scanner.nextInt();

	        for (i = 0; i < n; i++) {
	            System.out.print("\nEnter Burst Time for process " + (i + 1) + ": ");
	            bu[i] = scanner.nextInt();
	            ct[i] = bu[i];
	        }

	        System.out.print("\nEnter the size of time slice: ");
	        t = scanner.nextInt();
	        max = bu[0];
	        for (i = 1; i < n; i++) {
	            if (max < bu[i]) {
	                max = bu[i];
	            }
	        }

	        for (j = 0; j < (max / t) + 1; j++) {
	            for (i = 0; i < n; i++) {
	                if (bu[i] != 0) {
	                    if (bu[i] <= t) {
	                        tat[i] = (int) temp + bu[i];
	                        temp = temp + bu[i];
	                        bu[i] = 0;
	                    } else {
	                        bu[i] = bu[i] - t;
	                        temp = temp + t;
	                    }
	                }
	            }
	        }

	        for (i = 0; i < n; i++) {
	            wa[i] = tat[i] - ct[i];
	            att += tat[i];
	            awt += wa[i];
	        }

	        System.out.printf("\nThe Average Turnaround time is: %.2f", att / n);
	        System.out.printf("\nThe Average Waiting time is: %.2f", awt / n);
	        System.out.println("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME");
	        for (i = 0; i < n; i++) {
	            System.out.printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
	        }

	        scanner.close();
	    }
	}
