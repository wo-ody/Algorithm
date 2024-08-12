package two_pointer;

import java.io.*;
import java.util.*;

public class boj_1253_좋다 {
    static int N;
    static long[] input;
    static int result = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        input = new long[N];
        for (int i = 0; i < N; i++) {
            input[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(input);

        for (int i = 0; i < N; i++) {
            int lo = 0;
            int hi = N-1;
            boolean flag = false;
            while(true){
                if(lo == i) lo++;
                if(hi == i) hi--;

                if(lo >= hi) break;

                long sum = input[lo] + input[hi];
                if(sum < input[i]) lo++;
                else if(sum > input[i]) hi--;
                else {
                    flag = true;
                    break;
                }
            }

            if(flag) result++;
        }

        System.out.println(result);

    }
}
