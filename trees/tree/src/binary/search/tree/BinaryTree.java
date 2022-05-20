package binary.search.tree;

import java.util.ArrayDeque;
import java.util.Objects;
import java.util.Queue;

/**
 * Implementation Binary Search Tree(BST)
 * Complexity: In general, time complexity is O(h) where h is height of BST
 * @author karina
 * @param <T> wrapper class that implements comparable
 */
public class BinaryTree<T extends Comparable> {
    private Node root;

    public BinaryTree() {
        this.root = null;
    }

    public BinaryTree(int data) {
        this.root = new Node(data);
    }

    public Node getRoot() {
        return root;
    }

    /**
     * Note about compareTo
     * An int value: 0 if the string is equal to the other string.
     * < 0 if the string is lexicographically less than the other string
     * > 0 if the string is lexicographically greater than the other string (more characters)
     * @param value
     */
    private void addNonRecursive(T value){
        Node current = this.root;
        Node prev = current;

        while(current != null){
            prev = current;
            if (value.compareTo(current.data) < 0) {
                current = current.left;
            } else if (value.compareTo(current.data) > 0) {
                current = current.right;
            }else {// value already exists
                return;
            }
        }
        if(this.root == null){
            this.root = new Node(value);
        } else if (value.compareTo(prev.data) < 0) {
            prev.left = new Node(value);
        } else {
            prev.right = new Node(value);
        }
    }
    private Node addRecursive(Node current, T value) {
        if (current == null) {
            return new Node(value);
        }

        if (value.compareTo(current.data) < 0) {
            current.left = addRecursive(current.left, value);
        } else if (value.compareTo(current.data) > 0) {
            current.right = addRecursive(current.right, value);
        }else {// value already exists
            return current;
        }

        return current;
    }

    public void add(T value) {
        //root = addRecursive(root, value);
        addNonRecursive(value);
    }

    /**
     * Percurso em ordem simétrica:
     * 		1. Percorre a subárvore da esquerda em ordem simétrica
     * 		2. Visita a raiz
     * 		3. Percorre a subárvore da direita em ordem simétrica
     * @param node
     */
    public void simetricalTraversal(Node node){
        if(Objects.isNull(this.root)){
            throw new RuntimeException("Árvore está vazia");
        }
        if(Objects.nonNull(node.left)){
            simetricalTraversal(node.left);
        }
        System.out.print(node.getData() + " ");
        if(Objects.nonNull(node.right)){
            simetricalTraversal(node.right);
        }
    }

    /**
     * Percurso em pós-ordem:
     *      1. Percorre a subárvore da esquerda em pós-ordem
     *      2. Percorre a subárvore da direita em pós-ordem
     *      3. Visita a raiz
     * @param node
     */
    public void posOrderTraversal(Node node){
        if(Objects.isNull(this.root)){
            throw new RuntimeException("Árvore está vazia");
        }
        if(Objects.nonNull(node.left)){
            simetricalTraversal(node.left);
        }
        if(Objects.nonNull(node.right)){
            simetricalTraversal(node.right);
        }
        System.out.print(node.getData() + " ");
    }

    /**
     * Percurso em pré-ordem:
     *      1. Visita a raiz
     *      2. Percorre a subárvore da esquerda em pré-ordem
     *      3. Percorre a subárvore da direita em pré-ordem
     * @param node
     */
    public void preOrderTraversal(Node node){
        if(Objects.isNull(this.root)){
            throw new RuntimeException("Árvore está vazia");
        }
        System.out.print(node.getData() + " ");
        if(Objects.nonNull(node.left)){
            simetricalTraversal(node.left);
        }
        if(Objects.nonNull(node.right)){
            simetricalTraversal(node.right);
        }
    }

    /**
     * Percurso em nível:
     *      1. Percorre nível por nível da esquerda para direita
     * @param node
     */
    public void levelOrderTraversal(Node node){
        if(Objects.isNull(this.root)){
            throw new RuntimeException("Árvore está vazia");
        }
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(node);
        while (!queue.isEmpty()){
            Node temp = queue.poll();
            if(temp.left != null){
                queue.add(temp.left);
            }
            if (temp.right != null) {
                queue.add(temp.right);
            }
            System.out.print(temp.data + " ");
        }
    }

    /**
     * Find the min node
     * @param node from starts search
     * @return the min node
     */
    public Node min(Node node){
        if(Objects.isNull(node)){
            throw new RuntimeException("O nó de início está vazio");
        }

        Node current = node;
        while(Objects.nonNull(current.left)){
            current = current.left;
        }
        return current;
    }

    /**
     * Find the max node
     * @param node from starts search
     * @return the max node
     */
    public Node max(Node node){
        if(Objects.isNull(node)){
            throw new RuntimeException("O nó de início está vazio");
        }
        Node current = node;

        while(Objects.nonNull(current.right)){
            current = current.right;
        }
        return current;
    }

    public int height(Node node){
        if (node == null){
            return -1;
        }
        // compute the depth of each subtree
        int hLeft = height(node.left);
        int hRight = height(node.right);

        if (hLeft > hRight) {
            return 1 + hLeft;
        }else {
            return 1 + hRight;
        }
    }

    private Node searchNonRecursive(T value){
        if(this.root == null){
            throw new RuntimeException("Árvore está vazia");
        }
        Node current = this.root;

        while(current.data != value){

            if (value.compareTo(current.data) < 0) {
                current = current.left;
            } else {
                current = current.right;
            }
            if(current == null) {
                break;
            }
        }
       return current;
    }

    private Node searchRecursive(Node node, T value){
        if(node == null){
            return null;
        }
        if(node.data == value){
            return node;
        }

        if (value.compareTo(node.data) < 0) {
          return searchRecursive(node.left, value);
        }

        return searchRecursive(node.right, value);
    }

    public void search(T value){
        //Node node = searchNonRecursive(value);
        Node node = searchRecursive(this.root, value);
        System.out.println("Encontrou elemento? "+ (node != null));
    }

    /**
     * Remove node of the binary search tree
     * @param node The root of the binary search tree
     * @param value Remove the node with given value
     * @return The root of the binary search tree after removal
     */
    private Node removeRecursive(Node node, T value){
        /* BASE CASE: did not find the node to be removed or found the leaf that will take the place of the node to be removed */
        if(node == null){
            return node;
        }
        if (value.compareTo(node.data) < 0) {
            node.left = removeRecursive(node.left, value); //go to left subtree
        }else if (value.compareTo(node.data) > 0) {
            node.right = removeRecursive(node.right, value); //go to right subtree
        }else{
            /* if key is same as root's key, then this is the node to be deleted*/
            if(node.left == null){//the node to be removed only has children on the right
                return node.right;
            }
            if(node.right == null){//the node to be removed only has children on the left
                return node.left;
            }
            /* finds the smallest node on the right that will take the place of the removed node */
            Node substitute = min(node.right);
            node.data = substitute.data;
            node.right = removeRecursive(node.right, (T) substitute.data);
        }

        return node;
    }

    public void remove(T value){
       removeRecursive(this.root, value);
    }

    class Node<T extends Comparable>{
        T data;
        Node left;
        Node right;

        public Node() {
        }

        public Node(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }

        public T getData() {
            return data;
        }
    }
}
