package avl.tree;

public class Node<T extends Comparable<T>>{
    private T data;
    private int height;
    private Node<T> left;
    private Node<T> right;

    public Node() {
    }

    public Node(T data) {
        this.data = data;
        this.height = 0;
        this.left = null;
        this.right = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public Node<T> getLeft() {return left; }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }
}
