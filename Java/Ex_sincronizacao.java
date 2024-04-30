class Conta {

    protected double saldo;

    public synchronized void saca(double valor) {
        this.saldo = this.saldo - valor;
    }

    public synchronized void deposita(double valor) {
        this.saldo = this.saldo + valor;
    }

    public synchronized double getSaldo() {
        return this.saldo;
    }
}

class Depositador extends Thread {

    protected Conta conta;

    public Depositador(Conta a) {
        conta = a;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            this.conta.deposita(10);
        }
    }
}

class Sacador extends Thread {

    protected Conta conta;

    public Sacador(Conta a) {
        conta = a;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            this.conta.saca(10);
        }
    }
}

public class Ex_sincronizacao {

    public static void main(String args[]) {
        Conta conta = new Conta();
        Depositador c1 = new Depositador(conta);
        Sacador c2 = new Sacador(conta);

        c2.start();
        c1.start();
        try {
            //aguarda as threads terminarem
            c1.join();
            c2.join();
        } catch (Exception ex) {
        }
        System.out.println(conta.getSaldo());


    }
}
