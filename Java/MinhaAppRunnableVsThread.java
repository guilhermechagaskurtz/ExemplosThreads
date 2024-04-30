public class MinhaAppRunnableVsThread {

    public static void main(String[] args) {
        Runner r = new Runner();
        Thread t1 = new Thread(r, "Thread A");
        Thread t2 = new Thread(r, "Thread B");
        Strider s1 = new Strider("Thread C");
        Strider s2 = new Strider("Thread D");
        t1.start();
        t2.start();
        s1.start();
        s2.start();
    }
}

class Runner implements Runnable {

    private int counter = 0;

    public void run() {
        try {
            for (int i = 0; i != 2; i++) {
                System.out.println(Thread.currentThread().getName() + ": " + counter++);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Strider extends Thread {

    private int counter = 0;

    Strider(String name) {
        super(name);
    }

    public void run() {
        try {
            for (int i = 0; i != 2; i++) {
                System.out.println(Thread.currentThread().getName() + ": " + counter++);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
