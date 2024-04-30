class threadJoin extends Thread {

    public void run() {
        for (int k = 0; k < 10; k++) {
            for (int i = 0; i < 1000000000; i++) {
                for (int j = 0; j < 1000000000; j++) {
                }
            }
        }
        System.out.println("Ja terminei");
    }
}

public class Ex_join {

    public Ex_join() {
        threadJoin t = new threadJoin();
        t.start();
        try {
            //a chamada ao metodo join só terminará quando a thread t terminar
            t.join();
            //t.join(100);
            System.out.println("A thread terminou");
        } catch (Exception ex) {
        }

    }

    public static void main(String[] args) {
        new Ex_join();
    }
}
