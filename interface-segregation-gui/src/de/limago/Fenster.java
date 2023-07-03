package de.limago;

import java.awt.*;
import java.awt.event.*;


public class Fenster extends Frame  {


    public Fenster()  {

        setSize(300, 300);

        Button button = new Button("Drück mich");

        button.addActionListener(new MyActionListener());

        addWindowListener(new MyWindowListener());

        add(button);




    }

    private void ausgabe() {
        System.out.println("Button wurde gedrückt");
    }

    private void beenden() {
        // Daten speichern etc.
        dispose();
    }

    public static void main(String[] args) {

        new Fenster().setVisible(true);
    }

    class MyActionListener implements ActionListener {

        @Override
        public void actionPerformed(final ActionEvent e) {
           ausgabe();
        }
    }

    class MyWindowListener extends WindowAdapter {
        @Override
        public void windowClosing(final WindowEvent e) {
            beenden();
        }
    }
}
