package binary_search;

import java.io.*;
import java.util.*;

public class boj_2110_공유기설치 {
    static int N,C;
    static long[] input;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        input = new long[N];
        for (int i = 0; i < N; i++) {
            input[i] = Long.parseLong(br.readLine());
        }

        Arrays.sort(input);

        long lo = 0;
        long hi = (long)Math.pow(10,9) + 1;
        while(lo + 1 < hi){
            long mid = (lo + hi) / 2;
            if(check(mid)) lo = mid;
            else hi = mid;
        }

        System.out.println(lo);
    }

    public static boolean check(long len){
        int cnt = 1;
        long su = input[0];
        for (int i = 1; i < N; i++) {
            if(input[i] - su >= len) {
                su = input[i];
                cnt++;
            }
        }

        if(cnt >= C) return true;
        return false;

    }
}
