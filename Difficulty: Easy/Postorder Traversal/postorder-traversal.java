/*
class Node {
    int data;
    Node left, right;
    Node(int val){
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    ArrayList<Integer> in = new ArrayList();
    public ArrayList<Integer> postOrder(Node root) {
        // code here
        if(root!=null){
             postOrder(root.left);
             postOrder(root.right);
             in.add(root.data);
        }
        return in;
    }
}