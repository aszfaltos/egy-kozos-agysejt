class A {
    public static void main(String[] args) {
        System.out.print("Name: ");
        String name = System.console().readLine();
        System.out.println("Hello " + name +"!");
    }
}