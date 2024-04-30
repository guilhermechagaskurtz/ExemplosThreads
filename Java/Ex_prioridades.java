class threadPrioridade extends Thread {

    public threadPrioridade(String name) {
        super(name);
    }

    public void run() {
        int count = 0;
        while (true) {
            System.out.println(getName() + ": " + count++);

        }
    }
}

public class Ex_prioridades {

    public static void main(String args[]) {
        
         threadPrioridade t1 = new threadPrioridade("T1111111");
         t1.setPriority(Thread.MAX_PRIORITY);
         threadPrioridade t2 = new threadPrioridade("T2");
         t2.setPriority(Thread.MIN_PRIORITY);
         t2.start();
         t1.start();
    }
}