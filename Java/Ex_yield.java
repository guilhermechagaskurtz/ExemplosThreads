class threadYield extends Thread {

    public void run() {
        for (int i = 0; i < 10; i++) {
            // libera o controle para outra thread a cada 5 iterações.
            if (i == 5) {
                System.out.println(Thread.currentThread().getName() + " está liberando o controle em : " + i);
                Thread.yield();
            } else {
                System.out.println(Thread.currentThread().getName() + " com o controle em : " + i);
            }
        }

        System.out.println(Thread.currentThread().getName() + " finalizou sua execução.");
    }
}

public class Ex_yield {

    public static void main(String[] args) {
        threadYield t1 = new threadYield();
        threadYield t2 = new threadYield();
        t1.start();
        t2.start();
    }
}
