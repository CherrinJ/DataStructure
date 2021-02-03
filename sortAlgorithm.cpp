#include<iostream>
#include<algorithm>
#include<list>
#include <vector>
#include <map>

using namespace std;

template<class T>
int getArrayLen(T& arr){
    return (sizeof(arr)/sizeof(arr[0]));
}

template<size_t SIZE>
int getArrayLen2(int (&arr)[SIZE]){
    return (sizeof(arr)/sizeof(arr[0]));
}


template<size_t SIZE>
void printArr(int (&arr)[SIZE]){
    for(int i =0; i < SIZE; ++i){
        cout << arr[i]<< ", ";
    }
    cout<<endl;
}

//插入排序
 void insertSort2(){
    int arr[] = {3,1,7,5,2,4,9,6};
    int len = getArrayLen2(arr);
    int t = arr[0];
    list<int> _arr;
    for(int i =0 ; i < len; ++i){
        if(_arr.empty()){
            _arr.push_back(arr[i]);
        } else {
            bool insert = false;
            for(auto it = _arr.begin(); it != _arr.end(); ++it){
                if(arr[i] < *it){
                    _arr.insert(it, arr[i]);
                    insert = true;
                    break;
                }
            }
            if(!insert)
                _arr.push_back(arr[i]);
        }
    }

    for(auto v:_arr){
        cout << v<< ", ";
    }
 }

//直接插入
template<size_t ArrSize>
void InsertSort1(int (&arr)[ArrSize]){
    int t = arr[0];
    for(int i = 0; i < ArrSize; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[j] > arr[i]){
                    t = arr[i];
                    for(int k = i; k >= j + 1; --k){
                        arr[k] = arr[k - 1];
                    }
                    arr[j] = t;
                    break;
                }
            }
        
    }
}

//折半插入
template<size_t SIZE>
void HalfInsertSort(int (&arr)[SIZE]){
    int low = 0, high = 0;
   for(int i = 0; i < SIZE; ++i){
       int temp = arr[i];
       high = i - 1;
       low = 0;
       while(low <= high){
            int mid = (low+high) / 2;
            if(temp >= arr[mid]){
                low = mid+1;
            } else {
                high = mid - 1;
            }
       }

       int t = arr[high];
       for(int j = i; j > low; --j){
           arr[j] = arr[j - 1];
       }
       arr[low] = temp;
   }
        
}

//2路插入
template<size_t SIZE>
void CircleInsertSort(int (&arr)[SIZE]){
    int temp[SIZE] = {0};
    temp[0] = arr[0];
    int first = 0, end = 0;

    for(int i = 1; i < SIZE; ++i){
        int t = arr[i];
        if(temp[first] > t){
            first = SIZE - 1 - first;
            temp[first] = t;
        } else if(temp[end] <= t){
            end += 1;
            temp[end] = t;
        } else {
            int t_end = end;
            
            while(temp[t_end] > t){
                temp[t_end + 1] = temp[t_end];
                t_end = (t_end - 1 + SIZE) % SIZE;
            }
            temp[(t_end + 1 + SIZE) % SIZE] = t;
            end = (end + 1 + SIZE) % SIZE;
        }
    }

    for(int i = 0; i < SIZE; ++i){
        arr[i] = temp[(first + i + SIZE) % SIZE];
    }
    
}


template<size_t SIZE>
void HalfSort(int (&arr)[SIZE] ){

}

//冒泡
template<size_t SIZE>
void BaoSort(int (&arr)[SIZE]){
    for(int i = 0; i < SIZE; ++i){
        int a = arr[i];
        for(int j = i+1; j < SIZE; ++j){
            if(a > arr[j]){
                arr[i] = arr[j];
                arr[j] = a;
                a = arr[i];
            }
        }
    }
}

//希尔排序（缩小增量排序）
template<size_t SIZE>
void ShellSort(int (&arr)[SIZE]){
    int gap = SIZE / 2;
    //交换法
    int index = 0;
    while (gap > 0){
        for(int i = gap; i < SIZE; ++i){
            for(int j = i - gap; j >= 0; j -= gap){
                 if(arr[j + gap] < arr[j]){
                    int t = arr[j];
                    arr[j] = arr[j + gap];
                    arr[j + gap] = t;
                }
            }
        }

        index += gap;
        gap = gap / 2;
    }
}

//简单选择排序
template<size_t SIZE>
void SimpleChooseSort(int (&arr)[SIZE], int start = 0, int end = SIZE){
    for(int i = start; i < end; ++i){
        int t = arr[i];
        for(int j = i+1; j < end; ++j){
            if(arr[j] < t){
                arr[i] = arr[j];
                arr[j] = t;                                                                                                                                                      
                t = arr[i];
            }
        }
    }
}

