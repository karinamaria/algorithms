package tree;

public class MainBinaryTree {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.add('a');
        tree.add('b');
        tree.add('c');
        tree.add('d');
        System.out.println("Percurso simétrico: ");
        tree.simetricalTraversal(tree.getRoot());
        System.out.println("\nPercurso em pós-ordem: ");
        tree.posOrderTraversal(tree.getRoot());
        System.out.println("\nPercurso em pré-ordem: ");
        tree.preOrderTraversal(tree.getRoot());
        System.out.println("\nPercurso em nível: ");
        tree.levelOrderTraversal(tree.getRoot());
        //System.out.println("\nO menor nó é: "+tree.min(tree.getRoot()).getData());
        System.out.println("\nO maior nó é: "+tree.max(tree.getRoot()).getData());
    }
}
