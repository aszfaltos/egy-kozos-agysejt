class Factorial {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("2 args pls!!");
            return;
        }
        System.out.println(fact(Integer.parseInt(args[0])));

    }

    public static long fact(int n) {
        if (n <= 1)
            return 1;
        else
            return n * fact(n - 1);
    }
}