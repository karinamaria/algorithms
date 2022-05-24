package avl.tree;

import java.util.ArrayDeque;
import java.util.Objects;
import java.util.Queue;

/**
 * Implementation AVL Tree
 * Complexity: In general, time complexity is
 *      O(n) - space; O(log n) - search, insert and delete
 * @author karina
 * @param <T> wrapper class that implements comparable
 */
public class AVLTree<T extends Comparable<T>> {
    private Node<T> root;

    public AVLTree() {

    }

    public void add(T data){
        this.root = add(root,data);
    }

    private Node add(Node<T> node, T data){
        if (node == null) {
            return new Node<>(data);
        }
        if (data.compareTo(node.getData()) < 0) {
            node.setLeft(add(node.getLeft(), data));
        } else if (data.compareTo(node.getData()) > 0) {
            node.setRight(add(node.getRight(), data));
        } else {
            return node;
        }
        updateHeight(node);
        return applyRotation(node);
    }

    public void delete(T data) {
        root = delete(data, root);
    }

    private Node<T> delete(T data, Node<T> node) {
        if (node == null) {
            return null;
        }
        if (data.compareTo(node.getData()) < 0) {
            node.setLeft(delete(data, node.getLeft()));
        } else if (data.compareTo(node.getData()) > 0) {
            node.setRight(delete(data, node.getRight()));
        } else {
            // One Child or Leaf Node (no children)
            if (node.getLeft() == null) {
                return node.getRight();
            }
            if (node.getRight() == null) {
                return node.getLeft();
            }
            // Two Children
            Node substitute = min(node.getRight());
            node.setData((T) substitute.getData());
            node.setRight(delete(node.getData(), node.getRight()));
        }
        updateHeight(node);
        return applyRotation(node);
    }

    private Node<T> applyRotation(Node<T> node) {
        int balance = balance(node);//deve ser um valor entre [-1,1]
        if (balance > 1) {
            if (balance(node.getLeft()) < 0) {//eh necessária fazer rotação dupla, porque têm sinais diferentes
                node.setLeft(rotateLeft(node.getLeft()));
            }
            return rotateRight(node);
        }
        if (balance < -1) {
            if (balance(node.getRight()) > 0) {////eh necessária fazer rotação dupla, porque têm sinais diferentes
                node.setRight(rotateRight(node.getRight()));
            }
            return rotateLeft(node);
        }
        return node;
    }

    /**
     * Calcula o fator de balanceamento do nó, que é igual a diferença da altura
     * da subárvore esquerda e direita
     * @param node
     * @return
     */
    private int balance(Node<T> node) {
        return node != null ? height(node.getLeft()) - height(node.getRight()) : 0;
    }

    /*
    BEFORE
            15
          /     \
                 27
                /   \
                      49
    AFTER
             27
           /    \
          15     49
           \    /  \

     */
    private Node<T> rotateLeft(Node<T> node) {
        Node<T> rightNode = node.getRight();
        Node<T> centerNode = rightNode.getLeft();
        rightNode.setLeft(node);
        node.setRight(centerNode);
        updateHeight(node);
        updateHeight(rightNode);
        return rightNode;
    }

    /*
    BEFORE

             27
           /    \
          15     49
         / \    /  \
        10
        / \
       8
    AFTER
             27
           /    \
          10     49
         / \    /  \
        8  15
     */
    private Node<T> rotateRight(Node<T> node) {
        Node<T> leftNode = node.getLeft();
        Node<T> centerNode = leftNode.getRight();
        leftNode.setRight(node);
        node.setLeft(centerNode);
        updateHeight(node);
        updateHeight(leftNode);
        return leftNode;
    }

    private void updateHeight(Node<T> node) {
        /* Para descobrir a altura de um determinado nó precisamos descobrir qual subárvore tem a
        maior altura */
        int maxHeight = Math.max(height(node.getLeft()), height(node.getRight()));

        node.setHeight(maxHeight+1);
    }

    private int height(Node<T> node) {
        return node == null ? -1 : node.getHeight();
    }

    public T min(){
        Node<T> node = min(root);
        
        return node.getData();
    }

    private Node min(Node node){
        if(isEmpty()){
            return null;
        }

        if(node.getLeft() != null){
            return min(node.getLeft());
        }
        return node;
    }

    public T max(){
        Node<T> node = max(root);

        return node.getData();
    }

    private Node max(Node node){
        if(isEmpty()){
            return null;
        }

        if(node.getRight() != null){
            return max(node.getRight());
        }
        return node;
    }

    public boolean isEmpty(){
        return root == null;
    }

    /**
     * Percurso em nível:
     *      1. Percorre nível por nível da esquerda para direita
     */
    public void levelOrderTraversal(){
        if(Objects.isNull(this.root)){
            throw new RuntimeException("Árvore está vazia");
        }
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(this.root);
        while (!queue.isEmpty()){
            Node temp = queue.poll();
            if(temp.getLeft() != null){
                queue.add(temp.getLeft());
            }
            if (temp.getRight() != null) {
                queue.add(temp.getRight());
            }
            System.out.print(temp.getData() + " ");
        }
    }
}
