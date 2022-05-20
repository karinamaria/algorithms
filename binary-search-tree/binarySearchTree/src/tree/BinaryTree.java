package exemplo;

import java.util.ArrayDeque;
import java.util.Objects;
import java.util.Queue;


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
     * 1. Percorre a subárvore da esquerda em pós-ordem
     * 2. Percorre a subárvore da direita em pós-ordem
     * 3. Visita a raiz
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
     * 1. Visita a raiz
     * 2. Percorre a subárvore da esquerda em pré-ordem
     * 3. Percorre a subárvore da direita em pré-ordem
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
     * Percorre nível por nível da esquerda para direita
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
        Node prev = current;
        while(Objects.nonNull(node.left)){
            prev = current.right;
            current = current.right;
        }
        return prev;
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
        Node prev = current;

        while(Objects.nonNull(current.right)){
            prev = current.right;
            current = current.right;
        }
        return prev;
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
