//{ Driver Code Starts
import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0){
		    String s=br.readLine();
		    GfG g=new GfG();
		    int len=g.count(s);
		    System.out.println(len);
		}
	}
}

// } Driver Code Ends


/*Complete the function below*/
class GfG{
    public int count(String s)
    {
               // initialize variables
        int count = 0;
        int maxCount = 0;

        // iterate over the string from left to right
        for (char c : s.toCharArray()) {
            // if current character is '1' then increment count
            if (c == '1') {
                count++;
            } else { // otherwise, store the maximum count because it is the maximum length so far
                maxCount = Math.max(count, maxCount);
                count = 0;
            }
        }

        // if a sub-string is found at the end of the string
        maxCount = Math.max(count, maxCount);
        return maxCount;
    }
}