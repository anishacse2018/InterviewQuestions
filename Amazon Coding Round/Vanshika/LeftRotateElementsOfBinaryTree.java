/*
Given a binary tree where each level represents a floor of a multi storeyed building. 
Each node represents a house number. Number of nodes is the number of houses on that level. 
The task is to left rotate the digits of a house number, 
to have all the house numbers at a level arranged in increasing order.
                         
                          256                   256
                         /   \
                       537   189          537 918
                       /  \    \
                    438   365  167   384 536 716

https://www.geeksforgeeks.org/left-rotate-digits-of-node-values-of-all-levels-of-a-binary-tree-in-increasing-order/
*/

import java.util.*;

public class MyClass{
	
// TreeNode class
static class TreeNode
{
    public int val;
    public TreeNode left,right;
};
 
static TreeNode newNode(int v)
{
    TreeNode temp = new TreeNode();
    temp.val = v;
    temp.left = temp.right = null;
    return temp;
}

// Function to arrange node values
// of each level in increasing order
static void makeInc(TreeNode root)
{
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    while(!queue.isEmpty()){
        int sz = queue.size();
        int prev = -1;
        int flag = 0;
        while(sz--!=0){
            TreeNode node = queue.poll();
           // System.out.print(node.val+ " ");
            if(node.left!=null) queue.add(node.left);
            if(node.right!=null) queue.add(node.right);
            int min = node.val;
            String val = node.val+"";
            int n=val.length();
            ArrayList<Integer> list = new ArrayList<>();
            for(int i=0;i<n;i++){
                String newval = val.substring(i)+val.substring(0,i);
                //System.out.println(newval);
                int nval = Integer.parseInt(newval);
                if(nval>prev){
                    list.add(nval);
                }
            }
            if(list.size()==0){
                flag = 1;
                break;
            }
            Collections.sort(list);
            node.val = list.get(0);
            prev = node.val;
            System.out.print(node.val+ " ");
        }
        if(flag==1){
            System.out.print(-1);
            break;
        }
        System.out.println();
    }
}

// Driver code
public static void main (String[] args)
{
    // TC1
	TreeNode root = newNode(341);
	root.left = newNode(241);
	root.right = newNode(123);
	root.left.left = newNode(324);
	root.left.right = newNode(235);
	root.right.right = newNode(161);
	
	makeInc(root);
	System.out.println("*******");
	
	 // TC2
	TreeNode root2 = newNode(12);
	root2.left = newNode(89);
	root2.right = newNode(115);
	
	makeInc(root2);
	System.out.println("*******");
	
	 // TC3
    TreeNode root3 = newNode(12);
	root3.left = newNode(89);
	root3.right = newNode(15);
	
	makeInc(root3);
}
}

/*
Output:
134 
124 231 
243 352 611 
*******
12 
89 115 
*******
12 
89 -1
*/

/*
Optimised Code:
*/
import java.util.*;

public class MyClass{
	
// TreeNode class
static class TreeNode
{
    public int val;
    public TreeNode left,right;
};
 
static TreeNode newNode(int v)
{
    TreeNode temp = new TreeNode();
    temp.val = v;
    temp.left = temp.right = null;
    return temp;
}

// Function to arrange node values
// of each level in increasing order
static void makeInc(TreeNode root)
{
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    while(!queue.isEmpty()){
        int sz = queue.size();
        int prev = -1;
        int flag = 0;
        while(sz--!=0){
            TreeNode node = queue.poll();
           // System.out.print(node.val+ " ");
            if(node.left!=null) queue.add(node.left);
            if(node.right!=null) queue.add(node.right);
            int min = node.val;
            String val = node.val+"";
            int n=val.length();
            //ArrayList<Integer> list = new ArrayList<>();
            int mini = node.val;
            boolean flag2 = true;
            for(int i=0;i<n;i++){
                String newval = val.substring(i)+val.substring(0,i);
                //System.out.println(newval);
                int nval = Integer.parseInt(newval);
                if(nval>=prev && flag2==true){
                    mini = nval;
                    flag2 = false;
                }
                if(nval>=prev){
                    mini = Math.min(mini,nval);
                }
            }
            if(mini>=prev) {
                node.val = mini;
                prev = node.val;
                System.out.print(node.val+ " ");
            }else{
                flag = 1;
                break;
            }
        }
        if(flag==1){
            System.out.print(-1);
            break;
        }
        System.out.println();
    }
}

// Driver code
public static void main (String[] args)
{
    // TC1
	TreeNode root = newNode(341);
	root.left = newNode(241);
	root.right = newNode(123);
	root.left.left = newNode(324);
	root.left.right = newNode(235);
	root.right.right = newNode(161);
	
	makeInc(root);
	System.out.println("*******");
	
	 // TC2
	TreeNode root2 = newNode(12);
	root2.left = newNode(89);
	root2.right = newNode(115);
	
	makeInc(root2);
	System.out.println("*******");
	
	 // TC3
    TreeNode root3 = newNode(12);
	root3.left = newNode(89);
	root3.right = newNode(15);
	
	makeInc(root3);
}
}


