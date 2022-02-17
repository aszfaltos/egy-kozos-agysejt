class Print {
    public static void main(String[] args) {

        System.out.print("num1: ");
        double start = (double) Integer.parseInt(System.console().readLine());
        System.out.print("num2: ");
        double end = (double) Integer.parseInt(System.console().readLine());

        for (double i = start / 2; i <= end / 2; i += 0.5) {
            System.out.println(i);
        }
        /*
         * int i = 4;
         * System.out.println("Kiirtam " + i + " szamot");
         */
    }
}
