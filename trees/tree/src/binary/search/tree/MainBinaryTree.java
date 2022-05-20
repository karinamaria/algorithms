package binary.search.tree;

public class MainBinaryTree {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.add(63);
        tree.add(7);
        tree.add(69);
        tree.add(59);
        tree.add(52);
        tree.add(60);
        tree.add(65);
        tree.add(90);
        tree.add(83);
//        System.out.println("Percurso simétrico: ");
//        tree.simetricalTraversal(tree.getRoot());
//        System.out.println("\nPercurso em pós-ordem: ");
//        tree.posOrderTraversal(tree.getRoot());
//        System.out.println("\nPercurso em pré-ordem: ");
//        tree.preOrderTraversal(tree.getRoot());
        System.out.println("\nPercurso em nível: ");
        tree.levelOrderTraversal(tree.getRoot());
        System.out.println("===============");
        tree.remove(69);
        System.out.println("\nPercurso em nível: ");
        tree.levelOrderTraversal(tree.getRoot());
//        System.out.println("\nO menor nó é: "+tree.min(tree.getRoot()).getData());
//        System.out.println("\nO maior nó é: "+tree.max(tree.getRoot()).getData());
//        System.out.println("Altura da árvore: "+ tree.height(tree.getRoot()));
//        tree.search(16);
    }
}
