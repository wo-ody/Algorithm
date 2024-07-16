package boj;

import java.io.*;
import java.util.*;

public class boj_17281_야구공 {
    static int N;
    static int[][] result;

    static int[] order = new int[10];
    static boolean[] visited = new boolean[10];

    static int answer = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        result = new int[N+1][10];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                result[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        order[4] = 1;
        visited[1] = true;
        fact(1);

        System.out.println(answer);

    }

    public static void fact(int idx){
        if(idx == 4) {
            fact(5);
            return;
        }
        if(idx == 10){
            simulation();
            return;
        }

        for (int i = 2; i <= 9; i++) {
            if(!visited[i]){
                visited[i] = true;
                order[idx] = i;

                fact(idx + 1);

                visited[i] = false;
            }
        }
    }

    // order 에는 타자번호의 순서
    public static void simulation(){

//        if(isSame()){
//            System.out.println("끝");
//        }

        int sum = 0;
        int player = 1; // 1번 타자부터 시작
        Queue<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            int out = 0;
            while(out != 3){
                int score = result[i][order[player]];

                if(score == 0) out++;
                else if(score == 4){
                    sum += (q.size() + 1);
                    q.clear();
                }
                else{
                    int size = q.size();
                    for (int j = 0; j < size; j++) {
                        int su = q.poll();
                        if(su + score > 3) sum++;
                        else q.add(su + score);
                    }
                    q.add(score);
                }

                player = (player % 9) + 1;
            }
            // 이닝이 시작될때는 주자는 없다
            q.clear();
        }

        answer = Math.max(answer, sum);

    }

    public static boolean isSame(){
        int[] nOrder = new int[]{2, 3, 4, 1, 6, 7, 8, 9, 5};

        for (int i = 1; i <= 9 ; i++) {
            if(order[i] != nOrder[i-1]) return false;
        }
        return true;
    }
}
