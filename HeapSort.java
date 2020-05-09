package Heap;

import static java.lang.Math.ceil;
import java.util.Scanner;

public class HeapSort {

    public static void main(String[] args) throws Exception {
        System.out.println("Enter max no.of elements:");
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[] a = new int[m];
        System.out.println("Enter no.of elements you want to enter:");
        int n = sc.nextInt();
        if (n > m) {
            System.out.println("Invalid range");
            System.exit(0);
        }
        for (int i = 0; i < n; i++) {
            a[i] = -1;
        }
        System.out.println("Enter Elements:");
        for (int i = 0; i < n; i++) {
            percolateUp(sc.nextInt(), a, i);
        }
        int size=n;
        System.out.println("The Max Heap Representation is:");
        for (int i = 0; i < n; i++) {
            System.out.println(" " + i + ": " + a[i]);
        }
        System.out.println("After Sorting:");
        while (n > 0) {
            n--;
            int element = deleteFromHeap(a, n);
          a[n]=element;
        }
        for (int i = 0; i < size; i++) {
            System.out.println(" " + i + ": " + a[i]);
        }        
    }

    private static void percolateUp(int nextInt, int[] a, int i) throws Exception {
        a[i] = nextInt;
        int temp = 0;
        while (i > 0 && a[((int) (ceil((double) i / 2))) - 1] < nextInt) {
            temp = nextInt;
            a[i] = a[((int) (ceil((double) i / 2))) - 1];
            a[((int) (ceil((double) i / 2))) - 1] = temp;
            i = ((int) (ceil((double) i / 2))) - 1;
        }

    }

    private static int deleteFromHeap(int[] a, int n) {

        int element = a[0];
        a[0] = a[n];
        int parentpos = 0;
        int parent = a[parentpos];
        int maxchildpos = 0;
        int maxchild = 0;
        if (((2 * parentpos) + 1) < n) {
            maxchildpos = maxchildposition(a, parentpos, n);
            maxchild = a[maxchildpos];
        }
        while (maxchild > parent) {
            swap(a, parentpos, maxchildpos);
            parentpos = maxchildpos;
            if (((2 * parentpos) + 1) < n) {
                maxchildpos = maxchildposition(a, parentpos, n);
                maxchild = a[maxchildpos];
            } else {
                break;
            }

        }
        return element;
    }

    private static int maxchildposition(int[] a, int parentpos, int n) {
        int i = parentpos;
        if (((2 * i) + 2) > (n)) {
            return (2 * i) + 1;
        }
        if (a[(2 * i) + 1] > a[(2 * i) + 2]) {
            return (2 * i) + 1;
        } else {
            return (2 * i) + 2;
        }
    }

    private static void swap(int[] a, int parentpos, int maxchildpos) {
        int temp = a[parentpos];
        a[parentpos] = a[maxchildpos];
        a[maxchildpos] = temp;
    }

}
