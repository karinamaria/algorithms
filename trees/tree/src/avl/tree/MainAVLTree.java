package avl.tree;

public class MainAVLTree {
    public static void main(String[] args) {
        AVLTree<Integer> tree = new AVLTree<>();
        tree.add(63);
        tree.add(7);
        tree.add(69);
        tree.add(59);
        tree.add(52);
        tree.add(60);
        tree.add(65);
        tree.add(90);
        tree.add(83);
        tree.levelOrderTraversal();
        System.out.println("\nMax: "+tree.max()+ " Min: "+tree.min());
    }
}
