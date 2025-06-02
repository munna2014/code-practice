import java.util.*;

public class anagram {

    public List<List<String>> groupAnagrams(String[] strs) {
        // Map to store grouped anagrams
        Map<String, List<String>> res = new HashMap<>();

        for (String s : strs) {
            // Convert string to character array and sort it
            char[] charArray = s.toCharArray();
            Arrays.sort(charArray);
            // Convert sorted character array back to a string
            String sortedS = new String(charArray);

            // Add the original string to the corresponding group in the map
            res.putIfAbsent(sortedS, new ArrayList<>());
            res.get(sortedS).add(s);
        }

        // Return the values of the map as a list of lists
        return new ArrayList<>(res.values());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask user for input
        System.out.println("Enter strings separated by spaces:");
        String input = scanner.nextLine();

        // Split the input into an array of strings
        String[] strs = input.split(" ");

        // Create an instance of the Solution class
        anagram ana = new anagram();

        // Group anagrams
        List<List<String>> groupedAnagrams = ana.groupAnagrams(strs);

        // Print the result
        System.out.println("Grouped Anagrams:");
        for (List<String> group : groupedAnagrams) {
            System.out.println(group);
        }

        scanner.close();
    }
}
