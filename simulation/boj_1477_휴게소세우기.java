import java.io.*;
import java.util.*;

public class boj_1477_휴게소세우기 {
    static int N,M,L;
    static int[] building;
    
    public static void simulation(){
        Arrays.sort(building);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1,o2)->o2 - o1);
        for (int i = 0; i <= N ; i++) {
            pq.add(building[i+1] - building[i]);
        }

        for (int i = 0; i < M; i++) {
            int su = pq.poll();
            pq.add(su/2);
            pq.add(su - (su/2));
        }

        System.out.println(pq.poll());
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        
        building = new int[N + 2];
        building[0] = 1;
        building[N + 1] = L;
        
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N ; i++) {
            building[i] = Integer.parseInt(st.nextToken());
        }
        
        simulation();
        
    }
}
