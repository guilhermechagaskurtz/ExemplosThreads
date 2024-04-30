class threadIsAlive extends Thread {

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

public class Ex_isAlive {

    public Ex_isAlive() {
        threadIsAlive t = new threadIsAlive();
        t.start();

        int countSegundos = 0;
        //enquanto a thread acima estiver viva
        while (t.isAlive()) {
            try {
                Thread.sleep(1000);
                countSegundos++;
                System.out.println(countSegundos + " seg");
            } catch (Exception ex) {
            }
        }
    }

    public static void main(String[] args) {
        new Ex_isAlive();
    }
}
