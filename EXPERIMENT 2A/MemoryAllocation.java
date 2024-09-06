import java.util.Scanner;

public class MemoryAllocation {

    public static void main(String[] args) {
        int ms, bs, nob, ef, n;
        int[] mp = new int[10];
        int tif = 0;
        int p = 0;

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the total memory available (in Bytes): ");
        ms = sc.nextInt();

        System.out.print("Enter the block size (in Bytes): ");
        bs = sc.nextInt();

        nob = ms / bs;
        ef = ms - nob * bs;

        System.out.print("Enter the number of processes: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter memory required for process " + (i + 1) + " (in Bytes): ");
            mp[i] = sc.nextInt();
        }

        System.out.println("\nNo. of Blocks available in memory: " + nob);
        System.out.println("\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

        for (int i = 0; i < n && p < nob; i++) {
            System.out.print("\n " + (i + 1) + "\t\t" + mp[i]);
            if (mp[i] > bs) {
                System.out.print("\t\tNO\t\t---");
            } else {
                System.out.print("\t\tYES\t" + (bs - mp[i]));
                tif += bs - mp[i];
                p++;
            }
        }

        if (p < n) {
            System.out.println("\nMemory is Full, Remaining Processes cannot be accommodated.");
        }

        System.out.println("\n\nTotal Internal Fragmentation is " + tif);
        System.out.println("Total External Fragmentation is " + ef);

        sc.close();
    }
}