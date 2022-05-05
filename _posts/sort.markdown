---
layout: post
title:  "정렬 알고리즘 정리"
date:   2022-05-05 12:25:37 +0900
categories: jekyll update
---
# 정렬 알고리즘
+ 선택정렬
+ 삽입정렬
+ 버블정렬
+ 셀정렬
+ 힙정렬
+ 퀵정렬

## 선택정렬
+ 선택 정렬은 첫 번째 자료를 두 번째 자료부터 마지막 자료까지 차례대로 비교하여 가장 작은 값을 찾아 첫 번째에 놓고, 두 번째 자료를 세 번째 자료부터 마지막 자료까지와 차례대로 비교하여 그 중 가장 작은 값을 찾아 두 번째 위치에 놓는 과정을 반복하며 정렬을 수행한다.

+ 소스코드
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

            // 최솟값 (인덱스)
            for (int j = i; j < dst.length; j++) {
                if(comp.compare(min, dst[j]) > 0) {
                    min = dst[j];
                    idx = j;
                }
            }

            // 제일 왼쪽이랑 최솟값이랑 교환
            T tmp = dst[i];
            dst[i] = dst[idx];
            dst[idx] = tmp;
        }
        return dst;
    }
}
```
+ 시간복잡도: 어떠한 배열이 주어져서 시간복잡도는 O(n^2)이다.



## 버블정렬
+ 버블 정렬은 첫 번째 자료와 두 번째 자료를, 두 번째 자료와 세 번째 자료를, 세 번째와 네 번째를, … 이런 식으로 (마지막-1)번째 자료와 마지막 자료를 비교하여 교환하면서 자료를 정렬한다.
+ 한번 정렬하면 마지막 배열에 제일 큰값이 저장되고 그 값을 제외하여 1번과정을 반복한다

+ 소스코드
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
+ 시간복잡도: 최상 최악 평균 모드 O(n^2)
+ 버블정렬은 구현이 매우 간단하지만 특정요소가 최종정렬위치에 있더라도 교환이 발생하고 이동작업이 복잡하다.

## 삽입정렬
+ 삽입 정렬은 두 번째 자료부터 시작하여 그 앞의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘이다.
+ 두 번째 자료는 첫 번째 자료, 세 번째 자료는 두 번째와 첫 번째 자료, 네 번째 자료는 세 번째, 두 번째, 첫 번째 자료와 비교한 후 자료가 삽입될 위치를 찾는다. 자료가 삽입될 위치를 찾았다면 그 위치에 자료를 삽입하기 위해 자료를 한 칸씩 뒤로 이동시킨다.
+ 소스코드
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
+ 시간복잡도: 최선일 경우 O(n) 최악(배열이 역정렬일경우),평균일경우 O(n^2)
+ 삽입정렬은 입력개수가 작고 배열이 정렬이 되있을수록 유리하다. 그러나 배열의 입력개수가 많고 역정렬 되어있을수록 사용하기 부적합하다.

## 셀정렬
+ 삽입정렬을 보완한 정렬알고리즘
+ 구간을 k라하면 한번 정렬알고리즘이 반복될때마다 k를 반으로 줄인다.
+ 구간을 기준으로 나눈 각각의 배열을 비교하여 삽입정렬을 진행한다.
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
+ 연속적이지 않은 부분 리스트에서 자료의 교환이 일어나면 더 큰 거리를 이동한다. 따라서 교환되는 요소들이 삽입 정렬보다는 최종 위치에 있을 가능성이 높아진다.
+ 부분 리스트는 어느 정도 정렬이 된 상태이기 때문에 부분 리스트의 개수가 1이 되게 되면 셸 정렬은 기본적으로 삽입 정렬을 수행하는 것이지만 삽입 정렬보다 더욱 빠르게 수행된다.

+ 시간복잡도 : 최선일경우 O(N) 평균O(N^1.5) 최악O(N^2)

## 퀵정렬
+ 분할(Divide): 입력 배열을 피벗을 기준으로 비균등하게 2개의 부분 배열(피벗을 중심으로 왼쪽: 피벗보다 작은 요소들, 오른쪽: 피벗보다 큰 요소들)로 분할한다.
+ 정복(Conquer): 부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출 을 이용하여 다시 분할 정복 방법을 적용한다.
+ 결합(Combine): 정렬된 부분 배열들을 하나의 배열로 합친다.

+ 소스코드
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
+ 시간복잡도: 최선일때 O(nlog2 n) 평균O(nlog2 n) 최악일때 O(n^2)
+ 속도가 빠르고 추가 메모리 공간을 필요로하지 않지만 피벗에 의해 분할될때 불균형하게 분할이 되면 수행시간이 증가한다.
## 힙정렬
+ 최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법
내림차순 정렬을 위해서는 최대 힙을 구성하고 오름차순 정렬을 위해서는 최소 힙을 구성하면 된다.
+ 정렬해야할 배열의 요소들로 완전 이진트리를 만든다
+ 트리에서 값을 하나씩 꺼내면서 배열에 저장한다.
+ 소스코드
```
import java.util.*;

class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("배열의 크기를 입력하시오");
        int n = scanner.nextInt()+1;
        int[] arr = new int[n];

        System.out.println("배열에 들어갈 숫자를 입력하시오");
        for(int i = 1; i<n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("배열에 입력한 숫자");
        System.out.println(Arrays.toString(arr));

        buildHeap(arr); //배열을 힙으로 만드는 메서드

        System.out.println("힙으로 변경한 배열");
        System.out.println(Arrays.toString(arr));

        heapSort(arr); //힙을 이용해서 정렬하는 메서드

        System.out.println("정렬 완료된 배열");
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
        int eNN = arr.length - 1; // 마지막 노드
        int tNN = eNN/2 + 1; //1번째 리프노드 번호

        while(tNN > 1) {
            tNN--; // 자식을 가지고 있는 마지막 노드부터 시작
            pushDown(arr, tNN, eNN);
        }
    }

    static void pushDown(int[] arr, int tNN, int eNN) {
        int y = findLarger(arr, tNN, eNN); 
        //자식 노드중에서 루트 노드보다 더 큰 값을 가지는 노드 번호 얻어냄

        while(arr[tNN] < arr[y]){
            swap(arr, tNN, y);
            tNN = y;
            y = findLarger(arr, tNN, eNN);
            // leaf노드 쪽으로 내려가면서 값의 제자리를 찾아간다.
        }
    }

    static int findLarger(int[] arr, int tNN, int eNN){
        int tmp = tNN*2+1; //오른쪽 자식 노드의 번호
        int y = tNN;

        if(tmp <= eNN){//자식 노드가 두개인 경우
            if(arr[tNN] < arr[tmp]) //오른쪽 자식 노드의 value가 더 크다면
                y = tmp;
            if(arr[y] < arr[tmp-1]) //왼쪽 자식 노드의 value가 더 크다면
                y = tmp-1;
        }
        else if(tmp-1 <= eNN){ //자식 노드가 1개인 경우
            if(arr[tNN] < arr[tmp-1]) // 자식 노드의 value가 더 크다면
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
+ 시간 복잡도: 최선 최악 평균 모두 O(nlog2 n)
+ 시간복잡도가 좋고 전체 자료를 정렬하는 것이 아니라 가장 큰 값 몇개만 필요할 때 가장 유용하다.

## 수행시간
+ 버블정렬
<img src="버블정렬.png">
+ 선택정렬
<img src="선택정렬.png">
+ 삽입정렬 
<img src="삽입정렬.png">
+ 퀵정렬
<img src="퀵정렬.png">