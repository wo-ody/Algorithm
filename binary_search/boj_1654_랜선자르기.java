package binary_search;

import java.io.*;
import java.util.*;

public class boj_1654_랜선자르기 {
    static int K,N;
    static int[] input;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        input = new int[K];
        for (int i = 0; i < K; i++) {
            input[i] = Integer.parseInt(br.readLine());
        }

        long lo = 0;
        long hi = (long) Math.pow(2,31);

        while(lo + 1 < hi){
            long mid = (lo + hi) / 2;
            if(check(mid)) lo = mid;
            else hi = mid;
        }

        System.out.println(lo);
    }

    public static boolean check(long len){
        long cnt = 0;
        for(int su : input) cnt += (su / len);

        if(cnt >= N) return true;
        return false;
    }
}
