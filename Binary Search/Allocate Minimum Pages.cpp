Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:
Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
Note: If it is not possible to allocate books to all students, return -1.
//User function template in C++
class Solution 
{
    public:
    bool ispossible(int A[], int N, int M, int mid){
        int student_count = 1;
        int page_sum = 0;
        for(int i =0; i< N ; i++){
            if(page_sum + A[i] <= mid){
                page_sum += A[i];
            }
            else {
                student_count ++;
                if(student_count > M || A[i]> mid){
                    return false;
                }
                page_sum =0;
                page_sum += A[i];
            }
        }
        return true;
    }
        
    int findPages(int A[], int N, int M) 
    {
           if(M>N) return -1;
        int  s =0;
        int ans = -1;
        int e = accumulate(A, A+N, 0);
        while(s<= e){
            int mid = s +(e-s)/2;
            if(ispossible(A,N,M,mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
         
};  
  
