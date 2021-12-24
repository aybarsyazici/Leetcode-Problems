import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 */

// @lc code=start
class Tree{
    public TreeNode root = null;
    public List<TreeNode> leafs;
    private int[] candidates;
    private int target;

    public Tree(int target, int[] candidates){
        this.target = target;
        this.candidates = candidates;
        this.leafs = new ArrayList<TreeNode>();
        TreeNode root = constructTree(new TreeNode(target, null));
        this.root = root;
    }

    public void printTree(TreeNode node){
        if(node == null){
            return;
        }
        for(TreeNode childNode : node.nextNodes){
            System.out.print(childNode.value + ' ');
        }
        System.out.println();
        for(TreeNode childNode : node.nextNodes){
            printTree(childNode);
        }
    }

    private TreeNode constructTree(TreeNode current){
        for(int candidate: candidates){
            if(current.value - candidate >= 0){
                TreeNode node = constructTree(new TreeNode(current.value - candidate, current));
                current.nextNodes.add(node);
                if(current.value - candidate == 0){
                    this.leafs.add(node);
                }
            }
        }
        return current;
    }

    class TreeNode{

        public TreeNode(int value, TreeNode prevNode){
            this.value = value;
            this.nextNodes = new ArrayList<TreeNode>();
            this.prevNode = prevNode;
        }

        public int value;
        public List<TreeNode> nextNodes;
        public TreeNode prevNode;
    }
}

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {  
        Set<List<Integer>> mySet = new HashSet<List<Integer>>();
        Tree myTree = new Tree(target, candidates);
        for(Tree.TreeNode leafNode : myTree.leafs){
            List<Integer> combination = new ArrayList<>();
            Tree.TreeNode tempNode = leafNode;
            while(tempNode.prevNode != null){
                combination.add(tempNode.prevNode.value - tempNode.value);
                tempNode = tempNode.prevNode;
            }
            Collections.sort(combination);
            mySet.add(combination);
        }
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.addAll(mySet);
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<List<Integer>> combinationSum = sol.combinationSum(new int[] {2,3,5}, 8);
        for(List<Integer> combination : combinationSum){
            System.out.println(Arrays.toString(combination.toArray()));
        }

    }
}

// @lc code=end

