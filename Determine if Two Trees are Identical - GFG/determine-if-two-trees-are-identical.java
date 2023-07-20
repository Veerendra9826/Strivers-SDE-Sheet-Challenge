//{ Driver Code Starts
//Initial Template for Java

//Contributed by Sudarshan Sharma
import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class GfG {
    
    static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        
        Queue<Node> queue = new LinkedList<>(); 
        
        queue.add(root);
        // Starting from the second element
        
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    static void printInorder(Node root)
    {
        if(root == null)
            return;
            
        printInorder(root.left);
        System.out.print(root.data+" ");
        
        printInorder(root.right);
    }
    
	public static void main (String[] args) throws IOException{
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t-- > 0){
	            String s1 = br.readLine();
    	    	String s2 = br.readLine();
    	    	Node root1 = buildTree(s1);
    	    	Node root2 = buildTree(s2);
                Solution g = new Solution();
            //System.out.println(g.isIdentical(root,roott));
			    boolean b = g.isIdentical(root1,root2);
			    if(b==true)
				    System.out.println("Yes");
			    else
				    System.out.println("No");
	        }
	}
}


// } Driver Code Ends


//User function Template for Java



/*

class Node{
    int data;
    Node left,right;
    Node(int d){
        data=d;
        left=right=null;
    }
}*/


class Solution
{
    //Function to check if two trees are identical.
	boolean isIdentical(Node root1, Node root2)
	{
 if (root1 == null && root2 == null) // both trees are empty
            return true;
        if (root1 == null || root2 == null) // one of the trees is empty, which
                                     // means they are not identical
            return false;

        // Morris traversal
        while (root1 != null && root2 != null) {
            if (root1.data != root2.data) // if the data of the current nodes
                                    // is not the same, then the trees
                                    // are not identical
                return false;

            // Morris traversal for r1
            if (root1.left == null) { // if the left child is NULL, move to
                                   // the right child
                root1 = root1.right;
            } else { // if the left child is not NULL, find the
                     // predecessor
                Node pre = root1.left;
                while (pre.right != null && pre.right != root1) // find the rightmost node
                                                             // in the left subtree
                    pre = pre.right;
                if (pre.right == null) { // if the right pointer of the
                                         // predecessor is NULL, make it
                                         // point to the current node
                    pre.right = root1;
                    root1 = root1.left;
                } else { // if the right pointer of the
                         // predecessor is already pointing to the
                         // current node, set it back to NULL and
                         // move to the right child
                    pre.right = null;
                    root1 = root1.right;
                }
            }

            // Morris traversal for r2, same as for r1
            if (root2.left == null) {
                root2 = root2.right;
            } else {
                Node pre = root2.left;
                while (pre.right != null && pre.right != root2)
                    pre = pre.right;
                if (pre.right == null) {
                    pre.right = root2;
                    root2 = root2.left;
                } else {
                    pre.right = null;
                    root2 = root2.right;
                }
            }
        }

        return (root1 == null && root2 == null); 
	}
	
}