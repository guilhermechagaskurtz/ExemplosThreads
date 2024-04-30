class Message {

    private String text;

    public Message() {
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}

class Waiter extends Thread {

    Message message;

    public Waiter(Message message) {
        this.message = message;
    }

    @Override
    public void run() {
        synchronized (message) {
            try {
                System.out.println("Waiter " + getName() + " está esperando pelo notificador");
                message.wait(); //dorme enquanto ninguem mandar ela acordar
            } catch (InterruptedException e) {
            }
        }
        System.out.println("Waiter " + getName() + " terminou de esperar");
        System.out.println("Waiter " + getName() + " recebeu a seguinte mensagem: " + message.getText());
    }
}

class Notificador extends Thread {

    Message message;

    public Notificador(Message message) {
        this.message = message;
    }

    @Override
    public void run() {
        System.out.println("Notifier vai dormir por 3 segundos");
        try {
            sleep(3000);
        } catch (InterruptedException e1) {
        }
        synchronized (message) {
            message.setText("Notificador cochilou por 3 segundos");
            System.out.println("Notificador irá notificar a thread que está esperando para ela acordar");
            message.notify(); //acorda uma das waiterThread
            //message.notifyAll(); //acorda todas as waiterThread
        }

    }
}

public class Ex_wait_notify {

    public static void main(String args[]) {

        Message message = new Message();

        Waiter waiterThread = new Waiter(message); // Criação da thread Waiter (que irá esperar a notificação) 
        waiterThread.setName("waiterThread 1"); //define o nome da thread
        waiterThread.start();

        /* Criação de 10 threads Waiter (que irão esperar a notificação) */
        /*for (int i = 0; i < 10; i++) {
            Waiter waiterThread = new Waiter(message);
            waiterThread.setName("waiterThread " + i); //define o nome da thread
            waiterThread.start();
        }*/

        Notificador notifierThread = new Notificador(message);// Criação da thread Notificadora (que irá notificar a Waiter e fazer com que ela desbloqueie)
        notifierThread.setName("notifierThread");//define o nome da thread
        notifierThread.start();
    }
}