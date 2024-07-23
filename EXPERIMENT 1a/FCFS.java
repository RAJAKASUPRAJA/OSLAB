package oslab;
import java.util.Scanner;
public class FCFS {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of processes -- ");
        int n = sc.nextInt();
        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter Burst Time for Process " + i + " -- ");
            int burstTime = sc.nextInt();
            processes[i] = new Process(burstTime);
        }

        calculateWaitingTime(processes);
        calculateTurnaroundTime(processes);

        printResults(processes);
        
    }

    private static void calculateWaitingTime(Process[] processes) {
        processes[0].waitingTime = 0;
        for (int i = 1; i < processes.length; i++) {
            processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        }
    }

    private static void calculateTurnaroundTime(Process[] processes) {
        for (Process process : processes) {
            process.turnaroundTime = process.waitingTime + process.burstTime;
        }
    }

    private static void printResults(Process[] processes) {
        int totalWaitingTime = 0;
        int totalTurnaroundTime = 0;

        System.out.println("\nOUTPUT");
        System.out.println("PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");

        for (int i = 0; i < processes.length; i++) {
            System.out.println("P" + i + "\t" + processes[i].burstTime + "\t\t" + processes[i].waitingTime + "\t\t" + processes[i].turnaroundTime);
            totalWaitingTime += processes[i].waitingTime;
            totalTurnaroundTime += processes[i].turnaroundTime;
        }

        System.out.printf("Average Waiting Time-- %.6f\n", (double) totalWaitingTime / processes.length);
        System.out.printf("Average Turnaround Time -- %.6f\n", (double) totalTurnaroundTime / processes.length);
    }

}