package week1;
import java.util.Scanner;

public class MemoryAllocation {

    public static void main(String[] args) {
        int ms, temp, n = 0;
        int[] mp = new int[10];
        char ch = 'y';

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the total memory available (in Bytes): ");
        ms = sc.nextInt();
        temp = ms;

        for (int i = 0; ch == 'y'; i++, n++) {
            System.out.print("\nEnter memory required for process " + (i + 1) + " (in Bytes): ");
            mp[i] = sc.nextInt();

            if (mp[i] <= temp) {
                System.out.println("\nMemory is allocated for Process " + (i + 1));
                temp = temp - mp[i];
            } else {
                System.out.println("\nMemory is Full");
                break;
            }

            System.out.print("\nDo you want to continue(y/n): ");
            ch = sc.next().charAt(0);
        }

        System.out.println("\n\nTotal Memory Available: " + ms);
        System.out.println("\n\tPROCESS\t\tMEMORY ALLOCATED");

        for (int i = 0; i < n; i++) {
            System.out.println("\n\t" + (i + 1) + "\t\t" + mp[i]);
        }

        System.out.println("\nTotal Memory Allocated is " + (ms - temp));
        System.out.println("Total External Fragmentation is " + temp);

        sc.close();
    }
}