//快速排序，固定位置, 去第一个做固定值
template<size_t SIZE>
void QuickSort1(int (&arr)[SIZE], int start, int end){
    
    if(start >= end) return;
    int pivot = arr[start];
    int s = start+1 , e = end;
    while(true){
        while(s <= e && pivot >= arr[s]){
            ++s;
        }
        while ( s <= e && pivot <= arr[e]){
            --e;
        }

        if(s >= e) break;
        int t = arr[s];
        arr[s] = arr[e];
        arr[e] = t;
    }
    arr[start] = arr[e];
    arr[e] = pivot;
    // cout<<"------------------"<<start<<"--"<<end<<",pivot:" << pivot<<endl;
    cout<<"l,r,j:"<<start<<end<<e<<endl;
    printArr(arr);
    QuickSort1(arr, start, e - 1);
    QuickSort1(arr, e+1, end);

}

//快速排序：随机选取基准
template<size_t SIZE>
void QuickSort2(int (&arr)[SIZE], int start, int end){
    if(start >= end) return;
    // srand(0);
    int randomNum = rand() % (end - start) + start + 1;
    int pivot = arr[randomNum];
    arr[randomNum] = arr[start];
    arr[start] = pivot;

    int s = start+1, e = end;
    while(true){
        while(arr[e] >= pivot && s <= e){
            --e;
        }
        while(arr[s] <= pivot && s <= e){
            ++s;
        }
        if(s >=  e) break;
        int t = arr[s];
        arr[s] = arr[e];
        arr[e] = t;
    }

    arr[start] = arr[e];
    arr[e] = pivot;

    QuickSort2(arr, start, e-1);
    QuickSort2(arr, e+1, end);
}

//快速排序：取中间值做基准
template<size_t SIZE>
void QuickSort3(int (&arr)[SIZE], int start, int end){
    // cout<<"****&&"<<start<<"--"<<end<<endl;
    if(start >=  end) return;

    int mid = (start + end) / 2;
    int pivot = arr[mid];
    arr[mid] = arr[start];
    arr[start] = pivot;

    int s = start + 1, e = end;

    while(true){
        while(s <= e && arr[s] <= pivot){
            ++s;
        }
        while(s <= e && arr[e] >= pivot){
            --e;
        }

        if(s >= e) break;
        cout<<"****"<<s<<"--"<<e<<endl;
        int t = arr[e];
        arr[e] = arr[s];
        arr[s] = t;
    }
    arr[start] = arr[e];
    arr[e] = pivot;
    cout<<"------------------"<<start<<"--"<<end<<",mid,s:"<<mid<<","<<s<<",pivot:" << pivot<<endl;
    printArr(arr);
    QuickSort3(arr, start, e -1);
    QuickSort3(arr, e+1, end);
}

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

    int partition(vector<int>& nums, int l, int r)
	{
		int pivot = nums[l];
		int i = l + 1, j = r;
		while (true)
		{
			while (i <= j && nums[i] <= pivot) i++;//寻找比pivot大的元素
			while (i <= j && nums[j] >= pivot) j--;//寻找比pivot小的元素
			if(i>j) break;
			swap(nums[i], nums[j]);
		}
		//把arr[j]和主元交换
        cout<<"l,r,j:"<<l<<r<<j<<endl;
		swap(nums[j], nums[l]);
		return j;//为什么返回j而不是i，因为swap是先执行i++的while语句，如果和下面的替换顺序，则返回i
	}
	void QuickSort(vector<int>& nums, int l, int r) {
		if (l < r)
		{
			int mid = partition(nums, l, r);
			QuickSort(nums, l, mid - 1);//注意点，l和r的值自己写错
			QuickSort(nums, mid + 1, r);//注意点,l和r的值自己写错
		}
	}

//3路快速排序--快速排序优化（针对相同元素）
template<size_t SIZE>
void QuickSort4(int (&arr)[SIZE],int start, int end ){
    if( start >= end) return;
    // cout<<"start, end:"<<start<<end<<endl;
    // printArr(arr);
    int left = start+1, right = end;
    int gl = start, gr = right + 1;

    int pivot = arr[start];
    while(left < gr){
        int temp = arr[left];
        if(temp < pivot){
            swap(arr[left], arr[gl + 1]);
            ++gl;
            ++left;
        } else if(temp > pivot){
            swap(arr[left], arr[gr - 1]);
            --gr; 
        } else
            ++left;
    }
    swap(arr[start], arr[gl]);
    QuickSort4(arr, start, gl - 1);
    QuickSort4(arr, gr, end);

}

//归并排序
template<size_t SIZE>
void MergeSort(int (&arr)[SIZE], int start, int end){
    if(start >= end) return;
    int n =  (end - start) / 2;
    MergeSort(arr, start, start + n);
    MergeSort(arr, start+n+1 , end);
    return QuickSort4(arr, start , end);
}

//堆排序
template<size_t SIZE>
void StackSort(int (&arr)[SIZE]){
    
}

