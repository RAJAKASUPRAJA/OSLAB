package oslab;
import java.util.Scanner;

class Process {
    int burstTime;
    int waitingTime;
    int turnaroundTime;

    public Process(int burstTime) {
        this.burstTime = burstTime;
    }
}