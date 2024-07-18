package binary_serarch;

import java.io.*;
import java.util.*;

public class boj_1477_휴게소세우기 {
    static int N,M,L;
    static int[] building; // 어차피 입력받고 sorting 할거니깐, ArrayList 로 해도 되겠당

    public static boolean check(int x){
        // x 로 휴게소 M개 이상 지을 수 있다면 true, 아니면 false
        int cnt = 0;
        for (int i = 1; i < N+2 ; i++) {
            cnt += (building[i] - building[i-1] - 1) / x;
        }

        if(cnt > M) return true;
        else return false;
    }
    public static void simulation() {
        Arrays.sort(building);
        
        int lo = 0;
        int hi = L;
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if(check(mid)) lo = mid;
            else hi = mid;
        }
//        System.out.println(lo);
        System.out.println(hi);
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        
        building = new int[N + 2];
        building[0] = 0;
        building[N + 1] = L;
        
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N ; i++) {
            building[i] = Integer.parseInt(st.nextToken());
        }
        
        simulation();
        
    }
}
