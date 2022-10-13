import java.util.*;

public class MinimumIndexSumOfTwoLists {
    public static String[] findRestaurant(String[] list1, String[] list2) {
        HashMap<String,Integer> map =  new HashMap<>();

        for(int i=0 ; i<list1.length ; i++) {
            map.put(list1[i],i);
        }

        int min = Integer. MAX_VALUE ;
        int total=0;
        ArrayList<String> arr = new ArrayList<>();

        for(int i=0 ; i<list2.length ; i++) {
            if(map.get(list2[i])!= null){
                total=i+map.get(list2[i]);

                if(total<min) {
                    arr.clear();
                    arr.add(list2[i]);
                }

                if(total==min) {
                    arr.add(list2[i]);
                }

                min = Math.min(min,total);
            }


        }
        String[] ans = new String[arr.size()];

        return arr.toArray(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        String[] str1 = new String[n];
        String[] str2 = new String[k];

        for (int i = 0; i < n; i++) {
            str1[i] = sc.next();
        }

        for (int i = 0; i < k; i++) {
            str2[i] = sc.next();
        }

        String[] s = findRestaurant(str1,str2);

        System.out.println(Arrays.toString(s));

    }
}
