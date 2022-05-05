---
layout: post
title:  "���� �˰��� ����"
date:   2022-05-05 12:25:37 +0900
categories: jekyll update
---
# ���� �˰���
+ ��������
+ ��������
+ ��������
+ ������
+ ������
+ ������

## ��������
+ ���� ������ ù ��° �ڷḦ �� ��° �ڷ���� ������ �ڷ���� ���ʴ�� ���Ͽ� ���� ���� ���� ã�� ù ��°�� ����, �� ��° �ڷḦ �� ��° �ڷ���� ������ �ڷ������ ���ʴ�� ���Ͽ� �� �� ���� ���� ���� ã�� �� ��° ��ġ�� ���� ������ �ݺ��ϸ� ������ �����Ѵ�.

+ �ҽ��ڵ�
```

package sort;

import java.util.Comparator;

public class SelectionSort<T> extends Sort<T>{
    @Override
    public T[] sort(T[] src, Comparator<T> comp) {
        System.out.println(this.getClass().getSimpleName());
        T[] dst = src.clone();

        for (int i = 0; i < dst.length; i++) {
            T min = dst[i];
            int idx = i;

            // �ּڰ� (�ε���)
            for (int j = i; j < dst.length; j++) {
                if(comp.compare(min, dst[j]) > 0) {
                    min = dst[j];
                    idx = j;
                }
            }

            // ���� �����̶� �ּڰ��̶� ��ȯ
            T tmp = dst[i];
            dst[i] = dst[idx];
            dst[idx] = tmp;
        }
        return dst;
    }
}
```
+ �ð����⵵: ��� �迭�� �־����� �ð����⵵�� O(n^2)�̴�.



## ��������
+ ���� ������ ù ��° �ڷ�� �� ��° �ڷḦ, �� ��° �ڷ�� �� ��° �ڷḦ, �� ��°�� �� ��°��, �� �̷� ������ (������-1)��° �ڷ�� ������ �ڷḦ ���Ͽ� ��ȯ�ϸ鼭 �ڷḦ �����Ѵ�.
+ �ѹ� �����ϸ� ������ �迭�� ���� ū���� ����ǰ� �� ���� �����Ͽ� 1�������� �ݺ��Ѵ�

+ �ҽ��ڵ�
```
package sort;

import java.util.Comparator;

public class BubbleSort<T> extends Sort<T>{
    public T[] sort(T[] src, Comparator<T> comp) {
        System.out.println(this.getClass().getSimpleName());
        T[] dst = src.clone();

        for (int i = 0; i < dst.length; i++) {
            for (int j = 0; j < dst.length - 1 - i; j++) {
                if(comp.compare(dst[j], dst[j+1]) > 0) {
                    T tmp = dst[j];
                    dst[j] = dst[j + 1];
                    dst[j + 1] = tmp;
                }
            }
        }

        return dst;
    }
}
```
+ �ð����⵵: �ֻ� �־� ��� ��� O(n^2)
+ ���������� ������ �ſ� ���������� Ư����Ұ� ����������ġ�� �ִ��� ��ȯ�� �߻��ϰ� �̵��۾��� �����ϴ�.

## ��������
+ ���� ������ �� ��° �ڷ���� �����Ͽ� �� ���� �ڷ��� ���Ͽ� ������ ��ġ�� ������ �� �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰����̴�.
+ �� ��° �ڷ�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°, �� ��°, ù ��° �ڷ�� ���� �� �ڷᰡ ���Ե� ��ġ�� ã�´�. �ڷᰡ ���Ե� ��ġ�� ã�Ҵٸ� �� ��ġ�� �ڷḦ �����ϱ� ���� �ڷḦ �� ĭ�� �ڷ� �̵���Ų��.
+ �ҽ��ڵ�
```
public class Insertion_Sort {
 
	public static void insertion_sort(int[] a) {
		insertion_sort(a, a.length);
	}
	
	private static void insertion_sort(int[] a, int size) {
		
		
		for(int i = 1; i < size; i++) {
			
			int target = a[i];
			
			int j = i - 1;
			
			while(j >= 0 && target < a[j]) {
				a[j + 1] = a[j];
				j--;
			}
			
			
			a[j + 1] = target;	
		}
		
	}
}
```
+ �ð����⵵: �ּ��� ��� O(n) �־�(�迭�� �������ϰ��),����ϰ�� O(n^2)
+ ���������� �Է°����� �۰� �迭�� ������ ���������� �����ϴ�. �׷��� �迭�� �Է°����� ���� ������ �Ǿ��������� ����ϱ� �������ϴ�.

## ������
+ ���������� ������ ���ľ˰���
+ ������ k���ϸ� �ѹ� ���ľ˰����� �ݺ��ɶ����� k�� ������ ���δ�.
+ ������ �������� ���� ������ �迭�� ���Ͽ� ���������� �����Ѵ�.
```
public class ShellSort {
    public static void main(String[] args) {
       
        
        for(int h = N / 2; h > 0; h /= 2) {           
            for(int i = h; i < N; i++) {             
                int j;
                int temp = arr[i];                   
                
                for(j = i - h; j >= 0 && arr[j] > temp; j -= h) {   j = i - h 
                    arr[j + h] = arr[j];                           
                }
                arr[j + h] = temp;                                   
            }
        }
        
        
        }
    }
 
}

```
+ ���������� ���� �κ� ����Ʈ���� �ڷ��� ��ȯ�� �Ͼ�� �� ū �Ÿ��� �̵��Ѵ�. ���� ��ȯ�Ǵ� ��ҵ��� ���� ���ĺ��ٴ� ���� ��ġ�� ���� ���ɼ��� ��������.
+ �κ� ����Ʈ�� ��� ���� ������ �� �����̱� ������ �κ� ����Ʈ�� ������ 1�� �ǰ� �Ǹ� �� ������ �⺻������ ���� ������ �����ϴ� �������� ���� ���ĺ��� ���� ������ ����ȴ�.

