class Solution {
    public boolean checkInclusion(String s1, String s2) {
       
        int[] s1count = new int[26];
        int[] s2count = new int[26];
        if (s1.length() > s2.length()) {
          return false;  
        } 
        int len1 = s1.length();
        int len2 = s2.length();
        for (int i = 0; i < len1; i++) {
            s1count[s1.charAt(i) - 'a']++;
            s2count[s2.charAt(i) - 'a']++;
        }
        if (Arrays.equals(s1count, s2count)) {          
            return true;
        }
    
        for (int i = len1; i < len2; i++) {
            s2count[s2.charAt(i) - 'a']++;
            s2count[s2.charAt(i - len1) - 'a']--;
            if (Arrays.equals(s1count, s2count)) {
                return true;
            } 
        }
        
        return false;
    }

}
