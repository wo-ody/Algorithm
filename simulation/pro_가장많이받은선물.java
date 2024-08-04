import java.io.*;
import java.util.*;

class Solution {
    int N;
    int[][] presents;
    HashMap<String, Integer> hmap = new HashMap<>();
    
    public int solution(String[] friends, String[] gifts) {
        N = friends.length;
        
        presents = new int[N + 1][N + 1];
        
        make_presents(friends, gifts);
        return get_answer();
        
    }
    
    public void make_presents(String[] friends, String[] gifts){
      
        for(int i =0; i<N;i++){
            hmap.put(friends[i], i);
        }
        
        for(int i =0; i<gifts.length;i++){
            String[] tmp = gifts[i].split(" ");
            int a = hmap.get(tmp[0]);
            int b = hmap.get(tmp[1]);
            
            presents[a][b]++;
            
            presents[a][N]++;
            presents[N][b]++;
        }
        
        print_arr(presents);
    }
    
    public int get_answer(){
        int[] answer = new int[N];
        
        for(int i =0; i<N;i++){
            for(int j =i+1; j<N;j++){
                if(i == j) continue;
                
                int A = presents[i][j];
                int B = presents[j][i];
                System.out.println("ij"+i + j + "A : " + A + " B : " + B);
                
                if(A<B) answer[j]++;
                else if(A > B) answer[i]++;
                else {
                    int Ap = presents[i][N] - presents[N][i];
                    int Bp = presents[j][N] - presents[N][j];
                    System.out.println("Ap : " + Ap + " Bp : " + Bp);
                    if(Ap > Bp) answer[i]++;
                    else if(Ap < Bp) answer[j]++;
                }
                
                for(int a =0; a<N ;a++){
                    System.out.print(answer[a] + " ");
                }
                System.out.println();
                
            }
        }
        
        int result = -1;
        for(int i =0; i<N;i++){
            if(answer[i] > result) result = answer[i];
        }
        
        return result;
        
    }
    
    public void print_arr(int[][] arr){
        for(int i =0; i<arr.length ;i++){
            for(int j =0; j<arr[i].length ;j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}