+ �ð����⵵ : �ּ��ϰ�� O(N) ���O(N^1.5) �־�O(N^2)

## ������
+ ����(Divide): �Է� �迭�� �ǹ��� �������� ��յ��ϰ� 2���� �κ� �迭(�ǹ��� �߽����� ����: �ǹ����� ���� ��ҵ�, ������: �ǹ����� ū ��ҵ�)�� �����Ѵ�.
+ ����(Conquer): �κ� �迭�� �����Ѵ�. �κ� �迭�� ũ�Ⱑ ����� ���� ������ ��ȯ ȣ�� �� �̿��Ͽ� �ٽ� ���� ���� ����� �����Ѵ�.
+ ����(Combine): ���ĵ� �κ� �迭���� �ϳ��� �迭�� ��ģ��.

+ �ҽ��ڵ�
```
public class qucikSort {
    private static void quickSort(int[] arr,int start, int end) {
        int part=partition(arr,start,end);
        if(start<part-1) quickSort(arr,start,part-1);
        if(end>part) quickSort(arr,part,end);
    }

    private static int partition(int[] arr,int start,int end) {
        int pivot=arr[(start+end)/2];
        while(start<=end) {
            while(arr[start]<pivot) start++;
            while(arr[end]>pivot) end--;
            if(start<=end) {
                swap(arr,start,end);
                start++;
                end--;
            }
        }
        return start;
    }

    private static void swap(int[] arr,int start,int end) {
        int tmp=arr[start];
        arr[start]=arr[end];
        arr[end]=tmp;
        return;
    }

```
+ �ð����⵵: �ּ��϶� O(nlog2 n) ���O(nlog2 n) �־��϶� O(n^2)
+ �ӵ��� ������ �߰� �޸� ������ �ʿ������ ������ �ǹ��� ���� ���ҵɶ� �ұ����ϰ� ������ �Ǹ� ����ð��� �����Ѵ�.
## ������
+ �ִ� �� Ʈ���� �ּ� �� Ʈ���� ������ ������ �ϴ� ���
�������� ������ ���ؼ��� �ִ� ���� �����ϰ� �������� ������ ���ؼ��� �ּ� ���� �����ϸ� �ȴ�.
+ �����ؾ��� �迭�� ��ҵ�� ���� ����Ʈ���� �����
+ Ʈ������ ���� �ϳ��� �����鼭 �迭�� �����Ѵ�.
+ �ҽ��ڵ�
```
import java.util.*;

class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("�迭�� ũ�⸦ �Է��Ͻÿ�");
        int n = scanner.nextInt()+1;
        int[] arr = new int[n];

        System.out.println("�迭�� �� ���ڸ� �Է��Ͻÿ�");
        for(int i = 1; i<n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("�迭�� �Է��� ����");
        System.out.println(Arrays.toString(arr));

        buildHeap(arr); //�迭�� ������ ����� �޼���

        System.out.println("������ ������ �迭");
        System.out.println(Arrays.toString(arr));

        heapSort(arr); //���� �̿��ؼ� �����ϴ� �޼���

        System.out.println("���� �Ϸ�� �迭");
        System.out.println(Arrays.toString(arr));
    }

    static void heapSort(int[] arr) {
        int eNN = arr.length-1;
        while(eNN > 1) {
            swap(arr, 1, eNN);
            eNN--;
            pushDown(arr, 1, eNN);
        }
    }

    //eNN = endNodeNumber
    //tNN = tempNodeNumber
    static void buildHeap(int[] arr) {
        int eNN = arr.length - 1; // ������ ���
        int tNN = eNN/2 + 1; //1��° ������� ��ȣ

        while(tNN > 1) {
            tNN--; // �ڽ��� ������ �ִ� ������ ������ ����
            pushDown(arr, tNN, eNN);
        }
    }

    static void pushDown(int[] arr, int tNN, int eNN) {
        int y = findLarger(arr, tNN, eNN); 
        //�ڽ� ����߿��� ��Ʈ ��庸�� �� ū ���� ������ ��� ��ȣ ��

        while(arr[tNN] < arr[y]){
            swap(arr, tNN, y);
            tNN = y;
            y = findLarger(arr, tNN, eNN);
            // leaf��� ������ �������鼭 ���� ���ڸ��� ã�ư���.
        }
    }

    static int findLarger(int[] arr, int tNN, int eNN){
        int tmp = tNN*2+1; //������ �ڽ� ����� ��ȣ
        int y = tNN;

        if(tmp <= eNN){//�ڽ� ��尡 �ΰ��� ���
            if(arr[tNN] < arr[tmp]) //������ �ڽ� ����� value�� �� ũ�ٸ�
                y = tmp;
            if(arr[y] < arr[tmp-1]) //���� �ڽ� ����� value�� �� ũ�ٸ�
                y = tmp-1;
        }
        else if(tmp-1 <= eNN){ //�ڽ� ��尡 1���� ���
            if(arr[tNN] < arr[tmp-1]) // �ڽ� ����� value�� �� ũ�ٸ�
                y = tmp-1;
        }
        return y;
    }

    static void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}
```
+ �ð� ���⵵: �ּ� �־� ��� ��� O(nlog2 n)
+ �ð����⵵�� ���� ��ü �ڷḦ �����ϴ� ���� �ƴ϶� ���� ū �� ��� �ʿ��� �� ���� �����ϴ�.

## ����ð�
+ ��������
<img src="��������.png">
+ ��������
<img src="��������.png">
+ �������� 
<img src="��������.png">
+ ������
<img src="������.png">