template<size_t SIZE>
void CoutingSort(int (&arr)[SIZE]){
    int count = 0;
    // int **p = nullptr;
    // map<int, vector<int> > arrMap;
    int minV = 9999999, maxV = 0;
    vector<int> arrCount;
    for(int i = 0; i < SIZE; ++i){
        int c = arr[i];
        maxV = max(c, maxV);
        minV = min(c, minV);
    }
    // int countArr[maxV - minV];
    int numArr[maxV - minV+1];
    // memset(numArr, 0,9);
    for(int i = 0; i <= maxV - minV; ++i){
        numArr[i] = 0;
    }
    for(int i = 0; i < SIZE; ++i){
        // int add = true;
        // int c = arr[i];
        ++numArr[arr[i] - minV];
    }
    // int new_arr[SIZE];/
    for(int i = 0,j = 0; i <= maxV - minV; ++i){
        int value = minV + i;
        if(numArr[i] > 0){
            for(int id = 0; id < numArr[i]; ++id)
                arr[j++] = value;
        }
    }
}

//桶排序,[1-100], 适合排序数值在一定范围内，空间置换时间
template<size_t SIZE>
void BucketSort(int (&arr)[SIZE]){
    int bucketSize = 10;

    int **p =  new int *[10];
    int count[10] = {0};
    for(int i = 0; i < 10; ++i){
        p[i] = new int[10];
        count[i] = 0;
    }

   
    for(int i = 0; i < SIZE; ++i){
        int n = arr[i] / 10;
        ++count[n];
        bool add = true;
        for(int ii = 0; ii < count[n];++ii){
            int t = *(*(p+n))+ii;
            if(arr[i] < t){
                add = false;
                for(int i3 = count[n]; i3 > ii; --i3){
                    *((*(p+n))+i3) = *((*(p+n))+i3 - 1);
                }
                *((*(p+n))+ii) = arr[i];
                break;
            }
        }
        if(add)
            *((*(p+n))+ count[n] - 1) = arr[i];
    }

    for(int i =0; i < 10; ++i){
        for(int j = 0; j < 10; ++j)
            cout<<*(*(p+i))+j<<", ";
        cout<<endl;
    }
    
    int newArr[SIZE] = {0};
    for(int i = 0, k = 0; i < bucketSize; ++i){
        for(int j = 0; j < count[i]; ++j){
            arr[k++] = p[i][j];
        }
    }

    //申请内存的释放
	for (int i = 0 ; i<10 ;i++)  
	{  
		delete p[i];  
		p[i] =NULL;  
	}  
	delete []p;  
	p = NULL; 
}

//基数排序
template<size_t SIZE>
void RadixSort(int (&arr)[SIZE]){
    int minV = arr[0], maxV = arr[0];
    for(int i = 1; i < SIZE; ++i){
        minV = min(minV, arr[i]);
        maxV = max(maxV, arr[i]);
    }
    const int n = 8;//(maxV - minV) / 10;
    int count[n] = {0};
    int **p = new int*[n];
    for(int i = 0; i < n; ++i){
        *(p+i) = new int[10];
        count[i] = 0;
    }
    
    for(int i =0; i < SIZE; ++i){
        int n1 = (arr[i] / 10 - minV / 10);
       
        bool append = true;
        for(int j = 0; j < count[n1]; ++j){
            int t = *(*(p+n1)) + j;
            if(arr[i] < t){
                append = false;
                for(int l = count[n1]; l > j; --l){
                    *((*(p+n1))+l) = *((*(p+n1))+l - 1);
                    break;
                }
                *((*(p+n1))+j) = arr[i];
            }
        }
        if(append)
            *((*(p+n1))+ count[n1]) = arr[i];
         ++count[n1];
    }

    for(int i =0; i < n; ++i){
        for(int j = 0; j < 10; ++j)
            cout<<*(*(p+i))+j<<", ";
        cout<<endl;
    }

    for(int i = 0, k = 0; i <n; ++i){
        for(int j = 0; j < count[i]; ++j){
            arr[k++] = p[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        delete p[i];
        p[i] = nullptr;
    }
    delete []p;
    p = NULL;
}


int main(){
    //  int arr[] = {6,1,2,7,9,3,10,5,4,8};
    // int arr[] = {5,5,5,5,5,5,5,5};
    int arr[] = {42,45,41,20,12,3,73,1};
    // {3,1,4,2,5,7,9,6}
    // int arr[] = {3,1,7,5,2,4,9,6};
    int len = getArrayLen2(arr);
    // InsertSort1(arr);

    // insertSort2();
    // HalfInsertSort(arr);
    // CircleInsertSort(arr);
    // BaoSort(arr);
    // ShellSort(arr);
    // SimpleChooseSort(arr);
    // QuickSort1(arr, 0 ,len - 1);
    // QuickSort2(arr, 0,7);
    // QuickSort3(arr, 0,7);
    // QuickSort4(arr, 0, len-1);
    // SimpleChooseSort(arr, 0 , len - 1);
    // MergeSort(arr, 0, len - 1);
    // CoutingSort(arr);
    BucketSort(arr);
    // RadixSort(arr);
    printArr(arr);
//     vector<int> vect;
//     for(int i = 0; i < 8; ++i){
//         vect.push_back(arr[i]);
//     }
//     QuickSort(vect, 0,7);
//     
//    for(int i = 0; i < 8; ++i){
//         cout<<vect[i]<<", ";
    // }
	
	// quick_sort(arr,0,9);
	// for(int i=0;i<10;i++)printf("%d ",arr[i]);
    return 0;
}