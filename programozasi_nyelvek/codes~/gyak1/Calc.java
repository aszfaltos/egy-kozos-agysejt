class Calc {
    public static void main(String[] args) {
        // System.out.println("argc: " + args.length);
        if (args.length < 2) {
            System.out.println("2 args pls!!");
            return;
        }

        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        System.out.println("sum: " + (a + b));
        System.out.println("dif: " + (a - b));
        System.out.println("mul: " + (a * b));
        if (b != 0)
            System.out.println("div: " + ((double) a / b));
        else
            System.out.println("div by 0");
    }
}
