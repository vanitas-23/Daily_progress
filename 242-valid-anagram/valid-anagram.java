class Solution {
    public boolean isAnagram(String s, String t) {
   int[] alphabets_counter = new int[26];
        if(s.length()!=t.length()){
            return false;
        }
        for (char c : s.toCharArray())
            alphabets_counter[c-'a']++;

        for (char c : t.toCharArray()){
            if (alphabets_counter[c-'a'] == 0) return false;
            alphabets_counter[c-'a']--;
        }
        return true;
}
}